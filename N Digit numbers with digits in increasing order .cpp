/*

Given an integer N, print all the N digit numbers in increasing order, 
such that their digits are in strictly increasing order(from left to right).


Example 1:
Input:
N = 1
Output:
0 1 2 3 4 5 6 7 8 9

Explanation:
Single digit numbers are considered to be 
strictly increasing order.


Example 2:
Input:
N = 2
Output:
12 13 14 15 16 17 18 19 23....79 89

Explanation:
For N = 2, the correct sequence is
12 13 14 15 16 17 18 19 23 and so on 
up to 89.

Your Task:  
You don't need to read input or print anything. Your task is to complete the function increasingNumbers()
which takes an integer N as an input parameter and return the list of numbers such that their digits are in strictly increasing order.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)
*/

void gen_nums(int num,vector<int> &res,int x,int n){
        if(n==0){
            res.push_back(num);
            return;
        }
        
        for(int i=(x+1);i<=9;i++){
            gen_nums((num*10+i),res,i,n-1); 
        }
    }
    
    vector<int> increasingNumbers(int n)
    {
        // Write Your Code here
        vector<int> res;
        if(n==1){
            for(int i=0;i<=9;i++){
                res.push_back(i);
            }
            return res;
        }else{
            gen_nums(0,res,0,n);
            return res;
        }
        
    }

Constraints:
1 <= N <= 9
