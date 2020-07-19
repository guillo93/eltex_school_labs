#include <stdio.h>
#include <stdlib.h>

int NOD (int m, int n)
{
int div;
if (m==n)
{
return n;
}
int d=n-m;
if (d<0)
{
d=-d;
div=NOD(n,d);
}
else
{
div=NOD(m,d);
return div;
}
}

void main () {
int content, subcontent;
int m, n, i;

void menu() {

void startmenu () {
system ("clear");
printf ("Menu \n");
printf ("Melnikov Alexander Nikolaevich \n");
printf ("MR-71 \n");
printf ("Lab work #2 \n");
printf ("Find all common divisors for m and n \n");
printf ("1. Enter parameters \n");
printf ("2. Perform a task \n");
printf ("3. Exit \n");
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
printf ("Enter parameters \n");
printf ("1) Enter m \n");
printf ("2) Enter n \n");
printf ("3) Back \n");
scanf ("%d",&subcontent);

switch (subcontent)
{
case 1:
scanf ("%d",&m);
system ("clear");
goto transfer1;
case 2:
scanf ("%d",&n);
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
printf ("Common divisors for %d and %d \n",m,n);
for (i=1; i <= NOD(m,n); i++)
{
int result=NOD(m,n)%i;
if (result==0)
{
printf ("%d ", i);
}
}
printf ("\n");
printf ("Push 1 for back \n");
printf ("\n");
scanf ("%d",&subcontent);

switch (subcontent)
{
case 1:
goto transfer;
default:
goto transfer2;
}

case 3:
system ("clear");
break;
default:
system ("clear");
goto transfer;

}

}
