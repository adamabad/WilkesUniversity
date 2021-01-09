<?php

class Blogpost extends CI_Model {
    public $id;
    public $title;
    public $body;
    public $category;
    public $postedat;

    public function get_listing($skip = 0) {
        return $this->db->order_by('id', 'DESC')->limit(5, $skip)->get('blog_posts')->result();
    }
    
    public function total_posts() {
        return $this->db->count_all('blog_posts');
    }
    
    public function get_listing_category($catid = 0) {
        return $this->db->order_by('id', 'DESC')->where('category', $catid)->get('blog_posts')->result();
    }
    
    public function create() {
        $this->title = $this->input->post('title');
        $this->body = $this->input->post('body');
        $this->postedat = time();
        $this->category = $this->input->post('category');
        $this->db->insert('blog_posts', $this);
    }

}

?>