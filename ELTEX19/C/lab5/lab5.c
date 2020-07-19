#include <stdio.h>
#include <string.h>
#include <malloc.h>


//lib//str_oper.h
//char str1[]="1234";
//char str2[]="56";
//int sep=2;
//char *strstitch(str1, str2)//out//123456//like strcat
//char *strbreak(str1, sep, str2)//out//123564//into str1 past str2 after separator - 
//pointer for position

char* strstich(char *str1, char *str2){
	size_t len1=strlen(str1);
	size_t len2=strlen(str2);
	char *result=malloc(len1+len2+1);
	if (!result){
		fprintf(stderr, "malloc() failed: insufficient memory!\n");
		return NULL;
	}
	memcpy(result, str1, len1);
	memcpy(result + len1, str2, len2 + 1);
	
	return result;
	free(result);
}
/*
char strbreak(char str1, char str2){
	
	
	return str1;
}
*/
int main(){
	char str1[]="1234";
	char str2[]="56";
	//int sep=2;
	printf("strstitch=%s\n", strstich(str1,str2));
	//printf("strsbreak=%s\n", strbreak(str1,sep,str2));
	return 0;
}
	
