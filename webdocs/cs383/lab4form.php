<!DOCTYPE html>
<!--
Name: Adam Abad
File: lab4form.php
Date: 2/11/2020
-->

<html>
    <head>
        <title>Lab 4 Form Entry</title>    
    </head>
    <body>
        <h1>Input Form - n!</h1>
        <form action="./lab4submit.php" method="POST">
            <table border="0">
                <tr>
                    <td>Integer n between 2 and 25:</td>
                    <td><input type="text" name="n" maxlength="2" size="5"></td> 
                    <td><input type="submit" value="Calculate"></td>
                </tr>
            </table>
        </form>
    </body>
</html>
