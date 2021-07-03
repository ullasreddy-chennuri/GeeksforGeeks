/*
Given a binary tree. Find the inorder traversal of the tree without using recursion.


Example 1
Input:
           1
         /    \
       2       3
      /   \
    4     5
Output: 4 2 5 1 3

Explanation:
Inorder traversal (Left->Root->Right) of 
the tree is 4 2 5 1 3.


Example 2
Input:
            8
          /   \
            1      5
             \    /  \
             7   10   6
             \  /
          10 6
Output: 1 7 10 8 6 10 5 6

Explanation:
Inorder traversal (Left->Root->Right) 
of the tree is 1 7 10 8 6 10 5 6.
 

Your task:
You don't need to read input or print anything. Your task is to complete the function inOrder() 
which takes the root of the tree as input and returns a list containing the inorder traversal of the tree, calculated without using recursion.

Expected time complexity: O(N)
Expected auxiliary space: O(N)
*/


    vector<int> inOrder(Node* root)
    {
        //code here
        vector<int> res;
        Node* curr = root;
        stack<Node*> st;
        //st.push(curr)
        while(curr!=NULL || !st.empty()){
            while(curr!=NULL){
                st.push(curr);
                curr=curr->left;
            }
            curr = st.top();
            st.pop();
            res.push_back(curr->data);
            curr=curr->right;
        }
        return res;
    }



