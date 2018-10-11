// Daniel Arnqvist, 890410-4877

#include "power.h"
#include <stdio.h>

int main()
{
    printf("---Test libpower---\n");

    printf("calc_power_r: ");
    if(calc_power_r(12, 4) == 36)
    {
        printf("[OK]\n");
    }
    else
    {
        printf("[FAIL]\n");
    }

    printf("calc_power_i: ");
    if(calc_power_i(12, 4) == 48)
    {
        printf("[OK]\n");
    }
    else
    {
        printf("[FAIL]\n");
    }
}
