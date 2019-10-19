#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void program1(char *old_file_name, char *string_count, FILE *f_old){
	printf("Old file name is %s\n", old_file_name);
	char new_file_name[128];
	if (strchr(old_file_name, '.') != NULL){
		strcpy(new_file_name, strtok(old_file_name, "."));
		char format[8];
		strcpy(format, strtok(NULL, "."));
		if (strcmp(format, "txt") == 0){
			strcat(new_file_name, ".html");			
		}
		else{
			strcat(new_file_name, ".txt");
		}
	}
	else{
		strcpy(new_file_name, old_file_name);
		strcat(new_file_name, ".txt");	
	}
	printf("New file name is %s\nContent:\n", new_file_name);
	FILE *f_new=fopen(new_file_name, "w");
	int count=atoi(string_count);
	char buffer[1024];
	int i=0;
	while(!feof(f_old)){
		fgets(buffer, 1024, f_old);
		int numb_detect=0;
		if (i < count){
			for(int k=0; k < strlen(buffer); k++){
				if (isdigit(buffer[k]) != 0){
					numb_detect=1;
				}
			}
			if (numb_detect == 0){
				fputs(buffer, f_new);
				printf("%s", buffer);
			}
		}
		else{
			fputs(buffer, f_new);
			printf("%s", buffer);
		}
		i++;
	}
	if(fclose(f_new)){
		printf ("Error closing new file\n");
		exit(1);
	}
}

int main(int argc, char *argv[]){
	system ("clear");
	FILE *f;
	if (argc < 3){
		printf ("Invalid number of parameters\n");
		exit(1);
	}
	if ((f=fopen(argv[1], "r"))==NULL){
		printf ("Can't open file\n");
		exit(1);
	}
	program1(argv[1], argv[2], f);
	if(fclose(f)){
		printf ("Error closing old file\n");
		exit(1);
	}
	return 0;
}
	
