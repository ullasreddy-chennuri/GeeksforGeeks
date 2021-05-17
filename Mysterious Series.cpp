/*
Find the Nth term of the Mysterious series.
N    Nth term
1    5
2    10
3    26
4    50
5    122
.
.
.
10    842

Example 1:

Input: N = 1
Output: 5 
Explanation: First term of the series is 5.
Example 2:

Input: N = 2
Output: 10
Explanation: Second term of the series is 10. 


Your Task:  
You dont need to read input or print anything. 
Complete the function nthMysterious() which takes N as input parameter and returns the Nth term of the Mysterious series.

Expected Time Complexity: O(nlogn)
Expected Auxiliary Space: O(n)

Constraints:
1<= N <=103*/


// The mysterioes is nothing but the square(nth-prime)+1;

//code:



bool is_prime(long long n){
        for(long long i=2;i*i<=n;i++){
            if(n%i==0){
                return false;
            }
        }
        
        return true;
    }
  
    long long nthMysterious(long long n){
        // code here
        long long N=n;
        vector<long long>primes;
        primes.push_back(1);
        int k=2;
        while(true){
            if(is_prime(k)){
                primes.push_back(k);
                N--;
                if(N==0){
                    break;
                }
            }
            k++;
        }
        long long res = primes[n];
        res = res*res + 1;
        return res;
    }





