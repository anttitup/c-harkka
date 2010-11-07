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
#include "decode.h"
char *encodeOrDecode;

int main(int argc, char *argv[]);

int read_file(FILE *input, char * secretMessage);

long how_long_file(FILE *fileHandle);

int test_parameter(char *parameter);

int test_message(char *message,long fileSize);

char * collect_message(int numberOfArguments,char *message[]);

void hop_over_head(FILE *encFile);



