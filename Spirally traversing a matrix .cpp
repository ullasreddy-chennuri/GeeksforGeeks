/*
Given a matrix of size r*c. Traverse the matrix in spiral form.


Example 1:
Input:
r = 4, c = 4
matrix[][] = {{1, 2, 3, 4},
           {5, 6, 7, 8},
           {9, 10, 11, 12},
           {13, 14, 15,16}}
Output: 
1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10



Example 2:
Input:
r = 3, c = 4  
matrix[][] = {{1, 2, 3, 4},
           {5, 6, 7, 8},
           {9, 10, 11, 12}}
Output: 
1 2 3 4 8 12 11 10 9 5 6 7


Your Task:
You dont need to read input or print anything. Complete the function spirallyTraverse() that takes matrix,
r and c as input parameters and returns a list of integers denoting the spiral traversal of matrix. 

Expected Time Complexity: O(r*c)
Expected Auxiliary Space: O(r*c), for returning the answer only.

Constraints:
1 <= r, c <= 100
0 <= matrixi <= 100
*/
  

    // Iterative approach using four loops
    vector<int> spirallyTraverse(vector<vector<int> > arr, int r, int c) 
    {
        // code here 
        vector<int> res;
        int row_start=0,col_start=0;
        int row_end=r,col_end=c;
        while(row_start<row_end && col_start<col_end){
            // first printing first row from left to right
            for(int i=col_start;i<col_end;i++){
                res.push_back(arr[row_start][i]);
            }
            row_start++;
            //now, printing from top to bottom i.e., last col
            for(int i=row_start;i<row_end;i++){
                res.push_back(arr[i][col_end-1]);
            }
            col_end--;
            // now, printing from right to left i.e., last row
            if(row_start<row_end){
                for(int i=col_end-1;i>=col_start;i--){
                    res.push_back(arr[row_end-1][i]);
                }
                row_end--;
            }
            // now, printing from bottom to top i.e., first col
            if(col_start<col_end){
                for(int i=row_end-1;i>=row_start;i--){
                    res.push_back(arr[i][col_start]);
                }
                col_start++;
            }
            
        }
        return res;
    }



// Solved using recurssion same approach diff implementation

   void print_mat(vector<vector<int>> arr,int i,int j,int m,int n,vector<int> &res){
        if(i>=m || j>=n){
            return;
        }
        for(int p=j;p<n;p++){
            res.push_back(arr[i][p]);
        }
        
        for(int p=i+1;p<m;p++){
            res.push_back(arr[p][n-1]);
        }
        
        if(m-1!=i){
            for(int p=n-2;p>=j;p--){
                res.push_back(arr[m-1][p]);
            }
        }
        if(n-1!=j){
            for(int p=m-2;p>i;p--){
                res.push_back(arr[p][j]);
            }    
        }
        print_mat(arr,i+1,j+1,m-1,n-1,res);
    }
    
    vector<int> spirallyTraverse(vector<vector<int> > arr, int r, int c) 
    {
        // code here 
        vector<int> res;
        print_mat(arr,0,0,r,c,res);
        return res;
    }

