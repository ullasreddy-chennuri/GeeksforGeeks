/*
Serialization is to store a tree in an array so that it can be later restored and Deserialization is reading tree back from the array. 
Now your task is to complete the function serialize which stores the tree into an array A[ ] and deSerialize which deserializes the array to tree and returns it.
Note: The structure of tree must be maintained.


Example 1:
Input:
      1
    /   \
   2     3
Output: 2 1 3


Example 2:
Input:
         10
       /    \
      20    30
    /   \
   40  60
Output: 40 20 60 10 30


Your Task:
The task is to complete two function serialize which takes the root node of the tree as input and
stores the tree into an array and deSerialize which deserializes the array to the original tree and returns the root of it.


Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).


Constraints:
1 <= Number of nodes <= 1000
1 <= Data of a node <= 1000


Note: The Input/Ouput format and Example given above are used for system's internal purpose, 
and should be used by a user for Expected Output only. As it is a function problem, 
hence a user should not read any input from stdin/console, and should not print anything on stdout/console. 
The task is to complete the function specified, and not to write the full code.

*/

class Solution
{
    public:
    //Function to serialize a tree and return a list containing nodes of tree.
    
    void serial(Node* root,vector<int> &res){
        if(root==NULL){
            res.push_back(-1);
            return;
        }
        res.push_back(root->data);
        serial(root->left,res);
        serial(root->right,res);
    }
    
    vector<int> serialize(Node *root) 
    {
        //Your code here
        vector<int> res;
        serial(root,res);
        return res;
    }
    
    Node* deserial(vector<int> &arr,int &i){
        if(i==arr.size()){
            return NULL;
        }
        
        if(arr[i]==-1){
            i++;
            return NULL;
        }
        
        Node* root = new Node(arr[i]);
        i++;
        root->left = deserial(arr,i);
        root->right = deserial(arr,i);
        return root;
    }
    
    //Function to deserialize a list and construct the tree.
    Node * deSerialize(vector<int> &arr)
    {
       //Your code here
       int i=0;
       return deserial(arr,i);
       
    }

};
