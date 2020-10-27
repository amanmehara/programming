// Copyright 2020 Nivesh Pai
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/*  This program is used to illustrate the Bin-Packing algorithm using next fit heuristics. 
      In the bin packing problem, objects of different volumes must be packed into a finite number of bins or containers 
       each of volume V in a way that minimizes the number of bins used. 
      In computational complexity theory, it is a combinatorial NP-hard problem */

#include<stdio.h>
void binPacking(int *a, int size, int n) {
    int binCount = 1, i;
    int s = size;
    for (i = 0; i < n; i++) {
        if (s - *(a + i) > 0) {
            s -= *(a + i);
            continue;
        } else {
            binCount++;
            s = size;
            i--;
        }
    }
 
    printf("Number of bins required: %d", binCount);
}
 
int main(int argc, char **argv) {
    printf("Enter the number of items in Set: ");
    int n;    
    int a[n], i;
    int size;
    scanf("%d", &n);
    printf("Enter %d items:", n);
 
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Enter the bin size: ");
    scanf("%d", &size);
    binPacking(a, size, n);
    return 0;
}
