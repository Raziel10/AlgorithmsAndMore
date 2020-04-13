
#include <iostream>
#include <map>
#include <vector>

using namespace std;


long int SumMin(vector <uint64_t> A){
    uint32_t n = A.size();
    uint64_t sum = 0;
    vector < map <uint32_t, uint64_t>* > MinsValues;

    //auxiliar variables
    uint64_t ValueA;
    uint64_t ValueB;
    uint64_t min;

    //allocating memory for each member
    for( int j = 0; j < n; j++){
        map<uint32_t, uint64_t> *NewMap = new map <uint32_t, uint64_t>();
        MinsValues.push_back(NewMap);
        //Insert first values
        MinsValues[j]->insert(pair<uint32_t, uint64_t>(j,A[j]));
        sum += A[j];
        //cout << "Insert in map:" << j << " valor:" << A[j] << endl;
    }
    

    
    //Generate Mins
    for(int delta = 1; delta < n; delta ++){
        for(int k = 0; (k + delta) < n ; k++){
            ValueA = (*MinsValues[k])[k + delta -1];
            ValueB = (*MinsValues[k+1])[k + delta];
            //cout << "Valor A:" << ValorA << " valorB:" << ValorB << endl;
            min = ValueA < ValueB ? ValueA : ValueB;
            (*MinsValues[k])[k+delta] = min;
            sum+=min;
        }
    }
   
    return sum;
}

int main(void){
    int n;
    vector<uint64_t> A;
    uint64_t value;
    cin >> n;

    for(int i = 1;  i <= n; i++){
        cin >> value;
        A.push_back(value);
    }
    cout << SumMin(A);
    return 0;
}