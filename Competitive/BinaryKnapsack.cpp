#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct item{
    int weight;
    int value;
    bool operator < (const item& other) const{
        return weight < other.weight;
    }
};

int main(){
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n;
    int totalWeight;
    vector<item> items;
    //get information
    cin >> n >> totalWeight;

    for(int i = 0; i < n; ++i){
        int weight;
        int value;
        cin >> weight >> value;
        
        items.push_back((item){weight, value});
    }

    //Sort and reverse values.
    sort(items.begin(), items.end());
    reverse(items.begin(), items.end());

    int totalValue = 0;
    vector<int> candidates;

    for(int power = 0; power <= 30; ++power){
        int weight = 1 << power;
        //insert candidates with the same power.
        while(items.size() > 0 && items.back().weight == weight){
            candidates.push_back(items.back().value);
            items.pop_back();
        }

        sort(candidates.begin(), candidates.end());

        if(totalWeight & weight){
            //weight contained in the total
            if(candidates.size() > 0 ){
                totalValue += candidates.back();
                candidates.pop_back();
            }
        }

        vector<int> newCandidates;
        //Generate new candidates combinations
        while(candidates.size() >= 2){
            int combinedValue = candidates.back();
            candidates.pop_back();
            combinedValue += candidates.back();
            candidates.pop_back();
            newCandidates.push_back(combinedValue);
        }

        if(candidates.size() >= 1){
            newCandidates.push_back(candidates.back());
            candidates.pop_back();
        }

        candidates = newCandidates;
    }
    cout << totalValue << '\n';
    return 0;
}
