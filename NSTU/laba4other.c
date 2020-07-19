#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
void pasto(char* word1){
	int i, j=0;
	char word2[2*strlen(word1)];
	for(i=0;i<2*strlen(word1);i++){
		word2[i]='o';
	}
	for(i=0;i<strlen(word1);i++){
		j=2*i;
		word2[j]=word1[i];
	}
	printf("Результат: \n");
	printf("%s \n\n",word2);
}
void main()
{
	int content, w=1;
	char* word1;
	word1=(char *)malloc(sizeof(char));


	while (w==1){
	system ("clear");
	printf ("Мельников Алесандр Николаевич\n");
	printf ("МР-71\n");
	printf ("Лабораторная работа №4\n");
	printf ("Вставить после каждой буквы данного слова букву 'о'\n");
	printf ("1. Ввести параметры и выполнить задание\n");
	printf ("2. Выход \n\n");
	scanf ("%d",&content);
	switch (content) {
		case 1:
			system ("clear");
			printf("Введите слово\n\n");
			scanf("%s",word1);	
			system ("clear");			
			pasto(word1);
		break;
		case 2:
			system ("clear");
			exit(0);
	}
	printf("1. Повторить \n");
	printf("2. Выход \n\n");
	scanf("%d",&w);
	}
	system ("clear");
}
