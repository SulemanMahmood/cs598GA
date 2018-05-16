unsigned char approx_prime ( unsigned int n);
int main( void );

unsigned char approx_prime ( unsigned int n)
{
  int i;
  if ( n % 2  == 0 )
    return 1;

  _Pragma( "loopbound min 1 max 48" )
  for (i = 3; i*i*2 <= n; i += 2){
    if(n % i == 0)
      return 1;
  }
  return 0;
}

int main( void )
{
  approx_prime(99999);
  return 0 ;
}


