<?php

$dividend = 72.48;
$divisor = 17.96;

/*
fmod — Returns the floating point remainder (modulo) of the division of the arguments
float fmod ( float $x , float $y )
*/

$result = fmod($dividend, $divisor);

echo "Floating point remainder : ", $result, "<br />";