#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

void newfile() {
char file[1024];
printf("Enter the name of file\n");
scanf("%s",file);
char format[]=".txt"; 
strcat(file,format);
printf("\n");
char* text;
text = (char *)malloc(sizeof(char));
printf("Enter the text \n");
scanf ("%s",text);
printf("\nSave? \n");
printf("1. Yes \n");
printf("2. No \n");
int i;
scanf("%d", &i);
if (i==1) {
FILE *f;
f=fopen (file,"w+");
fputs (text,f);
fclose (f);
}
}

void openfile() {
int a, pos, pos1, pos2;
char file[1024];
printf("Enter the name of file\n");
scanf ("%s",file);
FILE *f;
f=fopen (file,"ab");
char ch;
char* text;
text = (char *)malloc(sizeof(char));
int i=0;
while ((ch=getc (f)) != EOF) {
printf ("%c", ch);
text[i]=ch;
i=i+1;
}
printf("1. Past text\n");
printf("2. Delete text\n");
scanf("%d",&a);
if (a==1) {
printf("\nEnter the cursor position\n");
scanf ("%d",&pos);
printf("\nEnter the pasted text\n");
char* past;
past = (char *)malloc(sizeof(char));
scanf ("%s",past);
char text2[strlen(text)-pos-1];
for (i=pos+1;i<strlen(text);i++) {
text2[i-pos-1]=text[i];
}
text[pos+1]='\0';
strcat(text,past);
strcat(text,text2);
}
if (a==2) {
printf("\nEnter the fist cursor position\n");
scanf ("%d",&pos1);
printf("\nEnter the second cursor position\n");
scanf ("%d",&pos2);
char text2[strlen(text)-pos2-1];
for (i=pos2+1;i<strlen(text);i++) {
text2[i-pos2-1]=text[i];
}
text[pos1+1]='\0';
strcat(text,text2);
}
printf("\n%s", text);
printf("\nSave? \n");
printf("1. Yes \n");
printf("2. No \n");
scanf("%d",&i);
if (i==1) {
f=fopen(file,"wb");
fputs (text,f);
fclose (f);
}
}

void main() {
int content, w=1;
while (w == 1) {
system ("clear");
printf ("Melnikov Alexander Nikolaevich\n");
printf ("MR-71\n");
printf ("Lab work #6\n");
printf ("Text editor\n");
printf ("1. New file\n");
printf ("2. Open file\n");
printf ("3. Exit \n");
scanf ("%d", &content);
switch (content) {
case 1:
system ("clear");
newfile();
break;
case 2:
system ("clear");
openfile();
break;
case 3:
system ("clear");
exit(0);
}
system ("clear");
printf("1. Back to menu\n");
printf("2. Exit \n\n");
scanf("%d", &w);
}
system ("clear");
}
