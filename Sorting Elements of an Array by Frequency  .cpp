/*
Given an array of integers, sort the array according to frequency of elements. 
That is elements that have higher frequency come first. If frequencies of two elements are same, 
then smaller number comes first.

Example 1:
Input:
N = 5
A[] = {5,5,4,6,4}
Output: 4 4 5 5 6

Explanation: The highest frequency here is
2. Both 5 and 4 have that frequency. Now
since the frequencies are same then 
smallerelement comes first. So 4 4 comes 
firstthen comes 5 5. Finally comes 6.
The output is 4 4 5 5 6.


Example 2:
Input:
N = 5
A[] = {9,9,9,2,5}
Output: 9 9 9 2 5

Explanation: The highest frequency here is
3. The element 9 has the highest frequency
So 9 9 9 comes first. Now both 2 and 5
have same frequency. So we print smaller
element first.
The output is 9 9 9 2 5.


Your Task:
You only need to complete the function sortByFreq that takes arr, and n as parameters and returns the sorted array.


Expected Time Complexity: O(NLogN).
Expected Auxiliary Space: O(N). 


Constraints:
1 ≤ N ≤ 105
1 ≤ Ai ≤ 105 

*/

bool mycomp(const pair<int,int> &a,const pair<int,int> &b){
    if(a.first!=b.first){
        return a.first>b.first;
    }else{
        return a.second<b.second;
    }
        
}

class Solution{
    
    public:
    //Complete this function
    //Function to sort the array according to frequency of elements.
    
    
    
    vector<int> sortByFreq(int arr[],int n)
    {
        //Your code here
        unordered_map<int,int> map;
        for(int i=0;i<n;i++){
            map[arr[i]]++;
        }
        
        vector<pair<int,int>> res;
        
        unordered_map<int,int>::iterator it1;
        for(auto it1=map.begin();it1!=map.end();it1++){
            res.push_back(make_pair(it1->second,it1->first));
        }
        sort(res.begin(),res.end(), mycomp);
        vector<int> freq;
        for(int i=0;i<res.size();i++){
            while(res[i].first>0){
                freq.push_back(res[i].second);
                res[i].first=res[i].first-1;
            }
        }
        
        return freq;
    }
};
