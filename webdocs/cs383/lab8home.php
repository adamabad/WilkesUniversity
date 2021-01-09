<?php
    /*
    Name: Adam Abad
    File: lab8home.php
    Date: 3/28/2020
    */
   session_save_path("../sessions/");
   session_start();
   if(isset($_SESSION["username"])) {
        if($_SESSION["username"] == "error1" || $_SESSION["username"] == "error2" || $_SESSION["username"] == "") {
            $_SESSION["username"] = "error2";
            header("Location: lab8loginform.php");   
            exit();
       }
    }
    else {
        $_SESSION["username"] = "error2";
        header("Location: lab8loginform.php");
        exit();
    }
    $name = explode(".", $_SESSION["username"]);
    $name = ucfirst($name[0]);
?>
<html>
    <head>
        <title>Lab 8 Homepage</title>
        <h1>Welcome, <?=$name;?>!</h1>
    </head>
</html>