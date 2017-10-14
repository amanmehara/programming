/**
 * Created by NafisaBarlaskar on 14-10-2017.
 */
package LeetCode;

import java.util.HashMap;

/**
 * Created by NafisaBarlaskar on 14-08-2017.
 */
public class RomanToInteger {

    static HashMap<String, Integer> map = new HashMap<String, Integer>();

    static {
        map.put("I", 1);
        map.put("V", 5);
        map.put("X", 10);
        map.put("L", 50);
        map.put("C", 100);
        map.put("D", 500);
        map.put("M", 1000);
    }

    public static Integer getIntegersFromRoman(String romanInput) {
        int length = romanInput.length();
        int result = 0;
        int i;
        if (romanInput != null) {
            for (i = 0; i < length && i + 1 < length; ) {
                String firstChar = String.valueOf(romanInput.charAt(i));
                String nextChar = String.valueOf(romanInput.charAt(i + 1));
                if (map.get(firstChar) < map.get(nextChar)) {
                    result += (map.get(nextChar) - map.get(firstChar));
                    i++;
                } else {
                    result += map.get(firstChar);
                }
                i++;
            }
        }
        return result;
    }

    public static void main(String[] args) {

        String romanNumber = "MCCXXXIV";
        System.out.println("Integer equivalent to the roman literal " + romanNumber +
                " is " + getIntegersFromRoman(romanNumber));
    }
}

