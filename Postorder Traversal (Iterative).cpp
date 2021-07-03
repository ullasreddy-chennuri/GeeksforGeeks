/*

Given a binary tree. Find the postorder traversal of the tree without using recursion.


Example 1
Input:
           1
         /   \
        2     3
      /  \
     4    5

Output: 4 5 2 3 1

Explanation:
Postorder traversal (Left->Right->Root) of 
the tree is 4 5 2 3 1.


Example 2
Input:
             8
          /      \
        1          5
         \       /   \
          7     10    6
           \   /
            10 6

Output: 10 7 1 6 10 6 5 8 

Explanation:
Inorder traversal (Left->Right->Root) 
of the tree is 10 7 1 6 10 6 5 8 .
 
Your task:
You don't need to read input or print anything. Your task is to complete the function postOrder() 
which takes the root of the tree as input and returns a list containing the postorder traversal of the tree, calculated without using recursion.
 
Expected time complexity: O(N)
Expected auxiliary space: O(N)
 
Constraints:
1 <= Number of nodes <= 105
1 <= Data of a node <= 105
*/

vector<int> postOrder(Node* node) {
    // code here
    vector<int> res;
    stack<Node*> st;
    st.push(node);
    while(!st.empty()){
        Node* temp = st.top();
        st.pop();
        res.push_back(temp->data);
        if(temp->left!=NULL){
            st.push(temp->left);
        }
        if(temp->right!=NULL){
            st.push(temp->right);
        }
        
    }
    reverse(res.begin(),res.end());
    return res;
}
