import java.util.*;
import java.io.*;

public class Ways_to_reach_nth_stairs {

    static int count_ways(int n,int m)
    {
        int res[]=new int[n];
        res[0]=1;
        res[1]=1;
        for (int i = 2; i <n; i++) {
            res[i]=0;
            for (int j = 1; j <=m && j<= i; j++) {
                res[i] +=res[i-j];
            }
        }
        return res[n-1];
    }
    
    public static void main(String[] args) {    
        int s=5;
        int n=2;
        System.out.println("The number of ways to reach "+s+" stairs taking "+n+" or less steps at a time is: "+count_ways(s+1,n));
    }

}
