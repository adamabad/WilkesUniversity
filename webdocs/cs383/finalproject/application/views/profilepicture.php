<?php
   defined('BASEPATH') OR exit('No direct script access allowed');
   $CI = get_instance();
   $CI->load->model('logincheck');
   $img = $CI->logincheck->get_pfp();
   $img = base64_decode($img[0]->picture);
   header("Content-Type: image/png");
   echo $img;
?>