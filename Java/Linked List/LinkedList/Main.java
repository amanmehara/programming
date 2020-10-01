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
