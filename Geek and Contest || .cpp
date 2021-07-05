/*

Geek hosted a contest and N students participated in it. The score of each student is given by an integer array arr. 
The task is to print the number of each student (indexes) in the order they appear in the scoreboard. A student with a maximum score appears first.
If two people have the same score then higher indexed student appears first. 

Input:
1. The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
2. The first line of each test case contains a single integer N.
3. The next line contains N space-separated integers.


Output: For each test case, print the order they appear in the scoreboard

Constraints:
1. 1 <= T <= 100
2. 1 <= N <= 104
3. 1 <= arr[i] <= 109

Example:
Input:
2
5
450 230 730 230 150
3
500 500 500

Output:
3 1 4 2 5
3 2 1

*/

#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	int t;cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    priority_queue<pair<int,int>> pq;
	    for(int i=1;i<=n;i++){
	        int marks;
	        cin>>marks;
	        pq.push(make_pair(marks,i));
	    }
	    
	    for(int i=0;i<n;i++){
	        pair<int,int> temp = pq.top();
	        pq.pop();
	        cout<<temp.second<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
