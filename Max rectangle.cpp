/*

Given a binary matrix. Find the maximum area of a rectangle formed only of 1s in the given matrix.

Example 1:
Input:
n = 4, m = 4
M[][] = {{0 1 1 0},
         {1 1 1 1},
         {1 1 1 1},
         {1 1 0 0}}
Output: 8

Explanation: For the above test case the
matrix will look like
0 1 1 0
1 1 1 1
1 1 1 1
1 1 0 0
the max size rectangle is 
1 1 1 1
1 1 1 1
and area is 4 *2 = 8.


Your Task: 
Your task is to complete the function maxArea which returns the maximum size rectangle area in a 
binary-sub-matrix with all 1’s. The function takes 3 arguments the first argument is the Matrix M[ ] [ ] 
and the next two are two integers n and m which denotes the size of the matrix M. 

Expected Time Complexity : O(n*m)
Expected Auixiliary Space : O(m)

Constraints:
1<=n,m<=1000
0<=M[][]<=1

Note:The Input/Ouput format and Example given are used for system's internal purpose, 
and should be used by a user for Expected Output only. As it is a function problem, 
hence a user should not read any input from stdin/console. The task is to complete the function specified, 
and not to write the full code.

*/

// here we used the same code which we used in Histogram problem
class Solution{
  public:
    
    int getMaxArea(int arr[], int n)
    {
        // Your code here
        int max_area=INT_MIN;
        stack<int> st;
        for(int i=0;i<n;i++){
            if(st.empty() || arr[st.top()]<=arr[i]){
                st.push(i);
            }else{
                while(!st.empty() && arr[st.top()]>arr[i]){
                    int t = st.top();
                    st.pop();
                    int area;
                    if(st.empty()){
                       area = arr[t]*i;
                    }else{
                        area = arr[t]*(i-st.top()-1);
                    }
                    max_area = max(max_area,area);
                }
                st.push(i);
            }
        }
        while(!st.empty()){
            int t=st.top();
            st.pop();
            int area;
            if(st.empty()){
                area = arr[t]*n;
            }else{
                area = arr[t]*(n-st.top()-1);
            }
            max_area = max(max_area,area);
        }
        return max_area;
    }
  
  
  
    int maxArea(int arr[MAX][MAX], int n, int m) {
        // Your code here
        int max_area = INT_MIN;
        max_area = max(max_area,getMaxArea(arr[0],m));
      // creating each row of a matrix and applying histogram code tp find max area for each row as base here.
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j]==0){
                    continue;
                }else{
                    arr[i][j]+=arr[i-1][j];
                }
            }
            max_area = max(max_area , getMaxArea(arr[i],m));
        }
        return max_area;
    }
};
