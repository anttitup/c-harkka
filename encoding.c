#include "encoding.h"

void hop_over_header(FILE *encFile)
{
	int headerLength = 0;
	
	fseek(encFile,0xA,SEEK_SET);
	fread(&headerLength,4,1,encFile);
	fseek(encFile,headerLength, SEEK_SET);
}

int  encode(FILE *encFile,char *message)
{
	int i,j;
	char * binaryForm;
	char const mask = 1<<7; 
	
	unsigned char bits[1];	
	hop_over_header(encFile);	
	printf("message: %s \n",message);

	for(i=0;i<strlen(message);i++)
	{
		binaryForm = convert_binary(message[i]);
		
		for(j=0;j<8;j++)
		{	
			printf("mask:%d \n",mask);
			fread(bits,1,8,encFile);
			printf("%d",bits[0]);
			if((int)binaryForm[j])
				bits[0] =bits[0] | mask;
			else
				bits[0] = bits[0] & ~mask;

			printf("%d",bits[0]);
			fwrite(bits,1,8,encFile);
		}
		free(binaryForm);
		
	}
	return 1;
}

char *convert_binary(char j)
{
	char *bin;
	int n = (int)j;
	int i=0;
	printf("\nn is %d\n",n);

	if((bin=(char*)malloc(8*sizeof(char)))==NULL)
	{
		exit(EXIT_FAILURE);
	}
	
   for( i = 7; i >= 0; i--)        
   {
        if( (1 << i) & n)
           bin[7 - i] = '1';
        else
           bin[7 - i] = '0';                   
   }
	return bin;

}

