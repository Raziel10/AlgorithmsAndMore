//The King problem
#include <iostream>

using namespace std;

int FindKings(int r, int c){
    int AccumulatedKings = 0; 
    int mult_r = 0;
    int mult_c = 0;
    int mod_r = 0; 
    int mod_c = 0;

    if((r <= 3) && (c <= 3)){
        //All the posible boards results can be formed from this solutions.
        if( (r == 3) && (c == 3)){
            return 8;
        }
        else if( (r == 2) && (c == 2)){
            return 3;
        }
        else if( (r == 1) && (c == 1)){
            return 0;
        }
        else if( ((r == 2) && (c == 3)) || ((r == 3) && (c == 2))){
            return 5;
        }

        else if( ((r == 2) && (c == 1)) || ((r == 1) && (c == 2))){
            return 1;
        }

        else if( ((r == 3) && (c == 1)) || ((r == 1) && (c == 3))){
            return 2;
        }
    }
    else{
        //At least one value bigger than 
        mult_c = c / 3;
        mult_r = r / 3;
        mod_c = c % 3;
        mod_r = r % 3;

        if((mult_c > 0) &&  (mult_r > 0)){
            //3 x 3 space
            AccumulatedKings +=  mult_c * mult_r * FindKings(3,3);
             //remaining borders
            AccumulatedKings +=  FindKings(mod_r, 3 * mult_c);
            AccumulatedKings +=  FindKings(3 * mult_r, mod_c);

        }
        else if((mult_r > 0) && (mult_c == 0)){
            AccumulatedKings += mult_r * FindKings(3, mod_c);
            
        }
        else if((mult_r == 0) && (mult_c > 0)){
            AccumulatedKings += mult_c * FindKings(mod_r, 3);
        }
        AccumulatedKings += FindKings(mod_r, mod_c);
    }
    return AccumulatedKings;
}


int main(void){
    int r;
    int c;
    int MaxKings = 0;
    cin >> r >> c;
    MaxKings = FindKings(r,c);
    cout << MaxKings;
    return 0;
}


//Solution B, but less eficient


int FindMaxKings(bool** Board, int r, int c, int pos, bool KingAvailable){
    bool** BoardA;
    int MaxKings = 0;
    bool InvalidBoard = false;
    int Kings = 0;
    
    // check if we are in a valid position
    if(pos >= (r * c)){
        return 0;
    }
    //Make 1 copy of the Board
    BoardA = new bool*[r]();
    for(int i = 0; i < r; ++i){
        BoardA[i] = new bool[c];
    } 
    //copy matrix content
    for(int j = 0; j < r; ++j){
        for(int k = 0; k < c; ++k){
            BoardA[j][k] = Board[j][k];
        }
    }

    if(KingAvailable){
        //Write King 
        int row = pos / c;
        int column = (pos - (c*row));
        
        BoardA[row][column] = true;
        //validate new element doesn´t mess with existing kings.
        for(int j = 0; j < r; ++j){
            for(int k = 0; (k < c) && (InvalidBoard == false); ++k){
                if(BoardA[j][k]  == true){
                    Kings++;
                    //Seven conditions at least one of them should be succesful
                    if(j > 0){
                        //Left-up 
                        if( (k > 0) && (BoardA[j - 1][k - 1] == false)){
                            //space available
                            continue;
                        }
                        //Up
                        else if( BoardA[j - 1][k] == false){
                            //space available
                            continue;
                        }
                        //Right - Up 
                        else if((k < (c -1)) && (BoardA[j - 1][k +1] == false)){
                            //space available
                            continue;
                        }
                    }
                    
                    //Left
                    if( (k > 0)  && (BoardA[j][k - 1] == false)){
                        //space available
                        continue;
                    }
                    //Right
                    else if((k < (c - 1)) && (BoardA[j][k + 1] == false)){
                        //space available
                        continue;
                    }

                    //Left-below
                    if(j < (r - 1)){
                        if( (k > 0) && (BoardA[j + 1][k - 1] == false)){
                        //space available
                        continue;
                        }
                        //Below
                        else if( BoardA[j + 1][k] == false){
                            //space available
                            continue;
                        }
                        //Right-below
                        else if( (k < (c - 1)) && (BoardA[j + 1][k + 1] == false)){
                            //space available
                            continue;
                        }
                    }
                    InvalidBoard = true;
                }
            }
        } 
    }

    //Move to next position with the 2 posibilities.
    if(!InvalidBoard){
        MaxKings = Kings;
       
        Kings = FindMaxKings(BoardA, r, c, pos + 1, true);
        if(Kings > MaxKings){
            MaxKings = Kings;
        }
        Kings = FindMaxKings(BoardA, r, c, pos + 1, false);
        if(Kings > MaxKings){
            MaxKings = Kings;
        }

    }
    else
    {
        //Invalid board stop recursive calls and retunrn
        MaxKings = 0;
    }    
    return MaxKings;
}