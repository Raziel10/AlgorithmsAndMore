//The King problem
#include <iostream>

using namespace std;

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


int main(void){
    int r;
    int c;
    int Kings;
    int MaxKings = 0;

    cin >> r >> c;
    bool** board = new bool*[r]();
    //Create the board.
    for(int i = 0; i < r; ++i){
        board[i] = new bool[c];
    }   
    MaxKings = FindMaxKings(board, r, c, 0, true);
    Kings = FindMaxKings(board, r, c, 0, false);
    if(Kings > MaxKings){
        MaxKings = Kings;
    }
    
    cout << MaxKings;
    return 0;
}

