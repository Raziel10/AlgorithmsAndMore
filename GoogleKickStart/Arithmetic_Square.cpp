
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;


bool isArithmeticSequence(int a, int b, int c){
    bool ans = false;

    if((a - b) == (b - c)){
        ans = true;
    }

    return ans;
}

int Arithmetic_Square(int (&A)[3][3]){
    map<int,int> freq;
    int delta;
    int val;
    int maxFreqVal = 0;
    int maxFreq = 0;    
    int ans = 0;

    //Check all lines 
    //middle vertical
    delta = (A[0][1] - A[2][1]);
    if( (delta % 2) == 0){
        //save value.
        
        val = A[0][1] - (delta/2);
        //cout << "MV delta: "<<delta/2 << "val:" << val<< endl;
        freq[val]++;
        if(freq[val] > maxFreq){
            maxFreqVal = val;
            maxFreq = freq[val];
        }
    }
    //middle horizontal
    delta = (A[1][0] - A[1][2]);
    if( (delta % 2) == 0){
        //save value.
        
        val = A[1][0] - (delta/2);
        //cout << "MH delta: "<<delta/2 << "val:" << val<< endl;
        freq[val]++;
        if(freq[val] > maxFreq){
            maxFreqVal = val;
            maxFreq = freq[val];
        }
    }
    // left diagonal 
    delta = (A[0][0] - A[2][2]);
    if( (delta % 2) == 0){
        //save value.
        
        val = A[0][0] - (delta/2);
        //cout << "delta: "<<delta/2 << "val:" << val<< endl;
        freq[val]++;
        if(freq[val] > maxFreq){
            maxFreqVal = val;
            maxFreq = freq[val];
        }
    }
    // right diagonal  
    delta = (A[0][2] - A[2][0]);
    if( (delta % 2) == 0){
        //save value.
        val = A[0][2] - (delta/2);
        //cout << "delta: "<<delta/2 << "val:" << val<< endl;
        freq[val]++;
        if(freq[val] > maxFreq){
            maxFreqVal = val;
            maxFreq = freq[val];
        }
    }
    //Check the rest of the lines.
    //cout << "max: "<<maxFreq << "val" << maxFreqVal;
    ans+= maxFreq;
    ans+= isArithmeticSequence(A[0][0],A[0][1],A[0][2])? 1 : 0;
    ans+= isArithmeticSequence(A[2][0],A[2][1],A[2][2])? 1 : 0;
    ans+= isArithmeticSequence(A[0][0],A[1][0],A[2][0])? 1 : 0;
    ans+= isArithmeticSequence(A[0][2],A[1][2],A[2][2])? 1 : 0;

    return ans;
}

void run_case(int caseNum){
	int A[3][3];

    cin >> A[0][0] >> A[0][1] >> A[0][2];
    cin >> A[1][0] >> A[1][2];
    cin >> A[2][0] >> A[2][1] >> A[2][2];
    cout << "Case #"  << caseNum << ": " << Arithmetic_Square(A)<< endl;
}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int tests;
	cin >> tests;

	for (int i = 1; i <= tests; i++) run_case(i);
	return 0;
}