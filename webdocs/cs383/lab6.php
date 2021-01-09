<?php
    /*
    Name: Adam Abad
    File: lab6.php
    Date: 2/27/2020
    */
    //Input Values
    $width = 700;
    $height = 300;   
    $leftMargin = 100;
    $bottomMargin = 75;
    $topMargin = 50;
    $data = [3, 85, 34, 20, 100, 78];
    $dataTitles = ["Item 1", "Item 2", "Item 3", "Item 4", "Item 5", "Item 6"];
    $title = "Test Graph";
    $xAxis = "Some Numbers";
    $yAxis = "How Many Numbers";
    $largefont = 16;
    $smallfont = 12;
    $font = "/home/mathcs/courses/cs383/Vera.ttf";

    //Calculated Values
    $items = count($data);
    $area = ($width - $leftMargin) / $items;
    $graphHeight = $height - $bottomMargin - $topMargin;
    $graphWidth = $width - $leftMargin;
    $yData = [];
    $max = max($data);
    $interval = 1;
    $columnWidth = $graphWidth / $items;
    while($interval * 5 < $max) {
        $interval++;
    }   
    for($x = 0; $x < 6; $x++) {
        $yData[$x] = $interval * $x;
    }

    //Allocations
    $im = imagecreate($width,$height);
    $white = imagecolorallocate($im, 0xFF, 0xFF, 0xFF);
    $black = imagecolorallocate($im, 0x00, 0x00, 0x00);
    $grey = imagecolorallocate($im, 0x69, 0x69, 0x69);
    $red =   imagecolorallocate($im, 0xFF, 0x00, 0x00);
    $dkred = imagecolorallocate($im, 0x99, 0x00, 0x00);
    $blue =  imagecolorallocate($im, 0x00, 0x00, 0xFF);
    $dkblue = imagecolorallocate($im, 0x00, 0x00, 0x99);
    $green = imagecolorallocate($im, 0x00, 0xFF, 0x00);
    $dkgreen = imagecolorallocate($im, 0x00, 0x99, 0x00);
    $yellow = imagecolorallocate($im, 0xFF, 0xFF, 0x00);
    $dkyellow = imagecolorallocate($im, 0x99, 0x99, 0x00);
    $orange = imagecolorallocate($im, 0xFF, 0xA5, 0x00);
    $dkorange = imagecolorallocate($im, 0x99, 0x85, 0x00);
    $colors = [$red, $dkred, $blue, $dkblue, $green, $dkgreen, $yellow, $dkyellow, $orange, $dkorange];
    
    //Image Creation
    //  Title and Axis Titles
    $titlebox = imagettfbbox($largefont, 0, $font, $title);
    $titlewidth = abs($titlebox[4] - $titlebox[0]);
    imagettftext($im, $largefont, 0, ($width - $titlewidth) / 2, 20, $black, $font, $title);

    $titlebox = imagettfbbox($smallfont, 90, $font, $yAxis);
    $titlewidth = abs($titlebox[4] - $titlebox[0]);
    imagettftext($im, $smallfont, 90, 20, $topMargin + $graphHeight - $titlewidth/2, $black, $font, $yAxis);
    
    $titlebox = imagettfbbox($smallfont, 0, $font, $xAxis);
    $titlewidth = abs($titlebox[4] - $titlebox[0]);
    imagettftext($im, $smallfont, 0, $leftMargin + (($graphWidth - $titlewidth) / 2), $height - 20, $black, $font, $xAxis);
    
    //Graph Area
    //  Main lines
    imageline($im, $leftMargin, $topMargin, $leftMargin, $height - $bottomMargin, $black);
    imageline($im, $leftMargin, $topMargin, $width - 1, $topMargin, $black);
    imageline($im, $leftMargin, $height - $bottomMargin, $width - 1, $height - $bottomMargin,$black);
    $textbox = imagettfbbox($smallfont, 0, $font, $yData[0]);
    $textwidth = abs($textbox[4] - $textbox[0]);
    $textheight = abs($textbox[5] - $textbox[1]);
    imagettftext($im, $smallfont, 0, $leftMargin - ($textwidth + 2), $height - $bottomMargin + ($textheight/2), $black, $font, $yData[0]);
    //Sub Divisions
    for($y = 1; $y < 6; $y++) {
        $textbox = imagettfbbox($smallfont, 0, $font, $yData[$y]);
        $textwidth = abs($textbox[4] - $textbox[0]);
        $textheight = abs($textbox[5] - $textbox[1]);
        imagettftext($im, $smallfont, 0, $leftMargin - ($textwidth + 2), $height - $bottomMargin + ($textheight/2) - ($y * ($graphHeight/5)), $black, $font, $yData[$y]);
        imageline($im, $leftMargin, ($y * ($graphHeight/5)) + $topMargin, $width - 1, ($y * ($graphHeight/5)) + $topMargin, $grey);
    }

    //Bar Graph Creation
    for($i = 0; $i < $items; $i++) {
        $textbox = imagettfbbox($smallfont, 0, $font, $dataTitles[$i]);
        $textwidth = abs($textbox[4] - $textbox[0]);
        $textheight = abs($textbox[5] - $textbox[1]);
        imagettftext($im, $smallfont, 0, $leftMargin + ($columnWidth * $i) + ($columnWidth- $textwidth)/2, $height - $bottomMargin + $textheight + 3, $black, $font, $dataTitles[$i]);
        
        for($y = 0; $y < $graphHeight * ($data[$i]/max($yData)); $y++) {
            //imagefilledrectangle($im, $leftMargin + ($columnWidth * $i) + ($columnWidth * .05), ($height - $bottomMargin) - $y, $leftMargin + ($columnWidth * ($i + 1)) - ($columnWidth*.05), ($height - $bottomMargin) - $y - 10, $colors[$i * 2 + 1]);
            imagefilledpolygon($im, 
                array($leftMargin + ($columnWidth * $i) + ($columnWidth * .05), ($height - $bottomMargin) - $y,                      
                    $leftMargin + ($columnWidth * $i) + ($columnWidth* .1), ($height - $bottomMargin) - $y - 10,                     
                    $leftMargin + ($columnWidth * ($i + 1)) - ($columnWidth * .05), ($height - $bottomMargin) - $y - 10,            
                    $leftMargin + ($columnWidth * ($i + 1)) - ($columnWidth* .1), ($height - $bottomMargin) - $y),        
                    4, $colors[($i * 2 + 1)%count($colors)]);
        }
       //imagefilledrectangle($im, $leftMargin + ($columnWidth * $i) + ($columnWidth * .05), ($height - $bottomMargin) - $y, $leftMargin + ($columnWidth * ($i + 1)) - ($columnWidth*.05), ($height - $bottomMargin) - $y - 10, $colors[$i * 2]);
       imagefilledpolygon($im, 
       array($leftMargin + ($columnWidth * $i) + ($columnWidth * .05), ($height - $bottomMargin) - $y,                      
           $leftMargin + ($columnWidth * $i) + ($columnWidth* .1), ($height - $bottomMargin) - $y - 10,                     
           $leftMargin + ($columnWidth * ($i + 1)) - ($columnWidth * .05), ($height - $bottomMargin) - $y - 10,            
           $leftMargin + ($columnWidth * ($i + 1)) - ($columnWidth* .1), ($height - $bottomMargin) - $y),        
           4, $colors[($i * 2)%count($colors)]);
    }

    //Closing comment and image destruction
    header("Content-Type: image/png");
    imagepng($im);
    imagedestroy($im);
?>