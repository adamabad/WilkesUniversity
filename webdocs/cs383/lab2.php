<!DOCTYPE html>
<!--
Name: Adam Abad
File: lab2.php
Date: 1/30/2020
-->

<html>
    <head>
        <?php
            Function factorial($value, $n = 0) {
                if($n == 0)
                  return $value;
                else
                  return factorial($value * $n, $n - 1);
            }
            
            if(array_key_exists("n", $_GET) && is_numeric($_GET["n"]) && $_GET["n"] == (int)$_GET["n"]) {
                $n = (int)$_GET["n"];
            }
            else {
                $n = -1;
            }
        ?>
<title><?= $n > 1 ? "Factorials: 1! through $n!" : "Invalid Input"?></title>
    </head>
    <body>
        <h1><?= $n > 1 ? "Factorials: 1! through $n!" : "Invalid Input"?></h1>
        <?php
            if($n < 2)
                echo "Valid input for n was not provided.</br>\n";
            else {
            ?>
    <table>
                <thead>
                    <tr>
                        <th>n</th>
                        <th>n!</th>
                    </tr>
                </thead>
            <?php
                for($x = 1; $x <= $n; $x++) {
                    if($x % 2)
                        $code = "#CCFF99";
                    else
                        $code = "#6699CC";
        ?>
            
            <tr bgcolor=<?="$code"?>> 
                <td><?="$x!"?></td>
                <td><?= factorial(1, $x)?></td>
            </tr>
        <?php     
                } //End for
                echo "</table>\n";
            } //End else
        ?>
    </body>
</html>