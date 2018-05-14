#include<stdio.h>

unsigned char prime_prime ( unsigned int n );
unsigned char approx_prime ( unsigned int n, int prime[], int size);
int main( void );

typedef struct primes {
  int primesAr[25];
  int size[10];
} primes;

primes data = {
{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97},
{4, 8, 10, 12, 15, 17, 19, 22, 24, 25}
}; 

unsigned char approx_prime ( unsigned int n, int prime[25], int size)
{
  int i;
//  printf("Coming here  %d\n", n);
  for (i = 0; i < size; i++){
    if(n % prime[i] == 0)
      return 1;
  }
  return 0;
}

unsigned char prime_prime ( unsigned int n )
{
  unsigned int i;
  if ( n % 2  == 0 )
    return 1;
  
  for ( i = 3; i * i <= n; i += 2 ) {
    if ( n % i == 0 )
      return 1;
  }
  return 0;
}


int main( void )
{
  int i;
  int j;
  int correct;
  int count;
  char result;
  for (j = 0; j < 10; j++){
    correct = 0;
    count = 0;
    for (i = 10000; i < 100000; i++){
      if (prime_prime(i)){
        count++;
        if (approx_prime(i, data.primesAr, data.size[j])){
          correct++;
        }
      }
    }
    printf("count = %d     correct = %d       accuracy = %lf  \n", count, correct, (double)correct * 100/ count);
  }
  return (0) ;
}


