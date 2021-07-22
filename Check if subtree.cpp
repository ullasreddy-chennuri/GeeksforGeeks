/*

Given two binary trees with head reference as T and S having at most N nodes. The task is to check if S is present as subtree in T.
A subtree of a tree T1 is a tree T2 consisting of a node in T1 and all of its descendants in T1.


Example 1:
Input:
T:      1          S:   3
      /   \            /
     2     3          4
   /  \    /
  N    N  4
Output: 1 

Explanation: S is present in T



Example 2:
Input:
T:      26         S:   26
       /   \           /  \
     10     N        10    N
   /    \           /  \
   20    30        20  30
  /  \            /  \
 40   60         40  60
Output: 1 

Explanation: 
S and T are both same. Hence, 
it can be said that S is a subtree 
of T.


Your Task:
You don't need to read input or print anything. Your task is to complete the function isSubtree() 
that takes root node of S and T as parameters and returns 1 if S is a subtree of T else 0.


Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= Number of nodes <= 105
1 <= Value of nodes <= 104
*/

class Solution
{
  public:
    //Function to check if S is a subtree of tree T.
    
    void inorder(Node* root,vector<int>&res){
        if(root==NULL){
            res.push_back(-1);
            return;
        }
            inorder(root->left,res);
            res.push_back(root->data);
            inorder(root->right,res);
    }
    void preorder(Node* root,vector<int>&res){
         if(root==NULL){
            res.push_back(-1);
            return;
        }
            res.push_back(root->data);
            preorder(root->left,res);
            preorder(root->right,res);
    }
    
    bool isSubArray(vector<int> one,vector<int> two){
        string s1="";
        string s2="";
        for(int i=0;i<one.size();i++){
            s1+=to_string(one[i]);
        }
        for(int i=0;i<two.size();i++){
            s2+=to_string(two[i]);
        }
        
        if(s1.find(s2)!=-1){
            return true;
        }
        return false;
    }
    
    bool isSubTree(Node* T, Node* S) 
    {
        // Your code here
        vector<int> inone;
        vector<int> intwo;
        vector<int> preone;
        vector<int> pretwo;
        inorder(T,inone);
        inorder(S,intwo);
        preorder(T,preone);
        preorder(S,pretwo);
        return isSubArray(inone,intwo)&&isSubArray(preone,pretwo);
    }
};
