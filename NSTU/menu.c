#include <stdio.h>
#include <stdlib.h>

void main () {
int content;
int subcontent;

void menu() {

void startmenu () {
system ("clear");
printf ("Menu \n");
printf ("Melnikov Alexander Nikolaevich \n");
printf ("MR-71 \n");
printf ("Lab work #1 \n");
printf ("1. Paragraph 1 \n");
printf ("2. Paragraph 2 \n");
printf ("3. Paragraph 3 \n");
printf ("4. Exit \n");
printf ("\n");
}

startmenu ();
scanf ("%d",&content);

}

transfer:
menu ();
switch (content) {
case 1:
transfer1:
system ("clear");
printf ("Paragraph 1 \n");
printf ("1) Subparagraph 1 \n");
printf ("2) Subparagraph 2 \n");
printf ("3) Back \n");
scanf ("%d",&subcontent);

switch (subcontent)
{
case 1:
system ("clear");
goto transfer1;
case 2:
system ("clear");
goto transfer1;
case 3:
system ("clear");
goto transfer;
default:
goto transfer1;
}

case 2:
system ("clear");
transfer2:
system ("clear");
printf ("Paragraph 2 \n");
printf ("1) Subparagraph 1 \n");
printf ("2) Subparagraph 2 \n");
printf ("3) Back \n");
printf ("\n");
scanf ("%d",&subcontent);

switch (subcontent)
{
case 1:
system ("clear");
goto transfer2;
case 2:
system ("clear");
goto transfer2;
case 3:
system ("clear");
goto transfer;
default:
goto transfer2;
}

case 3:
system ("clear");
transfer3:
system ("clear");
printf ("Paragraph 3 \n");
printf ("1) Subparagraph 1 \n");
printf ("2) Subparagraph 2 \n");
printf ("3) Back \n");
printf ("\n");
scanf ("%d",&subcontent);

switch (subcontent)
{
case 1:
system ("clear");
goto transfer3;
case 2:
system ("clear");
goto transfer3;
case 3:
system ("clear");
goto transfer;
default:
goto transfer3;
}

case 4:
system ("clear");
break;
default:
system ("clear");
goto transfer;

}

}
