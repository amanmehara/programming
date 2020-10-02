/*
 * Copyright 2020 Jinit Jain
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
// Java program to implement Round Robin
// Scheduling with different arrival time
import java.util.*;
//import java.util.concurrent.CompletableFuture;
public class RoundRobin {
    public static void findWaitingTime(int process[],int wt_time[],int n ,int brusttime[],int quantum,int completion_time[],int arrival_time[]){
         // copy the value of brusttime array into wt_time array.
        int rem_time[] = new int[n];
         
        for(int i=0;i<wt_time.length;i++){
            rem_time[i]= brusttime[i];
        }
        int t=0;
        int arrival=0;
        // processing until the value of element of rem_time array is 0
        while(true){
//            ;
            boolean done = true;
            for(int i=0;i<n;i++){
                if(rem_time[i]>0){
                     done =false;
                    if(rem_time[i]>quantum && arrival_time[i]<=arrival){
                        t +=quantum;
                        rem_time[i]-=quantum;
                        arrival++;
                    }
                    else{
                    if(arrival_time[i]<=arrival){
                        arrival++;
                        t+=rem_time[i];
                        rem_time[i]=0;
                        completion_time[i]=t; }
                    }
                 }
              }
             
            if(done==true)    
            { 
                break;
                }
        }    
        }
    public static void findTurnAroundTime(int process[] ,int wt_time[],int n,int brusttime[],int tat_time[],int completion_time[],int arrival_time[]){
        for(int i=0;i<n;i++){
            tat_time[i]= completion_time[i]-arrival_time[i];
            wt_time[i] = tat_time[i]-brusttime[i];
             
             
        }
         
    }
     
    public static void findAvgTime(int process[],int n,int brusttime[],int quantum,int arrival_time[]){
      int wt_time[] = new int[n];
      int tat_time[] = new int[n];
      int completion_time[] = new int[n];
      findWaitingTime(process,wt_time,n,brusttime,quantum,completion_time,arrival_time);    
      findTurnAroundTime(process,wt_time,n,brusttime,tat_time,completion_time,arrival_time);
      int total_wt = 0, total_tat = 0; 
       
      System.out.println("Processes " +" Arrival Time\t"+ "  Burst time " +" completion time"+ 
              " Turn Around Time " + " Waiting time");
      for (int i=0; i<n; i++) 
      { 
          total_wt = total_wt + wt_time[i]; 
          total_tat = total_tat + tat_time[i]; 
          System.out.println(" " + (i+1) + "\t\t"+ arrival_time[i]+"\t\t"+ + brusttime[i] +"\t " +completion_time[i]+"\t\t"
                            +tat_time[i] +"\t\t " + wt_time[i]); 
      } 
      
      System.out.println("Average waiting time = " + 
                        (float)total_wt / (float)n); 
      System.out.println("Average turn around time = " + 
                         (float)total_tat / (float)n); 
    }
 
    public static void main(String []agrs){
    RoundRobin object = new RoundRobin();
    Scanner scan = new Scanner(System.in);
     
    int quantum = 2;
    int arrival_time[] = new int[]{0,1,2,3};
    int process[] = new int[]{1,2,3,4};
    int brusttime[] = new int[]{5,4,2,1};
    int n  = process.length;
     
    findAvgTime(process,n,brusttime,quantum,arrival_time);
     
    scan.close();
         
    }
 
}