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
public class Main {
    public static void main(String[] args) {
        System.out.println ( "DoublyLinked list" );
        DoublyLinkedList dl = new DoublyLinkedList ();
        dl.InsertFirst ( 22 );
        dl.InsertFirst ( 44 );
        dl.InsertFirst ( 66 );

        dl.InsertLast ( 11 );
        dl.InsertLast ( 33 );
        dl.InsertLast ( 55 );
        dl.DisplayForward ();
        dl.DisplayBackward ();

        dl.DeleteFirst ();
        dl.DeleteLast ();
        dl.deleteKey ( 11 );

        dl.DisplayForward ();

    }
}
