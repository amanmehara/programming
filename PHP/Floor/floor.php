<?php

$one = -23.86;
$two = 9.9999;
$three = -4.27;
$four = 36.4;

/*
floor - Round fractions down
float floor ( float $value )
*/

$resultOne = floor($one);
$resultTwo = floor($two);
$resultThree = floor($three);
$resultFour = floor($four);

echo "floor (", $one, ") = ", $resultOne, "<br />";
echo "floor (", $two, ") = ", $resultTwo, "<br />";
echo "floor (", $three, ") = ", $resultThree, "<br />";
echo "floor (", $four, ") = ", $resultFour, "<br />";