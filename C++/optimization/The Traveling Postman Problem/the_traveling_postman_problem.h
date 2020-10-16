#include "point.h"

class TheTravelingPostmanProblem{
	int solve(int i, int s);
	void get_path(int i, int s, std::vector< Point > &path);

public:
	std::vector< Point > points;
	Point start;
	
	TheTravelingPostmanProblem(std::vector< Point > points, Point start){
		this->points = points;
		this->start = start;
	}

	std::pair< int, std::vector< Point > > 
		minimum_distance();//Return the minimum distance to take all 'points' starting on 'start' point, and then back to 'start' point again
	
};
