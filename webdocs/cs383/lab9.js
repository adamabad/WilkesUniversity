$(function() {
    $('#0').on('click', function() {
        $('#q1').hide();
        $('#right').show();
    });
    $('#1').on('click', function() {
        $('#q1').hide();
        $('#wrong').show();
    });
    $('#2').on('click', function() {
        $('#q1').hide();
        $('#wrong').show();
    });
    $('#3').on('click', function() {
        $('#q1').hide();
        $('#wrong').show();
    });
    $('#next').on('click', function() {
        $('#right').hide();
        $('#q2').show();
    });
    $('#return').on('click', function() {
        $('#wrong').hide();
        $('#q1').show();
    });
})
