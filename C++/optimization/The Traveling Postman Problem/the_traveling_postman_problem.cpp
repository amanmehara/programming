//This dynamic programming solves the TSP (traveling postman problem) in O(n²2^n). The points are modeled in a 2D plane
#include <algorithm>
#include <vector>
#include <cstdio>
#include "the_traveling_postman_problem.h"

using namespace std;

const int N = 15, inf = (int) 1e9 + 7;
int dp[N][1 << N], used[N][1 << N], test;

int dis(Point a, Point b){//The distance between two points is the manhattan distance
	return abs(a.x - b.x) + abs(a.y - b.y);
}

int TheTravelingPostmanProblem::solve(int i, int s){//*i* is the current point and *s* the mask of visited points
	int &ans = dp[i][s];
	
	if(used[i][s]){
		return ans;
	}
	
	used[i][s] = 1;
	ans = inf;
	bool find = false;
	
	for(int k = 0 ; k < points.size() ; k++){
		int chk = 1 << k;
		
		if((s & chk) == 0){//If point *k* is not visited then go to *k* from *i*
			find = true;
			ans = min(ans, solve(k, s | chk) + dis(points[i], points[k]));
		}	
	}
	
	if(!find){
		ans = dis(start, points[i]);
	}
	
	return ans;
}

void TheTravelingPostmanProblem::get_path(int i, int s, vector< Point > &path){//*i* is the current point and *s* the mask of visited points
	int &ans = dp[i][s];
	path.push_back(points[i]);
	bool find = false;

	for(int k = 0 ; k < points.size() ; k++){
		int chk = 1 << k;
		
		if((s & chk) == 0 && ans == solve(k, s | chk) + dis(points[i], points[k])){//If point *k* is not visited then go to *k* from *i*
			find = true;
			get_path(k, s | chk, path);
			break;
		}	
	}
}

//returns the minimum distance and a path that have this total distance
pair< int, vector< Point > > TheTravelingPostmanProblem::MinimumDistance(){
	int ans = inf;

	for(int i = 0 ; i < points.size() ; i++){//try starting from each of the points.
		ans = min(ans, solve(i, 1 << i) + dis(start, points[i]));
	}

	vector< Point > path;

	for(int i = 0 ; i < points.size() ; i++){
		if(ans == solve(i, 1 << i) + dis(start, points[i])){
			get_path(i, 1 << i, path);
			break;
		}
	}
	
	return {ans, path};
}