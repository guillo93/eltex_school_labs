#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

char** read_mas(int count){
	char buffer[1024];
	char **mas;
	mas = (char **)malloc(sizeof(char *)*count);
	for (int i=0; i < count; i++){
		printf ("Srting %d: ", i);
		fgets(buffer, 1024 ,stdin);
		mas[i]= (char *)malloc(sizeof(char)*(strlen(buffer)-1));
		strncpy(mas[i], buffer, strlen(buffer)-1);
	}
	return mas;	
}

int words_count(char *str){
	int words=1;
	for (int i=0; str[i]!='\0'; i++){ 
		if (str[i]==' '){
			words++;
		}
	}
	return words;
}

int swap=0;//quantity of insertion

char** sort(char **mas, int count){
	int i=0, swap_detect=0;
	char *buffer;
	while (i < count){
		if (i+1 != count && words_count(mas[i]) < words_count(mas[i+1])){
			buffer=mas[i];
			mas[i]=mas[i+1];
			mas[i+1]=buffer;
			swap_detect=1;
			swap++;
		}
		i++;
		if (i == count && swap_detect == 1){
			swap_detect=0;
			i=0;
		}
	}
	return mas;
}

void print_mas(char **mas, int count){
	printf ("\nSorted strings:\n");
	for (int i=0; i < count; i++){
		printf("%s\n", mas[i]);
	}
	printf ("\nQuantity of insertion: %d", swap);
	printf ("\nMaximum quantity of words in string: %d\n", words_count(mas[0]));
}

void free_mas(char **mas, int count){
	for (int i=0; i < count; i++){
		free(mas[i]);
	}
	free(mas);
}

int main (int argc, char **argv){
system ("clear");
printf ("Sorting strings of descending quantity of words\n");
char **mas = NULL;
int count;
printf ("Enter quantity of strings\n");
scanf ("%d", &count);
getchar();//eating '\n'
if (count>0){
	mas=read_mas(count);
	mas=sort(mas, count);
	print_mas(mas, count);
	free_mas(mas, count);
}
else{
	printf ("Quantity of strings must be greater than zero\n");
}
return 0;
}
