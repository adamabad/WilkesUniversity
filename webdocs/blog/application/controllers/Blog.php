<?php
defined('BASEPATH') OR exit('No direct script access allowed');

class Blog extends CI_Controller {
	public function index()
	{

        $skip = $this->uri->segment(3, 0);
        $this->load->model('blogpost');
        
        $this->load->library('pagination');

        $config['base_url'] = "http://abada.mathcs.wilkes.edu/blog/index.php/blog/index/";
        $config["total_rows"] = $this->blogpost->total_posts(); 
        $config["per_page"] = 5;

        $config["full_tag_open"] = "<nav aria-label='Page navigation example'><ul class='pagination'>";
        $config["full_tag_close"] = "</ul></nav>";
        
        $config["first_tag_open"] = $config["last_tag_open"] = $config["next_tag_open"] = $config["prev_tag_open"] = $config["num_tag_open"] = "<li class='page-item'>";
        $config["first_tag_close"] = $config["last_tag_close"] = $config["next_tag_close"] = $config["prev_tag_close"] = $config["num_tag_close"] = "</li>";        

        $config["cur_tag_open"] = "<li class='page-item active'><a class='page-link'>";
        $config["cur_tag_close"] = "</a></li>";

        $config["attributes"] = ["class" => 'page-link'];
        
        $this->pagination->initialize($config);

        $this->load->model('blogcat');
        
        $posts = $this->blogpost->get_listing($skip);
        $categories = $this->blogcat->get_categories();
        $data = array('posts' => $posts, 'page_links' => $this->pagination->create_links(), 'categories' => $categories);
        $this->load->view('listing', $data);
    }

    public function new() {
        $this->load->model('blogcat');
        $categories = $this->blogcat->get_categories();
        $data = array('categories' => $categories);
        $this->load->view('newpost', $data);
    }
    
    public function submit() {
        $this->load->model('blogpost');
        $this->blogpost->create();
        $data = array('newtitle' => $this->input->post('title'));
        $this->load->view('submitted', $data);
    }

    public function category() {
        $category = $this->uri->segment(3, 0);
        if($category) {
            $this->load->model('blogpost');
            $this->load->model('blogcat');
            $posts = $this->blogpost->get_listing_category($category);
            $categories = $this->blogcat->get_categories();
            $data = array('posts' => $posts, 'page_links' => '', 'categories' => $categories);
            $this->load->view('listing', $data);
        }
        else {
            redirect('blog/index');
        }
    }
}
