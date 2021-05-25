/*
Given a mathematical equation using numbers/variables and +, -, *, /. Print the equation in reverse.

Example 1:
Input:
S = "20-3+5*2"
Output: 2*5+3-20

Explanation: The equation is reversed with
numbers remaining the same.

â€‹Example 2:
Input: 
S = "a+b*c-d/e"
Output: e/d-c*b+a

Explanation: The equation is reversed with
variables remaining the same.

Your Task:
You don't need to read input or print anything. Your task is to complete the function reverseEqn() 
which takes the string S representing the equaltion as input and returns the resultant string representing the equaltion in reverse.


Expected Time Complexity: O(|S|).
Expected Auxiliary Space: O(|S|).


Constraints:
1<=|S|<=105
*/

string reverseEqn (string s)
        {
            //code here.
            int n=s.length();
            stack<char> st;
            for(int i=0;i<n;){
                if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'){
                    st.push(s[i]);
                    i++;
                }else{
                    string temp="";
                    while(s[i]!='+'&&s[i]!='-'&&s[i]!='*'&&s[i]!='/' && i<n){
                        temp+=s[i];
                        i++;
                    }
                    for(int k=temp.length()-1;k>=0;k--){
                        st.push(temp[k]);
                    }
                    //i++;
                }
            }
            string res="";
            while(!st.empty()){
                char c=st.top();
                st.pop();
                res+=c;
            }
            return res;
        }
