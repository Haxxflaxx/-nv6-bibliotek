/*

# Jonas Svensson, 700707-5679

*/

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

#include "resistance.h"

int main(int argc, char**argv) {
  float res;
  float *floatsp, *item;
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
    
  return 0;
}
