/*
A number is called good if it contains only 1's and 2's. Given an integer N, the task is to find Nth good number

Note: Some good numbers are 1, 2, 11, 12, 21, 22 ........

Input:
1. The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
2. The first line of each test case contains a single integer N.


Output: For each test case, print the Nth good number
Constraints:
1. 1 <= T <= 100
2. 1 <= N <= 104

Example:
Input:
2
5
10000

Output:
21
1122211121112

*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;cin>>t;
	while(t--){
	    int n;cin>>n;
	    int k=n;
	    vector<string> res;
	    queue<string>q;
	    q.push("1");
	    q.push("2");
	    while(n>0){
	        string t = q.front();
	        res.push_back(t);
	        q.pop();
	        q.push(t+"1");
	        q.push(t+"2");
            n--;
	    }
	    cout<<res[k-1]<<endl;
	}
	return 0;
}
