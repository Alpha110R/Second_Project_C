/*
 * AirportManager.h
 *
 *  Created on: Dec 1, 2020
 *      Author: alon
 */

#ifndef AIRPORTMANAGER_H_
#define AIRPORTMANAGER_H_
#include "Airport.h"

typedef struct{
	Airport* allAirports;
	int numberOfAirports;
	int maxNumAirports;
}AirportManager;


int initAllAirports(AirportManager* airportmanager);

void fillAirportManager(AirportManager* airportmanager);

int addAirport(AirportManager* airportmanager);

void printAllAirports (const AirportManager* airportmanager);

int checkDuplicateIATA(const Airport* airport, const AirportManager* airportmanager);

void freeAllAirports(AirportManager* airportmanager);

Airport* findAirportByIATA(const AirportManager* airportmanager, const char* IATA);



#endif /* AIRPORTMANAGER_H_ */
