/*Copyright 2020 Vanshika

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

public class BinaryTreeDFS {
	static class Node {
		int data;
		Node left, right;

		Node(int data) {
			this.data = data;
			left = right = null;
		}
	}

	static Node root;
	static Node temp = root;

	public static void inorder(Node temp) {
		if (temp == null) {
			return;
		}
		inorder(temp.left);
		System.out.print(temp.data + " ");
		inorder(temp.right);
	}

	public static void preorder(Node temp) {
		if (temp == null) {
			return;
		}
		System.out.print(temp.data + " ");
		preorder(temp.left);
		preorder(temp.right);
	}

	public static void postorder(Node temp) {
		if (temp == null) {
			return;
		}
		postorder(temp.left);
		postorder(temp.right);
		System.out.print(temp.data + " ");

	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		temp = new Node(1);
		temp.left = new Node(2);
		temp.right = new Node(3);
		temp.left.left = new Node(4);
		temp.left.right = new Node(5);
		System.out.println("Inorder traversal: ");
		inorder(temp);
		System.out.println("\nPreorder traversal: ");
		preorder(temp);
		System.out.println("\nPostorder traversal: ");
		postorder(temp);
	}

}



