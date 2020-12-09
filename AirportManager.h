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
void printAllAirports (AirportManager* airportmanager);
void freeAllAirports(AirportManager* airportmanager);
void fillAirportManager(AirportManager* airportmanager);
int addAirport(Airport airport);
#endif /* AIRPORTMANAGER_H_ */
