/*

Given a string S, find the length of the longest substring without repeating characters.


Example 1:
Input:
S = "geeksforgeeks"
Output:
7

Explanation:
Longest substring is
"eksforg".


Example 2:
Input:
S = "abdefgabef"
Output:
6

Explanation:
Longest substring are
"abdefg" , "bdefga" and "defgab".
 

Your Task:
You don't need to take input or print anything. Your task is to complete the function longestUniqueSubsttr() 
which takes a string S as and returns the length of the longest substring.

 

Expected Time Complexity: O(|S|).
Expected Auxiliary Space: O(K) where K is constant.


Constraints:
1 ≤ |S| ≤ 105
It is guaranteed that all characters of the String S will be lowercase letters from 'a' to 'z'
*/

    int longestUniqueSubsttr(string s){
        //code
        vector<int> mp(256,-1);
        int max_length=0;
        int start = 0;
        for(int i=0;i<s.length();i++){
            start = max(start,mp[s[i]]+1);
            max_length = max(max_length, i-start+1);
            mp[s[i]]=i;
        }
        
        //int len = s.length()-start;
        return max_length;
    }
