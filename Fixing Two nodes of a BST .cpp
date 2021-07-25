/*
Two of the nodes of a Binary Search Tree (BST) are swapped. Fix (or correct) the BST by swapping them back.
Do not change the structure of the tree.

Note: It is guaranteed than the given input will form BST, except for 2 nodes that will be wrong.
All changes must be reflected in the original linked list.
 
 
Example 1:
Input:
       10
     /    \
    5      8
   / \
  2   20
Output: 1

 
Example 2:
Input:
         11
       /    \
      3      17
       \    /
        4  10
Output: 1 

Explanation: 
By swapping nodes 11 and 10, the BST 
can be fixed.


Your Task:
You don't need to take any input. Just complete the function correctBst() that takes root node as parameter. 
The function should not return anything, all the changes must be done in the existing tree only.
BST will then be checked by driver code and 0 or 1 will be printed.

Expected Time Complexity : O(n)
Expected Auxiliary Space : O(1)
 
Constraints:
1 <= Number of nodes <= 1000

*/

    void checkBst(Node* root,Node **first,Node **middle,Node **last,Node **prev){
        if(root!=NULL){
            checkBst(root->left,first,middle,last,prev);
            
            if(*prev!=NULL && (*prev)->data > root->data){
                if(*first==NULL){
                    *first = *prev;
                    *middle = root;
                }else{
                    *last = root;
                }
            }
            *prev = root;
            checkBst(root->right,first,middle,last,prev);
        }
    }

    void correctBST( struct Node* root )
    {
        // add code here.
        Node *first,*middle,*last,*prev;
        first = last = middle = prev = NULL;
        checkBst(root,&first,&middle,&last,&prev);
        
        if(first && last){
            swap(first->data,last->data);
        }else if(first && middle){
            swap(first->data,middle->data);
        }
        
    }
