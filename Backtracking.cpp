#include <iostream>
#include<vector>
using namespace std;
int n;
vector<vector<int> > board;
bool isSafe(int row, int col)
{
    // col check
    for(int i=0;i<row;i++)
    {
        if(board[i][col] == 1)
        {
            return false;
        }
    }


    // right diagonal check
    for(int i=row-1, j=col +1; i>=0 && j<n; i--, j++)
    {
        if(board[i][j] == 1)
        {
            return false;
        }
    }

    // left diagonal
    for(int i=row-1, j= col-1; i>=0 && j>=0; i--, j--)
    {
        if(board[i][j]==1)
        {
            return false;
        }
    }

    return true;
}
 bool placeQueen(int row)
{
    if(row==n)
    {
        return true;
    }

    for(int col=0; col<n;col++)
    {
        if(isSafe(row,col))
        {
            board[row][col] = 1;

            if(placeQueen(row+1))
            {
                return true;
            }
            board[row][col] = 0; // backtracking
        }
    }
    return false;
}
int main()
{
    cout<< "Enter Board size and queen number:\n "<<endl;
    cin>>n;

    board.resize(n, vector<int> (n,0));

    bool result = placeQueen(0);

    if(result)
    {
        cout<<" Enter Chess Board:\n"<< endl;
    }
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout <<  board[i][j] << endl;;
            }
            cout<<endl;
        }
    }

    else
    {
        cout<<"No solution";
    }

        return 0;
}
