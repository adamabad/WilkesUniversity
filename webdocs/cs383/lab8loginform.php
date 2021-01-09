<?php
    session_save_path("../sessions/");
    session_start();
    $message = "";
    if(isset($_SESSION["username"])) {
        if($_SESSION["username"] == "error1") {
            $message = "Incorrect Username or Password";
        }
        else if($_SESSION["username"] == "error2") {
            $message = "To access the homepage, you must login.";
        }
        else {
            header("Location: lab8home.php");
        }
    }
?>
<html>
    <!--
    Name: Adam Abad
    File: lab8loginform.php
    Date: 3/28/2020
    -->
    <head>
        <title>Lab 8 Login</title>
        This is the login page for Lab 8.</br>
        <?=$message;?>
    </head>
    <body>
        <form action="./lab8proclogin.php" method="POST">
        <table>
            <tr>
                <td>Username:</td>
                <td><input type="text" name="username" maxlength="20"/></td>
            </tr>
            <tr>
                <td>Password:</td>
                <td><input type="password" name="password" maxlength="32"/></td>
            </tr>
                <td><input type="submit" value="Submit"/></td>
            <tr>
        </table>
        </form>
    </body>
</html>