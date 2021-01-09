<?php

$im = imagecreate(320,270);

$white = imagecolorallocate($im, 0xFF, 0xFF, 0xFF);
$black = imagecolorallocate($im, 0x00,0x00, 0x00);
$red = imagecolorallocate($im, 0xFF, 0x00, 0x00);
$blue = imagecolorallocate($im, 0x00, 0x00, 0xFF);
$green = imagecolorallocate($im, 0x00, 0xFF, 0x00);
$dkred = imagecolorallocate($im, 0x99, 0x00, 0x00);
$dkblue = imagecolorallocate($im, 0x00, 0x00, 0x99);
$dkgreen = imagecolorallocate($im, 0x00, 0x99, 0x00);

$font = "/home/mathcs/courses/cs383/Vera.ttf";
$title = "Favorite Animal";

$textbox = imagettfbbox(24, 0, $font, $title);
$textWidth = $textbox[4] - $textbox[0];
$xTitle = (320 - $textWidth)/2;

imagettftext($im, 24, 0, $xTitle, 45, $black, $font, $title);

for($y = 25; $y >= 0; $y--) {
    imagefilledarc($im, 100, 150 + $y, 200, 100, 0, 360/3, $dkred, IMG_ARC_PIE);
    imagefilledarc($im, 100, 150 + $y, 200, 100, 360/3, 360/3 + 360/6, $dkblue, IMG_ARC_PIE);
}

imagefilledarc($im, 100, 150, 200, 125, 0, 360/3, $red, IMG_ARC_PIE);
imagefilledarc($im, 100, 150, 200, 125, 360/3, 360/3 + 360/6, $blue, IMG_ARC_PIE);
imagefilledarc($im, 100, 150, 200, 125, 360/3 + 360/6, 360, $green, IMG_ARC_PIE);

imagefilledrectangle($im, 210, 120, 220, 130, $red);
imagefilledrectangle($im, 210, 135, 220, 145, $blue);
imagefilledrectangle($im, 210, 150, 220, 160, $green);

imagettftext($im, 10, 0, 225, 130, $black, $font, "Horse");
imagettftext($im, 10, 0, 225, 145, $black, $font, "Cat");
imagettftext($im, 10, 0, 225, 160, $black, $font, "Dog");

header("Content-Type: image/png");
imagepng($im);
imagedestroy($im);

?>