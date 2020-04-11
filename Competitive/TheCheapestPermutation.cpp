#include <iostream>
#include <vector>

using namespace std;
//The Cheapest Permutation problem

int FindCheapestPermutation(int costs[9][9], vector<int> *a, int start, int  end){
    int permutationCost = 0;
    int returnedCost;
    if(start == end){
        //compute cost
        for(int i = 0; i < end; i++){
            int row = a->at(i)-1;
            int column = a->at(i+1)-1;
            
            permutationCost += costs[row][column];
        }
        //return cost
        return permutationCost;
    }

    for(int j = start; j <= end; j++){
        vector<int> a_aux = (*a);
        //Swap value before recursive call...
        int aux_int = a_aux[start];
        a_aux[start] = a_aux[j];
        a_aux[j] = aux_int;

        //recursive call
        returnedCost = FindCheapestPermutation(costs, &a_aux, start+1, end);
        //compare returned cost
        if (permutationCost == 0){
            permutationCost = returnedCost;
        }
        else if (returnedCost < permutationCost)
        {
            permutationCost = returnedCost;
            a->assign(a_aux.begin(), a_aux.end());
        }

    }
    return permutationCost;
}



int main(void){
    int n;
    int Costs[9][9] = {0};
    int PermutationCost = 0;
    vector<int> a;
    
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
    PermutationCost = FindCheapestPermutation(Costs, &a, 0, n - 1);
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

