#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:

    bool isSafe(vector<vector<char>>& board, int row, int col, int value){

        int n= board.size();

        for(int i=0; i<n; i++){
            // row checking
            if(board[row][i]== value){
                return false;
            }
            // column checking
            if(board[i][col]== value){
                return false;
            }
            // 3 X 3 box check
            if(board[3*(row/3)+(i/3)][3*(col/3)+(i%3)]== value){
                return false;
            }
        }
        return true;

    }

    bool solve(vector<vector<char>>& board){
        int n = board.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){

                if(board[i][j]=='.'){
                    for(char val='1'; val<='9'; val++){

                        if(isSafe(board,i,j, val)){
                            board[i][j]=val;
                            //recursion
                            bool remaingSol = solve(board);
                            if(remaingSol== true){
                                return true;
                            }
                            // backtracking
                            else{
                            board[i][j]= '.';
                            }
                        }
                    }
                    return false;
                }

            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {    

        solve( board);
    }
};

int main(){

    Solution obj;

    vector<vector<char>> board(9, vector<char>(9));

    cout << "Enter all the sudoku element: "<< endl;
    cout << " Enter . if there is no element "<< endl;

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << "Enter value for row " << i+1 << ", column " << j+1 << ": ";
            cin >> board[i][j];
        }
    }

    cout << "Initial Sudoku Board:" << endl;
    for (int i = 0; i < 9; i++) {
        if (i % 3 == 0 && i != 0) {
            cout << "---------------------" << endl;
        }
        for (int j = 0; j < 9; j++) {
            if (j % 3 == 0 && j != 0) {
                cout << "| ";
            }
            cout << board[i][j] << " ";
        }
        cout << endl;
    }


    obj.solveSudoku(board);

   cout << "Solved Sudoku:" << endl;
    for (int i = 0; i < 9; i++) {
        if (i % 3 == 0 && i != 0) {
            cout << "---------------------" << endl;
        }
        for (int j = 0; j < 9; j++) {
            if (j % 3 == 0 && j != 0) {
                cout << "| ";
            }
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

return 0;

}