/*
 * Airport.c
 *
 *  Created on: Dec 1, 2020
 *      Author: alon
 */
#include "Airport.h"

int checkEqualsIATA(const Airport* airport1, const Airport* airport2)
{
	if(strcmp(airport1 ->IATA, airport2 ->IATA) ==0) return 1;
	return 0;
}

int checkCodeIATABelongToAirport(const char* codeIATA, const Airport* airport)
{
	if(strcmp(codeIATA, airport ->IATA) ==0) return 1;
	return 0;
}

