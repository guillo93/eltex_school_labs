#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

void fillfile(int n){
int i;
FILE *world;
world=fopen("text.txt", "r+");

printf ("Введите количество символов\n");
scanf("%d",&n);
char text[n];
for (i=0;i<n;i++) {
text[i]=rand()%126;
}
fclose(world);
}

void printfile(){
FILE *world;
world=fopen("text.txt", "r+");
char ch;
while ((ch=getc (world)) != EOF) {
printf ("%c", ch);
printf ("\n");
}
}

void printstring(int n) {
FILE *world;
world=fopen("text.txt", "r+");
char* string;
string=(char *)malloc(sizeof(char));
printf ("Введите подстроку\n");
scanf("%s",string);
if (fgets(string,n,world) != NULL) {
printf("%s\n", string);
}
}

void main() {
int content, w=1;
int n;
while (w == 1) {
system ("clear");
printf ("Мельников Александр Николаевич\n");
printf ("МР-71\n");
printf ("Лабораторная работа №6\n");
printf ("Война и мир\n");
printf ("1. Запонить файл\n");
printf ("2. Прочитай файл и вывести на экран\n");
printf ("3. Найти в файле указанную подстроку и вывести на экран \n");
scanf ("%d", &content);
switch (content) {
case 1:
system ("clear");
fillfile(n);
break;
case 2:
system ("clear");
printfile();
break;
case 3:
system ("clear");
printstring(n);
break;
}
system ("clear");
printf("1. Back to menu\n");
printf("2. Exit \n\n");
scanf("%d", &w);
}
system ("clear");
}

