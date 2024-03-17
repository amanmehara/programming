import java.util.LinkedHashMap;
import java.util.Scanner;

public class IntegerToRoman {
    public static void main(String args[]) {
        String ans = "";
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();
        LinkedHashMap<Integer, String> map = new LinkedHashMap<>();

        map.put(1000, "M");
        map.put(900, "CM");
        map.put(500, "D");
        map.put(400, "CD");
        map.put(100, "C");
        map.put(90, "XC");
        map.put(50, "L");
        map.put(40, "XL");
        map.put(10, "X");
        map.put(9, "IX");
        map.put(5, "V");
        map.put(4, "IV");
        map.put(1, "I");

        while (num > 0) {
            for (int i : map.keySet()) {
                if (num >= i) {
                    ans += map.get(i);
                    num -= i;
                    break;
                }
            }
        }
        System.out.println("Result: " + ans);
    }
}
