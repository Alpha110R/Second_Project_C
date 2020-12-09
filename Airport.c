/*
 * Airport.c
 *
 *  Created on: Dec 1, 2020
 *      Author: alon
 */
#include "Airport.h"
#include "AirportManager.h"
#include "helpFunctions.h"
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int initAirport(Airport* airport)
{
	airport->airportName = createString("Enter airport name:");
	if(!airport->airportName)
	{
		printf("Invalid input for name.");
		return 0;
	}
	airport->stateName = createString("Enter the State name of the airport:");
	if(!airport->stateName)
	{
		printf("Invalid input for state name.");
		return 0;
	}
	airport->IATA = createString("Enter IATA:");
	if(checkIATA(airport->IATA) ==0)
	{
		printf("Invalid length input for IATA.");
		return 0;
	}
	return 1;
}

void printAirport(Airport* airport)
{
	printf("The name of the airport is: %s", airport->airportName);
	printf("The airport's state: %s", airport->stateName);
	printf("The IATA is: %s", airport->IATA);
}

void freeAirport(Airport* airport)
{
	free(airport->IATA);
	free(airport->airportName);
	free(airport->stateName);
}

int checkIATA(char* IATA)//not valid length
{
	if(strlen(IATA) !=3) return 0;
	return 1;
}

int checkEqualsIATA(const Airport* airport1, const Airport* airport2)
{
	if(strcmp(airport1->IATA, airport2->IATA) ==0) return 1;
	return 0;
}

int checkCodeIATABelongToAirport(const char* codeIATA, const Airport* airport)
{
	if(strcmp(codeIATA, airport ->IATA) ==0) return 1;
	return 0;
}

char* createString(const char* msg)
{
	char* str;
	char temp[LEN_NAME];
	printf("Enter %s: ",msg);
	scanf("%s",temp);

	str = (char*)malloc((strlen(temp)+1)*sizeof(char));
	if(str != NULL)
		strcpy(str, temp);

	return str;
}



