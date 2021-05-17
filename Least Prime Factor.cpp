/*
Given a number N, find least prime factors for all numbers from 1 to N.  The least prime factor of an integer N is the smallest prime number that divides it.
Note : The least prime factor of all even numbers is 2. A prime number is its own least prime factor (as well as its own greatest prime factor).
1 needs to be printed for 1.â€‹

Example 1:

Input: N = 6
Output: [1, 2, 3, 2, 5, 2] 
Explanation: least prime factor of 1 = 1,
least prime factor of 2 = 2,
least prime factor of 3 = 3,
least prime factor of 4 = 2,
least prime factor of 5 = 5,
least prime factor of 6 = 2.
So answer is[1, 2, 3, 2, 5, 2]. 

Example 2:

Input: N = 4
Output: [1, 2, 3, 2]
Explanation: least prime factor of 1 = 1,
least prime factor of 2 = 2,
least prime factor of 3 = 3,
least prime factor of 4 = 2.
So answer is[1, 2, 3, 2]. 

Your Task:  
You dont need to read input or print anything. Complete the function leastPrimeFactor() which takes N as input parameter 
and returns a list of integers containing all the least prime factor of each numbers from 1 to N.

Expected Time Complexity: O(NlogN)
Expected Auxiliary Space: O(N)

Constraints:
2<= n <=103*/


vector<int> leastPrimeFactor(int n) {
        // code here
        vector<int>lpf(n+1,0);
        lpf[1]=1;
        for(int i=2;i<=n;i++){
            if(lpf[i]==0){
                lpf[i]=i;
                for(int j=i*i;j<=n;j=j+i){
                    if(lpf[j]==0){
                        lpf[j]=i;
                    }
                }
            }
        }
        
        return lpf;
    }
