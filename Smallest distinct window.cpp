/*
Given a string 's'. The task is to find the smallest window length that contains all the characters of the given string at least one time.
For eg. A = “aabcbcdbca”, then the result would be 4 as of the smallest window will be “dbca”.

Example 1:
Input : "AABBBCBBAC"
Output : 3

Explanation : Sub-string -> "BAC"


Example 2:
Input : "aaab"
Output : 2

Explanation : Sub-string -> "ab"
 
 
Example 3:
Input : "GEEKSGEEKSFOR"
Output : 8

Explanation : Sub-string -> "GEEKSFOR"

Your Task:  
You don't need to read input or print anything. Your task is to complete the function findSubString() 
which takes the string  S as inputs and returns the length of the smallest such string.

Expected Time Complexity: O(256.N)
Expected Auxiliary Space: O(256)

Constraints:
1 ≤ |S| ≤ 105
String may contain both type of English Alphabets.
*/

    string findSubString(string s)
    {
        // Your code goes here   
        string p = "";
        int l1 = s.length();
        vector<int> hstr(256,0);
        vector<int> hpat(256,0);
        
        unordered_map<char,int> mp;
        for(int i=0;i<l1;i++){
           // mp[s[i]]++;
            if(hpat[s[i]]==1){
                continue;
            }else if(mp[s[i]]==0){
                mp[s[i]]++;
                p+=s[i];
                //cout<<p<<endl;
            }
        }
        
        //cout<<" string is : "<<p<<endl;

        int l2 = p.length();
        for(int i=0;i<l2;i++){
            hpat[p[i]]++;
        }
        int min_len=INT_MAX;
        int count=0;
        int start=0;
        int start_index=-1;
        for(int i=0;i<=l1;i++){
            hstr[s[i]]++;
            //cout<<s[i]<<endl;
            if(hstr[s[i]]<=hpat[s[i]]){
                count++;
               // cout<<"count is:"<<count<<endl;
            }
            if(count==l2){
                while(hstr[s[start]]>hpat[s[start]]){
                    hstr[s[start]]--;
                    start++;
                   // cout<<"start is:"<<start<<endl;
                }
               // cout<<i<<endl;
                int len = i-start+1;
                //cout<<len<<endl;
                if(len<min_len){
                    min_len = len;
                    start_index = start;
                   // cout<<"min length is: "<<min_len<<"for i: "<<i<<endl;
                }
            }
        }
        if(start_index==-1){
            return "-1";
        }
        return s.substr(start_index,min_len);
    }

