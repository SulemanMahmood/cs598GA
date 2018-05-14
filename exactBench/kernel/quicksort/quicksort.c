void quicksort_int( int *a, unsigned long n);
int main(void);

void quicksort_int( int *a, unsigned long n)
{
  unsigned long j;
  int *pi, *pj, *pn;
  int tmp;

  _Pragma( "loopbound min 0 max 15" )
  while ( n > 1 ) {
    pi = a + ( n >> 1 );

    tmp = *a;
    *a = *pi;
    *pi = tmp;

    pi = a;
    pn = a + n;
    pj = pn;

    _Pragma( "loopbound min 1 max 250" )
    while ( 1 ) {
      _Pragma( "loopbound min 1 max 51" )
      do
        pi++;
      while ( ( pi < pn ) && ( *pi < *a ) );
      _Pragma( "loopbound min 1 max 27" )
      do
        pj--;
      while ( ( pj > a ) && ( *pj > *a ) );

      if ( pj < pi )
        break;

      tmp = *pi;
      *pi = *pj;
      *pj = tmp;
    }

    tmp = *a;
    *a = *pj;
    *pj = tmp;
    j = pj - a;
    n = n - j - 1;

    if ( j >= n ) {
      quicksort_int( a, j);
      a += ( j + 1 );
    } else {
      quicksort_int( a + ( j + 1 ) , n);
      n = j;
    }
  }
}

/*
  Main functions
*/

int main( )
{
  int Array[1000];
  _Pragma( "loopbound min 1000 max 1000" )
  for (int i = 1000; i > 0; i--){
    Array[1000-i] = i;
  }
  
  _Pragma( "marker recursivecall" )
  _Pragma( "flowrestriction 1*quicksort_int <= 521*recursivecall" )
  quicksort_int(Array, 1000);
  return 0;
}
