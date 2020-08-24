#include <stdio.h> 
#include "funkcje.h"
int main() 
{   //Wska�niki oraz zmienne pomocnicze.
	int* ptrW;
	int* ptrV;
	int i,m,n,W;


	// U�ytkownik podaje ilo�� przedmiot�w.
	
	printf("Enter number of elements: ");
	scanf("%d",&n);
	printf("You entered: %d \n",n);
	// Zarezerwownie miejsca w pami�ci na tablice wagi i warto�ci.
	ptrW = (int*)malloc(n * sizeof(int));
	ptrV = (int*)malloc(n * sizeof(int));
	if (ptrW == NULL) {
		printf("Memory not allocated.\n");
		exit(0);
	}
	else {
		printf("Memory successfully allocated using malloc.\n");
		// U�ytkownik podaje dane przedmiot�w.
		for (i = 0; i < n; ++i) {
			printf("Please input weight of item number %d \n",i+1);
			scanf("%d", &ptrW[i]);
			printf("Please input value of item number %d \n", i+1);
			scanf("%d", &ptrV[i]);
		}
		// Wy�wietlanie listy przedmiot�w.
		printf("The elements of the array are: ");
		for (i = 0; i < n; ++i) {
			printf("Item number %d, ", i+1);
			printf("Weight %d, ", ptrW[i]);
			printf("Value %d, \n", ptrV[i]);
		}
	}
	//Podanie pojemno�ci plecaka oraz wyb�r implementacji.
	printf("Please input the knapsack weight capacity \n");
	scanf("%d", &W);
	printf("Knapsack capacity set at:  %d \n", W);
	m=0;
	while(m!=3){
	printf("Choose implementation: \n"
	"1. Recursive. \n"
	"2. Dynamic. \n"
	"3. Exit. \n");
	scanf ("%d", &m);
	if(m==1){
	printf("1. Output: %d \n", knapSackRec(W, ptrW, ptrV, n));}
	else{
	if(m==2){
	printf("2. Output: %d \n", knapSackDyn(W, ptrW, ptrV, n));}
	else{
	printf("Wrong input. \n");}
	}}
	free(ptrW);
	free(ptrV);
	return 0;
}
