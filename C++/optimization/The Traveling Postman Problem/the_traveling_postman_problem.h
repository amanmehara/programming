#include "point.h"

class TheTravelingPostmanProblem{
	int solve(int i, int s);

public:
	std::vector< Point > points;
	Point start;
	
	TheTravelingPostmanProblem(std::vector< Point > points, Point start){
		this->points = points;
		this->start = start;
	}

	int MinimumDistance();//Return the minimum distance to take all 'points' starting on 'start' point, and then back to 'start' point again
};