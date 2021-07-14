/*

Given an array arr[] of N nodes representing preorder traversal of BST. 
The task is to print its postorder traversal.


Example 1:
Input:
N = 5
arr[]  = {40,30,35,80,100}
Output: 35 30 100 80 40

Explanation: PreOrder: 40 30 35 80 100
InOrder: 30 35 40 80 100
Therefore, the BST will be:
              40
           /      \
         30       80
           \        \   
           35      100
Hence, the postOrder traversal will
be: 35 30 100 80 40


Example 2:
Input:
N = 8
arr[]  = {40,30,32,35,80,90,100,120}
Output: 35 32 30 120 100 90 80 40

Your Task:
You need to complete the given function and return the root of the tree. 
The driver code will then use this root to print the post order traversal.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= N <= 103
1 <= arr[i] <= 104

*/


Node* cons_bst(Node* head,int val){
    if(head==NULL){
        return newNode(val);
    }
    
    if(val<head->data){
        head->left = cons_bst(head->left,val);
    }else{
        head->right = cons_bst(head->right,val);
    }
    return head;
}

Node* constructTree(int pre[], int size)
{
    //code here
    Node* head = newNode(pre[0]);
    for(int i=1;i<size;i++){
        cons_bst(head,pre[i]);
    }
    return head;
}
