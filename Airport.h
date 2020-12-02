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
	char* airportName[LEN_NAME];
	char* stateName[LEN_NAME];
	char* IATA[3];
}Airport;
int checkEqualsIATA(const Airport* airport1, const Airport* airport2);
int checkCodeIATABelongToAirport(const char* codeIATA, const Airport* airport);

#endif /* AIRPORT_H_ */
