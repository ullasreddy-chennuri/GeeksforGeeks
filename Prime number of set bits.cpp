/*

Given two integers L and R, write a program that finds the count of numbers having
prime number of set bits in their binary representation in the range [L, R].

Example 1:
Input: L = 6, R = 10
Output: 4
Explanation: 6, 7, 9, 10 having
prime set bits between 6 and 10. 


Example 2:
Input: L = 10, R = 15
Output: 5
Explanation: 10, 11, 12, 13, 14 having
prime set bits between 10 and 15.

Your Task:  
You dont need to read input or print anything. Complete the function primeSetBits() 
which takes L and R as input parameter and returns the count of numbers having prime number of set bits in their binary representation.

Expected Time Complexity: O(nlog(n)sqrt(n))
Expected Auxiliary Space: O(1)

Constraints:
1 <= L <= R <=1000
*/

bool is_prime(int n){
      if(n==1)
      {
          return false;
      }
      for(int i=2;i*i<=n;i++){
          if(n%i==0){
              return false;
          }
      }
      return true;
    }
    
    int setCount(int N){
        int s=0;
        while(N){
            if(N&1){
                s++;
            }
           N=N>>1;
        }
        
        return s;
    }
    
    
  
    int primeSetBits(int L, int R){
        // code here
        int sum=0;
        for(int i=L;i<=R;i++){
            //int k=setCouhnt(i);
            if(is_prime(setCount(i))){
                sum++;
            }
        }
        
        return sum;
    }
