#include <bits/stdc++.h>

#include "the_traveling_postman_problem.h"

int main(){
	TheTravelingPostmanProblem test({{0, 1}, {1, 0}, {2, 2}, {3, 3}}, {0, 0});

	printf("The MinimumDistance to take the points is %d\n", test.MinimumDistance());

	return 0;
}