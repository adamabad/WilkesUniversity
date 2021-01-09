<!DOCTYPE html>
<!--
Name: Adam Abad
File: lab4submit.php
Date: 2/11/2020
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
            if(array_key_exists("n", $_POST) && is_numeric($_POST["n"]) 
                                        && $_POST["n"] == (int)$_POST["n"] 
                                        && (int)$_POST["n"] >= 2 
                                        && (int)$_POST["n"] <= 25) {
                $n = (int)$_POST["n"];
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
    <a href="./lab4form.php">Back to form.</a>
    </body>
</html>
