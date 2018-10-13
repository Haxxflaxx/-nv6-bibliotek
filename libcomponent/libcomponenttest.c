#include <stdio.h>
#include <stdlib.h>
#include "libcomponent.h"
int main(){
	
	float res_array[3];

	float resistans;

	resistans = 398.0 + 240.0 + 900.0;
	e_resistance(resistans, res_array);

	printf("Ersättningsresistanser i E12-serien kopplade i serie: ");
	for(int i = 0; i < 3; i++){
		printf("%0.0f ", res_array[i]);
	}
	printf("\n");

	resistans = 1300.0 + 320.0 + 12.0;
	e_resistance(resistans, res_array);

	printf("Ersättningsresistanser i E12-serien kopplade i serie: ");
	for(int i = 0; i < 3; i++){
		printf("%0.0f ", res_array[i]);
	}
	printf("\n");

	resistans = 2345.0 + 650.0 + 1900.0;
	e_resistance(resistans, res_array);

	printf("Ersättningsresistanser i E12-serien kopplade i serie: ");
	for(int i = 0; i < 3; i++){
		printf("%0.0f ", res_array[i]);
	}
	printf("\n");
	return 0;

}
