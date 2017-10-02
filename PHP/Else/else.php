<?php

//Example 1
$first = rand();
$second = rand();
#rand() is for generating random numbers

if ($first > $second) {
    echo "first ($first) is greater than second ($second)";
} else {
    echo "first ($first) is NOT greater than second ($second)";
}

echo "<br/>";

//Example 2
$number = 8;
if ($number == 5):
    echo "number equals 5";
    echo "...";
else:
    echo "number is NOT equal to 5";
    echo "!!!";
endif;