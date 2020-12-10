/*
 * Flight.c
 *
 *  Created on: Dec 10, 2020
 *      Author: alon
 */
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "AirportManager.h"
#include "Airport.h"
#include "helpFunctions.h"
#include "Airline.h"
#include "Flight.h"
#define MAX 8

int initFlight(Flight* flight, Airport* departairport, Airport* destairport)//Initialize flight
{
	if(checkEqualsIATA(departairport, destairport) ==1)
	{
		printf("The depart and destination airport are identical");
		return 0;
	}
	flight->departAirport = departairport;
	flight->destAirport = destairport;

	do{//Make sure that the hour is between 0-23
		printf("What is the hour that the flight is depart? (round number)");
		scanf("%d", &(flight->hourOfDepart));
		if(flight->hourOfDepart <0 || flight->hourOfDepart >23)
			printf("The hour of depart is invalid. It needs to be between 0 to 23 and round number");
	}while (flight->hourOfDepart <0 || flight->hourOfDepart >23);
	return 1;
}

void initDateFlight(Flight* flight)
{
	char stringDate[MAX];
	printf("Enter the date of the flight in this formation: dd/mm/yy");
	fgets(stringDate, MAX, stdin);
	char* token = strtok(stringDate, "/");
	while(token != NULL)
	{

	}

}

int checkFlightIATA(const Flight* flight, const char* IATAdestination, const char* IATAdepart)//Q1 in Flight return 1 if the flight is
																							//compatible with the IATA depart and destination
{
	if(checkCodeIATABelongToAirport(IATAdestination, flight->destAirport) ==1
			|| checkCodeIATABelongToAirport(IATAdepart, flight->departAirport)==1) return 1;
	return 0;
}

int countFlightsByIATADestAndDepart(const Flight** arrayflights, const char* IATAdestination, const char* IATAdepart)
{
	int counter =0;
	for(int i=0 ; i< (sizeof(arrayflights)/4) ; i++)//4 because this is the size of pointer, sizeof(arrayflights)/4 -> to get the size of the array
	{
		if(arrayflights[i] == NULL) break;//if the array wont be full
		if(checkFlightIATA(arrayflights[i], IATAdestination,IATAdepart) == 1) counter++;
	}
	return counter;
}






