/*
Given a keypad as shown in the diagram, and an N digit number which is represented by array a[ ], 
the task is to list all words which are possible by pressing these numbers.


Example 1:
Input: N = 3, a[] = {2, 3, 4}
Output:
adg adh adi aeg aeh aei afg afh afi 
bdg bdh bdi beg beh bei bfg bfh bfi 
cdg cdh cdi ceg ceh cei cfg cfh cfi 
Explanation: When we press 2,3,4 then 
adg, adh, adi, ... cfi are the list of 
possible words.


Example 2:
Input: N = 3, a[] = {3, 4, 5}
Output:
dgj dgk dgl dhj dhk dhl dij dik dil 
egj egk egl ehj ehk ehl eij eik eil 
fgj fgk fgl fhj fhk fhl fij fik fil
Explanation: When we press 3,4,5 then 
dgj, dgk, dgl, ... fil are the list of 
possible words.

Your Task:
You don't need to read input or print anything. You just need to complete the function possibleWords()
that takes an array a[ ] and N as input parameters and returns an array of all the possible words in lexicographical increasing order. 

Expected Time Complexity: O(4N * N).
Expected Auxiliary Space: O(N).

Constraints:
1 ≤ N ≤ 10
2 ≤ a[i] ≤ 9
*/

void findComb(vector<char> keypad[],int arr[],vector<string> &res,string temp,int idx,int n){
        if(idx==n){
            res.push_back(temp);
            return;
        } 
        int digit = arr[idx];
        int st_len = keypad[digit].size();
        for(int i=0;i<st_len;i++){
            // first casee  -> temp = "a" and calling for second digit for its element, similarly for all elements all digits...
            findComb(keypad,arr,res,temp+keypad[digit][i],idx+1,n);   // recursive call for each digit's each char in order using loop for one string
        }
    }
    vector<string> possibleWords(int arr[], int n)
    {
        //Your code here
        vector<char> keypad[] =
        {
            {}, {},
            { 'a', 'b', 'c' },
            { 'd', 'e', 'f' },
            { 'g', 'h', 'i' },
            { 'j', 'k', 'l' },
            { 'm', 'n', 'o' },
            { 'p', 'q', 'r', 's'},
            { 't', 'u', 'v' },
            { 'w', 'x', 'y', 'z'}
        };
        vector<string> res;
        string temp="";
        findComb(keypad,arr,res,temp,0,n);
        return res;
    }
