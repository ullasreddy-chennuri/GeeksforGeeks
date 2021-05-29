/*
Given a sorted array arr[] of size N without duplicates, and given a value x. 
Floor of x is defined as the largest element K in arr[] such that K is smaller than or equal to x. 
Find the index of K(0-based indexing).


Example 1:
Input:
N = 7, x = 0 
arr[] = {1,2,8,10,11,12,19}
Output: -1

Explanation: No element less 
than 0 is found. So output 
is "-1".


Example 2:
Input:
N = 7, x = 5 
arr[] = {1,2,8,10,11,12,19}
Output: 1

Explanation: Largest Number less than 5 is
2 (i.e K = 2), whose index is 1(0-based 
indexing).

Your Task:
The task is to complete the function findFloor() which returns an integer 
denoting the index value of K or return -1 if there isn't any such number.

Expected Time Complexity: O(log N).
Expected Auxiliary Space: O(1).

Constraints:
1 ≤ N ≤ 107
1 ≤ arr[i] ≤ 1018
0 ≤ X ≤ arr[n-1]
*/

int findFloor(long long int arr[], int n, long long int key) {
    
    //Your code here
    long long lo=0,hi=n-1;
    long long mid;
    while(lo<=hi){
        mid=(lo+hi)/2;
        if(arr[mid]==key){
            return mid;
        }
        if(arr[mid]<key){
            if(mid==n-1){
                return mid;
            }
            if(arr[mid+1]<=key){
                lo=mid+1;
            }else{
                return mid;
            }
        }else{
            hi=mid-1;
        }
    }
    return -1;
}
