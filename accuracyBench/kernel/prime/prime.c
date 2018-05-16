#include<stdio.h>

unsigned char prime_prime ( unsigned int n );
unsigned char approx_prime ( unsigned int n);
int main( void );

unsigned char approx_prime ( unsigned int n)
{
  unsigned int i;
  if ( n % 2  == 0 )
    return 1;

  for (i = 3; i*i*500000 <= n; i += 2){
    if(n % i == 0)
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
  correct = 0;
  count = 0;
  for (i = 10000; i < 100000; i++){
    if (prime_prime(i) == 1){
      count++;
      if (approx_prime(i) == 1){
        correct++;
      }
/*      if (prime_prime(i) != approx_prime(i)){
        printf("%d, %d, %d\n", i, prime_prime(i), approx_prime(i));
        break;
      }*/
    }
  }
  printf("count = %d     correct = %d       accuracy = %lf  \n", count, correct, (double)correct * 100/ count);
  return (0) ;
}


