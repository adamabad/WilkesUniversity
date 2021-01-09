<?php
defined('BASEPATH') OR exit('No direct script access allowed');
if(!isset($_SESSION['username'])) {
  header("Location: ".site_url("/finalproject/login/"));
}
?>
<!doctype html>
<html lang="en">
    <head>
      <meta charset="utf-8">
      <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
      <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.4.1/css/bootstrap.min.css" integrity="sha384-Vkoo8x4CGsO3+Hhxv8T/Q5PaXtkKtu6ug5TOeNV6gBiFeWPGFN9MuhOf23Q9Ifjh" crossorigin="anonymous">
      <title>Change Profile Picture</title>
    </head>
    <body>
      <?php require_once(APPPATH."views/navbar.php"); ?>
        <div class="container">
          <h2>Change Profile Picture</h2>
          <img src='<?=site_url("/finalproject/getpfp/")?>' class="rounded mx-auto d-block" alt="Current Profile Picture">
          <form enctype="multipart/form-data" action=<?=site_url("finalproject/setpfp")?>>
            <label for="myfile">Select a file:</label>
            <input type="file" id="file" name="userfile" size="20" accept='.png'><br>
            <input type="submit" name="submit" value="upload">
            <label for="information">Not fully implemented, cannot change profile picture.</label>
          </form>
        </div>
      <script src="https://code.jquery.com/jquery-3.4.1.slim.min.js" integrity="sha384-J6qa4849blE2+poT4WnyKhv5vZF5SrPo0iEjwBvKU7imGFAV0wwj1yYfoRSJoZ+n" crossorigin="anonymous"></script>
      <script src="https://cdn.jsdelivr.net/npm/popper.js@1.16.0/dist/umd/popper.min.js" integrity="sha384-Q6E9RHvbIyZFJoft+2mJbHaEWldlvI9IOYy5n3zV9zzTtmI3UksdQRVvoxMfooAo" crossorigin="anonymous"></script>
      <script src=<?=site_url("/finalproject/javascript/")?>></script>
      <script src="https://stackpath.bootstrapcdn.com/bootstrap/4.4.1/js/bootstrap.min.js" integrity="sha384-wfSDF2E50Y2D1uUdj0O3uMBJnjuUD4Ih7YwaYd1iqfktj0Uod8GCExl3Og8ifwB6" crossorigin="anonymous"></script>
  </body>
</html>