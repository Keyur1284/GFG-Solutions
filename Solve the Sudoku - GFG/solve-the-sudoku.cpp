//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


// } Driver Code Ends
class Solution 
{
    public:
    //Function to find a solved Sudoku.
    
    bool isValid (int row, int col, int num, int grid[N][N])
    {
        for (int i = 0; i<9; i++)
        {
            if (grid[i][col] == num)
                return false;
            
            if (grid[row][i] == num)
                return false;
            
            if (grid[3 * (row/3) + i/3][3 * (col/3) + i % 3] == num)
                return false;
        }
        
        return true;
    }
    
    bool SolveSudoku(int grid[N][N])  
    { 
        for (int row = 0; row < 9; row++)
        {
            for (int col = 0; col < 9; col++)
            {
                if (grid[row][col] == 0)
                {
                    for (int num = 1; num <= 9; num++)
                    {
                        if (isValid(row, col, num, grid))
                        {
                            grid[row][col] = num;
                            
                            if (SolveSudoku(grid))
                                return true;
                                
                            grid[row][col] = 0;
                        }
                    }
                    
                    return false;
                }
            }
        }
        
        return true;
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        for (int row = 0; row < 9; row++)
        {
            for (int col = 0; col < 9; col++)
                cout << grid[row][col] << ' ';
        }
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}
// } Driver Code Ends