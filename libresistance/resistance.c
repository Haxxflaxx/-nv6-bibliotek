/*

# Jonas Svensson, 700707-5679

*/

#include <stddef.h>
#include "resistance.h"

float calc_serial(int count, float *array) {
  float res = 0.0;
  
  while(count>0) {
    res += *array;
    array++;
    count--;
  }
  return res;
}

float calc_parallell(int count, float *array) {
  float res = 0.0;
  
  while(count>0) {
    if(*array < 0.001)
      return 0;
    res += 1.0 / *array;
    array++;
    count--;
  }
  if(res < 0.001)
    return 0.0;
  else
    return 1.0/res;
}

float calc_resistance(int count, char conn, float *array)
{
  if(count < 0)
    return -1.0;
  if(array == NULL)
    return -1.0;
  
  switch(conn) {
  case 'S' :
    return calc_serial(count, array);
  case 'P' :
    return calc_parallell(count, array);
  }
  
  return -1.0;
}
