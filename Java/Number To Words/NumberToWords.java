/**
 * Created by NafisaBarlaskar on 09-05-2017.
 */

import java.text.DecimalFormat;

public class NumberToWords {

    private static  String[] tens = {
            "",
            "ten",
            "twenty",
            "thirty",
            "forty",
            "fifty",
            "sixty",
            "seventy",
            "eighty",
            "ninety"
    };

    private static String[] numNames = {
            "",
            " one",
            " two",
            " three",
            " four",
            " five",
            " six",
            " seven",
            " eight",
            " nine",
            " ten",
            " eleven",
            " twelve",
            " thirteen",
            " fourteen",
            " fifteen",
            " sixteen",
            " seventeen",
            " eighteen",
            " nineteen"
    };

    private static String convertLessThanOneThousand(int number){

        String numberToWords = "";

        if(number % 100 < 20){
            numberToWords = numNames[number%100];
            number /= 100;
        } else {
            numberToWords = numNames[number%10];
            number /= 10;

            numberToWords = tens[number%10] + " " + numberToWords;
            number /= 10;
        }

        if(number == 0){
            return numberToWords;
        }
        return numNames[number] + " hundred " + numberToWords;
    }

    private static String convert(long number){

        if(number == 0){
            return "zero";
        }

        String numberInWords = Long.toString(number);

        String mask = "000000000000";

        DecimalFormat df = new DecimalFormat(mask);
        numberInWords = df.format(number);

        int billions = Integer.parseInt(numberInWords.substring(0,3));
        int millions = Integer.parseInt(numberInWords.substring(3,6));
        int hundredThousands = Integer.parseInt(numberInWords.substring(6,9));
        int thousands = Integer.parseInt(numberInWords.substring(9,12));

        String convertBillions = "";

        switch(billions){
            case 0: convertBillions = "";
                break;
            case 1: convertBillions = convertLessThanOneThousand(billions) + " billion ";
                break;
            default: convertBillions =  convertLessThanOneThousand(billions) + " billion ";

        }

        String finalResult = convertBillions;

        String convertMillions = "";

        switch(millions){
            case 0: convertMillions = "";
                break;
            case 1: convertMillions = convertLessThanOneThousand(millions) + " million ";
                break;
            default: convertMillions =  convertLessThanOneThousand(millions) + " million ";

        }

        finalResult += convertMillions;

        String convertHundredThousands = "";

        switch(hundredThousands){
            case 0: convertHundredThousands = "";
                break;
            case 1: convertHundredThousands = "one thousand";
                break;
            default: convertHundredThousands =  convertLessThanOneThousand(hundredThousands) + " thousand";
        }

        finalResult += convertHundredThousands;

        String convertThousands = "";

        convertThousands =  convertLessThanOneThousand(thousands);

        finalResult += convertThousands;

        return finalResult; //.replaceAll("^\\s+", "").replaceAll("\\b\\s{2,}\\b", " ");
    }

    public static void main(String[] args){

        long number = 4378;
        System.out.println(number +" in words: "+ NumberToWords.convert(number));
    }
}

