<?php
//Name: Adam Abad
//File: lab1prime.php
//Date: 1/16/2020

Function isPrime($n) {
  $value = true;
  for($x = 2; $x < sqrt($n); $x++) {
    if($n % $x == 0) {
      $value = false;
      break;
    }
  }
  return $value;
}

echo "Enter n: ";
$n = trim(fgets(STDIN));
$bool = isPrime($n);

if($bool)
  echo "$n is prime.\n";
else
  echo "$n is not prime.\n";
?>