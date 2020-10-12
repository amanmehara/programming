#include <bits/stdc++.h>

#include "the_traveling_postman_problem.h"

int main(){
 TheTravelingPostmanProblem test({{0, 1}, {1, 0}, {2, 2}, {3, 3}}, {0, 0});
 auto ans = test.minimum_distance();

 printf("The Minimum Distance to take the points is %d\n", ans.first);

 printf("The path: ");

 printf("(%d, %d) -> ", test.start.x, test.start.y);

 for(int i = 0 ; i < ans.second.size() ; i++){
  printf("(%d, %d) -> ", ans.second[i].x, ans.second[i].y);
 }

 printf("(%d, %d)\n", test.start.x, test.start.y);

 return 0;
}
