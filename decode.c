#include "decode.h"

int decode(FILE *decFile)
{
	unsigned char bits[1];
	unsigned char mark = '\0';
	int i=1;
	int firstTime=1;
	unsigned int length=0,counter=0;
	hop_over_header(decFile);	
	
	printf("ei ainakaan täällä\n");

	while(fread(bits,1,8,decFile)==8)
	{
		if((bits[0] & (1 << 0)))
		{		
			mark |= 1 << (8-i);
		}
		else{
			mark &= ~(1<< (8-i));
		}

		if(i==8){
			i=0;
			if(firstTime)
			{
				firstTime=0;
				length=mark;	
			}
			else
			{
				printf("%c",mark);
				counter++;
			}
			
			if(length==counter)
				break;
			
			mark='\0';
		}		
		i++;
	}
	fclose(decFile);
	decFile=NULL;
	return 1;
}

