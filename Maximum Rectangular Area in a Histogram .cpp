/*
Find the largest rectangular area possible in a given histogram where the largest rectangle can be
made of a number of contiguous bars. For simplicity, assume that all bars have the same width and the width is 1 unit.

Example 1:

Input:
N = 7
arr[] = {6,2,5,4,5,1,6}
Output: 12


Example 2:
Input:
N = 8
arr[] = {7 2 8 9 1 3 6 5}
Output: 16

Explanation: Maximum size of the histogram 
will be 8  and there will be 2 consecutive 
histogram. And hence the area of the 
histogram will be 8x2 = 16.


Your Task:
The task is to complete the function getMaxArea() which takes the array arr[] and its size
N as inputs and finds the largest rectangular area possible and returns the answer.

Expected Time Complxity : O(N)
Expected Auxilliary Space : O(N)

Constraints:
1 ≤ N ≤ 106
1 ≤ arr[i] ≤ 1012
*/

#define ll long long

class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        ll max_area=INT_MIN;
        stack<int> st;
        for(int i=0;i<n;i++){
            if(st.empty() || arr[st.top()]<=arr[i]){
                st.push(i);
            }else{
                while(!st.empty() && arr[st.top()]>arr[i]){
                    int t = st.top();
                    st.pop();
                    ll area;
                    if(st.empty()){
                       area = arr[t]*i;
                    }else{
                        area = arr[t]*(i-st.top()-1);
                    }
                    max_area = max(max_area,area);
                }
                st.push(i);
            }
        }
        while(!st.empty()){
            int t=st.top();
            st.pop();
            ll area;
            if(st.empty()){
                area = arr[t]*n;
            }else{
                area = arr[t]*(n-st.top()-1);
            }
            max_area = max(max_area,area);
        }
        return max_area;
    }
};
