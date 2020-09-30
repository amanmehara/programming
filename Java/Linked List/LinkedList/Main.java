package LinkedList;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        System.out.println ( "Linked List: " );
        linkedList ll = new linkedList ();
        ll.InsertFirst ( 34 );
        ll.InsertFirst ( 23 );
        ll.InsertFirst ( 89 );
        ll.InsertFirst ( 12 );
        ll.Display ();
    }
}
