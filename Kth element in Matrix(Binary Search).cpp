/*

Given a N x N matrix, where every row and column is sorted in non-decreasing order. 
Find the kth smallest element in the matrix.

Example 1:
Input:
N = 4
mat[][] =     {{16, 28, 60, 64},
                   {22, 41, 63, 91},
                   {27, 50, 87, 93},
                   {36, 78, 87, 94 }}
K = 3
Output: 27
Explanation: 27 is the 3rd smallest element.
 

Example 2:
Input:
N = 4
mat[][] =     {{10, 20, 30, 40}
                   {15, 25, 35, 45}
                   {24, 29, 37, 48}
                   {32, 33, 39, 50}}
K = 7
Output: 30
Explanation: 30 is the 7th smallest element.


Your Task:
You don't need to read input or print anything. Complete the function kthsmallest() which takes the mat, 
N and K as input parameters and returns the kth smallest element in the matrix.
 

Expected Time Complexity: O(N*Log(N))
Expected Auxiliary Space: O(N)

 

Constraints:
1 <= N <= 50
1 <= mat[][] <= 10000
1 <= K <= N*N
*/

int count_fun(int arr[MAX][MAX],int val,int n){
    int count =0;
    int row = 0;
    int col = n-1;
    while(row<n && col>=0){
        if(arr[row][col]<=val){
            count+=col+1;
            row++;
            
        }else{
            col--;
        }
    }
    return count;
    
}

int kthSmallest(int arr[MAX][MAX], int n, int k)
{
  //Your code here
  // Binary Search method
  int maxi = arr[n-1][n-1];
  int mini = arr[0][0];
  while(mini<maxi){
      int mid = (maxi+mini)/2;
      if(count_fun(arr,mid,n)<k){
          mini = mid+1;
      }else{
          maxi = mid;
      }
  }
  return maxi;
  
}
