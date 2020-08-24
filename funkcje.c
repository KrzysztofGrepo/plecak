#include "funkcje.h"
int knapSackRec(int W, int wt[], int val[], int n) 
{ 
    // Implementacja rekurencyjna.
    if (n == 0 || W == 0) 
        return 0; 

    // Odrzucanie przedmiotów nie mieszcz¹cych siê do plecaka.
    if (wt[n - 1] > W) 
        return knapSackRec(W, wt, val, n - 1); 
  
 	// Drzewo BST.
    else
        return max( 
            val[n - 1] + knapSackRec(W - wt[n - 1], wt, val, n - 1), 
            knapSackRec(W, wt, val, n - 1)); 
} 
int knapSackDyn(int W, int wt[], int val[], int n) 
{ 
	// Implementacja dynamiczna.
	int i, w; 
	int K[n + 1][W + 1]; 

	// Wype³nienie tablicy dwuwymiarowej oraz szukanie
	// maksimum spe³niaj¹cego warunki.
	for (i = 0; i <= n; i++) { 
		for (w = 0; w <= W; w++) { 
			if (i == 0 || w == 0) 
				K[i][w] = 0; 
			else if (wt[i - 1] <= w) 
				K[i][w] = max( 
					val[i - 1] + K[i - 1][w - wt[i - 1]], 
					K[i - 1][w]); 
			else
				K[i][w] = K[i - 1][w]; 
		} 
	} 
	return K[n][W]; 
} 
// Funkcja zwracaj¹ca wiêksz¹ liczbê.
int max(int a, int b) 
{ 
	return (a > b) ? a : b; 
} 
