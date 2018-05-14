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
  _Pragma( "loopbound min 1 max 25" )
  for (i = 0; i < size; i++){
    if(n % prime[i] == 0)
      return 1;
  }
  return 0;
}

int main( void )
{
  approx_prime(99999, data.primesAr, data.size[9]);
  return 0 ;
}


