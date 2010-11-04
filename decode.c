#include "decode.h"

char * decode(FILE *decFile)
{
	unsigned char n=0;
	unsigned char bits[1];
	char mark = 1;
	char *message;
	int i=0;

	if((message = (char *) malloc(100*sizeof(char)))==NULL)
	{
		exit(EXIT_FAILURE);
	}

	hop_over_header(decFile);	
	
	printf("ei ainakaan täällä");
	while(fread(bits,1,8,decFile)==8)
	{
		mark=0;
		printf("bits: %d",bits[0]);
		
		for (n= 0; n< 8; n++)
      		mark |= (bits[n] & 1) << n;

		printf("mark:%d",mark);	
		if(mark=='\0')
			break;
		if(i>9)
			break;
		i++;
		printf("mark:%c",mark);
	}
	return message;
}
char binary_to_dec(char binaryForm[])
{
	char mark;
	int n;
	for (n= 0; n< 8; n++)
      mark |= (binaryForm[n] & 1) << n;
	printf("message... %c",mark);
	return mark;	
}
