/*
 * stat.h
 *
 *  Created on: Oct 4, 2010
 *      Author: antti
 */


char *encodeOrDecode;
char *secretMessage;

int main(int argc, char *argv[]);

int test_file(char *fileName);

int read_file(FILE *input);

long how_long_file(FILE *fileHandle);

int test_parameter(char *parameter);

int test_message(char *message,long fileSize);

void collect_message(int numberOfArguments,char *message[]);





