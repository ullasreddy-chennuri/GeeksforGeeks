/*
Given a set of positive integers, find all its subsets.


Example 1 :
Input : 
array = {1, 2, 3}
Output :
// this space denotes null element. 
1
1 2
1 2 3
1 3
2
2 3
3

Explanation: 
The following are the subsets 
of the array {1, 2, 3}.


Example 2 :
Input :
array = {1, 2}
Output :

1 
1 2
2

Explanation :
The following are the 
subsets of {1, 2}.

Your task :
You don't have to read input or print anything.
Your task is to complete the function subsets() which takes the array of integers as 
input and returns the list of list containing the subsets of the given set of numbers in lexicographical order.
 
Expected Time Complexity : O(2^n)))
Expected Auxiliary Space : O(2^n*length of each subset)
 
Constraints :
1 <= n <= 20
1 <= arr[i] <=10
*/

      void gen_subsets(vector<int> in,vector<int> &out,vector<vector<int> > &res,int i,int j,int n){
        if(i==n){
            res.push_back(out);
            return;
        }
        
        //rec case
        out.push_back(in[i]);
        gen_subsets(in,out,res,i+1,j+1,n);
        out.pop_back();
        gen_subsets(in,out,res,i+1,j,n);
    }
    
    
    vector<vector<int> > subsets(vector<int>& in)
    {
        //code here
        int n=in.size();
        vector<vector<int>> res;
        vector<int> out;
        gen_subsets(in,out,res,0,0,n);
        sort(res.begin(),res.end());
        return res;
    }

