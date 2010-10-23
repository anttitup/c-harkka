#include <stdio.h>
#include <stdlib.h>
#include<string.h>


void Hop_over_header(FILE *encodeThisFile)
{
	int headerLength = 0;
	
	fseek(encodeThisFile,0xA,SEEK_SET);
	fread(headerLength,4,1,encodeThisFile);
	fseek(encodeThisFile,&headerLength, SEEK_SET);
}

int  encode(FILE encodeThisFile,char *message)
{
	int i,j;
	int * bin;
	unsigned char bit;

	for(i=0;i<sizeof(message);i++)
	{
		bin =(int*)convert_binary(message[i]);
		
		for(j=0;j<sizeof(bin);j++)
		{
			if(fwrite(bin[i],1,8,encodeThisFile)!=8)
				return 0;
		}
	}
	return 0;
}

char *convert_binary(char i;)
{
	int *bin;
	int n = (int)i;
	int i=0;

	if((bin=(int*)malloc(8*sizeof(int)))==NULL)
	{
		exit(EXIT_FAILURE);
	}
	
	
	for(i;n!=0;i++)
	{
    		bin[i]=n%2;
    		n=n/2;
	}

	return bin;

}

int convert_decimal(int *bin)
{
   	int i,integer=0 ;
	for(i=sizeof(bin);i>sizeof(bin);i--)
   	{
		integer=integer + bin[i]*(int)pow(2,bin[i]);
	}
	return integer;
}
