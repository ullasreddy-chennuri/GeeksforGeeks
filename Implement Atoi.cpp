/*

Your task  is to implement the function atoi. The function takes a
string(str) as argument and converts it to an integer and returns it.

Note: You are not allowed to use inbuilt function.


Example 1:
Input:
str = 123
Output: 123


Example 2:
Input:
str = 21a
Output: -1

Explanation: Output is -1 as all
characters are not digit only.


Your Task:
Complete the function atoi() which takes a string as input parameter and 
returns integer value of it. if the input string is not a numerical string then returns 1..

Expected Time Complexity: O(|S|), |S| = length of string str.
Expected Auxiliary Space: O(1)

Constraints:
1<=length of S<=10

*/

    int atoi(string str)
    {
        //Your code here
        int res=0;
        int flag=0;
        for(int i=0;i<str.length();i++){
            if(str[i]=='-'){
                flag=1;
            }
            else if(str[i]>='0' && str[i]<='9'){
                res = res*10 + (str[i]-'0');
            }else{
                return -1;
            }
        }
        if(flag==1){
            return res*-1;
        }
        return res;
    }
