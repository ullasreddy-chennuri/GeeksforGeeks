/*

Given an array containing N integers and an integer K., 
Your task is to find the length of the longest Sub-Array with the sum of the elements equal to the given value K.

Example 1:
Input :
A[] = {10, 5, 2, 7, 1, 9}
K = 15
Output : 4
Explanation:
The sub-array is {5, 2, 7, 1}.


Example 2:
Input : 
A[] = {-1, 2, 3}
K = 6
Output : 0

Your Task:
This is a function problem. The input is already taken care of by the driver code. 
You only need to complete the function smallestSubsegment() that takes an array (A), sizeOfArray (n),  
sum (K)and returns the required length of the longest Sub-Array. The driver code takes care of the printing.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1<=N<=105
-105<=A[i], K<=105
*/

int lenOfLongSubarr(int arr[],  int n, int k) 
    { 
        // Complete the function
        unordered_map<int,int> map;
        int sum=0;
        int max_len=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            
            if(arr[i]==k && max_len==0){
                max_len=1;
            }
            if(sum==k){
                max_len=i+1;
            }
            if(map.find(sum-k)!=map.end()){
                max_len = max(max_len,i-map[sum-k]);
            }
            if(map.find(sum)==map.end()){
                map[sum]=i;
            }
        }
        return max_len;
  }
