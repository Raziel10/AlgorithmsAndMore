//Maximal Distance

#include <iostream>
#include <cstdlib>
#include <vector>


using namespace std;


long int getDistance(long int a, long int b){
    return abs(a - b);
}

void MaximalDistance(long int n){
    long int MaxDistance;
    long int xIndx;
    long int x; 
    long int yIndx;
    long int y;

    for(unsigned int i = 1; i <= n ; i ++){
        long int aux;
        cin >> aux;
        if(i == 1){
            //empty set, starting vales...
            x = aux;
            xIndx = i;
            y = aux;
            yIndx = i;
            MaxDistance = 0;
        }else{
            //Compare new value and check if MaxDistance is greater than existing values 
            long int max1 = getDistance(aux, x);
            long int max2 = getDistance(aux, y);

            if(max1 > MaxDistance || max2 > MaxDistance ){
                //Replace the one with bigger distance
                if(max1 > max2){
                    //Replace Coordinate1
                    y = aux;
                    yIndx = i;
                    MaxDistance = max1;
                }else{
                    //replace Coordinate2
                    x = aux;
                    xIndx = i;
                    MaxDistance = max2;
                }
            }
        }
        cout << xIndx << " " << yIndx << endl;
    }

}

int main (void){

    unsigned int n;
    cin >> n;
    MaximalDistance(n);
    
    return 0;
}


