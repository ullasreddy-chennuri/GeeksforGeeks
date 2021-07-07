/*
Given two strings S and P. Find the smallest window in the S consisting of all the characters of P.

Example 1:
Input:
S = "timetopractice"
P = "toc"
Output: 
toprac

Explanation: "toprac" is the smallest
substring in which "toc" can be found.


Example 2:
Input:
S = "zoomlazapzo"
P = "oza"
Output: 
apzo

Explanation: "apzo" is the smallest 
substring in which "oza" can be found.

Your Task:
You don't need to read input or print anything. Your task is to complete the function smallestWindow() 
which takes two string S and P as input paramters and returns the smallest window in string S having all the characters of the string P. 
In case there are multiple such windows of same length, return the one with the least starting index. Return "-1" in case there is no such window present. 

Expected Time Complexity: O(|S|)
Expected Auxiliary Space: O(1)

Constraints: 
1 ≤ |S|, |P| ≤ 105
*/

class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        // Your code here
        // using hashing brute force
    //     int min_len = INT_MAX;
    //     int start =-1;
    //     unordered_map<char,int> pat;
    //     for(int i=0;i<p.length();i++){
    //         pat[p[i]]++;
    //     }
    //     int count = 0;
    //     for(int i=0;i<s.length();i++){
    //         unordered_map<char,int> st;
    //         count=0;
    //         for(int j=i;j<s.length();j++){
    //             st[s[j]]++;
    //             if(st[s[j]]<=pat[s[j]]){
    //                 count++;
    //             }
    //             if(count == p.length()){
    //                 int len = j-i+1;
    //                 if(len<min_len){
    //                     min_len = len;
    //                     start = i;
    //                     break;
    //                 }                    
    //             }
    //         }
    //     }
    //     if(start==-1){
    //         return "-1";
    //     }
    //     return s.substr(start,min_len);
    // }
    
    
    // same code as above but implementing Two pointer approach
        int l1 = s.length();
        int l2 = p.length();
        vector<int> hstr(256,0);
        vector<int> hpat(256,0);
        for(int i=0;i<l2;i++){
            hpat[p[i]]++;
        }
        
        int start_index = -1;
        int start=0;
        int min_len = INT_MAX;
        int count=0;
        for(int i=0;i<l1;i++){
            hstr[s[i]]++;
            if(hstr[s[i]]<=hpat[s[i]]){
                count++;
            }
            if(count == l2){
                while(hstr[s[start]]>hpat[s[start]]){
                    hstr[s[start]]--;
                    start++;
                }
                int len = i-start+1;
                if(len<min_len){
                    start_index = start;
                    min_len = len;
                }
            }
            
        }
        
        if(start_index == -1){
            return "-1";
        }
        return s.substr(start_index,min_len);
    }
    
};
