/*
 * helpFunctions.c
 *
 *  Created on: Dec 6, 2020
 *      Author: alon
 */

#include "helpFunctions.h"
#include <stdio.h>
#define LEN_NAME 255

char* createString(const char* msg)
{
	char* str;
	char temp[LEN_NAME];
	printf("%s",msg);
	scanf("%s",temp);

	str = (char*)malloc((strlen(temp)+1)*sizeof(char));
	if(str != NULL)
		strcpy(str, temp);

	return str;
}

