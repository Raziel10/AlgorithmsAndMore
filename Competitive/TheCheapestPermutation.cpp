#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
//The Cheapest Permutation problem


void FindCheapestPermutation2(int costs[9][9], vector<int> a, int level, vector<int>& min, int* minPermutationCost){
    
    int permutationCost = 0;
    int size = a.size();
    if (size == level) 
    { 
        for(int i = 0; i < size - 1; i++){
            int row = (a.at(i))-1;
            int column = (a.at(i+1))-1;
            permutationCost += costs[row][column];
        }
        if (permutationCost < *minPermutationCost){
            *minPermutationCost = permutationCost;
            min.assign(a.begin(), a.end());
        }
    } 
    
    for (int i=level; i<size; i++) 
    { 
        swap(a[level], a[i]);
        FindCheapestPermutation2(costs,a,level + 1, min , minPermutationCost); 
        swap(a[level], a[i]); 
    }
} 

int main(void){
    int n;
    int Costs[9][9] = {0};
    int PermutationCost = 0;
    int minPermutationCost = 65000;
    vector<int> a;
    vector<int> m;
    
    cin >> n;
    //create original permutation with all values
    for(int k = 1; k <= n; k++){
        a.push_back(k);
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> Costs[i][j];
        }
    }
    FindCheapestPermutation2(Costs, a, 0, m, &minPermutationCost);
    for(int i = 0; i < n; i++){
        cout << m[i] << " ";
    }
}

