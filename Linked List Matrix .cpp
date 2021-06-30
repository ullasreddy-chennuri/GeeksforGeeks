/*
Given a Matrix mat of N*N size, the task is to complete the function constructLinkedMatrix(), 
that constructs a 2D linked list representation of the given matrix.

Input : 2D matrix 
1 2 3
4 5 6
7 8 9

Output :
1 -> 2 -> 3 -> NULL
|    |    |
v    v    v
4 -> 5 -> 6 -> NULL
|    |    |
v    v    v
7 -> 8 -> 9 -> NULL
|    |    |
v    v    v
NULL NULL NULL

Input:
The fuction takes 2 argument as input, first the 2D matrix mat[][] and second an integer variable N, denoting the size of the matrix.
There will be T test cases and for each test case the function will be called separately.

Output:
The function must return the reference pointer to the head of the linked list.

Constraints:
1<=T<=100
1<=N<=150

Example:
Input:
2
3
1 2 3 4 5 6 7 8 9
2
1 2 3 4
Output:
1 2 3 4 5 6 7 8 9
1 2 3 4

Note:The Input/Ouput format and Example given are used for system's internal purpose,
and should be used by a user for Expected Output only. As it is a function problem, hence a user should not read any input from stdin/console.
The task is to complete the function specified, and not to write the full code.
*/

Node* construct(int arr[MAX][MAX],int i,int j,int n){
    if(i>n-1||j>n-1){
        return NULL;
    }
    Node *temp=new Node(arr[i][j]);
    //temp->data=arr[i][j];
    temp->right=construct(arr,i,j+1,n);
    temp->down=construct(arr,i+1,j,n);
    return temp;
}

Node* constructLinkedMatrix(int arr[MAX][MAX], int n)
{
    // code here
    // Using Recurssion
    Node *head = construct(arr,0,0,n);
    return head;
}
