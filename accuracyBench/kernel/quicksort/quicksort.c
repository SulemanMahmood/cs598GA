#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "sortInput.h"

int main( int argc, char *argv[] );
int count_inversions(int Array[] );

int Limit;
int Calls;
int MaxCalls;

int count_inversions(int Array[] ){
  int inversions = 0;
  for (int i = 0; i < 1000; i++){
    for (int j = i; j < 1000; j++){
      if (Array[i] > Array[j]){
        inversions++;
      }
    }
  }
  return inversions;
}

void quicksort_int( int *a, unsigned long n)
{
  unsigned long j;
  int *pi, *pj, *pn;
  int tmp;

  Calls++;
  while ( n > Limit ) {
    pi = a + ( n >> 1 );

    tmp = *a;
    *a = *pi;
    *pi = tmp;

    pi = a;
    pn = a + n;
    pj = pn;

    _Pragma( "loopbound min 1 max 170" )
    while ( 1 ) {
      _Pragma( "loopbound min 1 max 26" )
      do
        pi++;
      while ( ( pi < pn ) && ( *pi < *a ) );

      _Pragma( "loopbound min 1 max 49" )
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

int main( int argc, char *argv[] )
{
  double accuracy[1000];
  double average = 0.0;
  double sd = 0.0;
  Limit = atoi(argv[1]);
  MaxCalls = 0;
  for (int i = 1000; i > 0; i--){
    GlobalStructure[0].array[1000 - i] = i;
  }
  for (int i = 0; i < 1000; i++){
    int inversions_left;
    Calls = 0;
    quicksort_int(GlobalStructure[i].array, 1000);
    if (Calls > MaxCalls)
      MaxCalls = Calls;
    inversions_left = count_inversions(GlobalStructure[i].array);
    accuracy[i] = 100 - ((double)inversions_left) * 100 / ((double)GlobalStructure[i].inversions);
  }
  for (int i = 0; i < 1000; i++){
    average = average + accuracy[i];
  }
  average = average / 1000;

  for (int i = 0; i < 1000; i++){
    sd = sd + (accuracy[i] - average) * (accuracy[i] - average);
  }
  sd = sd / 1000;
  sd = sqrt(sd);
  
  printf("average accuracy is %lf \n", average);
  printf("Standard deviation is %lf \n", sd);
  printf("Max Calls is %d \n", MaxCalls);
  
	
  return 0;
}
