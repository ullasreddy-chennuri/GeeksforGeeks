/*
Dilpreet wants to paint his dog's home that has n boards with different lengths. 
The length of ith board is given by arr[i] where arr[] is an array of n integers. 
He hired k painters for this work and each painter takes 1 unit time to paint 1 unit of the board. 

The problem is to find the minimum time to get this job done if all painters start together with the constraint 
that any painter will only paint continuous boards, say boards numbered {2,3,4} or only board {1} or nothing but not boards {2,4,5}.



Example 1:
Input:
n = 5
k = 3
arr[] = {5,10,30,20,15}
Output: 35

Explanation: The most optimal way will be:
Painter 1 allocation : {5,10}
Painter 2 allocation : {30}
Painter 3 allocation : {20,15}
Job will be done when all painters finish
i.e. at time = max(5+10, 30, 20+15) = 35



Example 2:
Input:
n = 4
k = 2
arr[] = {10,20,30,40}
Output: 60

Explanation: The most optimal way to paint:
Painter 1 allocation : {10,20,30}
Painter 2 allocation : {40}
Job will be complete at time = 60
 

Your task:
Your task is to complete the function minTime() which takes the integers n and k and 
the array arr[] as input and returns the minimum time required to paint all partitions.

Expected Time Complexity: O(n log m) , m = sum of all boards' length
Expected Auxiliary Space: O(1)

Constraints:
1 <= n <= 105
1 <= k <= 105
1 <= arr[i] <= 105
*/

bool solve(int arr[],long long val,long long count,int n){
        long long sum=0;
        int k=1;    // to make note of no of painters used
        int i;
        for(i=0;i<n;i++){
            if(sum+arr[i]>val){ 
            // if sum value increases by adding new element, add new painter
                k++;
                sum=arr[i];
                // check whether new painters exists 
                // if no painters left, then return false
                if(k>count){
                    return false;
                }
            }else{  
                sum+=arr[i];
            }
            // if array element itself is greater than val, return false directly
            if(arr[i]>val){
                return false;
            }
        }
        
        return true;
        
    }
    
    long long minTime(int arr[], int n, int k)
    {
        // using binary search approach
        // code here
        //1. Calculate the total_sum of array
        //2. find the max element of array
        long long max=INT_MIN;
        long long sum=0;
        
        for(int i=0;i<n;i++){
            if(arr[i]>max){
                max=arr[i];
            }
            sum+=arr[i];
        }
        
        //3.loop from max of array to sum of array as 
        // answer lies in between those ranges
        // apply binarysearch here to reduce TC..
        //4.we form a bitonic array, very for each and 
        //return the answer which is least possible
        long long lo=max,hi=sum;
        long long mid;
        long long ans=hi; 
        while(lo<=hi){
            mid=(lo+hi)/2;
            if(solve(arr,mid,k,n)){
                ans = mid;  // noting the minimum answer every time and checking for other
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }
        return ans;
        // return minimum time
    }
