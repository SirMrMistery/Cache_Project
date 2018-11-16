#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char *decimal_to_binary(int x,int n)
{
	int c, d, count;
	char *pointer;
		     
	count = 0;
	pointer = (char*)malloc(32+1);
				      
	if (pointer == NULL)
		exit(EXIT_FAILURE);
								        
										
	for (c = x-1 ; c >= 0 ; c--)
	{
		d = n >> c;
		if (d & 1)
			*(pointer+count) = 1 + '0';
		else
			*(pointer+count) = 0 + '0';
																								        
		count++;
	}
	*(pointer+count) = '\0';
																														   
	return  pointer;
}

int main(int argc, char *argv[]){

	if(argc != 2){
		printf("INCORRECT # OF PARAMETERS\n");
		return 0;

	}

	FILE *fp;

	char buffer[255];
	fp = fopen("1KB_64B", "r");

	//while (fscanf(fp, "%s", buffer) == 1) // expect 1 successful conversion
	while (fgets(buffer, sizeof buffer, fp) != NULL)
	{
		  printf("-------------------\n%s \n\n",buffer);

		  char *computer;
		  char *action;
		  char *address;
		  int i = 0;


		    char *temp = strtok (buffer," :,.-");
			while (temp != NULL)
			{
				printf ("%s\n",temp);
				

				if(i==2){

					int k;
					int decimal;
					unsigned long L, M;
					char *bin = "";

   					
					sscanf(temp,"%x",&decimal);


					L = decimal & 0x7f;

					printf("%lu \n",L);

					printf("%s \n",decimal_to_binary(7,L));

					M = decimal >> 7;

					printf("%s \n",decimal_to_binary(25,M));



					printf("******* \n-------------------\n");	
					

				}
				temp = strtok (NULL, " :,.-");

				++i;
			}

	}
	if (feof(fp)) 
	{
		  printf("End of FILE! \n");
	}
	else
	{
		  printf("ERROR! \n");
		  return -1;
	}
	printf("Hello, World! \n");	
	printf("%d\n",argc);
	return 0;
}

