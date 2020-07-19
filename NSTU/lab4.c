#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

int main()
{
int content, i, j, w=1;
char* word;
word = (char *)malloc(sizeof(char));
	while (w==1){
	system ("clear");
	printf ("Melnikov Alexander Nikolaevich \n");
	printf ("MR-71 \n");
	printf ("Lab work #4 \n");
	printf ("Delete all letters 'я' in the word \n");
	printf ("1. Enter the word and perform the task \n");
	printf ("2. Exit \n\n");
	scanf ("%d",&content);
	switch (content) {
		case 1:
			system ("clear");
			printf("Enter the word \n\n");
			scanf("%s",word);	
			system ("clear");
			for(i=0;i<strlen(word);i++){
				if(word[i]=='a'){
					for(j=i;j<strlen(word);j++){
					word[j]=word[j+1];
					}	
				}
			}
			printf("Result: \n");
			printf("%s \n\n",word);
		break;
		case 2:
			system ("clear");
			exit(0);
	}
	printf("1. Back \n");
	printf("2. Exit \n\n");
	scanf("%d",&w);
	}
	system ("clear");
	return 0;
}
