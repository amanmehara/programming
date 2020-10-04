// Copyright 2020 Nayeem Rafsan
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

import java.util.Arrays;

class MergseSort {
  public static void main(String[] args) {
    int a[] = {6,1,3,2,5,9,8};
    mergseSort(a);
    // to print the array
    System.out.print(Arrays.toString(a));
  }
  static void mergseSort(int a[]){
    // if array length = 1 then it is sorted
    if(a.length==1)
		  return;
	  else {
      int m=0;
      // dividing the array to 2 parts
      int a1[],a2[];
      if(a.length%2==0){
        m = (a.length-1)/2;
        a2 = new int[m+1];
      }
      else{
       m = a.length/2;
       a2 = new int[m];
      }
      a1 = new int[m+1];
      // diving the first half
      for(int k=0;k<=m;k++){
        a1[k] = a[k];
      }
      // diving the second half
      for(int k=m+1,l=0;k<a.length;k++, l++){
        a2[l] = a[k];
      }
      // applying mergse sort on first array
      mergseSort(a1);
      // applying mergse sort on second array
      mergseSort(a2);
      // after sorting merging the array
      merge(a1,a2,a);
	  }
  }
  static void merge(int a1[], int a2[], int a[]){
    int index =0, i=0, j=0;
    while(i<a1.length && j<a2.length){
      // if a1[i] smaller than adding it to array a
      if(a1[i]<a2[j]){
        a[index]= a1[i];
        i++;// for array 1
      }
      else {
      // if a2[j] smaller than adding it to array a
        a[index] = a2[j];
        j++; // for array 2
      }
      index++; // for main array
    }
    // if one array is completely added then we add the rest 
    // of the elements without comparing
    while(i<a1.length || j<a2.length){
      if(i<a1.length){
        a[index] = a1[i];
        i++; 
      }
      else {
        a[index] = a2[j];
        j++;
      }
    }
  }
}