
$('#changeProfilePicture').submit(function (evt) {
    var file = document.getElementById('file').files[0];
    if(file && file.size < 102400) {
        return true;
    }
    else {
        alert("File too large (No larger than 100 kb)");
        return false;
    }
});

$('#newMovie').submit(function (evt) {
    var error = false;
    var text = 'Missing Elements:\n';
    var title = document.newMovie.title.value;
    if(!title.length) {            
        text = text + '\tTitle\n';
        error = true;
    }

    var year = document.newMovie.year.value;
    if(!year.length) {
        text = text + '\tRelease Year\n';
        error = true;
    }
        
    var length = document.newMovie.length.value;
    if(!length.length) {
        text = text + '\tLength of Movie\n';
        error = true;
    }
        
    var description = document.newMovie.description.value;
    if(!description.length) {
        text = text + '\tMovie\'s Description\n';
        error = true;
    }
        
    var duration = document.newMovie.duration.value;
    if(!duration.length) {
        text = text + '\tRental Duration\n';
        error = true;
    }
        
    var cost = document.newMovie.replacementCost.value;
    if(!cost.length) {
        text = text + '\tReplacement Cost\n';
        error = true;
    }

    var rating = document.newMovie.rating.value;
    if(!rating.length) {
        text = text + '\tMovie\'s Rating\n';
        error = true;
    }
    
    evt.preventDefault();
    window.history.back();
});

$