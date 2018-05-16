#include<stdio.h>
#include"stInput.h"
#include<math.h>

float st_fabs( float );
float st_sqrtf( float, int );
float st_square( float );
void st_calc_Sum_Mean( float *, float *, float *);
void st_calc_Var_Stddev( float *, float, float *, float *, int );
void st_calc_LinCorrCoef( float *, float *, float, float, float *, int );
int main( void );


/*
  Declaration of global variables
*/

float st_sumA, st_sumB, st_meanA, st_meanB, st_varA, st_varB, st_stddevA, st_stddevB, st_coef;



/*
  Arithmetic math functions
*/

float st_fabs( float n )
{
  float f;

  if ( n >= 0 )
    f = n;
  else
    f = -n;

  return ( f );
}


float st_sqrtf( float val, int limit )
{
  float x = val / 10;
  float dx;
  float diff;
  float min_tol = 0.00001f;

  int i, flag = 0; 

  if ( val == 0 )
    x = 0;
  else {
    _Pragma( "loopbound min 20 max 20" )
    for ( i = 1; i <= limit; i++ ) {
      if ( !flag ) {
        dx = ( val - ( x * x ) ) / ( 2.0f * x );
        x = x + dx;
        diff = val - ( x * x );

        if ( st_fabs( diff ) <= min_tol )
          flag = 1;
      }
    }
  }

  return ( x );
}


float st_square( float x )
{
  return ( x * x );
}


/*
  Algorithm core functions
*/

void st_calc_Sum_Mean( float *array, float *sum, float *mean )
{
  int i;

  *sum = 0;

  _Pragma( "loopbound min 1000 max 1000" )
  for ( i = 0; i < 1000; i++ )
    *sum += array[ i ];
  *mean = *sum / 1000;
}


void st_calc_Var_Stddev( float *array, float mean, float *var, float *stddev, int limit )
{
  int i;
  float diffs = 0.0f;

  _Pragma( "loopbound min 1000 max 1000" )
  for ( i = 0; i < 1000; i++ )
    diffs += st_square( array[ i ] - mean );

  *var = diffs / 1000;
  *stddev = st_sqrtf( *var, limit );
}


void st_calc_LinCorrCoef( float *arrayA, float *arrayB, float meanA,
                          float meanB, float *coef, int limit )
{
  int i;
  float numerator = 0.0f, Aterm = 0.0f, Bterm = 0.0f;

  _Pragma( "loopbound min 1000 max 1000" )
  for ( i = 0; i < 1000; i++ ) {
    numerator += ( arrayA[ i ] - meanA ) * ( arrayB[ i ] - meanB );
    Aterm += st_square( arrayA[ i ] - meanA );
    Bterm += st_square( arrayB[ i ] - meanB );
  }

  *coef = numerator / ( st_sqrtf( Aterm, limit ) * st_sqrtf( Bterm, limit ) );
}




int main( void )
{
  int i;
  int limit;
  float savesd, saveco;
  double sdacc[1000];
  double sdAvg, sdsd, coAvg, cosd;
  double coacc[999];

  for (limit = 1; limit <= 20; limit++){
    sdAvg = 0;
    sdsd = 0;
    coAvg = 0;
    cosd = 0;
    st_calc_Sum_Mean( GlobalStructure[0] , &st_sumA, &st_meanA );
    st_calc_Var_Stddev( GlobalStructure[0] , st_meanA, &st_varA, &savesd, 20 );  // accurate
    st_calc_Var_Stddev( GlobalStructure[0] , st_meanA, &st_varA, &st_stddevA, limit );  // approx
    sdacc[0] = 100 - (fabs((double)st_stddevA - (double)savesd)) * 100 / (double)savesd;

    for (i = 1; i < 1000; i++){
      st_calc_Sum_Mean( GlobalStructure[i] , &st_sumB, &st_meanB );
      st_calc_Var_Stddev( GlobalStructure[i] , st_meanB, &st_varB, &savesd, 20 );  // accurate
      st_calc_Var_Stddev( GlobalStructure[i] , st_meanB, &st_varB, &st_stddevB, limit );  // approx
      sdacc[i] = 100 - (fabs((double)st_stddevB - (double)savesd)) * 100 / (double)savesd;

      st_calc_LinCorrCoef( GlobalStructure[0], GlobalStructure[i], st_meanA, st_meanB, &saveco, 20 );
      st_calc_LinCorrCoef( GlobalStructure[0], GlobalStructure[i], st_meanA, st_meanB, &st_coef, limit );

      coacc[i-1] = 100 - fabs((fabs((double)st_coef - (double)saveco)) * 100 / (double)saveco);
    }

    for (int i = 0; i < 1000; i++){
      sdAvg = sdAvg + sdacc[i];
    }
    sdAvg = sdAvg / 1000;

    for (int i = 0; i < 1000; i++){
      sdsd = sdsd + (sdacc[i] - sdAvg) * (sdacc[i] - sdAvg);
    }
    sdsd = sdsd / 1000;
    sdsd = sqrt(sdsd);

    printf("Limit is %d\n", limit);


    for (int i = 0; i < 999; i++){
      coAvg = coAvg + coacc[i];
    }
    coAvg = coAvg / 999;

    for (int i = 0; i < 999; i++){
      cosd = cosd + (coacc[i] - coAvg) * (coacc[i] - coAvg);
    }
    cosd = cosd / 1000;
    cosd = sqrt(cosd);

    printf("%.2lf,%.2lf,%.2lf,%.2lf\n\n", sdAvg,sdsd,coAvg,cosd);
  }

  
  return 0;
}
