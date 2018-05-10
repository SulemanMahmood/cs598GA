/*

  This program is part of the TACLeBench benchmark suite.
  Version V 2.0

  Name: binarysearch

  Author: Sung-Soo Lim <sslim@archi.snu.ac.kr>

  Function: binarysearch performs binary search in an array of 15 integer
    elements.
    This program is completely structured (no unconditional jumps, no exits
    from loop bodies), and does not contain switch statements, no do-while
    loops.

  Source: MRTC
          http://www.mrtc.mdh.se/projects/wcet/wcet_bench/bs/bs.c

  Original name: bs

  Changes: No major functional changes.

  License: May be used, modified, and re-distributed freely, but
           the SNU-RT Benchmark Suite must be acknowledged

*/

/*
  This program is derived from the SNU-RT Benchmark Suite for Worst
  Case Timing Analysis by Sung-Soo Lim
*/


/*
  Forward declaration of functions
*/

#include"searchInput.h"

/*void binarysearch_initSeed( void );
long binarysearch_randomInteger( void );
void binarysearch_init( void );*/
int binarysearch_return( void ); 
int binarysearch_binary_search( int );
void binarysearch_main( void );
int main( void );


/*
  Declaration of global variables
*/

/*volatile int binarysearch_seed;

struct binarysearch_DATA {
  int key;
  int value;
};

struct binarysearch_DATA binarysearch_data[ 15 ];*/

int binarysearch_result;


/*
  Initialization- and return-value-related functions
*/

/*
  binarysearch_initSeed initializes the seed used in the "random" number
  generator.
*/
/*
void binarysearch_initSeed( void )
{
  binarysearch_seed = 0;
}*/


/*
  binarysearch_RandomInteger generates "random" integers between 0 and 8094.
*/

/*long binarysearch_randomInteger( void )
{
  binarysearch_seed = ( ( binarysearch_seed * 133 ) + 81 ) % 8095;
  return( binarysearch_seed );
}*/

/*
void binarysearch_init( void )
{
  int i;

  binarysearch_initSeed();

  _Pragma( "loopbound min 15 max 15" )
  for ( i = 0; i < 15; ++i ) {
    binarysearch_data[ i ].key = binarysearch_randomInteger();
    binarysearch_data[ i ].value = binarysearch_randomInteger();
  }
}

*/
int binarysearch_return( void )
{
  return( binarysearch_result );
}


/*
  Algorithm core functions
*/

int binarysearch_binary_search( int x )
{
  int fvalue, mid, up, low;

  mid = (x * 8191) / 32768;
  low = mid;
  up = mid;
  if (low < 0){
    low = 0;
  }	
  if (up > 8191){
    up = 8191;
  }
  fvalue = -1;

  _Pragma( "loopbound min 1 max 1" )
  while ( low <= up ) {
    mid = ( low + up ) >> 1;

    if ( binInput0[mid] == x ) {
      /* Item found */
      up = low - 1;
      fvalue = mid;
    } else

    if ( binInput0[mid] > x )
      /* Item not found */
      up = mid - 1;
    else
      low = mid + 1;
  }

  return( fvalue );
}


/*
  Main functions
*/

void _Pragma( "entrypoint" ) binarysearch_main( void )
{
  binarysearch_result = binarysearch_binary_search( 8 );
}


int main( void )
{
  /*binarysearch_init();*/
  binarysearch_main();

  return( binarysearch_return() - (-1) != 0 );
}
