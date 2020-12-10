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

int initAirport(Airport* airport)//Initialize airport
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
	initAirportIATA(airport);//Call to function that enter the IATA untill its a valid input
	return 1;
}

void printAirport(const Airport* airport)//Print all the details of the airport
{
	printf("The name of the airport is: %s\n", airport->airportName);
	printf("The airport's state: %s\n", airport->stateName);
	printf("The IATA is: %s\n", airport->IATA);
}

void freeAirport(Airport* airport)// Free funcion to the dinamic memory
{
	free(airport->IATA);
	free(airport->airportName);
	free(airport->stateName);
}

void initAirportIATA(Airport* airport)//Enter the IATA untill its a valid input
{
	do{
			airport->IATA = createString("Enter IATA:");
			if(checkIATA(airport->IATA) ==0)
			{
				printf("Invalid length input for IATA.You need 3 characters");
			}
	}while(checkIATA(airport->IATA) ==0);
}

int checkIATA(const char* IATA)//Check if the length of the IATA is valid
{
	if(strlen(IATA) !=3) return 0;
	return 1;
}

int checkEqualsIATA(const Airport* airport1, const Airport* airport2)//Q1 in Airport return 1 if they equals
{
	if(strcmp(airport1->IATA, airport2->IATA) ==0) return 1;
	return 0;
}

int checkCodeIATABelongToAirport(const char* codeIATA, const Airport* airport)//Q2 in Airport return 1 if they equals
{
	if(strcmp(codeIATA, airport ->IATA) ==0) return 1;
	return 0;
}




