/*
 * main.c
 *
 *  Created on: Dec 1, 2020
 *      Author: alon
 */
#include "Airport.h"
#include "AirportManager.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
AirportManager a;
char IATA [3]= {'a','a', 'a'};
initAllAirports(&a);
printAllAirports(&a);
printAirport(findAirportByIATA(&a, IATA));
return 1;
}
