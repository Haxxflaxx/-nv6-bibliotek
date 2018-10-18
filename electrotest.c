/*

# Jonas Svensson, 700707-5679

*/

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

#include "resistance.h"
#include "libcomponent.h"
#include "power.h"

int main(int argc, char**argv) {
  float res;
  float *floatsp, *res_array, *item;
  int count;
  char conn;
  float volt;
  const int MAXLINE=100;
  char line[MAXLINE];

  printf("Ange spänningskälla i V: ");
  fgets(line,MAXLINE,stdin);
  sscanf(line, "%f", &volt);
  
  printf("Ange koppling[S | P]: ");
  fgets(line,MAXLINE,stdin);
  sscanf(line, "%c", &conn);

  printf("Antal komponenter: ");
  fgets(line,MAXLINE,stdin);
  sscanf(line, "%d", &count);
  floatsp = malloc(count * sizeof(float));
  item = floatsp;
  for(int i=0;i<count;i++) {
    printf("Komponent %d i ohm: ",i+1);
    fgets(line,MAXLINE,stdin);
    sscanf(line, "%f", item);
    item++;
  }

  res = calc_resistance(count, conn, floatsp);

  printf("Ersättningsresistans:\n%.1f ohm\n", res);
  printf("Effekt:\n%.2f W\n", calc_power_r(volt, res));

  free(floatsp);

  res_array = malloc(3 * sizeof(float));
  int count_res = e_resistance(res, res_array);
  printf("Ersättningsresistanser i E12-serien kopplade i serie:\n");

  for(int i = 0; i < count_res; i++)
  {
	  if(res_array[i] != 0)
		printf("%.0f\n", res_array[i]);
  }

  free(res_array); 
  return 0;
}
