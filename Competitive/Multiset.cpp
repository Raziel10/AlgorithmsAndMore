#include <iostream>
#include <map>

using namespace std; 

int main(void){
    int n;
    map<int,int> starts;
    map<int,int> ends;

    cin >> n;
    //read values;
    for(int i = 0; i < n; i++){
        int s; 
        int e;
        cin >> s >> e;

        if(starts.count(s) > 0 ){
            //value exists in map 
            starts[s]++;
        }else{
            starts[s] = 1;
        }

        if(ends.count(e) > 0 ){
            //value exists in map 
            ends[e]++;
        }else{
            ends[e] = 1;
        }
    }
    //iterate over each value

    int SetsIntersected = 0; 
    map<int,int>::iterator it = starts.begin();
    for(int i = it->first; i <= ends.rbegin()->first; ){
        if(starts.count(i)){
            SetsIntersected += starts[i];
            it++;
        }
        if(SetsIntersected > 0){
            cout << i << " " << SetsIntersected << endl;
        }

        if(ends.count(i)){
            SetsIntersected -= ends[i];
        }

        if(SetsIntersected == 0){
            if(it != starts.end()){
                i = it->first;
            }
            else{
                i++;
            }
            
        }else{
            i++;
        }

    }


    return 0;
}