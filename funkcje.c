/** \file funkcje.c
 * Function file.
 * Contatins definitions of functions.
 */
#include "funkcje.h"
///Knapsack - recurention version.
///
///Funtion uses recurention to make a binary tree, which it searches for the best outcome.
int knapSackRec(int W, int wt[], int val[], int n) 
{ 
    if (n == 0 || W == 0) 
        return 0; 

    if (wt[n - 1] > W) 
        return knapSackRec(W, wt, val, n - 1); 
  
    else
        return max( 
            val[n - 1] + knapSackRec(W - wt[n - 1], wt, val, n - 1), 
            knapSackRec(W, wt, val, n - 1)); 
} 
///Knapsack - dynamic version.
///
///Builds dynamic 2d array in bottom up manner .
int knapSackDyn(int W, int wt[], int val[], int n) 
{ 
	int row = W+1, col=n+1;
	int i, w; 
	int **array;
	array = malloc(sizeof(int*)*col);
	for(i=0; i<col;i++){
		array[i] = malloc(sizeof(int)*row);
	}
	
		for (i = 0; i <= n; i++) { 
			for (w = 0; w <= W; w++) { 
				if (i == 0 || w == 0) 
					array[i][w] = 0; 
				else if (wt[i - 1] <= w) 
					array[i][w] = max( 
						val[i - 1] + array[i - 1][w - wt[i - 1]], 
						array[i - 1][w]); 
				else
					array[i][w] = array[i - 1][w]; 
					
			}}
		w =  array[n][W]; 	
		free(array);
		return w;
}
 ///Maximum.
///
///Defining this function allows us to not include additional libraries.
int max(int a, int b) 
{ 
	return (a > b) ? a : b; 
} 
