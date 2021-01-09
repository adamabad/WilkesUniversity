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
      <title>Add Movie</title>
    </head>
    <body>
      <?php require_once(APPPATH."views/navbar.php"); ?>
      
      <div class="container">
        <h2>Add Movie</h2>
        <form name="newMovie" id="newMovie" action='<?=site_url("/finalproject/newMovie/")?>' method="post">
            <div class="form-group">
                <label>Title</label>
                <input type="text" class="form-control form-control-sm" id="movieTitle" name="title" value="<?=set_value('title')?>">
            </div>
            <div class="form-group">
                <label>Release Year</label>
                <input type="text" class="form-control form-control-sm" id="year" name="year" value="<?=set_value('year')?>">

            </div>
            <div class="form-group">
                <label>Length (in minutes)</label>
                <input type="text" class="form-control form-control-sm" id="movieLength" name="length" value="<?=set_value('length')?>">
            </div>
            <div class="form-group">
                <label>Description</label>
                <input type="text" class="form-control form-control-sm" id="description" name="description" value="<?=set_value('description')?>">
            </div>
            <div class="form-group">
                <label>Rental Duration</label>
                <input type="text" class="form-control form-control-sm" id="duration" name="duration" value="<?=set_value('duration')?>">
            </div>
            <div class="form-group">
                <label>Replacement Cost</label>
                <input type="text" class="form-control form-control-sm" id="replacement" name="replacementCost" value="<?=set_value('replacementCost')?>">
                
            </div>
            <div class="form-group">
                <select class="custom-select mt-2" name="rating">
                    <option value="" selected>Rating</option>
                    <option value="G">G</option>
                    <option value="PG">PG</option>
                    <option value="PG-13">PG-13</option>
                    <option value="R">R</option>
                    <option value="NC-17">NC-17</option>
                </select>
            </div>
            <button type="submit" class="btn btn-primary mb-4">Submit</button>
            <?=validation_errors('<div class="alert alert-danger" role="alert">',"</div>")?>
        </form>
      </div>
      <script src="https://code.jquery.com/jquery-3.4.1.slim.min.js" integrity="sha384-J6qa4849blE2+poT4WnyKhv5vZF5SrPo0iEjwBvKU7imGFAV0wwj1yYfoRSJoZ+n" crossorigin="anonymous"></script>
      <script src="https://cdn.jsdelivr.net/npm/popper.js@1.16.0/dist/umd/popper.min.js" integrity="sha384-Q6E9RHvbIyZFJoft+2mJbHaEWldlvI9IOYy5n3zV9zzTtmI3UksdQRVvoxMfooAo" crossorigin="anonymous"></script>
      <script src="https://stackpath.bootstrapcdn.com/bootstrap/4.4.1/js/bootstrap.min.js" integrity="sha384-wfSDF2E50Y2D1uUdj0O3uMBJnjuUD4Ih7YwaYd1iqfktj0Uod8GCExl3Og8ifwB6" crossorigin="anonymous"></script>
  </body>
</html>