import java.util.*;
class RodCuttingProblem {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the length of pipe: ");
        int pipeLength = sc.nextInt();
        int price[] = new int[pipeLength];
        int optimalPrices[] = new int[pipeLength];
        int shortRod[] = new int[pipeLength];
        System.out.println("Enter the price for respective pipe lengths: ");
        for(int i = 0 ; i < pipeLength ; i++) {
            System.out.print((i+1)+": ");
            price[i] = sc.nextInt();
        }
        optimalPrices[0] = price[0];
        shortRod[0] = 1;
        for(int i = 1 ; i < pipeLength ; i++) {
            int m = 0;
            int n = i-1;
            int max = price[i];
            shortRod[i] = i+1;
            while(m<=n) {
                if((optimalPrices[m]+optimalPrices[n]) > max) {
                    max = optimalPrices[m] + optimalPrices[n];
                    shortRod[i] = shortRod[m];
                }
                m++;
                n--;
            }
            optimalPrices[i] = max;
        }
        System.out.println("The optimal prices and first cut are: ");
        for(int i = 0 ; i < pipeLength ; i++) {
            System.out.print((i+1)+": ");
            System.out.print(optimalPrices[i]+" ");
            System.out.println(shortRod[i]);
        }
    }
}
/*
    OUTPUT:
    ````````
    C:\Users\app\Desktop>java RodCuttingProblem
    Enter the length of pipe:
    10
    Enter the price for respective pipe lengths:
    1: 1
    2: 5
    3: 8
    4: 9
    5: 10
    6: 17
    7: 17
    8: 20
    9: 24
    10: 30
    The optimal prices and first cut are:
    1: 1 1
    2: 5 2
    3: 8 3
    4: 10 2
    5: 13 2
    6: 17 6
    7: 18 1
    8: 22 2
    9: 25 3
    10: 30 10
*/