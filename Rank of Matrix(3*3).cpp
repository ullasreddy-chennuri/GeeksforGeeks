/*

Write a program to find the rank of a 3x3 Matrix.

Input: The first line contains an integer 'T' denoting the total number of test cases. 
Each test case consists of 3 lines and each line consists of 3 integers. 
First 3 lines denotes a matrix of whose rank is to be determined.  
Output: Rank of the matrix is displayed in one line.


Constraints:
1 <=T<= 100
-100 <=N<= 100


Example:
Input: 
2
10 20 10
-20 -30 10
30 50 0
2 4 3
1 0 9
9 6 8

Output:
2
3

*/

#include<bits/stdc++.h>
using namespace std;

int findRank(int arr[][3]){
    int x,y,z,det;
    x = arr[0][0]*(arr[1][1]*arr[2][2] - arr[2][1]*arr[1][2]);
    y = arr[0][1]*(arr[1][0]*arr[2][2] - arr[2][0]*arr[1][2]);
    z = arr[0][2]*(arr[1][0]*arr[2][1] - arr[2][0]*arr[1][1]);
    det = x-y+z; // finding determinant for 3*3 matrix
    if(det!=0){
        return 3;
    }else{
        // finding det for all the 2*2 matrixes manually
        int  p =arr[0][0]*arr[1][1] - arr[0][1]*arr[1][0];
        int q = arr[0][1]*arr[1][2] - arr[0][2]*arr[1][1];
        int r = arr[1][0]*arr[2][1] - arr[1][1]*arr[2][0];
        int s = arr[1][1]*arr[2][2] - arr[2][1]*arr[1][2];
        
        if(p!=0 || q!=0 || r!=0 || s!=0){
            return 2;
        }
    }
    return 1;
}

int main()
 {
	//code
	int t;
	cin>>t;
	while(t--){
	    //int n;
	    //cin>>n;
	    int arr[3][3];
	    int flag=0;
	    for(int i=0;i<3;i++){
	        for(int j=0;j<3;j++){
	            cin>>arr[i][j];
	            if(arr[i][j]==0){
	                flag++;
	            }
	        }
	    }
	    if(flag==9){
	        cout<<"0"<<"\n";
	    }else{
	        cout<<findRank(arr)<<"\n";
	    }
	}
	return 0;
}

