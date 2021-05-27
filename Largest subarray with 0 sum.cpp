/*
Given an array having both positive and negative integers.
The task is to compute the length of the largest subarray with sum 0.

Example 1:
Input:
N = 8
A[] = {15,-2,2,-8,1,7,10,23}
Output: 5

Explanation: The largest subarray with
sum 0 will be -2 2 -8 1 7.

Your Task:
You just have to complete the function maxLen() which takes two arguments an array A and n, 
where n is the size of the array A and returns the length of the largest subarray with 0 sum.

Expected Time Complexity: O(N*Log(N)).
Expected Auxiliary Space: O(N).

Constraints:
1 <= N <= 105
-1000 <= A[i] <= 1000, for each valid i
*/

int maxLen(int arr[], int n)
{
    // Your code here
    unordered_map<int,int> map;
    int sum=0;
    int max_len=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        
        if(arr[i]==0 && max_len==0){
            max_len=1;
        }
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
