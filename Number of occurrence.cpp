/*

Given a sorted array Arr of size N and a number X, 
you need to find the number of occurrences of X in Arr.

Example 1:

Input:
N = 7, X = 2
Arr[] = {1, 1, 2, 2, 2, 2, 3}
Output: 4
Explanation: 2 occurs 4 times in the
given array.
Example 2:

Input:
N = 7, X = 4
Arr[] = {1, 1, 2, 2, 2, 2, 3}
Output: 0

Explanation: 4 is not present in the
given array.

Your Task:
You don't need to read input or print anything. 
Your task is to complete the function count() which takes the array of integers 
arr, n and x as parameters and returns an integer denoting the answer.

Expected Time Complexity: O(logN)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ N ≤ 105
1 ≤ Arr[i] ≤ 106
1 ≤ X ≤ 106
*/

int first_occ(int arr[],int n,int key){
	    int lo=0,hi=n-1;
	    while(lo<=hi){
	        int mid=(lo+hi)/2;
	        if(arr[mid]==key){
	            if(mid==0){
	                return mid;
	            }
	            if(arr[mid-1]!=key){
	                return mid;
	            }else if(arr[mid-1]==key){
	                hi=mid-1;
	            }else{
	                lo=mid+1;
	            }
	        }else if(arr[mid]>key){
	            hi=mid-1;
	        }else{
	            lo=mid+1;
	        }
	    }
	    return -1;
	}	
		
	int last_occ(int arr[],int n,int key){
	    int lo=0,hi=n-1;
	    while(lo<=hi){
	        int mid=(lo+hi)/2;
	        if(arr[mid]==key){
	            if(mid==n-1){
	                return mid;
	            }
	            if(arr[mid+1]!=key){
	                return mid;
	            }else if(arr[mid+1]==key){
	                lo=mid+1;
	            }else{
	                hi=mid-1;
	            }
	        }else if(arr[mid]>key){
	            hi=mid-1;
	        }else{
	            lo=mid+1;
	        }
	    }
	    return -1;
	}	
	
	int count(int arr[], int n, int x) {
	    // code here
	    int k = first_occ(arr,n,x);
	    int l = last_occ(arr,n,x);
	    if(k==-1){
	        return 0;
	    }
	    return l-k+1;
	}
