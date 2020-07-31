#include <iostream>
#include <vector>

using namespace std;

int main (void){
    int n; 
    int m;
    string S1;
    string S2;
    int InsertCost;
    int DeleteCost;
    int SubsCost;

    //read values
    
    //read n
    cin >> n;
    //read m
    cin >> m;

    //read strings
    //read S1
    cin >> S1;
    //read S2
    cin >> S2;

    // read costs
    // read Insert
    cin >> InsertCost;
    // read delete
    cin >> DeleteCost;
    // read Substitution
    cin >> SubsCost;

    //create matrix
    vector< vector<int> > ED (m+1,vector<int>(n+1,0));
   
    //set first row and colum values according to 
    for(int i = 0; i < n+1; i++){
        ED[0][i] = i * DeleteCost;
    }
    for(int j = 0; j < m+1; j++){
        ED[j][0] = j * InsertCost;
    }

    //iterate in all the rows and compute min according to editing distance algorith
    int minCost;
    int DC;
    int IC;
    int MC;

    for(int j = 1; j < m+1; j++){
        for(int i = 1; i < n+1; i++){
            DC = ED[j][i-1] + DeleteCost;
            IC = ED[j-1][i] + InsertCost;
            MC = (S1[i-1] == S2[j-1]) ? ED[j - 1][i - 1] : ED[j - 1][i - 1] + SubsCost;
            ED[j][i] = min(DC,min(IC,MC));
        }  
    }

    cout << ED[m][n];
    return 0;
}