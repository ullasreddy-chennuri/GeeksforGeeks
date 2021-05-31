/*
Given a string S. The task is to find all permutations of a given string.

Example 1:
Input:
S = ABC
Output: ABC ACB BAC BCA CAB CBA 


Example 2:
Input:
S = ABSG
Output: ABGS ABSG AGBS AGSB ASBG ASGB
BAGS BASG BGAS BGSA BSAG BSGA GABS
GASB GBAS GBSA GSAB GSBA SABG SAGB
SBAG SBGA SGAB SGBA
 

Your Task:
This is a function problem. You only need to complete the function permutation that 
takes S as parameter and returns the list of permutations in lexicographically increasing order. 
The newline is automatically added by driver code.

Constraints:
1 ≤ size of string ≤ 5

Expected Time Complexity: O(N * N!), N = length of string.
Expected Auxiliary Space: O(1)
*/

void permute(string str,int i,int n,vector<string> &res){
        if(i==n){
            res.push_back(str);
            return;
        }
        
        for(int j=i;j<n;j++){
            // swapping the first element
            swap(str[i],str[j]);
            // rec call for remaining elements
            permute(str,i+1,n,res);
            // restoring or bactracking original array
            swap(str[i],str[j]);
        }
    }
    
    vector<string> permutation(string str)
    {
        //Your code here
        int n = str.length();
        vector<string> res;
        permute(str,0,n,res);
        sort(res.begin(),res.end());
        return res;
    }
