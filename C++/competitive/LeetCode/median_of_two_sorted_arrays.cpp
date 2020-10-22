// Copyright 2020 Sakshi Sharma
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

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
    //Take smaller array as first one
    if(nums1.size() > nums2.size())
        return findMedianSortedArrays(nums2,nums1);
        
    int x=nums1.size(), y=nums2.size();
    int low=0, high=x;
        
    while(low <= high){
        int partition_x = (low+high)/2; //number of elements from nums1 on left
        int partition_y = ((x+y+1)/2) - partition_x;
        int maxleft_x = (partition_x == 0) ? INT_MIN : (nums1[partition_x-1]);
        int minright_x = (partition_x == x) ? INT_MAX : (nums1[partition_x]);
            
        int maxleft_y = (partition_y == 0) ? INT_MIN : (nums2[partition_y-1]);
        int minright_y=(partition_y == y) ? INT_MAX : (nums2[partition_y]);
            
        if(maxleft_x <= minright_y && maxleft_y <= minright_x){
            if(((x+y) % 2) == 0)
                return (double)(max(maxleft_x, maxleft_y) + min(minright_x, minright_y))/2;
            else 
                return (double) max(maxleft_x, maxleft_y);
        }
        else if(maxleft_x < minright_y)
            low = partition_x + 1;
        else 
            high = partition_x - 1;

    }
    return -1;
}