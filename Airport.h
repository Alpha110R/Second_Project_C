/*
 * Airport.h
 *
 *  Created on: Dec 1, 2020
 *      Author: alon
 */

#ifndef AIRPORT_H_
#define AIRPORT_H_

#define LEN_NAME 255


typedef struct
{
	char* airportName;
	char* stateName;
	char* IATA;
}Airport;
int initAirport(Airport* airport);
int checkIATA(char* IATA);
int checkEqualsIATA(const Airport* airport1, const Airport* airport2);
int checkCodeIATABelongToAirport(const char* codeIATA, const Airport* airport);
char* createString(const char* msg);
void printAirport(Airport* airport);
void freeAirport(Airport* airport);

#endif /* AIRPORT_H_ */
