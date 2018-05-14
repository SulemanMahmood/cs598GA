unsigned char prime_prime ( unsigned int n );
int main( void );

unsigned char prime_prime ( unsigned int n )
{
  unsigned int i;
  if ( n % 2  == 0 )
    return 1;
  
  _Pragma( "loopbound min 1 max 157" )
  for ( i = 3; i * i <= n; i += 2 ) {
    if ( n % i == 0 )
      return 1;
  }
  return 0;
}


int main( void )
{
  prime_prime(99999);
}


