<?php
defined('BASEPATH') OR exit('No direct script access allowed');

class Finalproject extends CI_Controller {
	public function index() {
        if(isset($_SESSION['username'])) {
            $data = array("message" => "");
            $this->load->view('home', $data);
        }
        else {
            $data = array("message" => "", "type" => "alert alert-danger");
            $this->load->library('form_validation');
            $this->load->view('login', $data);
        }
    }
    
    public function proclogin() { 
        $this->load->helper(array('form'));
        $this->load->library('form_validation');
        $this->form_validation->set_rules('username','Username','required');
        $this->form_validation->set_rules('password','Password','required');
        
        if($this->form_validation->run() == FALSE) {
            $data = array("message" => "Field Missing", "type" => "alert alert-danger");
            $this->load->view('login',$data);
        }
        else {
            $this->load->model('logincheck');
            $result = $this->logincheck->get_login();
            if($result) {
                $_SESSION['username'] = $this->input->post('username');
                $data = array("message" => "");
                $this->load->view('home', $data);
            } else {
                $data = array("message" => "Invalid Login", "type" => "alert alert-danger");
                $this->load->view('login', $data);
            }
        }
    }

    public function login() {
        $this->load->library('form_validation');
        $data = array("message" => "", "type" => "alert alert-danger");
        $this->load->view('login', $data);
    }

    public function change() {
        $this->load->helper(array('form'));
        $this->load->library('form_validation');
        $data = array("message" => "", "type" => "");
        $this->load->view('changepassword', $data);
    }
    
    public function chart() {
        $this->load->view('dashboardchart');
    }
    
    public function javascript() {
        $this->load->view('Jqueryfile.js');
    }

    public function listing() {
        $this->load->model('databasecheck');
        $movies = $this->databasecheck->get_movies();
        $data = array('movies' => $movies);
        $this->load->view('listing', $data);
    }

    public function movie() {
        if($_SERVER["HTTP_REFERER"] != site_url("/finalproject/listing/")) {
            redirect('finalproject/invalid');
        }
        $this->load->model('databasecheck');
        $movie = $this->uri->segment(3,0);
        if($movie) {
            $moviedata = $this->databasecheck->get_movie($movie);
            $data = array("movie" => $moviedata);
            $this->load->view('movie',$data);
        }
        else {
            redirect('finalproject/listing');
        }
    }

    public function confirm() {
        if($_SERVER["HTTP_REFERER"] != site_url("/finalproject/listing/") && $_SERVER["HTTP_REFERER"] != site_url("/finalproject/listing?") &&
            $_SERVER["HTTP_REFERER" != site_url("/finalproject/listing")]) {
            redirect('finalproject/invalid');
        }
        $this->load->model('databasecheck');
        $movie = $this->input->post('filmID');
        if($movie) {
            $moviedata = $this->databasecheck->get_movie($movie);
            $data = array("movie" => $moviedata, "filmID" => $this->input->post('filmID'));
            $this->load->view('confirm',$data);
        }
        else {
            redirect('finalproject/listing');
        }
    }

    public function remove() {
        $this->load->model('databasecheck');
        $this->databasecheck->remove_movie($this->input->post('filmID'));
        redirect('finalproject/listing');
    }

    public function add() {
        $this->load->library('form_validation');
        $this->load->view('add');
    }

    public function changepfp() {
        $data = array("message" => "");
        $this->load->view('changepfp', $data);
    }

    public function getpfp() {
        $this->load->view('profilepicture');
    }
    
    public function setpfp() {
        $config['upload_path']          = './uploads/';
        $config['allowed_types']        = 'png';
        $config['max_size']             = 100;

        $this->load->library('upload', $config);

        if ( ! $this->upload->do_upload('userfile')) {
            $error = array('error' => $this->upload->display_errors());
            $this->load->view('changepfp', $error);
        }
        else {
            $data = array('upload_data' => $this->upload->data());
        }
    }

    public function invalid() {
        $this->load->view('invalid');
    }
    
    public function newMovie() {
        if($_SERVER["HTTP_REFERER"] != site_url("/finalproject/add/") && $_SERVER["HTTP_REFERER"] != site_url("/finalproject/newMovie/"))   {
            redirect('finalproject/invalid');
        }
        $this->load->helper(array('form'));
        $this->load->library('form_validation');

        $this->form_validation->set_rules('title','Movie Title','required');
        $this->form_validation->set_rules('year','Release Year','required|numeric',
            array('numeric' => 'The year must be numeric'));
        $this->form_validation->set_rules('length','Movie Length','required|numeric',
            array('numeric' => 'The length of the movie must be numeric'));
        $this->form_validation->set_rules('description','Movie Description','required');
        $this->form_validation->set_rules('duration','Rental Duration','required|numeric',
            array('numeric' => 'The rental duration must be numeric'));
        $this->form_validation->set_rules('replacementCost','Rental Replacement Cost','required|decimal',
            array('decimal' => 'The year must be expressed as a decimal'));
        $this->form_validation->set_rules('rating','Movie Rating','required');
        
        if($this->form_validation->run() == FALSE) {
            $this->load->view('add');
        }
        else {
            $title = $this->input->post('title');
            $year = $this->input->post('year');
            $length = $this->input->post('length');
            $description = $this->input->post('description');
            $duration = $this->input->post('duration');
            $replacementCost = $this->input->post('replacementCost');
            $rating = $this->input->post('rating');
        
            $this->load->model('databasecheck');
            $data = array('title' => $title, 'year' => $year, 'length' => $length, 'description' => $description, 
                        'duration' => $duration, 'replacementCost' => $replacementCost, 'rating' => $rating);
            $this->databasecheck->add_movie($data);
            redirect('finalproject/listing');                
        }
    }

    public function reset() {
        if($_SERVER["HTTP_REFERER"] != site_url("/finalproject/change/") && $_SERVER["HTTP_REFERER"] != site_url("/finalproject/reset/")) {
            redirect('finalproject/invalid');
        }
        $this->load->helper(array('form'));
        $this->load->library('form_validation');

        $this->form_validation->set_rules('curPass','Current Password','required|callback_password_check',
            array('required' => 'You must input your %s.', 'password_check' => 'Invalid Password'));
        $this->form_validation->set_rules('newPass1','New Password','required',
            array('required' => '%s fields cannot be left blank'));
        $this->form_validation->set_rules('newPass2','New Password','required',
            array('required' => '%s fields cannot be left blank'));
        $this->form_validation->set_rules('newPass1','Passwords','matches[newPass2]',
            array('matches' => 'New %s did not match'));
        
        if($this->form_validation->run() == FALSE) {
            $this->load->view('changepassword');
        }
        else {
            $this->logincheck->change_password();
            $data = array('message' => "Password Chaged");
            $this->load->view('success',$data);
        }
    }

    public function password_check() {
        $this->load->model('logincheck');
        $result = $this->logincheck->password_validate();
        if($result) {
            return TRUE;
        }
        else {
            return FALSE;
        }
    }

    public function success() {
        $data = array('message' => "Success Page");
        $this->load->view('success',$data);
    }
    
    public function logout() {
        $_SESSION['username'] = NULL;
        $data = array("message" => "Logged Out", "type" => "alert alert-warning");
        $this->load->library('form_validation');
        $this->load->view('login', $data);
    }
}
