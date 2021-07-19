/*
Given a Binary Tree, find the vertical traversal of it starting from the leftmost level to the rightmost level.
If there are multiple nodes passing through a vertical line, then they should be printed as they appear in level order traversal of the tree.


Example 1:
Input:
           1
         /   \
       2       3
     /   \   /   \
   4      5 6      7
              \      \
               8      9           
Output: 
4 2 1 5 6 3 8 7 9 


Example 2:
Input:
       1
    /    \
   2       3
 /    \      \
4      5      6
Output: 4 2 1 5 3 6
Your Task:
You don't need to read input or print anything. Your task is to complete the function verticalOrder() 
which takes the root node as input parameter and returns an array containing 
the vertical order traversal of the tree from the leftmost to the rightmost level. 
If 2 nodes lie in the same vertical level, they should be printed in the order they appear in the level order traversal of the tree.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 <= Number of nodes <= 3*104
*/

    vector<int> verticalOrder(Node *root)
    {
        //Your code here
        // using level order traversal and hashmap to store the vertical order
        map<int, vector<int>> mp;
        queue<pair<Node*, int>> q;
        int k = 0;
        q.push(make_pair(root,k));
        while(!q.empty()){
            pair<Node*,int> temp = q.front();
            q.pop();
            Node* curr = temp.first;
            k = temp.second;
            mp[k].push_back(curr->data);
            
            if(curr->left!=NULL){
                q.push(make_pair(curr->left,k-1));
            }
            if(curr->right!=NULL){
                q.push(make_pair(curr->right,k+1));
            }
        }
        vector<int> res;
        map<int, vector<int>>::iterator it;
        for(it=mp.begin();it!=mp.end();it++){
            vector<int> t = it->second;
            for(int i=0;i<t.size();i++){
                res.push_back(t[i]);
            }
        }
    
        return res;
    }
