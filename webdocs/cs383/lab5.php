<!--
Name: Adam Abad
File: lab5.php
Date: 2/11/2020
-->
<?php
    Function imagecentertext($resource, $text, $size, $fontfile, $text_color) {
        $box = imagettfbbox($size,0,$fontfile,$text);
        $myx = ((imagesx($resource) - 1) / 2) - ((abs($box[4] - $box[0]) / 2));
        $myy = ((imagesy($resource) - 1) / 2) + ((abs($box[5] - $box[1]) / 2));
        $box[4] = $myx;
        $box[5] = $myy;
        imagettftext($resource, $size, 0, $myx, $myy, $text_color, $fontfile, $text);
    }

    Function imageborderedrectangle($resource, $x1, $y1, $x2, $y2, $border_color, $border_thickness, $fill_color) {
        imagefilledrectangle($resource, $x1, $y1, $x2, $y2, $border_color);
        imagefilledrectangle($resource, $x1 + $border_thickness, $y1 + $border_thickness, $x2 - $border_thickness, $y2 - $border_thickness, $fill_color);    
    }

    Function imagefittextsize($w, $h, $text, $fontfile) {
        $fit = true;
        $size = 0;
        while($fit) {
            $box = imagettfbbox($size,0,$fontfile,$text);
            if(abs($box[4] - $box[0]) > $w || abs($box[5] - $box[1]) > $h) {
                $fit = false;
                $size--;
            }
            else {
                $size++;
            }
        }
        return $size;
    }

    Function imageinvertcolors($resource) {
        for($x = 0; $x < imagesx($resource); $x++) {
            for($y = 0; $y < imagesy($resource); $y++) {
                $colors = imagecolorsforindex($resource, imagecolorat($resource, $x, $y));
                $r = 255 - $colors["red"];
                $g = 255 - $colors["green"];
                $b = 255 - $colors["blue"];
                $newColor = imagecolorallocate($resource,$r, $g, $b);
                imagesetpixel($resource, $x, $y, $newColor);
            }
        }
    }
    
    $fontpath = "/home/mathcs/courses/cs383/Vera.ttf";
    $testimage = "/home/mathcs/users/fall17/abada/Pictures/footer-logo.png";
    $image = imagecreatefrompng($testimage);
    $orange = imagecolorallocate($image, 255, 165, 0);
    $yellow = imagecolorallocate($image, 255, 255, 0);
    
    //imageinvertcolors($image); //Works
    //imagefittextsize(202, 157, "This is centered", $fontpath); //Tested
    //imagecentertext($image,"This is centered.", 19, $fontpath, $orange); //Works
    //imageborderedrectangle($image, 0, 0, 100, 100, $orange, 10, $yellow); //Works
    imagepng($image, "newpicture.png");
    imagedestroy($image);
?>
