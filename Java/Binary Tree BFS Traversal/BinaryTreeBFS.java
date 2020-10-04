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
public class BinaryTreeBFS {
	static class Node{
		int data;
		Node left,right;
		Node(int data){
			this.data=data;
			left=right=null;
		}
	}
	static Node root;
	static Node temp=root;
	public static void bfs(Node temp) {
		if(temp==null) {
			return;
		}
		Queue<Node> q=new LinkedList<Node>();
		List<Integer>l=new ArrayList<Integer>();
		q.add(temp);
		Node temp2;
		while(!q.isEmpty()) {
			temp2=q.poll();
			l.add(temp2.data);
			if(temp2.left!=null) {
				q.add(temp2.left);
			}
			if(temp2.right!=null) {
				q.add(temp2.right);
			}
		}
		System.out.println("Level Order is: "+l);
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		temp=new Node(1);
		temp.left=new Node(2);
		temp.right=new Node(3);
		temp.left.left=new Node(4);
		temp.left.right=new Node(5);
		bfs(temp);
	}
}
