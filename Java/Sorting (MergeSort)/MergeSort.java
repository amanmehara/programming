/*
 * Calling mergeSort(float[] a) will sort the given array, a, using the
 * merge sort algorithm. This method modifies the given array. To sort 
 * a list of integers or doubles simply copy all elements into a float
 * array and cast all elements to floats.
 * 
 */

import java.util.Arrays;

public class MergeSort {

	/**
	 * Sorts a given array of integers
	 * @param a A list of floats to sort
	 */
	public static void mergeSort(float[] a)
	{
		float[] tmp = new float[a.length];
		mergeSort(a, tmp,  0,  a.length - 1);
	}

	/**
	 * A recursive method that splits a list repeatedly so that they can be
	 * ordered and remerged
	 * @param a The list to sort
	 * @param tmp The temp list to hold the sorted elements
	 * @param left The index of the start of the current list
	 * @param right The index of the end of the current list
	 */
	private static void mergeSort(float [ ] a, float [ ] tmp, int left, int right)
	{
		if( left < right )
		{
			int center = (left + right) / 2;
			mergeSort(a, tmp, left, center);
			mergeSort(a, tmp, center + 1, right);
			merge(a, tmp, left, center + 1, right);
		}
	}

	/**
	 * Merges two sublists back together, in order
	 * @param a The out of order list
	 * @param tmp The list to recombine the elements into
	 * @param left The index of the beginning of the left list
	 * @param right the index of the beginning of the right list
	 * @param rightEnd The index of the end of the right list
	 */
    private static void merge(float[ ] a, float[ ] tmp, int left, int right, int rightEnd )
    {	
        int leftEnd = right - 1;
        int k = left;
        int num = rightEnd - left + 1;

        while(left <= leftEnd && right <= rightEnd)
            if(a[left] <= a[right])
                tmp[k++] = a[left++];
            else
                tmp[k++] = a[right++];

        while(left <= leftEnd)    // Copy rest of first half
            tmp[k++] = a[left++];

        while(right <= rightEnd)  // Copy rest of right half
            tmp[k++] = a[right++];

        // Copy tmp back
        for(int i = 0; i < num; i++, rightEnd--)
            a[rightEnd] = tmp[rightEnd];
    }
    
    public static void main(String[] args) {
    	int NUM_ELEMENTS = 10;
    	float[] testArray = new float[NUM_ELEMENTS];
    	
    	System.out.println("Testing Array of floats");
    	for (int i = 0; i < testArray.length; i++) {
    		testArray[i] = (float) ( Math.random() * 10 );
    	}
    	
    	System.out.println("Before Sort: " + Arrays.toString(testArray));
    	mergeSort(testArray);
    	System.out.println("After Sort: " + Arrays.toString(testArray));
    }
}
