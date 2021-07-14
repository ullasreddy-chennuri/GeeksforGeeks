/*

Given a Binary Tree, print Left view of it. Left view of a Binary Tree is set of nodes visible when tree is visited from Left side. 
The task is to complete the function leftView(), which accepts root of the tree as argument.
Left view of following tree is 1 2 4 8.

          1
       /     \
     2        3
   /     \    /    \
  4     5   6    7
   \
     8   


Example 1:
Input:
   1
 /  \
3    2
Output: 1 3


Your Task:
You just have to complete the function leftView() that prints the left view. The newline is automatically appended by the driver code.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
0 <= Number of nodes <= 100
1 <= Data of a node <= 1000
*/

vector<int> leftView(Node *root)
{
   // Your code here
   vector<int> res;
   if(root==NULL){
       return res;
   }
   queue<Node*> q;
   q.push(root);
   
   while(!q.empty()){
       int n = q.size();
       for(int i=1;i<=n;i++){
           Node* temp = q.front();
           q.pop();
           if(i==1){
               res.push_back(temp->data);
           }
           if(temp->left!=NULL){
               q.push(temp->left);
           }
           if(temp->right!=NULL){
               q.push(temp->right);
           }
       }
   }
   return res;
}
