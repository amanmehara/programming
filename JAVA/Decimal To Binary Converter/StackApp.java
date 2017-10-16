package hacktoberfest;

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
