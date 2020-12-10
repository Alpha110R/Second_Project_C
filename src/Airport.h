/*
 * Airport.h
 *
 *  Created on: Dec 1, 2020
 *      Author: alon
 */

#ifndef AIRPORT_H_
#define AIRPORT_H_


typedef struct
{
	char* airportName;
	char* stateName;
	char* IATA;
}Airport;


int initAirport(Airport* airport);

void printAirport(const Airport* airport);

void freeAirport(Airport* airport);

void initAirportIATA(Airport* airport);

int checkIATA(const char* IATA);

int checkEqualsIATA(const Airport* airport1, const Airport* airport2);

int checkCodeIATABelongToAirport(const char* codeIATA, const Airport* airport);




#endif /* AIRPORT_H_ */
