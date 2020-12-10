/*
 * Flight.h
 *
 *  Created on: Dec 10, 2020
 *      Author: alon
 */

#ifndef FLIGHT_H_
#define FLIGHT_H_

struct Airport;
struct Airline;

typedef struct{
	int day;
	int month;
	int year;
}Date;

typedef struct{
Airport* departAirport;
Airport* destAirport;
int hourOfDepart;//(0-23)
struct Date;
}Flight;



int initFlight(Flight* flight, Airport* departairport, Airport* destairport);//finish it after the function date

void initDateFlight(Flight* flight);

int checkFlightIATA(const Flight* flight, const char* IATAdestination, const char* IATAdepart);

int countFlightsByIATADestAndDepart(const Flight** arrayflights, const char* IATAdestination, const char* IATAdepart);//arrayflights= array of pointers to flights

void printFlight(Flight* flight);//finish it after the date function

void freeFlight(Flight* flight);//finish it after the date function

#endif /* FLIGHT_H_ */
