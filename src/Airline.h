/*
 * Airline.h
 *
 *  Created on: Dec 10, 2020
 *      Author: alon
 */

#ifndef AIRLINE_H_
#define AIRLINE_H_
#include "Flight.h"

typedef struct{
char* companyName;
int numOfFlights;
int maxNumFlights;
Flight** flights; //In the default there is no flights unless said otherwise
}Airline;

int initAirline(Airline* airline);

void fillAirlineFlightArray(Airline* airline);

int addFlightToAirline(Airline* airline);

void printAirline(Airline* airline);

void freeAirline(Airline* airline);

#endif /* AIRLINE_H_ */
