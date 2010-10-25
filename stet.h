/*
 * stat.h
 *
 *  Created on: Oct 4, 2010
 *      Author: antti
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "encoding.h"

char *encodeOrDecode;
char *secretMessage;

int main(int argc, char *argv[]);

int test_file(char *fileName);

int read_file(FILE *input);

long how_long_file(FILE *fileHandle);

int test_parameter(char *parameter);

int test_message(char *message,long fileSize);

void collect_message(int numberOfArguments,char *message[]);





