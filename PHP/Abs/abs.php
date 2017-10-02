<?php

$one = 236; #integer
$two = -64; #integer
$three = -4.27; #double/float
$four = 36.4; #double/float

/*
abs - Absolute Value
number abs ( mixed $number )
*/

$resultOne = abs($one);
$resultTwo = abs($two);
$resultThree = abs($three);
$resultFour = abs($four);

echo "abs (", $one, ") = ", $resultOne, "<br />";
echo "abs (", $two, ") = ", $resultTwo, "<br />";
echo "abs (", $three, ") = ", $resultThree, "<br />";
echo "abs (", $four, ") = ", $resultFour, "<br />";