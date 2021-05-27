/*
Given an array of 0s and 1s. Find the length of the largest subarray with equal number of 0s and 1s.


Example 1:
Input:
N = 4
A[] = {0,1,0,1}
Output: 4
Explanation: The array from index [0...3]
contains equal number of 0's and 1's.
Thus maximum length of subarray having
equal number of 0's and 1's is 4.


Example 2:
Input:
N = 5
A[] = {0,0,1,0,0}
Output: 2
Your Task:
You don't need to read input or print anything. Your task is to complete the function maxLen() 
which takes the array arr[] and the size of the array as inputs and returns the length of the largest subarray with equal number of 0s and 1s.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= N <= 105
0 <= A[] <= 1
*/

int maxLen(int arr[], int n)
    {
        // Your code here
        for(int i=0;i<n;i++){
            if(arr[i]==0){
                arr[i]=-1;
            }
        }
        unordered_map<int,int> map;
        int sum=0;
        int max_len=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum==0){
                max_len=i+1;
            }
            if(map.find(sum)!=map.end()){
                max_len = max(max_len,i-map[sum]);
            }else{
                map[sum]=i;
            }
        }
        return max_len;
    }
