#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct libr {
char bookname[128];
char authors[128];
char clientfullname[128];
char bookpresence[128];
char clientphonenumber[128];
char clientaddress[128];
char bookcopies[128];
};

void work(int number,struct libr *p){
int i=1;
while (i<=number){
printf ("#%d \n",i);
printf("Title of the book: ");
scanf("%s", p[i].bookname);
printf("Authors: ");
scanf("%s", p[i].authors);
printf("Client's full name: ");
scanf("%s", p[i].clientfullname);
printf("Book presence: ");
scanf("%s", p[i].bookpresence);
printf("Client's phone number: ");
scanf("%s", p[i].clientphonenumber);
printf("Client's address: ");
scanf("%s", p[i].clientaddress);
printf("Number of book copies: ");
scanf("%s", p[i].bookcopies);
getchar ();
i++;
}
}

void base() {
struct libr *p;
p=(struct libr *)malloc(sizeof(struct libr));
int i=1;
int otvet;
int number;
int number1=number;
while (otvet != 1){
printf ("Enter number of books\n");
scanf ("%d",&number);
work (number,p);
printf("Print the data?\n");
printf("1. Yes\n");
printf("2. No\n");
scanf ("%d",&otvet);
i=1;
system ("clear");
}
int g=1;
while (g<=number){
printf("#%d\n",g);\
printf("Title of the book: %s\n",p[g].bookname);
printf("Authors: %s\n",p[g].authors);
printf("Client's full name: %s\n",p[i].clientfullname);
printf("Book presence: %s\n",p[g].bookpresence);
printf("Client's phone number: %s\n",p[i].clientphonenumber);
printf("Client's address: %s\n", p[g].clientaddress);
printf("Number of book copies: %s\n",p[g].bookcopies);
g++;
}
g=1;
printf("\nPress 'enter' to exit");
getchar();getchar();
}

int main() {
int way=0;
while ((way !=2)&&(way !=1)){
printf ("Melnikov Alexander Nikolaevich\n");
printf ("MR-71\n");
printf ("Lab work #6\n");
printf ("Library data structure\n");;
printf("1. Enter the data\n");
printf("2. Exit \n");
scanf("%d" ,&way);
system ("clear");
}
switch (way)
{
case 1:
base ();
break;
case 2:
break;
}
return 0;
} 
