//QUESTION

// You are given a sorted array containing only numbers 0 and 1.
// Find the transition point efficiently. 
//The transition point is a point where "0" ends and "1" begins (0 based indexing).
// Note that, if there is no "1" exists, print -1.
// Note that, in case of all 1s print 0.

import java.util.*;

class Sorted_Array {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        while (T > 0) {
            int n = sc.nextInt();
            int arr[] = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] = sc.nextInt();
            }
            Transition obj = new Transition();
            System.out.println(obj.transitionPoint(arr, n));
            T--;
        }
    }
}

class Transition {
    int transitionPoint(int arr[], int n) {
        int count = 0;
        int i = 0;
        while (arr[i] == 0) {
            count++;
            i++;
        }
        
        if (count == n) {
            count = -1;
        }
        return count;
    }
}


