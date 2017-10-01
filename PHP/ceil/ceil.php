<?php

$one = -23.86;
$two = 9.9999;
$three = -4.27;
$four = 36.4;

/*
ceil - Round fractions up
float ceil ( float $value )
*/

$resultOne = ceil($one);
$resultTwo = ceil($two);
$resultThree = ceil($three);
$resultFour = ceil($four);

echo "ceil (", $one, ") = ", $resultOne, "<br />";
echo "ceil (", $two, ") = ", $resultTwo, "<br />";
echo "ceil (", $three, ") = ", $resultThree, "<br />";
echo "ceil (", $four, ") = ", $resultFour, "<br />";