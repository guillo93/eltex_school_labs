#include <stdio.h>
#include <string.h>

void main()
{
int i, j, s2=0;

char word1[]="1234";
char word2[]="12";
char *a;
a=strstr(word1, word2);
while (a!=NULL) {
	s2=s2+1;
	for(i=0;i<strlen(word2);i++){
		for(j=i;j<strlen(a);j++){
			a[j]=a[j+1];
		}
	a=strstr(a, word2);
	}
}
printf("%d \n", s2);
}
