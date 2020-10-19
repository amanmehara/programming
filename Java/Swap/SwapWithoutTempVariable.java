public class SwapWithoutTempVariable {
	public static void main(String args[]){
		int a = 10;
		int b = 5;
		
		System.out.println("Before swapping : " + a + " " + b); // Before swapping : 10 5
		
		a = a + b;
		b = a - b;
		a = a - b;
		
		System.out.println("After swapping : " + a + " " + b); // After swapping : 5 10
		
	}
}
