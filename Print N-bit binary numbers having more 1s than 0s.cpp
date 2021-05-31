/*

Given a positive integer N, the task is to find all the N bit binary numbers 
having more than or equal 1’s than 0’s for any prefix of the number.


Example 1:
Input:  N = 2
Output: 11 10
Explanation: 11 and 10 have more than 
or equal 1's than 0's


Example 2:
Input:  N = 3
Output: 111 110 101
Explanation: 111, 110 and 101 have more 
than or equal 1's than 0's

User Task:
Your task is to complete the function NBitBinary() which takes a single number as input and 
returns the list of strings in decreasing order. You need not take any input or print anything.

Expected Time Complexity: O(|2N|)
Expected Auxiliary Space: O(2N)

Constraints:
1 <= N <= 20
*/

void gen_bits(string out,vector<string> &res,int j,int n,int one,int zero){
        if(j==n){
                res.push_back(out);
            return;
        }
        
        //out[j]='1';
        gen_bits(out+'1',res,j+1,n,one+1,zero);
        if(one>zero){
            //out[j]='1';
            gen_bits(out+'0',res,j+1,n,one,zero+1);
        }
        return;
    }


	vector<string> NBitBinary(int n)
	{
	    // Your code goes here
	    vector<string> res;
	    string out="";
	    gen_bits(out,res,0,n,0,0);
	    return res;
	}
