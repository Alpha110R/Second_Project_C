/*
 * AirportManager.c
 *
 *  Created on: Dec 1, 2020
 *      Author: alon
 */
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "AirportManager.h"
#include "Airport.h"

int initAllAirports(AirportManager* airportmanager)//Fill the airport manager
{
	printf("Enter the number of airports that will be:");
	scanf("%d", &(airportmanager->maxNumAirports));
	airportmanager->allAirports = (Airport*) malloc(sizeof(Airport) * (airportmanager->maxNumAirports));
	if(!airportmanager->allAirports)
	{
		printf("The malloc func for all aitports didnt succeed");
		return 0;
	}
	airportmanager->numberOfAirports=0;
	if(airportmanager->maxNumAirports ==0)
	{
		airportmanager->allAirports = NULL;
		return 1;
	}
	fillAirportManager(airportmanager);
	return 1;

}

void fillAirportManager(AirportManager* airportmanager)//Function that check if the user want to enter another airport
														// and there is option to add if the array is full
{
	int ok = 1;
		char tav;

		while (ok) {
			if (airportmanager->maxNumAirports == airportmanager->numberOfAirports) //The airport array is full
				{
				char tav2;
						printf("The airport array is full. Do you want to add another one anyway? y/n\n");
						do {
							scanf("%c", &tav2);
						} while (isspace(tav2));
						if (tav2 == 'y' || tav2 == 'Y')
						{
							airportmanager->allAirports=realloc(airportmanager->allAirports, sizeof(Airport) * (airportmanager->maxNumAirports) +1);// Add another place for the new airport
							airportmanager->maxNumAirports++;
							addAirport(airportmanager);
						}
						return;
				}

			printf("Do you want to add an airport? y/n\n");
			do {
				scanf("%c", &tav);
			} while (isspace(tav));

			if (tav == 'y' || tav == 'Y')
				ok = addAirport(airportmanager);
			else
				ok = 0;
		}
}

int addAirport(AirportManager* airportmanager)//Q1 in AirportManager. Add airport to the array
{
	Airport* newAirport =  (Airport*) malloc(sizeof(Airport));
	if (!newAirport)
		return 0;
	if (!initAirport(newAirport))
				return 0;
	do{
		if(checkDuplicateIATA(newAirport, airportmanager) ==0)
		{
			printf("This IATA %s is excist allready, enter another one\n", newAirport->IATA);
			initAirportIATA(newAirport);
		}
	}while(checkDuplicateIATA(newAirport, airportmanager) ==0);
	airportmanager->allAirports[airportmanager->numberOfAirports] = *newAirport;
	airportmanager->numberOfAirports++;
	return 1;
}
void printAllAirports(const AirportManager* airportmanager)//Prints all the airports in the airportmanager
{
	printf("The airports are:\n");
	for(int i=0 ; i< airportmanager->numberOfAirports ; i++)
	{
		printAirport(&(airportmanager->allAirports[i]));
		printf("\n");
	}
}
int checkDuplicateIATA(const Airport* airport, const AirportManager* airportmanager)//Return 0 if there is allready this IATA in the airportmanager
{
	for(int i=0 ; i< airportmanager->numberOfAirports ; i++)
	{
		if(strcmp(airport->IATA, airportmanager->allAirports[i].IATA) ==0)
		{
			return 0;
		}
	}
	return 1;
}

void freeAllAirports(AirportManager* airportmanager)//Free all the airports in the array include the array
{
	for(int i=0 ; i<airportmanager->numberOfAirports ; i++)
	{
		freeAirport(&(airportmanager->allAirports[i]));
	}
	free(airportmanager->allAirports);
}

Airport* findAirportByIATA(const AirportManager* airportmanager, const char* IATA)//Q2 in AirportManager.
{
	for(int i=0 ; i< airportmanager->numberOfAirports ; i++)
	{
		if(checkCodeIATABelongToAirport(IATA, &(airportmanager->allAirports[i])) == 1)
			return &(airportmanager->allAirports[i]);
	}
	return NULL;
}





