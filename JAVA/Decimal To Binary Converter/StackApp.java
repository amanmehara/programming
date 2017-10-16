/*
Copyright 2017 Erandi Atapattu

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

import java.util.Scanner;

public class StackApp {

     private int maxSize;
     private int[] stackData;
     private int top;
     
     public StackApp(int s){
         stackData=new int[s];
         maxSize=s;
         top=-1;
     }
     
     public void push(int j){
         
         if(isFull())
             System.out.println("Stack is full");
         else{
             top++;
             stackData[top]=j;}
     }
     
     public int pop(){
         if(isEmpty()){
             System.out.println("Stack is emnpty");
             return -1;}
         else{
            int temp=stackData[top];
            top--;
            return temp;}
     }
     
     public int peek(){ 
            return stackData[top];
     
     }
     
     public boolean isEmpty(){
         if(top==-1)
             return true;
         else 
             return false;
     }
     
     public boolean isFull(){
         if(top==maxSize-1)
             return true;
         else 
             return false;
         
     }
     
    public static void main(String[] args) {
    	
    	System.out.println("------Initializing Decimal to Octal Converter-------");
    	Scanner s=new Scanner(System.in);
    	System.out.println("Enter decimal number:");
    	int decimalNo=s.nextInt();
        int temp=decimalNo;
        int count=0;
        while(temp!=0){
            int rem=temp%8;
            temp=temp/8;
            count++;
        }
        StackApp s2=new StackApp(count);
        temp=decimalNo;
        while(temp!=0){
            int rem=temp%8;
            temp=temp/8;
            s2.push(rem);
        }
        
        while(s2.isEmpty()!=true){
            System.out.print(s2.pop()+" ");
        }
        
        
    }
    
}
