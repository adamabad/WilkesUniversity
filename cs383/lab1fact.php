<?php
//Name: Adam Abad
//File: lab1fact.php
//Date: 1/16/2020


Function factorial($value, $n = 0) {
  if($n == 0)
    return $value;
  else
    return factorial($value * $n, $n - 1); 
}

for($x = 1; $x < $argc; $x++)
  echo "$argv[$x]! = " . factorial(1,$argv[$x]) ."\n";
?>