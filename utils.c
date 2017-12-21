//utils.c
//
//Library of routins implementing utilis.h
//source: "ECAM-C3BE-2017-Mini-Projet-Example"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "utils.h"

#define BUFFER_SIZE 80

// Source: http://stackoverflow.com/questions/122616/how-do-i-trim-leading-trailing-whitespace-in-a-standard-way
char* trim (char *str)
{
	char *end;
	while (isspace (*str))
	{
		str++;
	}
	
	if (*str == 0)
	{
		return str;
	}
	
	end = str + strlen (str) - 1;
	while (end > str && isspace (*end))
	{
		end--;
	}
	
	*(end + 1) = 0;
	
	return str;
}


char* readString (FILE* file)
{
	char buffer[BUFFER_SIZE];
	fgets (buffer, BUFFER_SIZE, file);
	return strCopy (trim (buffer));
}

int readInt (FILE* file)
{
	char buffer[BUFFER_SIZE];
	fgets (buffer, BUFFER_SIZE, file);
	return atoi (buffer);
}