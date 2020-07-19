#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

void Insertion(int n, int A[])
{
int i, newelement, location;
for (i = 1; i < n; i++)
{
newelement = A[i];
location = i - 1;
while(location >= 0 && A[location] > newelement)
{
A[location+1] = A[location];
location = location - 1;
}
A[location+1] = newelement;
}
}

void sort1() {
int n, i;
printf ("\nВведите число элементов \n");
scanf ("%d", &n);
int A[n];
for (i=0; i < n; i++)
{
printf ("A[%d]=", i);
scanf ("%d", &A[i]);
}
printf ("\n");
Insertion(n, A);
for (i=0; i < n; i++)
{
printf ("%d ", A[i]);
}
printf ("\n");
}

void sort2() {
int n, i;
printf ("\nВведите число элементов \n");
scanf ("%d", &n);
int A[n];
int *rpt;
rpt = A;
for (; rpt-A < n; rpt++)
{
i = rpt-A;
printf ("A[%d]=", i);
scanf ("%d", rpt);
}
printf ("\n");
Insertion(n, A);
for (rpt=A; rpt-A < n; rpt++)
{
printf ("%d ", *rpt);
}
printf ("\n");
}

void sort3() {
int n, i;
printf ("\nВведите число элементов \n");
scanf ("%d", &n);
int* A;
A = (int*) malloc(sizeof(int)*n);
for (i=0; i < n; i++)
{
printf ("A[%d]=", i);
scanf ("%d", &A[i]);
}
printf ("\n");
Insertion(n, A);
for (i=0; i < n; i++)
{
printf ("%d ", A[i]);
}
printf ("\n");
free(A);
}

int main () {
int sort;
system ("clear");
printf ("Мельников Александр Николаевич \n");
printf ("МР-71 \n");
printf ("Лабораторная работа №3 \n");
printf ("Сортировка одномерного массива по возрастанию элементов \n");
printf ("Выберите тип сортировки: \n");
printf ("1. Вставками \n");
printf ("2. Используя указатели \n");
printf ("3. Используя динамическое выделение памяти \n");
scanf ("%d", &sort);

switch (sort) 
{
case 1:
sort1();
break;

case 2:
sort2();
break;

case 3:
sort3();
break;

default:
break;
}

return 0;
}
