import java.util.Scanner;

public class DecimalToBinary {

    public static void main(String[] args) {
        
        Stack stk= new Stack();
        Scanner scn = new Scanner(System.in);
        
        System.out.println("Wellcome to Programme - Decimal To Binary Using Stack \n\nEnter a Decimal Number : ");
        int number = scn.nextInt(); // Getting an integer from user
        
        for(int x = number ; x != 0; x = x/2) {
            stk.push(x%2);
        }
        System.out.print("Binary number equal to " + number + " : ");
        while(!stk.isEmpty()) {
            System.out.print(stk.pop().data);
        }
        
    }  
}


class Node {
    int data ;
    Node next ;
    
    public Node (int i) {
        data=i;
        next=null;
    }
    
    public void display () {
        System.out.print(data);
    }
}

class Stack {
    private Node top ; // holds a reference to the top node
    public Stack () {
        top=null;
    }
    
    public boolean isEmpty () {
        if(top==null)
            return true;
        else
            return false;
    }
    
    public void push (int i) {
        if(isEmpty())
            top=new Node(i);
        else {
            Node old = top;
            top=new Node(i);
            top.next=old;
        }

    }
    
    public Node pop () {
        Node removed=top;
        top=top.next;
        return removed;
    }
    
    public Node peek () {
        return top;
    }
}