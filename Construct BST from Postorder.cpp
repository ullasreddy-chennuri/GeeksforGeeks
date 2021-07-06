/*

Given postorder traversal of a Binary Search Tree, you need to construct a BST from postorder traversal. 
The output will be inorder traversal of the constructed BST.

 

Example 1:

Input:
6
1 7 5 50 40 10

Output:
1 5 7 10 40 50

Explanation:
Testcase 1: The BST for the given post order traversal is:
Thus the inorder traversal of BST is: 1 5 7 10 40 50.
 

Your Task:
The task is to complete the function constructTree() which takes an array post[], 
size as as the argument and returns the root of BST.

Expected Time Complexity: O(Height of the BST)
Expected Auxiliary Space: O(Height of the BST)

 
Constraints:
1 <= T <= 100
1 <= N <= 100
*/

Node* insertNode(Node* root,int val){
    if(root==NULL){
        Node* temp = new Node(val);
        //temp->data = val;
        return temp;
    }
    else if(val > (root->data)){
        root->right = insertNode(root->right,val);
    }else if(val < (root->data)){
        root->left= insertNode(root->left,val);
    }
    return root;
}


Node *constructTree (int post[], int size)
{
    //code here
    Node* root= new Node(post[size-1]);
    //root->data = post[size-1];
    for(int i=size-2;i>=0;i--){
        insertNode(root,post[i]);
    }
    return root;
}
