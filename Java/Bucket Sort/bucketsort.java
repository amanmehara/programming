/*
Copyright 2020 Sakshi Khachane
Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at
    http://www.apache.org/licenses/LICENSE-2.0
Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
 */

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;


public class BucketSort {

  public static void main(String[] args) {

    System.out.println("Bucket sort in Java");
    int[] input = { 80, 50, 30, 10, 90, 60, 0, 70, 40, 20, 50 };

    System.out.println("integer array before sorting");
    System.out.println(Arrays.toString(input));

    // sorting array using radix Sort Algorithm
    bucketSort(input);

    System.out.println("integer array after sorting using bucket sort algorithm");
    System.out.println(Arrays.toString(input));

  }


  public static void bucketSort(int[] input) {
    // get hash codes
    final int[] code = hash(input);

    // create and initialize buckets to ArrayList: O(n)
    List[] buckets = new List[code[1]];
    for (int i = 0; i < code[1]; i++) {
      buckets[i] = new ArrayList();
    }

    // distribute data into buckets: O(n)
    for (int i : input) {
      buckets[hash(i, code)].add(i);
    }

    // sort each bucket O(n)
    for (List bucket : buckets) {
      Collections.sort(bucket);
    }

    int ndx = 0;
    // merge the buckets: O(n)
    for (int b = 0; b < buckets.length; b++) {
      for (int v : buckets[b]) {
        input[ndx++] = v;
      }
    }
  }

  private static int[] hash(int[] input) {
    int m = input[0];
    for (int i = 1; i < input.length; i++) {
      if (m < input[i]) {
        m = input[i];
      }
    }
    return new int[] { m, (int) Math.sqrt(input.length) };
  }

  private static int hash(int i, int[] code) {
    return (int) ((double) i / code[0] * (code[1] - 1));
  }

}


/*Output
Bucket sort in Java
integer array before sorting
[80, 50, 30, 10, 90, 60, 0, 70, 40, 20, 50]
integer array after sorting using bucket sort algorithm
[0, 10, 20, 30, 40, 50, 50, 60, 70, 80, 90]*/
