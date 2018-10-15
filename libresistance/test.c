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
  printf("Expected Result null array: -1.000000\n");
  res = calc_resistance(3, 'P', NULL);
  printf("Result null array: %f\n", res);
  
  /* test bad data 1 */
  printf("Expected Result bad data 1: -1.000000\n");
  floats[0] = 100.0;
  floats[1] = 200.0;
  floats[2] = 300.0;
  res = calc_resistance(3, 'd', floats);
  printf("Result bad data 1: %f\n", res);

  /* test bad data 2 */
  printf("Expected Result bad data 2: -1.000000\n");
  floats[0] = 100.0;
  floats[1] = 0.0;
  floats[2] = 300.0;
  res = calc_resistance(-3, 'S', floats);
  printf("Result bad data 2: %f\n", res);

  /* test serial */
  printf("Expected Result serial 1: 600.000000\n");
  floats[0] = 100.0;
  floats[1] = 200.0;
  floats[2] = 300.0;
  res = calc_resistance(3, 'S', floats);
  printf("Result serial 1: %f\n", res);

  /* test parallell */
  printf("Expected Result parallell 1: 54.545456\n");
  floats[0] = 100.0;
  floats[1] = 200.0;
  floats[2] = 300.0;
  res = calc_resistance(3, 'P', floats);
  printf("Result parallell 1: %f\n", res);

  /* test parallell zero */
  printf("Expected Result parallell zero: 0.000000\n");
  floats[0] = 100.0;
  floats[1] = 0.0;
  floats[2] = 300.0;
  res = calc_resistance(3, 'P', floats);
  printf("Result parallell zero: %f\n", res);

  return 0;
}
