<?php
require "lab7.php";
$graph = new BarChart("Test Chart","Some X values","Some Y values");
$graph->addCategory("Value 1", 4);
$graph->addCategory("Value 2", 5);
$graph->addCategory("Value 3", 2);
$graph->addCategory("Value 4", 4);
$graph->addCategory("Value 5", 1);

$graph->displayGraph();
?>