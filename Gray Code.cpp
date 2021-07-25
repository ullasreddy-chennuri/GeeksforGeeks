/*

Given a number N, generate bit patterns from 0 to 2^N-1 such that successive patterns differ by one bit. 
A Gray code sequence must begin with 0.
 
 
Example 1:
Input:
N = 2
Output: 
00 01 11 10

Explanation: 
00 and 01 differ by one bit.
01 and 11 differ by one bit.
11 and 10 also differ by one bit.
 
 
Example 2:
Input:
N=3
Output:
000 001 011 010 110 111 101 100

Explanation:
000 and 001 differ by one bit.
001 and 011 differ by one bit.
011 and 010 differ by one bit.
Similarly, every successive pattern 
differs by one bit.


Your task:
You don't need to read input or print anything. Your task is to complete the function graycode()
which takes an integer N as input and returns a la list of patterns.
 
Expected Time Complexity: O(2n)
Expected Auxiliary Space: O(2n)
*/


class Solution
{
    public:
    vector<string> graycode(int n)
    {
        //code here
       /* store 0,1 first for n==1;
        for n==2, reverse n==1 array and append 0 to first half and 1 to second half
        similarly repeat for n==3, reverse n==2 array and append 0 to first hald and 1 to second half
        this is standard pattern as this is gray code*/
        /*
        vector<string> res;
        if(n<=0){
            return res;
        }
        int i,j;
        res.push_back("0");
        res.push_back("1");
        for(i=2;i<(1<<n);i=i<<1){
            for(j=i-1;j>=0;j--){
                res.push_back(res[j]);
            }
            for(j=0;j<i;j++){
                res[j]="0"+res[j];
            }
            for(j=i;j<2*i;j++){
                res[j]="1"+res[j];
            }
        }
        
        return res;
        */
        
        // recursive 
        if(n<=0){
            return {"0"};
        }
        if(n==1){
            return {"0","1"};
        }
        
        vector<string> res = graycode(n-1);
        vector<string> ans;
        for(int i=0;i<res.size();i++){
            ans.push_back("0"+res[i]);
        }
        
        for(int i=res.size()-1;i>=0;i--){
            ans.push_back("1"+res[i]);
        }
        return ans;
    }
};
