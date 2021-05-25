/*
Given a string s and an integer k, the task is to reduce the string by applying the following operation:
Choose a group of k consecutive identical characters and remove them.

The operation can be performed any number of times until it is no longer possible.


Example 1:
Input:
k = 2
s = "geeksforgeeks"

Output:
gksforgks

Explanation:
Modified String after each step: 
"geeksforgeeks" -> "gksforgks"


Example 2:
Input:
k = 2
s = "geegsforgeeeks" 

Output:
sforgeks

Explanation:
Modified String after each step:
"geegsforgeeeks" -> "ggsforgeks" -> "sforgeks"
Your Task:  
You don't need to read input or print anything. Complete the function Reduced_String()
which takes integer k and string s as input parameters and returns the reduced string.

Expected Time Complexity: O(|s|)
Expected Auxiliary Space: O(|k|)

Constraints:
1 ≤ |s| ≤ 105
1 ≤ k ≤ |s|

*/

string Reduced_String(int k,string s){
        // Your code goes here
        string res="";
        while(true){
            int lb=0;
            for(int i=0;i<s.length();){
                int c=1;
                int j=i;
                while(s[j]==s[j+1] && c<k){
                    j++;
                   // lb++;
                    c++;
                }
                if(c==k){
                    lb++;
                    i=i+k;
                }else{
                    res+=s[i];
                    i++;
                }
            }
            s = res;
            res="";
            if(lb==0){
                break;
            }
        }
    return s;
}
