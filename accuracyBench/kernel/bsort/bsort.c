#include"sortInput.h"
#include<stdio.h>
#include<math.h>

void bsort_main( void );
int bsort_BubbleSort( int Array[] );
int count_inversions(int Array[] );

#define bsort_SIZE 1000

int count_inversions(int Array[] ){
  int inversions = 0;
  for (int i = 0; i < bsort_SIZE; i++){
    for (int j = i; j < bsort_SIZE; j++){
      if (Array[i] > Array[j]){
        inversions++;
      }
    }
  }
  return inversions;
}

int bsort_BubbleSort( int Array[] )
{
  int Sorted = 0;
  int Temp, Index, i;

  for ( i = 0; i < bsort_SIZE - 1; i += 1 ) {
    if (i % 12 == 0)
	continue;

    Sorted = 1;
    for ( Index = 0; Index < bsort_SIZE - 1; Index += 1 ) {
//      if (Index % 500 == 0)
//        continue;  

      if ( Index > bsort_SIZE - i )
        break;
      if ( Array[ Index ] > Array[Index + 1] ) {
        Temp = Array[ Index ];
        Array[ Index ] = Array[ Index + 1 ];
        Array[ Index + 1 ] = Temp;
        Sorted = 0;
      }
    }

    if ( Sorted )
      break;
  }

  return 0;
}

int main( void )
{
  double accuracy[1000];
  double average = 0.0;
  double sd = 0.0;
  for (int i = 0; i < 1000; i++){
    int inversions_left;
    bsort_BubbleSort(GlobalStructure[i].array);
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
  
	
  return 0;
}
