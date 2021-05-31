/*
Given a string you need to print all possible strings that can be made by placing spaces (zero or one) in between them. 
The output should be printed in sorted increasing order of strings


Example 1:
Input:
S = "ABC"
Output: (A B C)(A BC)(AB C)(ABC)

Explanation:
ABC
AB C
A BC
A B C
These are the possible combination of "ABC".
 

Example 2:
Input:
S = "AB"
Output: (A B)(AB)

Your Task:  
You don't need to read input or print anything. Your task is to complete the function permutation() 
which takes the string S as input parameters and returns the sorted array of the string denoting the different permutation 
(DON'T ADD '(' and ')' it will be handled by the driver code only).

Expected Time Complexity: O(2^n)
Expected Auxiliary Space: O(1)
*/


void perm_space(string str,char temp[],vector<string> &res,int n,int i,int j){
        if(i==n){
            temp[j]='\0';
            res.insert(res.begin(),temp);
            return;
        }
        temp[j]=str[i];
        perm_space(str,temp,res,n,i+1,j+1);
        temp[j]=' ';
        temp[j+1]=str[i];
        perm_space(str,temp,res,n,i+1,j+2);
    }
    
    vector<string> permutation(string str){
        // Code Here
        vector<string> res;
        int n = str.length();
        char temp[2*n];
        temp[0] = str[0];
        perm_space(str,temp,res,n,1,1);
        return res;
    }
