public class BubbleSort {
    public static void main (String[] args) {
        
        int array[] = {5,8,2,7,25,14,1,65,3};
        
        System.out.println("Original Array : ");
        for(int num : array )
        System.out.print(num+"\t");  
                  
        bubbleSort(array);  

        System.out.println("\nSorted Array : ");
        for(int num : array )
        System.out.print(num+"\t");  
        
    }
    
    public static void bubbleSort(int arr[]) {
        for(int i=0; i < arr.length; i++){  
            for(int j=1; j < (arr.length - i); j++){ 
                int temp;
                if(arr[j-1] > arr[j]){   
                       temp = arr[j-1];  
                       arr[j-1] = arr[j];  
                       arr[j] = temp;  
                }  
            }  
        }
    } 
}
