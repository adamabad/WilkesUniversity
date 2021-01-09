<?php
//Name: Adam Abad
//File: lab1fib.php
//Date: 1/16/2020

Function fibonacci($n) {
  $fib = array(0,1);
  
  while(($fib[count($fib) - 1] + $fib[count($fib) - 2]) <= $n)
    $fib[] = $fib[count($fib) - 1] + $fib[count($fib) - 2];
  return $fib;
}

echo "Enter n: ";
$array = fibonacci(trim(fgets(STDIN)));
print_r($array);

?>