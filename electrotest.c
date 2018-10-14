/*

# Jonas Svensson, 700707-5679

*/

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

#include "resistance.h"
#include "libcomponent.h"

int main(int argc, char**argv) {
  float res;
  float *floatsp, *res_array, *item;
  int count;
  char conn;
  

  printf("Ange koppling[S | P]: ");
  scanf("%c", &conn);
  printf("Antal komponenter: ");
  scanf("%d", &count);
  floatsp = malloc(count * sizeof(float));
  item = floatsp;
  for(int i=0;i<count;i++) {
    printf("Komponent %d i ohm: ",i+1);
    scanf("%f", item);
    item++;
  }

  res = calc_resistance(count, conn, floatsp);
  printf("Ersättningsresistans: %.1f\n", res);

  free(floatsp);

  res_array = malloc(3 * sizeof(float));
  int count_res = e_resistance(res, res_array);
  printf("Ersättningsresistanser i E12-serien kopplade i serie: %.1f, %.1f, %.1f \n", res_array[0], res_array[1], res_array[2]);

  free(res_array); 
  return 0;
}
