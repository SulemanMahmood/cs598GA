#define MAXSIZE 100
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include"sortInput.h"

int countnegative_sum( int Array[MAXSIZE][MAXSIZE] );
int Limit;

int countnegative_sum( int Array[MAXSIZE][MAXSIZE] )
{
  register int Outer, Inner;

  int Ptotal = 0; /* changed these to locals in order to drive worst case */
  int Ntotal = 0;
  int Pcnt = 0;
  int Ncnt = 0;

  _Pragma( "loopbound min 20 max 20" )
  for ( Outer = 0; Outer < MAXSIZE; Outer++ )
    _Pragma( "loopbound min 20 max 20" )
    for ( Inner = 0; Inner < Limit; Inner++ )
      if ( Array[Outer][Inner] >= 0 ) {
        Ptotal += Array[Outer][Inner];
        Pcnt++;
      } else {
        Ntotal += Array[Outer][Inner];
        Ncnt++;
      }

  return (Ncnt * MAXSIZE) / Limit;
}

int main(int argc, char** argv )
{
  double accuracy[1000];
  double average = 0.0;
  double sd = 0.0;
  Limit = atoi(argv[1]);
  
  for (int i = 0; i < 1000; i++){
    int count;
    count = countnegative_sum(GlobalStructure[i].array);
    accuracy[i] = 100 - ((double)(abs(count - GlobalStructure[i].negatives )) * 100 / (double)(GlobalStructure[i].negatives));
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


  return 0;
}
