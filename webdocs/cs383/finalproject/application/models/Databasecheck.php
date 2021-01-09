<?php
defined('BASEPATH') OR exit('No direct script access allowed');

class Databasecheck extends CI_Model {
    public function get_total() {
        return $this->db->query("SELECT * FROM sakila_inventory")->num_rows();
    }
    
    public function get_rented() {
        return $this->db->query("SELECT * FROM sakila_rental WHERE return_date IS NULL")->num_rows();
    }

    public function get_movies() {
        return $this->db->query("SELECT film_id, title, release_year, length FROM sakila_film ORDER BY title")->result();
    }

    public function get_movie($filmid = 0) {
        return $this->db->query("SELECT title, release_year, length, description, rental_duration, replacement_cost, rating FROM sakila_film WHERE film_id = ".$this->db->escape($filmid)."")->result();
    }

    public function remove_movie($filmid = 0) {
        $this->db->query("DELETE FROM sakila_film WHERE film_id = ".$this->db->escape($filmid)."");
    }

    public function add_movie($movieData) {
        $this->db->query("INSERT INTO sakila_film (title, release_year, length, description, rental_duration, replacement_cost, rating) VALUES 
            (".$this->db->escape($movieData['title']).", ".$this->db->escape($movieData['year']).", 
            ".$this->db->escape($movieData['length']).", ".$this->db->escape($movieData['description']).", 
            ".$this->db->escape($movieData['duration']).", ".$this->db->escape($movieData['replacementCost']).", 
            ".$this->db->escape($movieData['rating']).")");
    }
}
?>