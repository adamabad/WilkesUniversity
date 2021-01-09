<?php
    session_save_path("../sessions/");
    session_start();
    /*
    Name: Adam Abad
    File: lab8proclogin.php
    Date: 3/28/2020
    */
    if(isset($_SESSION["username"])) {
        if($_SESSION["username"] != "error1" && $_SESSION["username"] != "error2") {
            header("Location: lab8home.php");
            exit();
        }
    }
    if(array_key_exists("username", $_POST))
        $thisuser = strtolower($_POST["username"]);
    if(array_key_exists("password", $_POST))
        $thispass = $_POST["password"];

    require_once('mysql_login.php');
    $conn = new mysqli('localhost', $username, $password, 'cs383');
    if($conn->connect_error)
        die($conn->connect_error);
    $result = $conn->query("SELECT * FROM lab8users WHERE username = '".$conn->real_escape_string($thisuser)."' AND password = MD5(CONCAT(salt,'".$conn->real_escape_string($thispass)."'))");
    if(!$result) die($conn->error);
    $conn->close();
    if(mysqli_num_rows($result) == 1) {
        $_SESSION["username"] = $thisuser;
        session_write_close();
        header("Location: lab8home.php");
        exit();
    }
    else {
        $_SESSION["username"] = "error1";
        session_write_close();
        header("Location: lab8loginform.php");
        exit();
    }
?>