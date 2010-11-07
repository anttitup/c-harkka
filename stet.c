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
	char * secretMessage;

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

	if((fileHandler=fopen(argv[1],"r+"))!=NULL)
	{	
		secretMessage = collect_message(argc,argv);
		read_file(fileHandler, secretMessage);
	}
	else 
	{
		printf("wrong message");
		return EXIT_FAILURE;
	}

	printf("it works");
	return EXIT_SUCCESS;
}

int read_file(FILE *input, char * secretMessage)
{
	
	if(strcmp(encodeOrDecode,"encode")==0)
	{
		printf("message here is:%s \n",secretMessage);

		if(encode(input,secretMessage))
		{
				printf("we encoded message in picture\n");
				return 1;
		}
	}
	else
	{	
		printf("message was\n");
		decode(input);	
	}


	return 1;
}

long how_long_file(FILE *fileHandle)
{
	fseek(fileHandle,0L,SEEK_END);
	return ftell(fileHandle);
}

int test_parameter(char *parameter)
{
	if(strcmp(parameter,"encode")==0)
	{
		encodeOrDecode = "encode";
		return 0;
	}

	else if(strcmp(parameter,"decode")==0)
	{
		encodeOrDecode = "decode";
		return 0;
	}
	else
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

char * collect_message(int numberOfArguments,char *message[])
{
	int lengthOfMessage= numberOfArguments;
	int i;
	int length=0;
	char * secretMessage;
	char * vali= " ";
	
	for(i=3;i<lengthOfMessage;++i)
	{
		length+=strlen(message[i]);
	}
	
	length+=i;

	if((secretMessage= malloc(length  * sizeof(char)))==NULL)
	{
		printf("cannot locate memory");
		exit(EXIT_FAILURE);
	}
	
	
	for(i=3;i<lengthOfMessage;++i)
	{
		strcat(secretMessage,message[i]);
		strcat(secretMessage,vali);
	}

	if(length>=255)
	{
		printf("message is bigger than 100 charechters exiting...");
		exit(EXIT_FAILURE);
	}

	return secretMessage;
}

void hop_over_header(FILE *encFile)
{
	int headerLength = 0;
	
	fseek(encFile,0xA,SEEK_SET);
	fread(&headerLength,4,1,encFile);
	fseek(encFile,headerLength, SEEK_SET);
}
