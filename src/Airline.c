/*
 * Airline.c
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

int initAirline(Airline* airline)
{
	airline->companyName = createString("Enter the company name:\n");
	if(!airline->companyName)
	{
		printf("Invalid input for company name");
		return 0;
	}
	printf("Enter the number of flights that the airline has:\n");
	scanf("%d", &airline->maxNumFlights);
	airline->numOfFlights =0;
	airline->flights = (Flight**) malloc(sizeof(Flight*)* (airline->maxNumFlights));
	if(airline->maxNumFlights == 0)
	{
		airline->flights = NULL;
		return 1;
	}
	if(!airline->flights)
	{
		printf("The malloc func for flights** didnt succeed");
		return 0;
	}
	fillAirlineFlightArray(airline);

}

void fillAirlineFlightArray(Airline* airline)//Function that check if the user want to enter another Flight
														// and there is option to add if the array is full
{
	int ok = 1;
		char tav;

		while (ok) {
			if (airline->maxNumFlights == airline->numOfFlights) //The airport array is full
				{
				char tav2;
						printf("The airport array is full. Do you want to add another one anyway? y/n\n");
						do {
							scanf("%c", &tav2);
						} while (isspace(tav2));
						if (tav2 == 'y' || tav2 == 'Y')
						{
							airline->flights=realloc(airline->flights, sizeof(Airline*) * (airline->maxNumFlights) +1);// Add another place for the new airport
							airline->maxNumFlights++;
							addFlightToAirline(airline);
						}
						return;
				}

			printf("Do you want to add an airport? y/n\n");
			do {
				scanf("%c", &tav);
			} while (isspace(tav));

			if (tav == 'y' || tav == 'Y')
				ok = addFlightToAirline(airline);
			else
				ok = 0;
		}
}

int addFlightToAirline(Airline* airline)//
{
	Flight* newFlight =  (Flight*) malloc(sizeof(Airport));
	if (!newFlight)
		return 0;

}






