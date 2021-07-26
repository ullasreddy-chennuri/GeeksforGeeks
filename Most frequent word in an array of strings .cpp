/*

Given an array arr containing N words consisting of lowercase characters.
Your task is to find the most frequent word in the array. If multiple words have same frequency, 
then print the word whose first occurence occurs last in the array as compared to the other strings with same frequency.


Example 1:
Input:
N = 3
arr[] = {geeks,for,geeks}
Output: geeks

Explanation: "geeks" comes 2 times.


Example 2:
Input:
N = 2
arr[] = {hello,world}
Output: world

Explanation: "hello" and "world" both
have 1 frequency. We print world as
its first occurence comes last in the
input array.


Your Task:
Complete mostFrequentWord function which takes array of strings and its length as arguments 
and returns the most frequent word. The printing is done by the driver code.

Expected Time Complexity: O(N * WORD_LEN).
Expected Auxiliary Space: O(N * WORD_LEN).

Constraints:
1 <= N <= 50000
1 <= |each string| <= 50
Sum of length of every string does not exceed 5*105

*/

class Solution
{
    public:
    //Function to find most frequent word in an array of strings.
    struct node{
        string s;
        int c;
    };
   
    string mostFrequentWord(string arr[], int n) 
    {
        // code here
        node res[n];
        unordered_map<string,int> mp;
        int maxi=1;
        for(int i=n-1;i>=0;i--){
            mp[arr[i]]++;
            maxi = max(maxi,mp[arr[i]]);
            res[i].s=arr[i];
            res[i].c=mp[arr[i]];
        }
       
        string ans="";
        for(int i=0;i<n;i++){
           if(res[i].c == maxi){
               ans = res[i].s;
           }
        }
        
    
        return ans;
    }
};
