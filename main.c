/** \file main.c
 * Main project file.
 * Reads file, checks data, stores values and calls out funtions.
 */
#include <stdio.h> 
#include "funkcje.h"
#include <time.h>
int main(int argc, char** argv[])
{ 
	int* ptrW;
	int* ptrV;
	int i=0, n, W;
	char m;
	double time_taken;
 	clock_t t; 
 	
	FILE* fp;
	fp = fopen(argv[2], "r");
	if (fp == NULL)
	{
		printf("Error while opening the file.\n");
		exit(0);
	}
	else 
		{
		if (fp) {
			while (!feof(fp)) {
				i++;
				if(fscanf(fp, "%d", &n)==0){
					printf ("Entered input is incorrect.\n");
					fclose(fp);
    				exit(1);
			}
		}
	}
}
i=i-2;
i=i/2;
printf(" %d \n", i);

	fp = fopen(argv[2], "r");
	if (fp == NULL)
	{
		printf("Error while opening the file.\n");
		exit(0);
	}
	else {
		if (fp) {
			while (!feof(fp)) {
				fscanf(fp, "%d", &n);
				fscanf(fp, "%d", &W);
				printf(" %d \n", n);
				if(i!=n){
					printf ("Entered input is incorrect.\n");
    				exit(1);
}	
				ptrW = (int*)malloc(n * sizeof(int));
				ptrV = (int*)malloc(n * sizeof(int));
				
				if (ptrW == NULL) {
					printf("Memory not allocated.\n");
					free(ptrW);
					free(ptrV);
					exit(0);
				}
				if (ptrV == NULL) {
					printf("Memory not allocated.\n");
					free(ptrW);
					free(ptrV);
					exit(0);
				}
				for (i = 0; i < n; ++i) {
					fscanf(fp, "%d", &ptrW[i]);
					fscanf(fp, "%d", &ptrV[i]);
			}
		}
	}
}

printf("The elements of the array are: \n");
for (i = 0; i < n; ++i) {
	printf("Item number %d, ", i + 1);
	printf("Weight %d, ", ptrW[i]);
	printf("Value %d, \n", ptrV[i]);
}
printf("Knapsack capacity set at:  %d \n", W);
while (m != '4') {
		printf( " \n"
		"Choose implementation: \n"
		"1. Recursive. \n"
		"2. Dynamic. \n"
		"3. Comparison. \n"
		"4. Exit. \n"
		" \n");
		scanf(" %c", &m);
	switch(m)
    {
        case '1':
            t = clock(); 
            printf("3. Recursive Output: %d \n", knapSackRec(W, ptrW, ptrV, n));
            t = clock() - t;
            time_taken = ((double)t)/CLOCKS_PER_SEC;
            printf("Recursive output took %f seconds to execute \n", time_taken);
            break;
			
        case '2':
             t = clock();
            printf("   Dynamic Output: %d \n", knapSackDyn(W, ptrW, ptrV, n));
            t = clock() - t;
            time_taken = ((double)t)/CLOCKS_PER_SEC;
             printf("Dynamic output took %f seconds to execute \n", time_taken);
            break;
		case '3':
	 		t = clock(); 
            printf("3. Recursive Output: %d \n", knapSackRec(W, ptrW, ptrV, n));
            t = clock() - t;
            time_taken = ((double)t)/CLOCKS_PER_SEC;
            printf("Recursive output took %f seconds to execute \n", time_taken);
            t = clock();
            printf("   Dynamic Output: %d \n", knapSackDyn(W, ptrW, ptrV, n));
            t = clock() - t;
            time_taken = ((double)t)/CLOCKS_PER_SEC;
             printf("Dynamic output took %f seconds to execute \n", time_taken);
            break;
        case '4':
            printf("4. Exit. \n");
			free(ptrW);
			free(ptrV);
			return 0;
            break;

        default:
           	printf("Wrong input. \n");
    }

}
fclose(fp);
free(ptrW);
free(ptrV);
return 0;

}
