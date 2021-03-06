<?php
defined('BASEPATH') OR exit('No direct script access allowed');
?><!doctype html>
<html lang="en">
	<head>
		<meta charset="utf-8">
		<meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
		<link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.4.1/css/bootstrap.min.css" integrity="sha384-Vkoo8x4CGsO3+Hhxv8T/Q5PaXtkKtu6ug5TOeNV6gBiFeWPGFN9MuhOf23Q9Ifjh" crossorigin="anonymous">
		<title>New Post</title>
	</head>
	<body>
		<div class='container'>
			<h1>New Post</h1>
			<form action="<?= site_url("blog/submit") ?>" method="post">
				<div class="form-group">
					<label for="title">Post Title</label>
					<input type="text" name="title" id="title" class="form-control">
				</div>
                <div class="form-group">
                     <label for="category">Category</label>
                     <select name="category" id="category" class="form-control">
<?php
foreach($categories as $category) {
     echo "\t\t\t\t\t\t<option value='$category->id'>$category->title</option>\n";
}
?>                               
                     </select>
                </div>
				<div class="form-group">
					<label for="body">Post Body</label>
					<textarea name="body" id="body" class="form-control"></textarea>
				</div>
				<button type="submit" class="btn btn-lg btn-primary">Submit Post</button>
			</form>	
		</div>
		<script src="https://code.jquery.com/jquery-3.4.1.slim.min.js" integrity="sha384-J6qa4849blE2+poT4WnyKhv5vZF5SrPo0iEjwBvKU7imGFAV0wwj1yYfoRSJoZ+n" crossorigin="anonymous"></script>
		<script src="https://cdn.jsdelivr.net/npm/popper.js@1.16.0/dist/umd/popper.min.js" integrity="sha384-Q6E9RHvbIyZFJoft+2mJbHaEWldlvI9IOYy5n3zV9zzTtmI3UksdQRVvoxMfooAo" crossorigin="anonymous"></script>
		<script src="https://stackpath.bootstrapcdn.com/bootstrap/4.4.1/js/bootstrap.min.js" integrity="sha384-wfSDF2E50Y2D1uUdj0O3uMBJnjuUD4Ih7YwaYd1iqfktj0Uod8GCExl3Og8ifwB6" crossorigin="anonymous"></script>
	</body>
</html>
