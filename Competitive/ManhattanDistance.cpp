#include <iostream>
#include <vector>
using namespace std;

int main (void){
    //read n
    //iterate 0 ... n-1
        //read coordinates x,y
        //evaluate min max sum and diff
        //Compare values
        //print Max MD coordinates
    
    int n = 0 ;
    int x = 0;
    int y = 0;
    
    int MinSum;
    int MinSumIndx;
    int MaxSum;
    int MaxSumIndx;
    int MinDiff;
    int MinDiffIndx;
    int MaxDiff;
    int MaxDiffIndx; 

    cin >> n;
    

    for(int i = 0; i < n; i++){
        cin >> x >> y;
        int sum = x + y;
        int diff = x - y;
        if(i == 0){
            MinSum = MaxSum =  sum;
            MinSumIndx = MaxSumIndx =  0;
            MinDiff = MaxDiff = diff;
            MinDiffIndx = MaxDiffIndx = 0;
        }
        else{
            if(sum > MaxSum){
                MaxSum = sum;
                MaxSumIndx = i;
            }
            if(sum < MinSum){
                MinSum = sum;
                MinSumIndx = i;
            }
            if(diff > MaxDiff){
                MaxDiff = diff;
                MaxDiffIndx = i;
            }
            if(diff < MinDiff){
                MinDiff = diff;
                MinDiffIndx = i;
            }
            
        }
        //Update diffs 
        if((MaxSum - MinSum) > (MaxDiff - MinDiff)){
            cout <<  MaxSumIndx + 1 << " " <<  MinSumIndx + 1 << endl;
        }
        else{
            cout <<  MaxDiffIndx + 1 << " " <<  MinDiffIndx + 1 << endl;
        }
        
    }

}