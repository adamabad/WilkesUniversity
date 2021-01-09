<?php

class Blogcat extends CI_Model {
    public $id;
    public $title;
    public $body;
    public $category;
    public $postedat;

    public function get_categories() {
        return $this->db->order_by('title')->get('blog_categories')->result();
    }
}


?>