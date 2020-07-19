#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

void occur(char* word1, char* letter, char* word2) {
	int i, j, s1=0, s2=0, s3=0;
	for(i=0;i<strlen(word1);i++) {
		if(word1[i] == letter[0]) {
		s1=s1+1;
		}
	}
	char *a;
	a = strstr(word1, word2);
	while (a != NULL) {
		s2=s2+1;
		for(i=0;i<strlen(word2);i++){
			for(j=i; j<strlen(a); j++){
				a[j]=a[j+1];
			}
			a=strstr(a, word2);
		}
	}
	char bcd[42]="BCDFGHJKLMNPQRSTVWXYZbcdfghjklmnpqrstvwxyz";
	for(i=0; i<strlen(word1); i++) {
		for(j=0; j<42; j++) {
			if(word1[i] == bcd[j]) {
			s3=s3+1;
			}
		}
	}
	printf("The occurences of letter-word_2-consonant_letters \n");
	printf("%d-%d-%d \n", s1, s2, s3);
}

void main()
{
int content, w=1;
char* word1;
word1 = (char *)malloc(sizeof(char));
char letter[1];
char* word2;
word2 = (char *)malloc(sizeof(char));
	while (w == 1) {
	system ("clear");
	printf ("Melnikov Alexander Nikolaevich \n");
	printf ("MR-71 \n");
	printf ("Lab work #5 \n");
	printf ("Counting the occurences of a letter, ");
	printf ("word 2, consonant letters into word 1 \n");
	printf ("1. Enter the words and perform the task \n");
	printf ("2. Exit \n\n");
	scanf ("%d", &content);
	switch (content) {
		case 1:
			system ("clear");
			printf("Enter the word 1\n\n");
			scanf("%s", word1);	
			system ("clear");
			printf("Enter the letter\n\n");
			scanf("%s", letter);	
			system ("clear");
			printf("Enter the word 2\n\n");
			scanf("%s", word2);
			occur(word1, letter, word2);
		break;
		case 2:
			system ("clear");
			exit(0);
	}
	printf("1. Back \n");
	printf("2. Exit \n\n");
	scanf("%d", &w);
	}
	system ("clear");
}
