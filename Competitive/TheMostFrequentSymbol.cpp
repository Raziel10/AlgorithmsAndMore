#include <iostream>
#include <map>
#include <vector>

using namespace std;

map<char, vector<int> > WordLetterMap;

char FindMostFrequentSymbol(int l, int r){
    map<char, vector<int> >::iterator MapIt;
    char mostFreqLetter;
    int MaxRepetitions = 0;
    for(MapIt = WordLetterMap.begin(); MapIt != WordLetterMap.end(); MapIt++){
        int repetitions = MapIt->second[r] - MapIt->second[l-1];
        if(repetitions > MaxRepetitions){
            mostFreqLetter = MapIt->first;
            MaxRepetitions = repetitions;
        }
    }
    return mostFreqLetter;

}

int main (void){
    string word;
    int queries;
    int l, r;
    cin >> word;
    cin >> queries;
    
    map<char, vector<int> >::iterator MapIt;
    vector<int>::iterator VecIt;
    //Create vector per letter 
    for(int j = 1; j <= word.length();j++){
        for(MapIt = WordLetterMap.begin(); MapIt != WordLetterMap.end(); MapIt++){
            if(MapIt->first == word[j-1]){
                MapIt->second[j] =  MapIt->second[j-1] + 1;
            }
            else{
                MapIt->second[j] =  MapIt->second[j-1];
            }
        }
        if(WordLetterMap.count(word[j-1]) == 0){
            WordLetterMap.insert(pair<char,vector<int> >(word[j-1], vector<int>(word.length()+1, 0)));
            WordLetterMap[word[j-1]][j] = 1;
        }
    }

    /*for(MapIt = WordLetterMap.begin(); MapIt != WordLetterMap.end(); MapIt++){
        cout << MapIt->first <<endl; 
        for(VecIt = MapIt->second.begin(); VecIt != MapIt->second.end(); VecIt++){
            cout << *VecIt << " "; 

        }
        cout << endl;
    }*/


    for(int i = 0; i < queries; i++){
        cin >> l >> r;
        cout << FindMostFrequentSymbol(l,r) << endl;
    }
    
}