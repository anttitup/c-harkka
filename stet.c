/*
 ============================================================================
 Name        : stet.c
 Author      : Antti Tupamäki
 Version     :0.0
 Copyright   : Your copyright notice
 Description : Salaiset viestit, anna parametrit järjestyksessä, kuva ,enkoodaus
 vai dekoodaus ja viesti.
 ============================================================================
 */
#include "stet.h"

int main(int argc, char **argv)
{
	FILE *fileHandler;

	if(argc<3)
	{
		printf("not enougth parameters");
		return EXIT_FAILURE;
	}

	if(test_parameter(argv[2]))
	{
		printf("wrong parameter");
		return EXIT_FAILURE;
	}

	if(test_file(argv[0]))
	{	
		if((fileHandler=fopen(argv[1],"r"))!=NULL)
		{	
			collect_message(argc,argv);
			read_file(fileHandler);
		}
		else
		{
			printf("ei toimi");
		}
	}
	else
	{
		printf("ei toimi");
		return EXIT_FAILURE;
	}

	printf("it works");
	return EXIT_SUCCESS;
}

int test_file(char *fileName)
{

	if(strlen(fileName)<4)
	{
		printf("cannot open wrong fileName");
	    return 0;
	}

	if(strstr(fileName,".bmi")>0)
	{
			printf("cannot open");
			return 0;
	}

	return 1;
}

int read_file(FILE *input)
{
	FILE *copy = input;
	
	long size = how_long_file(copy);
	
	printf("how long file %ld \n ",size);

	if(strcmp(encodeOrDecode,"encode")==0)
	{
		if(test_message(secretMessage,size))
		{
			if(encode(input,secretMessage))
			{
				printf("we encoded message in picture\n");
				return 1;
			}
		}
	}
	else
	{	
		return 1;
	}

	printf("it works1");
	fclose(input);

	return 1;
}

long how_long_file(FILE *fileHandle)
{
	fseek(fileHandle,0L,SEEK_END);
	return ftell(fileHandle);
}

int test_parameter(char *parameter)
{
	printf("%s", parameter);
	if(strcmp(parameter,"encode")==0)
	{
		encodeOrDecode = "encode";
		return 0;
	}

	if(strcmp(parameter,"decode")==0)
	{
		encodeOrDecode = "decode";
		return 0;
	}

	return 1;
}

int test_message(char *message,long fileLength)
{
	int messageLength = strlen(message);
	int ktLength=(fileLength/8)-128;

	if(ktLength<messageLength)
	{
		printf("too short message");
		return 0;
	}

	return 1;
}

void collect_message(int numberOfArguments,char *message[])
{
	int lengthOfMessage= numberOfArguments- 2;
	int i;

	if((secretMessage= malloc(100*sizeof(char)))==NULL)
	{
		printf("cannot locate memero");
		exit(EXIT_FAILURE);
	}
	for(i=2;i<lengthOfMessage;++i)
	{
		strcpy(secretMessage,"");
		strcpy(secretMessage,message[i]);
	}

	strcpy(secretMessage,"\0");

}
