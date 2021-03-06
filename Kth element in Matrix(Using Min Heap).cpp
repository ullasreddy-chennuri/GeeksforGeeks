/*
Given a N x N matrix, where every row and column is sorted in non-decreasing order. Find the kth smallest element in the matrix.

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


int kthSmallest(int arr[MAX][MAX], int n, int k)
{
  //Your code here
  // using min heap implementing through priority_queue
  
  priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
  for(int i=0;i<n;i++){
      pq.push({arr[i][0],{i,0}});
  }
  int ans=-1;
  while(k--){
      ans = pq.top().first;
      int v = pq.top().second.first;
      int w = pq.top().second.second;
      pq.pop();
     // w++;
      if(w+1<n){
          pq.push({arr[v][w+1],{v,w+1}});
      }
  }
  
  return ans;
}
