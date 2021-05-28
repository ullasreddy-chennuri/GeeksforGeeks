/*
Given a Binary Square Matrix where each row and column of the matrix is sorted in ascending order. 
Find the total number of Zeros present in the matrix.

Input:
The first line of input will be the no of test cases then T test cases will follow.
The second line of each test case contains an integer N denoting the dimension of the matrix.
Then in the next line are the space separated values of the matrix A[ ] [ ]. 

Output:
Print in a single line, the total number of zeros present in the given Binary Matrix.

User Task:
You don't need to read input or print anything. Your task is to complete the function countZeros() 
which takes the Binary Matrix A[][] and its size N as inputs and returns an integer denoting the total number of Zeros present in the matrix.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1<=T<=50
1<=M,N<=1000
0<=A[][]<=1

Example:
Input
2
3
0 0 0 0 0 1 0 1 1
2
1 1 1 1 
Output
6
0

Note:The Input/Ouput format and Example given are used for system's internal purpose, 
and should be used by a user for Expected Output only. As it is a function problem, 
hence a user should not read any input from stdin/console. The task is to complete the function specified, 
and not to write the full code.
*/


int b_search(int arr[],int n){
    int lo=0,hi=n-1;
    int mid;
    while(lo<=hi){
        mid=(lo+hi)/2;
        if(arr[mid]==1){
            if(mid==0){
                return mid;
            }
            if(mid>0 && arr[mid-1]==0){
               return mid; 
            }else if(mid>0 && arr[mid-1]==1){
                hi=mid-1;
            }
            
        }else{
            lo=mid+1;
        }
    }
    return -1;
}

int countZeros(int arr[MAX][MAX],int n)
{
    //Your code here
    int count=0;
    for(int i=0;i<n;i++){
        int k = b_search(arr[i],n);
        if(k!=-1){
            count+=k;
        }else{
            count+=n;
        }
    }
    return count;
}
