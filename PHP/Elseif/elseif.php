<?php

//Example 1
$first = rand();
$second = rand();
#rand() is for generating random numbers

if ($first > $second) {
    echo "first ($first) is greater than second ($second)";
} elseif ($first == $second) {
    echo "first ($first) is equal to second ($second)";
} else {
    echo "first ($first) is smaller than second ($second)";
}

echo "<br/>";

//Example 2
$number = 6;
if ($number == 5):
    echo "number equals 5";
    echo "...";
elseif ($number == 6):
    echo "number equals 6";
    echo "!!!";
else:
    echo "number is neither 5 nor 6";
endif;