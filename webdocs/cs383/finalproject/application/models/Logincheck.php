<?php

class Logincheck extends CI_Model {
    public $username;
    public $password;
    public function get_login() {
        $this->username = $this->input->post('username');
        $this->password = $this->input->post('password');
        return $this->db->query("SELECT * FROM sakila_staff WHERE username = ".$this->db->escape($this->username)." AND password = MD5(".$this->db->escape($this->password).")")->num_rows();
    }
    
    public function password_validate() {
        $this->password = $this->input->post('curPass');
        $this->username = $_SESSION['username'];
        return $this->db->query("SELECT * FROM sakila_staff WHERE username = ".$this->db->escape($this->username)." AND password = MD5(".$this->db->escape($this->password).")")->num_rows();
    }

    public function change_password() {
        $this->password = $this->input->post('newPass1');
        $this->username = $_SESSION['username'];
        $this->db->query("UPDATE sakila_staff SET password = MD5(".$this->db->escape($this->password).") WHERE username = ".$this->db->escape($this->username)."");
    }
    
    public function change_pfp($data) {
        $this->db->query("UPDATE sakila_staff SET picture = ".$this->db->escape($data['picture'])." WHERE username = ".$this->db->escape($data['username'])."");
    }

    public function get_pfp() {
        $this->username = $_SESSION['username'];
        return $this->db->query("SELECT picture FROM sakila_staff WHERE username = ".$this->db->escape($this->username)."")->result();
    }
}

?>