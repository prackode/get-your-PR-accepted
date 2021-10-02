/* 
Problem Statement As Given On Hackerearth
 
    Problem
Given a chess board having  cells, you need to place N queens on the board in such a way that no queen attacks any other queen.

Input:
The only line of input consists of a single integer denoting N.

Output:
If it is possible to place all the N queens in such a way that no queen attacks another queen, then print N lines having N integers. The integer in  line and  column will denote the cell  of the board and should be 1 if a queen is placed at  otherwise 0. If there are more than way of placing queens print any of them. If it is not possible to place all N queens in the desired way, then print "Not possible" (without quotes).


Sample Input
4
Sample Output
0 1 0 0 
0 0 0 1 
1 0 0 0 
0 0 1 0 

*/


#include<bits/stdc++.h>
using namespace std;

 // The following function is to check whether the queen will be safe from other queens at a particular point 
bool isSafe(int** arr, int x, int y, int n){

    for(int row=0; row<x; row++){        //checking in coloumn if a queen is already present in the same coloumn or not.
        if(arr[row][y]==1){             // we're placing queen at a particular square and give that as square as a mark 1. hence "==1"
            return false;
        }
    }

    int row =x;       
    int col =y;
    while (row>=0 && col >=0){   // condition so we dont get out of the chess board while checking from the left side    
        if(arr[row][col]==1){
            return false;
        }
        row --;         // this is done for checking diagonals on the left side 
        col--;
    } 
    row =x ;
    col =y;
    while (row>=0 && col <n){    // contions are so that we dont get out of the chess board while checking diagonals
        if(arr[row][col]==1){
            return false;
        }
        row --;        // this is done for checking the diagonals on the right side 
        col ++;
    }
    return true;        // if we dont return false anywhere we return true that the particular square is safe for placing the queen
}

//This the function where we recursively call the function and backtrack if needed
bool nQueen(int **arr, int x , int n){  // we dont need y here as we dont need to check further coloumns once we place our queen 
    if (x>=n){
        return true;        // x>=n means we havev placed all the queens    
    }
    for (int col=0; col < n; col++){   // for checking all rows and coloumns
        if (isSafe(arr,x,col,n)){       //checking and placing 1
            arr[x][col]=1;
            if (nQueen(arr, x+1,n)){        
                return true;
            }   
            arr[x][col]=0;  //BACKTRACKING
        }

    }
    return false;
}



int main(){
    int n;
    cin >> n;
    int **arr = new int*[n];        //making a 2D array
    if (n>1 && n<4){
        cout << "Not possible";
    }
    else
    {
    for (int i=0; i<n; i++){
        arr[i] = new int[n];
        for(int j=0;j<n; j++)
            arr[i][j]=0;
    }
    if (nQueen(arr,0,n)){       //if this gives true printing array. 
        for (int i=0; i<n; i++){
        
            for(int j=0;j<n; j++){
                cout << arr[i][j]<< " ";
            }
            cout << endl;
        }
    }}
    return 0;
}
