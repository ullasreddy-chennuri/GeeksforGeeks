/*
Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order: 

Left boundary nodes: defined as the path from the root to the left-most node ie- the leaf node you could reach 
when you always travel preferring the left subtree over the right subtree. 

Leaf nodes: All the leaf nodes except for the ones that are part of left or right boundary.

Reverse right boundary nodes: defined as the path from the right-most node to the root. 
The right-most node is the leaf node you could reach when you always travel preferring the right subtree over the left subtree. 
Exclude the root from this as it was already included in the traversal of left boundary nodes.

Note: If the root doesn't have a left subtree or right subtree, then the root itself is the left or right boundary. 


Example 1:
Input:
        1
      /   \
     2     3    
   
Output: 1 2 3


Example 2:
Input:
          20
        /   \
       8     22
     /   \    \
    4    12    25
        /  \ 
       10   14 

Output: 20 8 4 10 14 25 22 
 

Your Task:
This is a function problem. You don't have to take input. Just complete the function printBoundary() 
that takes the root node as input and returns an array containing the boundary values in anti-clockwise.

Expected Time Complexity: O(N). 
Expected Auxiliary Space: O(Height of the Tree).
*/

class Solution {
public:
    
    void printLeftBoundary(Node* root,vector<int> &res){
        if(root==NULL){
            return ;
        }
        if(root->left!=NULL){
            res.push_back(root->data);
            printLeftBoundary(root->left,res);
        }else if(root->right!=NULL){
            res.push_back(root->data);
            printLeftBoundary(root->right,res);
        }
        
    }
    
    void printLeafNodes(Node* root,vector<int> &res){
        if(root==NULL){
            return;
        }
        
        printLeafNodes(root->left,res);
        
        if(root->left==NULL && root->right==NULL){
            res.push_back(root->data);
            return;
        }
        
        printLeafNodes(root->right,res);
    }
    
    void printRightBoundary(Node* root,vector<int> &res){
        if(root==NULL){
            return;
        }
        if(root->right!=NULL){
            printRightBoundary(root->right,res);
            res.push_back(root->data);
        }else if(root->left!=NULL){
            printRightBoundary(root->left,res);
            res.push_back(root->data);
        }
    }

    vector <int> printBoundary(Node *root)
    {
        //Your code here
         vector<int> res;
        if(root==NULL){
            return res;
        }
         
        res.push_back(root->data);
      
        printLeftBoundary(root->left,res);
        printLeafNodes(root->left,res);
        printLeafNodes(root->right,res);
        printRightBoundary(root->right,res);
        return res;
    }
};
