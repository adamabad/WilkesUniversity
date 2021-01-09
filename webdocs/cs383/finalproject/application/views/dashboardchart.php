<?php
    defined('BASEPATH') OR exit('No direct script access allowed');
    require(APPPATH."/views/BarChart.php");
    $CI = get_instance();
    $CI->load->model('databasecheck');
    $total = $CI->databasecheck->get_total();
    $rented = $CI->databasecheck->get_rented();
    
    $graph = new BarChart("Rentable Videos","Type","Copies Avilable");
    $graph->addCategory("Total ".$total,$total);
    $graph->addCategory("Rented ".$rented,$rented);
    $graph->displayGraph();
?>