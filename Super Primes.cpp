/*
A prime number is Super Prime if it is a sum of two primes. Find all the Super Primes upto N


Example 1:
Input:
N = 5
Output: 1
Explanation: 5 = 2 + 3, 5 is the
only super prime


Example 2:
Input:
N = 10 
Output: 2
Explanation: 5 and 7 are super primes

Your Task:  
You don't need to read input or print anything. 
Your task is to complete the function superPrimes() which takes 
the N as input and returns the count of super primes.

Expected Time Complexity: O(Nlog(logN))
Expected Auxiliary Space: O(N)

Constraints:
1 ≤ N ≤ 105
*/

int pair_sum(int arr[],int n){
	    int c=0;
	    // Except 2 every prime number is odd
	    // adding two odd numbers always give even non prime number
	    // so we have to consider prime numbers whose difference is two
	    for(int i=2;i<=n;i++){
	        //ex: consider i = 5
	        // i-2 == 3 is also prime 
	        //=> 3+2 = 5 exists so increase count..
	        // similarly for 7, 5 is prime so 5+2 is possible, so count increase.
	        if(arr[i] && arr[i-2]){
	            c++;
	        }
	    }
	    return c;
	}
	
	
	int superPrimes(int n)
	{
	    // Your code goes here
	    int sieve[n];
	    sieve[1]=0;
	    for(int i=2;i<=n;i++){
	        sieve[i]=1;
	    }
      // making array of prime numbers
	    for(int i=2;i*i<=n;i++){
	        if(sieve[i]==1){
	            for(int j=i*i;j<=n;j=j+i){
	                sieve[j]=0;
	            }
	        }
	    }
	    
	    int c = pair_sum(sieve,n);
	    return c;
	}
