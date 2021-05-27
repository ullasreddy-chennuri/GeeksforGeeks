/*
Given an array containing 0s and 1s. Find the number of subarrays having equal number of 0s and 1s.


Example 1:
Input:
n = 7
A[] = {1,0,0,1,0,1,1}
Output: 8
Explanation: The index range for the 8 
sub-arrays are: (0, 1), (2, 3), (0, 3), (3, 4), 
(4, 5) ,(2, 5), (0, 5), (1, 6)


Example 2:
Input:
n = 5
A[] = {1,1,1,1,0}
Output: 1
Explanation: The index range for the 
subarray is (3,4).


Your Task:
You don't need to read input or print anything. 
Your task is to complete the function countSubarrWithEqualZeroAndOne() which takes the array arr[] 
and the size of the array as inputs and returns the number of subarrays with equal number of 0s and 1s.

Expected Time Complexity: O(n).
Expected Auxiliary Space: O(n).
*/


long long int countSubarrWithEqualZeroAndOne(int arr[], int n)
    {
        //Your code here
        
        //converting all 0's to -1's
        for(int i=0;i<n;i++){
            if(arr[i]==0){
                arr[i]=-1;
            }
        }
        
        //Calculating prefix sums 
        unordered_map<int,int> map;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            map[sum]++;
        }
        
        
        // iterating through map to take the count of frequencies of each sum whose values are >1    //so that each equal some make a pair or more in between
        unordered_map<int,int>::iterator it;
        long long freq=0;
        for(auto it=map.begin();it!=map.end();it++){
            //int k=
            if(it->second>1){
                freq+= (it->second)*(it->second-1)/2;
            }
        }
         
            if(map.find(0)!=map.end()){
                freq+=map[0];
            }
        
        return freq;
    }
