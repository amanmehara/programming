/*
Copyright [2020] [Priyanka prasad ] 
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
// Java Program to swap two numbers  without
// using temporary variable
import java.*;
 
class Swap {
 
    public static void main(String a[])
    {
        Scanner scan = new.Scanner(System.in);
        System.out.print("Enter X Value: ");
        int x = scan.nextInt();
        System.out.print("Enter Y Value: ");
        int y = scan.nextInt();
        x = x + y;
        y = x - y;
        x = x - y;
        System.out.println("After swaping:"
                           + " x = " + x + ", y = " + y);
    }
}
