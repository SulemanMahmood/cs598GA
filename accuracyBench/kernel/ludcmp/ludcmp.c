#include<stdio.h>
#include<math.h>
#include"ludcmpInput.h"
#define MAX 6

void ludcmp_init_exact( double ludcmp_a[MAX][MAX] );
int ludcmp_test_exact( int n, double ludcmp_a[MAX][MAX] );
void ludcmp_init_approx( float ludcmp_a[MAX][MAX] );
int  ludcmp_test_approx( int n, float ludcmp_a[MAX][MAX]  );
int main( void );

double ludcmp_b[MAX], ludcmp_x[MAX];
float ludcmp_b1[MAX], ludcmp_x1[MAX];

double normd(double x[MAX]){
  double n = 0;
  for(int i = 0; i < MAX; i++){
    n = n + (x[i] * x[i]);
  }
  return sqrt(n); 
}

void ludcmp_init_exact( double ludcmp_a[MAX][MAX] )
{
  int             i, j, n = MAX - 1;
  double          w;

  _Pragma( "loopbound min 6 max 6" )
  for ( i = 0; i <= n; i++ ) {
    w = 0;
    _Pragma( "loopbound min 6 max 6" )
    for ( j = 0; j <= n; j++ ) {
      if ( i == j )
        ludcmp_a[i][j] *= 10;
      w += ludcmp_a[i][j];

    }

    ludcmp_b[i] = w;
  }
}

int ludcmp_test_exact( int n, double ludcmp_a[MAX][MAX] )
{
  int             i, j, k;
  double          w, y[100];

  _Pragma( "loopbound min 5 max 5" )
  for ( i = 0; i < n; i++ ) {
    _Pragma( "loopbound min 1 max 5" )
    for ( j = i + 1; j <= n; j++ ) {
      w = ludcmp_a[j][i];

      if ( i != 0 ) {
        _Pragma( "loopbound min 1 max 4" )
        for ( k = 0; k < i; k++ )
          w -= ludcmp_a[j][k] * ludcmp_a[k][i];
      }

      ludcmp_a[j][i] = w / ludcmp_a[i][i];
    }

    _Pragma( "loopbound min 1 max 5" )
    for ( j = i + 1; j <= n; j++ ) {
      w = ludcmp_a[i + 1][j];

      _Pragma( "loopbound min 1 max 5" )
      for ( k = 0; k <= i; k++ )
        w -= ludcmp_a[i + 1][k] * ludcmp_a[k][j];

      ludcmp_a[i + 1][j] = w;
    }
  }

  y[0] = ludcmp_b[0];

  _Pragma( "loopbound min 5 max 5" )
  for ( i = 1; i <= n; i++ ) {
    w = ludcmp_b[i];

    _Pragma( "loopbound min 1 max 5" )
    for ( j = 0; j < i; j++ )
      w -= ludcmp_a[i][j] * y[j];

    y[i] = w;
  }

  ludcmp_x[n] = y[n] / ludcmp_a[n][n];

  _Pragma( "loopbound min 5 max 5" )
  for ( i = n - 1; i >= 0; i-- ) {
    w = y[i];

    _Pragma( "loopbound min 1 max 5" )
    for ( j = i + 1; j <= n; j++ )
      w -= ludcmp_a[i][j] * ludcmp_x[j];

    ludcmp_x[i] = w / ludcmp_a[i][i];
  }

  return ( 0 );
}

void ludcmp_init_approx( float ludcmp_a[MAX][MAX] )
{
  int             i, j, n = MAX - 1;
  float          w;

  _Pragma( "loopbound min 6 max 6" )
  for ( i = 0; i <= n; i++ ) {
    w = 0;
    _Pragma( "loopbound min 6 max 6" )
    for ( j = 0; j <= n; j++ ) {
      if ( i == j )
        ludcmp_a[i][j] *= 10;
      w += ludcmp_a[i][j];

    }

    ludcmp_b1[i] = w;
  }
}

int ludcmp_test_approx( int n, float ludcmp_a[MAX][MAX] )
{
  int             i, j, k;
  float          w, y[100];

  _Pragma( "loopbound min 5 max 5" )
  for ( i = 0; i < n; i++ ) {
    _Pragma( "loopbound min 1 max 5" )
    for ( j = i + 1; j <= n; j++ ) {
      w = ludcmp_a[j][i];

      if ( i != 0 ) {
        _Pragma( "loopbound min 1 max 4" )
        for ( k = 0; k < i; k++ )
          w -= ludcmp_a[j][k] * ludcmp_a[k][i];
      }

      ludcmp_a[j][i] = w / ludcmp_a[i][i];
    }

    _Pragma( "loopbound min 1 max 5" )
    for ( j = i + 1; j <= n; j++ ) {
      w = ludcmp_a[i + 1][j];

      _Pragma( "loopbound min 1 max 5" )
      for ( k = 0; k <= i; k++ )
        w -= ludcmp_a[i + 1][k] * ludcmp_a[k][j];

      ludcmp_a[i + 1][j] = w;
    }
  }

  y[0] = ludcmp_b1[0];

  _Pragma( "loopbound min 5 max 5" )
  for ( i = 1; i <= n; i++ ) {
    w = ludcmp_b1[i];

    _Pragma( "loopbound min 1 max 5" )
    for ( j = 0; j < i; j++ )
      w -= ludcmp_a[i][j] * y[j];

    y[i] = w;
  }

  ludcmp_x1[n] = y[n] / ludcmp_a[n][n];

  _Pragma( "loopbound min 5 max 5" )
  for ( i = n - 1; i >= 0; i-- ) {
    w = y[i];

    _Pragma( "loopbound min 1 max 5" )
    for ( j = i + 1; j <= n; j++ )
      w -= ludcmp_a[i][j] * ludcmp_x1[j];

    ludcmp_x1[i] = w / ludcmp_a[i][i];
  }

  return ( 0 );
}

int main( void )
{
  int i, j;
  double diff[MAX];
  double accuracy[1000];
  double average = 0.0;
  double sd = 0.0;
  double norm1, normdiff;
  for (i; i < 1000; i++){
    ludcmp_init_exact(GlobalStructure[i].darray);
    ludcmp_test_exact(MAX-1, GlobalStructure[i].darray);

    ludcmp_init_approx(GlobalStructure[i].farray);
    ludcmp_test_approx(MAX-1, GlobalStructure[i].farray);

    for(j = 0; j < MAX; j++){
      diff[j] = ludcmp_x[j] - ludcmp_x1[j];
    }

    norm1 = normd(ludcmp_x);
    normdiff = normd(diff);
    accuracy[i] = fabs(norm1 - normdiff) * 100 / norm1;
    printf("%lf     %lf \n", norm1, accuracy[i]);
  }

  for (i = 0; i < 1000; i++){
    average = average + accuracy[i];
  }
  average = average / 1000;

  for (i = 0; i < 1000; i++){
    sd = sd + (accuracy[i] - average) * (accuracy[i] - average);
  }
  sd = sd / 1000;
  sd = sqrt(sd);

  printf("average accuracy is %lf \n", average);
  printf("Standard deviation is %lf \n", sd);



  return 0;
}
