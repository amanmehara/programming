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
class Pair<X,Y>
{
	public final X first;   	
	public final Y second;  	
	private Pair(X first, Y second)
	{
		this.first = first;
		this.second = second;
	}
	public static <X,Y> Pair <X,Y> of(X a, Y b)
	{
		return new Pair<>(a, b);
	}
}
public class BinaryTreeTopView
{
	public static void printTop(BinaryNode root, int dist, int level,
			Map<Integer, Pair<Integer, Integer>> map)
	{
		if (root == null) {
			return;
		}
		if (!map.containsKey(dist) || level < map.get(dist).second) {		
			map.put(dist, Pair.of(root.data, level));
		}
		printTop(root.left, dist - 1, level + 1, map);
		printTop(root.right, dist + 1, level + 1, map);
	}	
	public static void printTop(BinaryNode root)
	{
		Map<Integer, Pair<Integer, Integer>> map = new TreeMap<>();
		printTop(root, 0, 0, map);
		for (Pair<Integer, Integer> it: map.values()) {
			System.out.print(it.first + " ");
		}
	}
	public static void main(String[] args)
	{
		BinaryNode root = new BinaryNode(1);
		root.left = new BinaryNode(2);
		root.right = new BinaryNode(3);
		root.left.right = new BinaryNode(4);
		root.right.left = new BinaryNode(5);
		root.right.right = new BinaryNode(6);
		root.right.left.left = new BinaryNode(7);
		root.right.left.right = new BinaryNode(8);
		System.out.println("Top view of the binary tree: ");
		printTop(root);
	}
}
