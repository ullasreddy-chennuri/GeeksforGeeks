/*
Given a Binary Search Tree, modify the given BST such that itis balanced and has minimum possible height.

Examples :

Input:
       30
      /
     20
    /
   10
Output:
     20
   /   \
 10     30


Input:
         4
        /
       3
      /
     2
    /
   1
   
Output:
      3            3           2
    /  \         /  \        /  \
   1    4   OR  2    4  OR  1    3   OR ..
    \          /                   \
     2        1                     4 
     

Your Task:
The task is to complete the function buildBalancedTree() which takes root as the input argument, 
and returns the root of tree after converting the given BST into a balanced BST that has minimum possible height. 
The driver code will print the height of the updated tree in output itself.
 

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)
Here N denotes total number of nodes in given BST.


Constraints:
1<=N<=200
*/

Node* balancetree(vector<int> &res,int s,int e){
    if(s>e){
        return NULL;
    }
    int mid = (s+e)/2;
    Node* treenode = new Node(res[mid]);
    treenode->right = balancetree(res,mid+1,e);
    treenode->left = balancetree(res,s,mid-1);
    return treenode;
}


void help(Node* root,vector<int> &res){
    if(root){
        help(root->left,res);
        res.push_back(root->data);
        help(root->right,res);
    }
}

Node* buildBalancedTree(Node* root)
{
	// Code here
	vector<int> res;
	// storing in sorted order by using inorder
	help(root,res);
	return balancetree(res,0,res.size()-1);
	
}
