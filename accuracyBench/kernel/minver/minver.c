#include<stdio.h>
#include<math.h>
#include"minverInput.h"

int minver_minver_exact(double in[3][3]);
double minver_fabs( double n );
int minver_minver_approx(float in[3][3]);
float minver_fabs_approx( float n );
double normd(double x[9]);
int main( void );


/*
    Arithmetic math functions
*/

double normd(double x[9]){
  double n = 0;
  for(int i = 0; i < 9; i++){
    n = n + (x[i] * x[i]);
  }
  return sqrt(n); 
}


double minver_fabs( double n )
{
  double f;

  if ( n >= 0 )
    f = n;
  else
    f = -n;
  return f;
}

int minver_minver_exact(double in[3][3])
{
  double minver_det;
  int work[ 500 ], i, j, k, iw;
  int r = 0;
  double w, wmax, pivot, api, w1;

  w1 = 1.0;
  _Pragma( "loopbound min 3 max 3" )
  for ( i = 0; i < 3; i++ )
    work[ i ] = i;
  _Pragma( "loopbound min 3 max 3" )
  for ( k = 0; k < 3; k++ ) {
    wmax = 0.0;
    _Pragma( "loopbound min 1 max 3" )
    for ( i = k; i < 3; i++ ) {
      w = minver_fabs( in[ i ][ k ] );
      if ( w > wmax ) {
        wmax = w;
        r = i;
      }
    }
    pivot = in[ r ][ k ];
    api = minver_fabs( pivot );
    if ( api <= 1.0e-6 ) {
      minver_det = w1;
      return ( 1 );
    }
    w1 *= pivot;
    if ( r != k ) {
      w1 = -w;
      iw = work[ k ];
      work[ k ] = work[ r ];
      work[ r ] = iw;
      _Pragma( "loopbound min 3 max 3" )
      for ( j = 0; j < 3; j++ ) {
        w = in[ k ][ j ];
        in[ k ][ j ] = in[ r ][ j ];
        in[ r ][ j ] = w;
      }
    }
    _Pragma( "loopbound min 3 max 3" )
    for ( i = 0; i < 3; i++ )
      in[ k ][ i ] /= pivot;
    _Pragma( "loopbound min 3 max 3" )
    for ( i = 0; i < 3; i++ ) {
      if ( i != k ) {
        w = in[ i ][ k ];
        if ( w != 0.0 ) {
          _Pragma( "loopbound min 3 max 3" )
          for ( j = 0; j < 3; j++ ) {
            if ( j != k ) in[ i ][ j ] -= w * in[ k ][ j ];
          }
          in[ i ][ k ] = -w / pivot;

        }
      }
    }
    in[ k ][ k ] = 1.0 / pivot;
  }
  _Pragma( "loopbound min 3 max 3" )
  for ( i = 0; i < 3; ) {
    _Pragma( "loopbound min 1 max 3" )
    while ( 1 ) {
      k = work[ i ];
      if ( k == i ) break;
      iw = work[ k ];
      work[ k ] = work[ i ];
      work[ i ] = iw;
      _Pragma( "loopbound min 3 max 3" )
      for ( j = 0; j < 3; j++ ) {
        w = in [k ][ i ];
        in[ k ][ i ] = in[ k ][ k ];
        in[ k ][ k ] = w;
      }
    }
    i++;
  }
  minver_det = w1;
  return ( 0 );

}

float minver_fabs_approx( float n )
{
  float f;

  if ( n >= 0 )
    f = n;
  else
    f = -n;
  return f;
}

int minver_minver_approx(float in[3][3])
{
  float minver_det;
  int work[ 500 ], i, j, k, iw;
  int r = 0;
  float w, wmax, pivot, api, w1;

  w1 = 1.0;
  _Pragma( "loopbound min 3 max 3" )
  for ( i = 0; i < 3; i++ )
    work[ i ] = i;
  _Pragma( "loopbound min 3 max 3" )
  for ( k = 0; k < 3; k++ ) {
    wmax = 0.0;
    _Pragma( "loopbound min 1 max 3" )
    for ( i = k; i < 3; i++ ) {
      w = minver_fabs_approx( in[ i ][ k ] );
      if ( w > wmax ) {
        wmax = w;
        r = i;
      }
    }
    pivot = in[ r ][ k ];
    api = minver_fabs_approx( pivot );
    if ( api <= 1.0e-6 ) {
      minver_det = w1;
      return ( 1 );
    }
    w1 *= pivot;
    if ( r != k ) {
      w1 = -w;
      iw = work[ k ];
      work[ k ] = work[ r ];
      work[ r ] = iw;
      _Pragma( "loopbound min 3 max 3" )
      for ( j = 0; j < 3; j++ ) {
        w = in[ k ][ j ];
        in[ k ][ j ] = in[ r ][ j ];
        in[ r ][ j ] = w;
      }
    }
    _Pragma( "loopbound min 3 max 3" )
    for ( i = 0; i < 3; i++ )
      in[ k ][ i ] /= pivot;
    _Pragma( "loopbound min 3 max 3" )
    for ( i = 0; i < 3; i++ ) {
      if ( i != k ) {
        w = in[ i ][ k ];
        if ( w != 0.0 ) {
          _Pragma( "loopbound min 3 max 3" )
          for ( j = 0; j < 3; j++ ) {
            if ( j != k ) in[ i ][ j ] -= w * in[ k ][ j ];
          }
          in[ i ][ k ] = -w / pivot;

        }
      }
    }
    in[ k ][ k ] = 1.0 / pivot;
  }
  _Pragma( "loopbound min 3 max 3" )
  for ( i = 0; i < 3; ) {
    _Pragma( "loopbound min 1 max 3" )
    while ( 1 ) {
      k = work[ i ];
      if ( k == i ) break;
      iw = work[ k ];
      work[ k ] = work[ i ];
      work[ i ] = iw;
      _Pragma( "loopbound min 3 max 3" )
      for ( j = 0; j < 3; j++ ) {
        w = in [k ][ i ];
        in[ k ][ i ] = in[ k ][ k ];
        in[ k ][ k ] = w;
      }
    }
    i++;
  }
  minver_det = w1;
  return ( 0 );

}


/*
    Initialization- and return-value-related functions
*/

int main( void )
{
  int i, j, k;
  double diff[9];
  double copy[9];
  double accuracy[1000];
  double average = 0.0;
  double sd = 0.0;
  double norm1, normdiff;
  for (i; i < 1000; i++){
    minver_minver_exact(GlobalStructure[i].darray);
    minver_minver_approx(GlobalStructure[i].farray);

    for(j = 0; j < 3; j++){
      for (k = 0; k < 3; k++){
        diff[3*j + k] = GlobalStructure[i].darray[j][k] - GlobalStructure[i].farray[j][k];
        copy[3*j + k] = GlobalStructure[i].darray[j][k];
      }
    }

    norm1 = normd(copy);
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





