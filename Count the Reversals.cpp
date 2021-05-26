/*
Given a string S consisting of only opening and closing curly brackets '{' and '}', 
find out the minimum number of reversals required to convert the string into a balanced expression.
A reversal means changing '{' to '}' or vice-versa.


Example 1:
Input:
S = "}{{}}{{{"
Output: 3

Explanation: One way to balance is:
"{{{}}{}}". There is no balanced sequence
that can be formed in lesser reversals.


â€‹Example 2:
Input: 
S = "{{}{{{}{{}}{{"
Output: -1

Explanation: There's no way we can balance
this sequence of braces.



Your Task:
You don't need to read input or print anything. Your task is to complete the function countRev() 
which takes the string S as input parameter and returns the minimum number of reversals required to 
balance the bracket sequence. If balancing is not possible, return -1. 

Expected Time Complexity: O(|S|).
Expected Auxiliary Space: O(1).

Constraints:
1 ≤ |S| ≤ 105
*/


int countRev (string s)
{
    // your code here
    int l=s.length();
    if(l%2!=0){
        return -1;
    }
    int m=0,n=0;
    int i=0;
    while(i<l){
        if(s[i]=='{'){
            m++;
        }else if(m && s[i]=='}'){
            m--;
        }else{
            n++;
        }
        i++;
    }
    
    return m%2==0? (ceil(m/2)+ceil(n/2)) : 2+(ceil(m/2)+ceil(n/2)) ;
}
