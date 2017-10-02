<?php

$perpendicular = 16;
$base = 12;

/*
hypot — Calculate the length of the hypotenuse of a right-angle triangle
float hypot ( float $x , float $y )
*/

$hypotenuse = hypot($perpendicular, $base);

echo "Perpendicular : ", $perpendicular, "<br />";
echo "Base : ", $base, "<br />";
echo "Hypotenuse : ", $hypotenuse, "<br />";