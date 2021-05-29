/*
Given an array of distinct elements which was initially sorted. This array is rotated at some unknown point. 
The task is to find the minimum element in the given sorted and rotated array. 


Example 1:
Input:
N = 10
arr[] = {2,3,4,5,6,7,8,9,10,1}
Output: 1

Explanation: The array is rotated 
once anti-clockwise. So minium 
element is at last index (n-1) 
which is 1.


Example 2:
Input:
N = 5
arr[] = {3,4,5,1,2}
Output: 1

Explanation: The array is rotated 
and the minimum element present is
at index (n-2) which is 1.

Your Task:
The task is to complete the function minNumber() which takes the array arr[] and its starting 
and ending indices (low and high) as inputs and returns the minimum element in the given sorted and rotated array.

Expected Time Complexity: O(LogN).
Expected Auxiliary Space: O(LogN).

Constraints:
1 <= N <= 107
1 <= arr[i] <= 107
*/

int minNumber(int arr[], int lo, int hi)
    {
        // Your code here
        int mid;
        int n=hi;
        while(lo<=hi){
            mid = (lo+hi)/2;
            if(arr[mid]<arr[mid-1] || lo==hi){
                return arr[mid];
            }else if(arr[mid]>=arr[hi]){
                lo=mid+1;
            }else{
                 hi = mid-1;
            }
        }
    }
