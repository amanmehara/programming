/*
 * Copyright 2020 Shashwat Pandey
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

