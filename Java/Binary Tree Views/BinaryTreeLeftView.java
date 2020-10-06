/*
Copyright 2020 Vanshika
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
import java.util.*;
public class BinaryTreeLeftView {
	public static int leftview(BinaryNode root,int currlevel,int lastlevel) {
		if(root==null)
			return lastlevel;
		if(currlevel>lastlevel) {
			System.out.print(root.data+" ");
			lastlevel=currlevel;
		}
		lastlevel=leftview(root.left,currlevel+1,lastlevel);
		lastlevel=leftview(root.right,currlevel+1,lastlevel);
		return lastlevel;
	}
	public static void leftview(BinaryNode root) {
		leftview(root,1,0);
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		BinaryNode root = new  BinaryNode(10); 
		root.left = new  BinaryNode(2); 
		root.right = new  BinaryNode(3); 
		root.left.left = new  BinaryNode(7); 
		root.left.right = new  BinaryNode(8); 
		root.right.right = new  BinaryNode(15); 
		root.right.left = new BinaryNode(12); 
		root.right.right.left = new  BinaryNode(14); 
		System.out.println("Left view of the binary tree: ");
		leftview(root);
	}

}
