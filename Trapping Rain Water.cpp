/*
Given an array arr[] of N non-negative integers representing the height of blocks. 
If width of each block is 1, compute how much water can be trapped between the blocks during the rainy season. 
 
 
Example 1:
Input:
N = 6
arr[] = {3,0,0,2,0,4}
Output:
10


Example 2:
Input:
N = 4
arr[] = {7,4,0,9}
Output:
10

Explanation:
Water trapped by above 
block of height 4 is 3 units and above 
block of height 0 is 7 units. So, the 
total unit of water trapped is 10 units.


Example 3:
Input:
N = 3
arr[] = {6,9,9}
Output:
0

Explanation:
No water will be trapped.

Your Task:
You don'y need to read input or print anything. The task is to complete the function trappingWater() 
which takes arr and N as input parameters and returns the total amount of water that can be trapped.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)


Constraints:
3 <= N <= 107
0 <= Ai <= 108
*/

    int trappingWater(int arr[], int n){
        // Code here
        int left[n];
        int right[n];
        left[0]=arr[0];
        right[n-1]=arr[n-1];
        
        // filling array with left max elements
        for(int i=1;i<n;i++){
            if(arr[i]>left[i-1]){
                left[i]=arr[i];
            }else{
                left[i]=left[i-1];
            }
        }
        
        //filling elements with right max elements 
        for(int i=n-2;i>=0;i--){
            if(arr[i]<right[i+1]){
                right[i]=right[i+1];
            }else{
                right[i]=arr[i];
            }
        }
        
        //calculating the water level
        int sum=0;
        for(int i=0;i<n;i++){
            if((min(left[i],right[i])-arr[i])<0){
                continue;
            }else{
                sum=sum+(min(left[i],right[i]) - arr[i]);
            }
           // sum= sum + ;
        }
        return sum;
    }
