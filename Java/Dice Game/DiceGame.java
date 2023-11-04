package com.company;
import java.util.Random;
import java.util.Scanner;


public class DiceGame {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("What is your starting sum of money?");
        int money =  scanner.nextInt();
        GameInstance game = new GameInstance(money);
    }
}

class GameInstance
{
    Scanner scanner = new Scanner(System.in);
    int money;
    public GameInstance(int money)
    {
        this.money = money;
        Begin();
    }

    private void Begin()
    {
        while(true)
        {
            if(money <= 0) break;
            drawScreen();
            Roll(Bet(), Guess());

        }
        System.out.println("Sorry you are out of funds :)");

    }

    private int Bet()
    {
        System.out.println("What is next bet?");
        int bet;
        while(true)
        {
            bet = scanner.nextInt();
            if(bet > 0) break;
            System.out.println("Invalid amount! Please enter another sum of money");
        }
        return bet;
    }

    private int Guess()
    {
        System.out.println("Guess the number from 1 to 6");
        int guess;
        while(true)
        {
            guess = scanner.nextInt();
            if(guess >= 1 && guess <= 6) break;
            System.out.println("Invalid number! Please enter a number from 1 to 6");
        }
        return guess;
    }



    private void drawScreen()
    {
        System.out.print("\033[H\033[2J");
        System.out.flush();
        System.out.println("\t  your money: " + money);
    }


    private void Roll(int bet, int number)
    {
        Random rnd = new Random();
        int roll = rnd.nextInt((6-1)+1)+1;
        System.out.println(roll);
        if(roll == number)
        {
            System.out.println("Congratulations! You Won!");
            money += bet;
        }
        else {
            System.out.println("Yikes... Better luck next time!");
            money -= bet;
        }
        }
    }





