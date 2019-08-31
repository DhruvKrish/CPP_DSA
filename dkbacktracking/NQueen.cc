#include <bits/stdc++.h>
#include <vector>
using namespace std;
class Solution {
public:

    vector<vector<string>> solutions;

    //Start placing queens from left column, backtrack if not possible.
    vector<vector<string>> solveNQueens(int n) {

        //prep board
        vector<string> board;
        string temp;
        for(int i=0;i<n;i++)
        {
            temp="";
            for(int j=0;j<n;j++){
                temp+=".";
            }
            board.push_back(temp);
        }

        solveNQueensCol(board, 0, n);

        return solutions;
    }

    //Check if queen can be placed in col
    bool solveNQueensCol(vector<string> board, int col, int n){
        //placed queen in all columns
        if(col>=n){
            solutions.push_back(board);
            return true;
        }

        //try placing in each row of col
        for(int i=0;i<n;i++){
            //check if queen can be placed in i, col
            if(isSafe(board, i, col, n)){
                //place queen
                board[i][col]='Q';
                //check place in next column
                if(!solveNQueensCol(board, col+1, n)){
                    //backtrack to check next col
                    board[i][col]='.';
                }
            }
        }
        return false;
    }

    //Check if safe to place on board[row][col]
    bool isSafe(vector<string> board, int row, int col, int n){
        int i,j;

        //check for queens to left
        for(j=0;j<col;j++){
            if(board[row][j]=='Q') return false;
        }

        //check for queens to diagonal left up
        for(i=row-1,j=col-1; i>=0 && j>=0; i--,j--){
            if(board[i][j]=='Q') return false;
        }

        //check for queens to diagonal left down
        for(i=row+1,j=col-1; i<n && j>=0; i++,j--){
            if(board[i][j]=='Q') return false;
        }

        return true;
    }
};

int main(){
  Solution temp;

  temp.solveNQueens(5);

  for(int i=0;i<temp.solutions.size();i++){
    for(int j=0;j<temp.solutions[i].size();j++){
      cout<<temp.solutions[i][j]<<" "<<endl;
    }
    cout<<endl;
  }
}
