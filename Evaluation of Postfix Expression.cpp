/*
Given string S representing a postfix expression, the task is to evaluate the expression and find the final value. 
Operators will only include the basic arithmetic operators like *, /, + and -.

Example 1:
Input: S = "231*+9-"
Output: -4

Explanation:
After solving the given expression, 
we have -4 as result.
 

Example 2:
Input: S = "123+*8-"
Output: -3

Explanation:
After solving the given postfix 
expression, we have -3 as result.


Your Task:
You do not need to read input or print anything. Complete the function evaluatePostfixExpression()
that takes the string S denoting the expression as input parameter and returns the evaluated value.


Expected Time Complexity: O(|S|)
Expected Auixilliary Space: O(|S|)


Constraints:
1 ≤ |S| ≤ 105
*/

bool is_operator(char c){
        if(c=='^'||c=='*'||c=='/'||c=='+'||c=='-'){
            return true;
        }
        return false;
    }

    int eval(int a,int b,char c){
        if(c=='^'){
            return a^b;
        }else if(c=='/'){
            return a/b;
        }else if(c=='*'){
            return a*b;
        }else if(c=='+'){
            return a+b;
        }else{
            return a-b;
        }
    }
    
    int evaluatePostfix(string s)
    {
        // Your code here
        int n=s.length();
        stack<int> st;
        for(int i=0;i<n;i++){
            if(is_operator(s[i])){
                int op1,op2;
                op2=st.top();
                st.pop();
                op1=st.top();
                st.pop();
                int res = eval(op1,op2,s[i]);
                //cout<<op1<<" "<<op2<<endl;
                //cout<<"res - "<<res<<endl;
                st.push(res);
            }else{
                int k =s[i]-'0';
                //cout<<"pushing : "<<k<<endl;
                st.push(k);
            }
        }
        int fres=st.top();
        return fres;
    }
