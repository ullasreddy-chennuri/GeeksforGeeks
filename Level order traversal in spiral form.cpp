/*

Complete the function to find spiral order traversal of a tree. 
For below tree, function should return 1, 2, 3, 4, 5, 6, 7.


Example 1:
Input:
      1
    /   \
   3     2
   
Output:1 3 2



Example 2:
Input:
           10
         /     \
        20     30
      /    \
    40     60
    
Output: 10 20 30 60 40 


Your Task:
The task is to complete the function findSpiral() which takes root node as input parameter and 
returns the elements in spiral form of level order traversal as a list. The newline is automatically appended by the driver code.


Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
0 <= Number of nodes <= 105
0 <= Data of a node <= 105
*/

vector<int> findSpiral(Node *root)
{
    //Your code here
    vector<int> res;
    if(root==NULL){
        return res;
    }
    
    stack<Node*> sto,ste;
    sto.push(root);
      while(!sto.empty() || !ste.empty()){
            while(!sto.empty()){
                Node* temp = sto.top();
                sto.pop();
                res.push_back(temp->data);
                if(temp->right){
                    ste.push(temp->right);
                }
                if(temp->left){
                    ste.push(temp->left);
                }
            }
            while(!ste.empty()){
                Node* temp = ste.top();
                ste.pop();
                res.push_back(temp->data);
                if(temp->left){
                    sto.push(temp->left);
                }
                if(temp->right){
                    sto.push(temp->right);
                }
            }
     }
    return res;
    
}
