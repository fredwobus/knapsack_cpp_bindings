#include <bits/stdc++.h> 
#include "knapsack.hpp"

using namespace std; 

// Driver code 
int main() 
{ 
	int profit[] = { 60, 90, 120, 80 }; 
	int weight[] = { 10, 20, 30, 15 }; 
	int W = 40; 
	int n = sizeof(profit) / sizeof(profit[0]); 

        cout << "profit:";
        for (int i = 0; i < n; i++) 
            cout << "\t" << profit[i];
        cout << endl;

        cout << "weight:";
        for (int i = 0; i < n; i++) 
            cout << "\t" << weight[i];
        cout << endl;

        cout << "Max value that can be put into the knapsack of size " << W << ":" << endl;
	cout << knapSack(W, weight, profit, n) << endl; 
	return 0; 
} 

