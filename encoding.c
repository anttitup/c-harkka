#include "encoding.h"

int  encode(FILE *encFile,char *message)
{
	int j,i;
	int * binaryForm;
	unsigned char bits[1];
	fpos_t pos;
	int length;

	hop_over_header(encFile);	
	length = strlen(message);
	
	binaryForm = convert_binary(length);
	
	for(j=0;j<=7;++j)
	{	
			fgetpos(encFile,&pos);	
			if(fread(bits,1,8,encFile)!=8)
			{
				fflush(encFile);
				printf("message is too long cannot write");
				exit(EXIT_FAILURE);
			}
	
			fsetpos(encFile,&pos);

			if(binaryForm[j])
			{
				bits[0] |= 1 << 0;
			}

			else
			{
				bits[0] &= ~(1 << 0);
			}

			if((fwrite(bits,1,8,encFile))!=8)
			{
				printf("message is too long cannot write");
				fflush(encFile);
				exit(EXIT_FAILURE);
			}
	}
	
	free(binaryForm);
	binaryForm = NULL;	

	for(i=0;i<strlen(message);i++)
	{
				
		binaryForm = convert_binary(message[i]);
		for(j=0;j<=7;++j)
		{	
			fgetpos(encFile,&pos);	
			if(fread(bits,1,8,encFile)!=8)
			{
				fflush(encFile);
				printf("message is too long cannot write");
				exit(EXIT_FAILURE);
			}
	
			fsetpos(encFile,&pos);

			if(binaryForm[j])
			{
				bits[0] |= 1 << 0;
			}

			else
			{
				bits[0] &= ~(1 << 0);
			}

			if((fwrite(bits,1,8,encFile))!=8)
			{
				printf("message is too long cannot write");
				fflush(encFile);
				exit(EXIT_FAILURE);
			}
		}
			free(binaryForm);
			binaryForm = NULL;	
	}

	free(message);
	message=NULL;		
	fclose(encFile);
	encFile = NULL;
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
	
   for( i = 7; i >= 0; i--)        
   {
        if( (1 << i) & n)
           bin[7 - i] = 1;
        else
           bin[7 - i] = 0;
   }

	return bin;

}


