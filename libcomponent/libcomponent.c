#include <stdio.h>
#include <stdlib.h>

int e_resistance(float orig_resistance, float *res_array)
{
	int count = 0;
	float ersResistans = orig_resistance;

	/*En array innehållande tillgängliga ersättningsresistorer. */
	float E12[] = {
	10.0,12.0,15.0,18.0,22.0,27.0,33.0,39.0,47.0,56.0,68.0,82.0,100.0,
	120.0,150.0,180.0,220.0,270.0,330.0,390.0,470.0,560.0,680.0,820.0,1000.0,
	1200.0,1500.0,1800.0,2200.0,2700.0,3300.0,3900.0,4700.0,5600.0,6800.0,8200.0,10000.0,
	12000.0,15000.0,18000.0,22000.0,27000.0,33000.0,39000.0,47000.0,56000.0,68000.0,82000.0,
	100000.0};

	for(int i = 0; i < 3; i++){
		res_array[i] = 0;
	}
	/*Om kvarvarande värde för att beräkna ersättningsresistans är lika med eller större än 10 
	  (min-värdet i arrayen för ersättningsresistorer) och count är lägre än 3, så sker en ny
	  beräkning av ersättningsresistor. */
	
	while(ersResistans >= 10 && count < 3)
	{
		if(res_array != NULL)
		{
			/*Loopa igenom arrayen för ersättningsresistorer. */
			for(int i = 0; i < sizeof(E12); i++)
			{
				/*Om påträffat värde i arrayen för ersättningsresistorer, är 	
				  större än tillgänligt värde för ersResistans, skall värdet 
				  innan, i arrayen, läggas till i res_array. */
				if(E12[i] > ersResistans)
				{
					/*Läg till ersättningsvärdet i arrayen.*/
					res_array[count] = E12[i-1];
					/*Minska värdet för ersättningsresistansen, med värdet
					  som lagts till i arrayen. */
					ersResistans -= E12[i-1];
					/*Avbryt for-satsen om ersättningsresistans är hittad. */
					break;
				}
			}
		}
	/* Öka värdet för count med 1. */
	count++;
	}
	
	return count;

}

