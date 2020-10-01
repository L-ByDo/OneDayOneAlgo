package sieveOfEratosthenes;

import java.util.Scanner;

public class SieveOfEratosthenes {

  public static void main(String[] args) {

    Scanner sc = new Scanner(System.in);

    // taking user input of two numbers
    System.out.println("Enter Two numbers a and b, such that a < b ");
    int a = sc.nextInt();
    int b = sc.nextInt();
    sc.close();
    if (a < 2) {
      System.out.println(
          "sorry try again, minimum number which you can enter is 2");
      return;
    }
    if (b < a) {
      System.out.println("First entered number should be smaller, Try again ");
      return;
    }
    boolean isPrime[] = new boolean[b + 1];
    for (int i = 0; i < b; i++) {
      isPrime[i] = true;
    }

    for (int i = 2; i * i <= b; i++) {
      if (isPrime[i] == true) {
        for (int j = i * i; j <= b; j += i) {
          isPrime[j] = false;
        }
      }
    }

    // Printing output
    for (int i = a; i <= b; i++) {
      if (isPrime[i] == true)
        System.out.print(i + " ");
    }
  }
}
