/*
Given a set of N nuts of different sizes and N bolts of different sizes. 
There is a one-one mapping between nuts and bolts. Match nuts and bolts efficiently.

Comparison of a nut to another nut or a bolt to another bolt is not allowed. 
It means nut can only be compared with bolt and bolt can only be compared with nut to see which one is bigger/smaller.
The elements should follow the following order ! # $ % & * @ ^ ~ .


Example 1:
Input: 
N = 5
nuts[] = {@, %, $, #, ^}
bolts[] = {%, @, #, $ ^}

Output: 
# $ % @ ^
# $ % @ ^


Example 2:
Input: 
N = 9
nuts[] = {^, &, %, @, #, *, $, ~, !}
bolts[] = {~, #, @, %, &, *, $ ,^, !}
Output: 
! # $ % & * @ ^ ~
! # $ % & * @ ^ ~


Your Task:  
You don't need to read input or print anything. Your task is to complete the function matchPairs() 
which takes an array of characters nuts[], bolts[] and n as parameters and returns void. You need to change the array itswelf.

Expected Time Complexity: O(NlogN)
Expected Auxiliary Space: O(1)

Constraints:
1 <= N <= 9
Array of Nuts/Bolts can only consist of the following elements:{'@', '#', '$', '%', '^', '&', '~', '*', '!'}.
*/


bool c_sear(char a,char arr[],int n){
        for(int i=0;i<n;i++){
            if(arr[i]==a){
                return true;
            }
        }
        return false;
    }
    
    
	void matchPairs(char nuts[], char bolts[], int n) {
	    // code here
	    char arr[]={'!','#','$','%','&','*','@','^','~','.','\0'};
	    char out_nuts[n],out_bolts[n];
	    int c=0;
	    for(int i=0;i<10;i++){
	        if(c_sear(arr[i],nuts,n)){
	            out_nuts[c]=arr[i];
	            c++;
	        }
	    }
	    for(int i=0;i<n;i++){
	        bolts[i]=out_nuts[i];
	        nuts[i]=out_nuts[i];
	    }
	    return;
	}
