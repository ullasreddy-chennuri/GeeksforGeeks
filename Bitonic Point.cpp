/*
Given an array arr of n elements which is first increasing and then may be decreasing, find the maximum element in the array.
Note: If the array is increasing then just print then last element will be the maximum value.


Example 1:
Input: 
n = 9
arr[] = {1,15,25,45,42,21,17,12,11}
Output: 45

Explanation: Maximum element is 45.


Example 2:
Input: 
n = 5
arr[] = {1, 45, 47, 50, 5}
Output: 50

Explanation: Maximum element is 50.

Your Task:  
You don't need to read input or print anything. Your task is to complete the function findMaximum() 
which takes the array arr[], and n as parameters and returns an integer denoting the answer.

Expected Time Complexity: O(logn)
Expected Auxiliary Space: O(1)

Constraints:
3 ≤ n ≤ 106
1 ≤ arri ≤ 106
*/

int findMaximum(int arr[], int n) {
	    // code here
	    int lo=0,hi=n-1;
	    while(lo<=hi){
	        int mid = (lo+hi)/2;
	        if(mid == n-1){
	            return arr[n-1];
	        }
	        if(mid==0){
	            return arr[0];
	        }
	        if(arr[mid]>arr[mid-1]&&arr[mid]>arr[mid+1]){
	            return arr[mid];
	        }else if(arr[mid]>arr[mid-1]&&arr[mid]<arr[mid+1]){
	            lo=mid+1;
	        }else{
	            hi=mid-1;
	        }
	    }
	    return arr[n-1];
	}
