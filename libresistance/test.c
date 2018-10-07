/*

# Jonas Svensson, 700707-5679

*/

#include <stdio.h>
#include <stddef.h>

#include "resistance.h"

int main(int argc, char**argv) {
  float res;
  float floats[3];
  
  /* test array null */
  res = calc_resistance(3, 'P', NULL);
  printf("Result null array: %f\n", res);
  
  /* test bad data 1 */
  floats[0] = 100.0;
  floats[1] = 200.0;
  floats[2] = 300.0;
  res = calc_resistance(3, 'd', floats);
  printf("Result bad data 1: %f\n", res);

  /* test bad data 2 */
  floats[0] = 100.0;
  floats[1] = 0.0;
  floats[2] = 300.0;
  res = calc_resistance(-3, 'S', floats);
  printf("Result bad data 2: %f\n", res);

  /* test serial */
  floats[0] = 100.0;
  floats[1] = 200.0;
  floats[2] = 300.0;
  res = calc_resistance(3, 'S', floats);
  printf("Result serial 1: %f\n", res);

  /* test parallell */
  floats[0] = 100.0;
  floats[1] = 200.0;
  floats[2] = 300.0;
  res = calc_resistance(3, 'P', floats);
  printf("Result parallell 1: %f\n", res);

  /* test parallell zero */
  floats[0] = 100.0;
  floats[1] = 0.0;
  floats[2] = 300.0;
  res = calc_resistance(3, 'P', floats);
  printf("Result parallell zero: %f\n", res);

  return 0;
}
