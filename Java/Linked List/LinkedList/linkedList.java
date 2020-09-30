package LinkedList;

public class linkedList {
    private Link head;

    public linkedList() {
        head = null;
    }

    public boolean isEmpty() {
        return (head == null);
    }

    public void InsertFirst(int data) {
        Link node = new Link ( data );
        node.next = head;
        head = node;
    }

    public void InsertAtLast(int data) {
        Link node = new Link ( data );
        node.next = null;
        if (head == null) {
            head = node;
        } else {
            Link n = head;
            while (n.next != null) {
                n = n.next;
            }
            n.next = node;
        }
    }

    public Link find(int key) throws Exception {
        Link node = head;
        while (node.data != key) {
            if (node == null) {
                throw new Exception ( "Not Found Elements" );
            } else
                node = node.next;
        }
        return node;
    }

    public void InsertAtAnyPostion(int index, int data) {
        Link node = new Link ( data );
        if (index == 0) {
            InsertFirst ( data );
        } else {
            Link n = head;
            for (int i = 0; i < index - 1; i++) {
                n = n.next;
            }
            node.next = n.next;
            n.next = node;
        }
    }

    public Link DeleteFirst() {
        Link temp = head;
        head = head.next;
        return temp;
    }

    public void Display() {
        Link node = head;
        System.out.print ( "[ " );
        while (node != null) {
            node.DisplayNode ();
            node = node.next;
        }
        System.out.println ( "]" );
        System.out.println ( " " );
    }
}

