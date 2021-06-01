/*

Given an array arr[] of N integers arranged in a circular fashion. 
Your task is to find the maximum contiguous subarray sum.


Example 1:
Input:
N = 7
arr[] = {8,-8,9,-9,10,-11,12}
Output:
22

Explanation:
Starting from the last element
of the array, i.e, 12, and 
moving in a circular fashion, we 
have max subarray as 12, 8, -8, 9, 
-9, 10, which gives maximum sum 
as 22.


Example 2:
Input:
N = 8
arr[] = {10,-3,-4,7,6,5,-4,-1}
Output:
23

Explanation: Sum of the circular 
subarray with maximum sum is 23

Your Task:
The task is to complete the function circularSubarraySum() which returns a sum of the circular subarray with maximum sum.


Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).


Constraints:
1 <= N <= 106
-106 <= Arr[i] <= 106
*/

    int circularSubarraySum(int arr[], int num){
        
        // your code here
        int pre_sum=arr[0];
        int max_sum=arr[0];
        int pre_min_sum=arr[0];
        int min_sum=arr[0];
        int tot_sum=arr[0];
        
        // using kadane's algo finding maxsum,minsum,totsum contiguous subarray sum's
        // max circular sum = max(tot-minsum,maxsum);
        
        if(num==1){
            return arr[0];
        }
        
        
        for(int i=1;i<num;i++){
            tot_sum+=arr[i];
            pre_min_sum=min(arr[i]+pre_min_sum,arr[i]);
            pre_sum=max(arr[i]+pre_sum,arr[i]);
            if(max_sum<pre_sum){
                max_sum=pre_sum;
            }
            
            if(min_sum>pre_min_sum){
                min_sum=pre_min_sum;
            }
        }
        if(min_sum==tot_sum){
            return max_sum;
        }
        return max(max_sum,(tot_sum-min_sum));
    }
