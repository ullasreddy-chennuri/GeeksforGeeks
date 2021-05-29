/*
Given two unsorted arrays arr1[] and arr2[]. They may contain duplicates. 
For each element in arr1[] count elements less than or equal to it in array arr2[].

Example 1:

Input:
m = 6, n = 6
arr1[] = {1,2,3,4,7,9}
arr2[] = {0,1,2,1,1,4}
Output: 4 5 5 6 6 6
Explanation: Number of elements less than
or equal to 1, 2, 3, 4, 7, and 9 in the
second array are respectively 4,5,5,6,6,6
Example 2:

Input:
m = 5, n = 7
arr1[] = {4 8 7 5 1}
arr2[] = {4,48,3,0,1,1,5}
Output: 5 6 6 6 3
Your Task :
Complete the function countEleLessThanOrEqual() that takes two array arr1[], arr2[],  
m, and n as input and returns an array containing the required results
(the count of elements less than or equal to it in arr2 for each element in arr1 where ith output represents the count for ith element in arr1.)

Expected Time Complexity: O((m + n) * log n).
Expected Auxiliary Space: O(1).

Constraints:
1<=m,n<=10^5
1<=arr1[i],arr2[j]<=10^5
*/

    
int b_search(int arr[], int n, int key) {
    
    //Your code here
    int lo=0,hi=n-1;
    int mid;
    if(key >= arr[n-1]){
        return n-1;
    }
    if(key<arr[0]){
        return -1;
    }
    while(lo<=hi){
        mid=(lo+hi)/2;
        if(arr[mid]<=key){
            lo=mid+1;
        }else{
            hi=mid-1;
        }
    }
    return hi;
}
  
    vector<int> countEleLessThanOrEqual(int arr1[], int arr2[], 
                                 int m, int n)
    {
        //Your code goes here
        vector<int> res;
        sort(arr2,arr2+n);
        for(int i=0;i<m;i++){
            int temp = b_search(arr2,n,arr1[i]);
            if(temp!=-1){
                res.push_back(temp+1);
            }else{
                res.push_back(0);
            }
        }
        return res;
    }
