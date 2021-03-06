#include <iostream>
#include <stack>
#include <cmath>


using namespace std;

int64_t getValue(int8_t  Digits[7], int8_t DigitsPos ){
    int64_t Value = 0;
    int64_t Accum;
    for(int d = 0; d < DigitsPos ; d++ ){
        Accum = pow(10,DigitsPos-d-1);
        Value += Digits[d] * Accum;
    }
    return Value;
}

int64_t EvaluateExpression(string s){
    int64_t Result = 0;
    int64_t Value1;
    int64_t Value2;
    int8_t  Digits[7] = {0};
    int8_t  DigitsPos = 0;
    int64_t op;
    
    stack<char> s_Operators;
    stack<int64_t> s_Values;

    for(int c = 0; c < s.length(); c++ ){
        if( s[c] == '+' || s[c] == '-'){
            Value1 = getValue( Digits, DigitsPos );
            s_Values.push(Value1);
            DigitsPos = 0;

            if(!s_Operators.empty()){
                Value2 = s_Values.top();
                s_Values.pop();
                Value1 = s_Values.top();
                s_Values.pop();

                if(s_Operators.top() == '+'){
                    op = 1;
                }
                else if(s_Operators.top() == '-'){
                    op = -1;
                }
                s_Operators.pop();
                Result = Value1 + Value2 * op;
                s_Values.push(Result);
            }
            s_Operators.push(s[c]);
            
        }
        else if ((s[c] >= '0') && (s[c] <='9')) {
            Digits[DigitsPos] = s[c] - '0';
            DigitsPos++;
        }
    }


    Value1 = getValue( Digits, DigitsPos );
    s_Values.push(Value1);
    DigitsPos = 0;


    while(!s_Operators.empty()){
        Value2 = s_Values.top();
        s_Values.pop();
        Value1 = s_Values.top();
        s_Values.pop();

        if(s_Operators.top() == '+'){
            op = 1;
        }
        else if(s_Operators.top() == '-'){
            op = -1;
        }
        s_Operators.pop();
        Result = Value1 + Value2 * op;
        s_Values.push(Result);
    }
    Result = s_Values.top();
    s_Values.pop();


    return Result;
}

int main(void){
    string s;
    cin >> s;

    cout << EvaluateExpression(s);
    return 0;
}