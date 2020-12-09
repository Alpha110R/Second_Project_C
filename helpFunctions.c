/*
 * helpFunctions.c
 *
 *  Created on: Dec 6, 2020
 *      Author: alon
 */

#include "helpFunctions.h"
#include <stdio.h>

char* myGets(char* buf, size_t size)
{
	if(buf != NULL && size > 0)
	{
		if(fgets(buf,size,stdin))
		{
			buf[strcspn(buf,"\n")] = '\0';
			return buf;
		}
		*buf = '\0';
	}
	return NULL;

}
