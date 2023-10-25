/*
  Name: Daniel Hamdan
  Unix Systems Programming - CS4350 - 01
  Assignment Number - 5
  Due Date: October 25, 2023
*/


#include <math.h>
#include <stdio.h>

// Named Constants
#define MAX_INPUT 1000
#define MIN_INPUT 2

// Function to check if a number is prime
int isPrime(int num) {
  if (num <= 1)
    return 0;
  if (num <= 3)
    return 1;
  if (num % 2 == 0 || num % 3 == 0)
    return 0;

  for (int i = 5; i * i <= num; i += 6) {
    if (num % i == 0 || num % (i + 2) == 0)
      return 0;
  }
  return 1;
}

// Function to find and display prime numbers between 2 and n
void findAndDisplayPrimes(int n) {
  printf("All Prime Numbers between %d and %d are:\n", MIN_INPUT, n);
  for (int i = MIN_INPUT; i <= n; i++) {
    if (isPrime(i)) {
      printf("%d, ", i);
    }
  }
  printf("\n");
}

// Function to find and display square pair numbers between 1 and n
void findAndDisplaySquarePairs(int n) {
  printf(
      "The square pair numbers are:\nN  P  N + P  P - N\n------------------\n");
  for (int N = 1; N < n; N++) {
    for (int P = N + 1; P <= n; P++) {
      int sum = N + P;
      int diff = P - N;
      if (sqrt(sum) == (int)sqrt(sum) && sqrt(diff) == (int)sqrt(diff)) {
        printf("%d  %d  %d  %d\n", N, P, sum, diff);
      }
    }
  }
}

int main() {
  char repeat;
  do {
    int num;
    printf("Would you like to repeat the process for another number? (Y/N): ");
    while (1) {
      scanf(" %c", &repeat);
      if (repeat == 'Y' || repeat == 'y' || repeat == 'N' || repeat == 'n') {
        break;
      } else {
        printf("Invalid choice, must enter Y, y, N, or n. Please try again: ");
      }
    }

    if (repeat != 'Y' && repeat != 'y') {

      if (repeat == 'n' || repeat == 'N') {
        printf("Mathematics and Computer Programming\nPrepared by Daniel Hamdan and Mustafa Chambers\n10-25-2023");
        break;
      }
      break;
    }

    printf("Enter a positive integer: ");
    scanf("%d", &num);

    if (num <= 0) {
      printf("Invalid Number, Number must be positive.\n");
      continue;
    }

    if (num > MAX_INPUT) {
      printf("Invalid Number, Number must be between %d and %d.\n", MIN_INPUT,
             MAX_INPUT);
      continue;
    }

    if (isPrime(num)) {
      printf("%d is a Prime Number\n", num);
    } else {
      printf("%d is not a Prime Number\n", num);
    }
    findAndDisplayPrimes(num);
    findAndDisplaySquarePairs(num);

  } while (repeat == 'Y' || repeat == 'y');

  return 0;
}
// End of Program
