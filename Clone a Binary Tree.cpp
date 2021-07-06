/*
Given a special binary tree having random pointers along with the usual left and right pointers. 
Clone the given tree.

Example 1:

Input:

Output: 1
Explanation: The tree was cloned successfully.

Your Task:
No need to read input or print anything. Complete the function cloneTree() 
which takes root of the given tree as input parameter and returns the root of the cloned tree. 

Note: The output is 1 if the tree is cloned successfully. Otherwise output is 0.


Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).


Constraints:
1 <=Number of nodes<= 100
1 <=Data of a node<= 1000

*/


class Solution{
  public:
    /* The function should clone the passed tree and return 
       root of the cloned tree */
       
    void cloneRandom(Node* tree,Node* head,unordered_map<Node*,Node*> &mp){
        if(head==NULL){
            return;
        }
        head->random = mp[tree->random];
        cloneRandom(tree->left,head->left,mp);
        cloneRandom(tree->right,head->right,mp);
        return;
    }
       
    Node* clone_tree(Node* tree,unordered_map<Node*,Node*> &mp){
        if(tree==NULL){
            return NULL;
        }
        Node* cloneNode = new Node(tree->data);
        mp[tree] = cloneNode;
        cloneNode->left = clone_tree(tree->left,mp);
        cloneNode->right = clone_tree(tree->right,mp);
        return cloneNode;
    }
    
    Node* cloneTree(Node* tree)
    {
       //Your code here
       unordered_map<Node*,Node*> mp;
       Node* head = clone_tree(tree,mp);
       cloneRandom(tree,head,mp);
       return head;
    }
};
