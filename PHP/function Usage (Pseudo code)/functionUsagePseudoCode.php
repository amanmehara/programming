<?php

/*
 * Pseudo code to demonstrate function uses
 *
 * Any valid PHP code may appear inside a function, even other functions and class definitions.
 *
 * Function names follow the same rules as other labels in PHP.
 * A valid function name starts with a letter or underscore, followed by any number of letters, numbers, or underscores.
 * As a regular expression, it would be expressed thus: [a-zA-Z_\x7f-\xff][a-zA-Z0-9_\x7f-\xff]*.
 */

function foo($arg_1, $arg_2, /* ..., */ $arg_n)
{
    echo "Example function.\n";
    return $retval;
}