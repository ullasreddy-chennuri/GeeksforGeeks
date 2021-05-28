/*
Given a matrix of size n x m, where every row and column is sorted in increasing order, 
and a number x. Find whether element x is present in the matrix or not.

Example 1:

Input:
n = 3, m = 3, x = 62
matrix[][] = {{ 3, 30, 38},
              {36, 43, 60},
              {40, 51, 69}}
Output: 0
Explanation:
62 is not present in the matrix, 
so output is 0.

Example 2:
Input:
n = 1, m = 6, x = 55
matrix[][] = {{18, 21, 27, 38, 55, 67}}
Output: 1
Explanation: 55 is present in the matrix.

Your Task:
You don't need to read input or print anything. Complete the function search() that takes n, m, x, 
and matrix[][] as input parameters and returns a boolean value. True if x is present in the matrix and false if it is not present.

Expected Time Complexity: O(N + M)
Expected Auxiliary Space: O(1)

Constraints:
1 <= N, M <= 1000
1 <= mat[][] <= 105
1 <= X <= 1000
*/

 bool b_search(vector<int> arr,int n,int key){
        int lo=0,hi=n-1;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(arr[mid]==key){
                return true;
            }else if(arr[mid]>key){
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }
        return false;
    }
    
    
    bool search(vector<vector<int> > arr, int n, int m, int x) 
    {
        // code here 
        
        for(int i=0;i<n;i++){
            vector<int> temp = arr[i];
            if(temp[0]<=x && temp[m-1]>=x){
                if(b_search(temp,m,x)){
                    return true;
                }
            }
        }
        return false;
    }
