/*

Given a binary tree you need to check if it follows max heap property or not.

Input:
The task is to complete the method which takes one argument, root of Binary Tree. 
The struct Node has a data part which stores the data, pointer to left child and pointer to right child.
There are multiple test cases. For each test case, this method will be called individually.

Output:
The function should return true if property holds else false.
 

Example 1:

Input:
      5
    /  \
   2    3
Output: 1
Example 2:

Input:
       10
     /   \
    20   30 
  /   \
 40   60
Output: 0
Constraints:
1 ≤ Number of nodes ≤ 100
1 ≤ Data of a node ≤ 1000
*/


class Solution {
  public:
    bool isHeap(struct Node * tree)
    {
        // code here
        if(tree==NULL){
            return  true;
        }
        // condition that left node should be top prior than right in heap
        if(!tree->left&&tree->right){
            return false;
        }
        if(tree->right && tree->data<tree->right->data){
            return false;
        }
         if(tree->right && tree->data<tree->left->data){
            return false;
        }
        
        return isHeap(tree->left) && isHeap(tree->right);
    
    }
};
