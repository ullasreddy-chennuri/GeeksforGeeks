/*
Given a binary tree with a value associated with each node, 
we need to choose a subset of these nodes such that sum of chosen nodes is maximum under a constraint that 
no two chosen node in subset should be directly connected that is, if we have taken a node 
in our sum then we can’t take its any children in consideration and vice versa.
                 

Example 1:
Input:
     11
    /  \
   1    2
Output: 11

Explanation: The maximum sum is sum of
node 11.


Example 2:
Input:
        1
      /   \
     2     3
    /     /  \
   4     5    6
Output: 16

Explanation: The maximum sum is sum of
nodes 1 4 5 6 , i.e 16. These nodes are
non adjacent.


Your Task:
You don't need to read input or print anything. You just have to complete function getMaxSum() 
which accepts root node of the tree as parameter and returns the maximum sum as described.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
1 <= N <= 1000
*/

//Function to return the maximum sum of non-adjacent nodes.
int getSum(Node* root,map<Node*,int> &mp);

int getGrandChildSum(Node* root,map<Node*,int> &mp){
    int sum = 0;
    
    if(root->left){
        sum+= getSum(root->left->left,mp) + getSum(root->left->right,mp);
    }
    if(root->right){
        sum+= getSum(root->right->left,mp) + getSum(root->right->right,mp);
    }
    return sum;
}


int getSum(Node* root,map<Node*,int> &mp){
    if(root==NULL){
        return 0;
    }
    
    //if the current node is already calculated then return its value
    if(mp.find(root)!=mp.end()){
        return mp[root];
    }
    
    // including the current node
    int inc = root->data + getGrandChildSum(root,mp);
    
    // Exclusing curr node and adding its children
    int exc = getSum(root->right,mp)+getSum(root->left,mp);
    
    mp[root] = max(inc,exc);    //update
    return max(inc,exc);
    
}



int getMaxSum(Node *root) 
{
    // Add your code here
    if(root==NULL){
        return 0;
    }
    map<Node*,int> mp;
    return getSum(root,mp);
}
