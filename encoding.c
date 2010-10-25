#include "encoding.h"

void hop_over_header(FILE *encFile)
{
	int *headerLength = 0;
	
	fseek(encFile,0xA,SEEK_SET);
	fread(headerLength,4,1,encFile);
	fseek(encFile,&headerLength, SEEK_SET);
}

int  encode(FILE *encFile,char *message)
{
	int i,j;
	int * binaryForm;
	unsigned int bit[1];
	
	hop_over_header(encFile);	

	for(i=0;i<sizeof(message);i++)
	{
		binaryForm = (int*)convert_binary(message[i]);
		
		for(j=0;j<sizeof(binaryForm);j++)
		{	
			bit[0]=binaryForm[i];
			if(fwrite(bit[0],1,8,encFile)!=8)
				return 0;
		}
	}
	return 1;
}

int *convert_binary(char j)
{
	int *bin;
	int n = (int)j;
	int i=0;

	if((bin=(int*)malloc(8*sizeof(int)))==NULL)
	{
		exit(EXIT_FAILURE);
	}
	
	
	for(i=0;n!=0;i++)
	{
    		bin[i]=n%2;
    		n=n/2;
	}

	return bin;

}

