package LinkedList;

public class Link {
    public int data;
    public Link next;

    public Link(int data) {
        this.data = data;
    }

    public void DisplayNode() {
        System.out.print ( this.data + " " );
    }
}
