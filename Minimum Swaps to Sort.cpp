/*
Given an array of n distinct elements.
Find the minimum number of swaps required to sort the array in strictly increasing order.


Example 1:

Input:
nums = {2, 8, 5, 4}
Output:
1
Explaination:
swap 8 with 4.


Example 2:
Input:
nums = {10, 19, 6, 3, 5}
Output:
2

Explaination:
swap 10 with 3 and swap 19 with 5.

Your Task:
You do not need to read input or print anything. 
Your task is to complete the function minSwaps() which takes the nums as input parameter and returns
an integer denoting the minimum number of swaps required to sort the array. If the array is already sorted, return 0. 


Expected Time Complexity: O(nlogn)
Expected Auxiliary Space: O(n)


Constraints:
1 ≤ n ≤ 105
1 ≤ numsi ≤ 106
*/

	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    int n=nums.size();
	    vector<pair <int,int>> arr;
	    for(int i=0;i<n;i++){
	        arr.push_back(make_pair(nums[i],i));
	    }
	    sort(arr.begin(),arr.end());
	    int c=0;
	    for(int i=0;i<n;i++){
	        int k=arr[i].second;
	        if(i!=k){
	            swap(arr[i],arr[k]);
	            c++;
	            i--;
	        }
	    }
	    return c;
	}

