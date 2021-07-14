/*

Given elements of a stack, clone the stack without using extra space.


Example 1:
Input:
N = 10
st[] = {1, 1, 2, 2, 3, 4, 5, 5, 6, 7}
Output:
1 


Your Task:  
You don't need to read input or print anything.
Your task is to complete the function clonestack() which takes the input stack st[], 
an empty stack cloned[], you have to clone the stack st into stack cloned.
The driver code itself prints 1 in the output if the stack st is cloned properly and prints 0 otherwise.


Expected Time Complexity: O(N*N)
Expected Auxiliary Space: O(1)
 

Constraints:
1 <= N <= 1000
1<= st[i] <= 105
*/

    void insert_at_bottom(stack<int> &st,int k){
        if(st.empty()){
            st.push(k);
        }else{
            int t=st.top();
            st.pop();
            insert_at_bottom(st,k);
            st.push(t);
        }
    }
    
    void rever(stack<int> &st){
        if(!st.empty()){
            int k = st.top();
            st.pop();
            rever(st);
            insert_at_bottom(st,k);
        }
    }
    
    void clonestack(stack<int> st, stack<int>& cloned)
    {
        //code here
        rever(st);
        while(!st.empty()){
            int k=st.top();
            st.pop();
            cloned.push(k);
        }
       
    }
