/*
 * AirportManager.c
 *
 *  Created on: Dec 1, 2020
 *      Author: alon
 */
#include <stdio.h>
#include "AirportManager.h"

int initAllAirports(AirportManager* airportmanager)
{
	printf("Enter the number of airports that will be:");
	scanf("%d", &(airportmanager->maxNumAirports));
	airportmanager->allAirports = (Airport*) malloc(sizeof(Airport) * airportmanager->maxNumAirports);
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

void fillAirportManager(AirportManager* airportmanager)
{

}

int addAirport(Airport airport, AirportManager airportmanager)
{
	//airportmanager ->allAirport = realloc(allAirport[],sizeof(Airport)+1);
}
