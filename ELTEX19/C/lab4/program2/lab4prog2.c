#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

void program2(char *file_name, char *insert_count, FILE *f_in, FILE *f_out){
	printf("File name is %s\nUpdate content:\n", file_name);
	int count=atoi(insert_count);
	char ch;
	int i=0;
	while ((ch=fgetc(f_in)) != EOF){
		fputc(ch, f_out);
		printf("%c", ch);
		if (ch == '.' && i < count){
			fputc('\n', f_out);
			printf("\n");
			i++;
		}
	}
}

int main(int argc, char *argv[]){
	system ("clear");
	if (argc < 3){
		printf ("Invalid number of parameters\n");
		exit(1);
	}
	FILE *f_in=fopen(argv[1], "r"), *f_out=fopen(argv[1], "r+");
	if (f_in == NULL || f_out == NULL){
		printf ("Can't open file\n");
		exit(1);
	}
	program2(argv[1], argv[2], f_in, f_out);
	if(fclose(f_in) || fclose(f_out)){
		printf ("Error closing file\n");
		exit(1);
	}
	return 0;
}
	
