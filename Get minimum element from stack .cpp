/*

You are given N elements and your task is to Implement a Stack in which you can get minimum element in O(1) time.

Example 1:

Input:
push(2)
push(3)
pop()
getMin()
push(1)
getMin()
Output: 3 2 1

Explanation: In the first test case for
query 
push(2)  the stack will be {2}
push(3)  the stack will be {2 3}
pop()    poped element will be 3 the
         stack will be {2}
getMin() min element will be 2 
push(1)  the stack will be {2 1}
getMin() min element will be 1


Your Task:
You are required to complete the three methods push() which take one argument an integer 'x' to be pushed into the stack, pop() which returns a integer poped out from the stack and getMin() which returns the min element from the stack. (-1 will be returned if for pop() and getMin() the stack is empty.)

Expected Time Complexity : O(1) for all the 3 methods.
Expected Auixilliary Space : O(1) for all the 3 methods.

Constraints:
1 <= Number of queries <= 100
1 <= values of the stack <= 100

*/


/*returns min element from stack*/
int _stack :: getMin()
{
   //Your code here
   if(s.empty()){
       return -1;
   }
   return minEle;
}

/*returns poped element from stack*/
int _stack ::pop()
{
   //Your code here
   if(s.empty()){
       return -1;
   }
   int t = s.top();
   s.pop();
   if(t>=minEle){
       //s.pop();
       return t;
   }else{
       int k=minEle;
       minEle = 2*minEle - t;
       return k;
   }
}

/*push element x into the stack*/
void _stack::push(int x)
{
   //Your code here
   if(s.empty()){
       minEle = x;
       s.push(x);
   }else{
       if(minEle>x){
           s.push(2*x-minEle);
           minEle = x;
       }else{
           s.push(x);
       }
   }
   
}
