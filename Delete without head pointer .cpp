/*

You are given a pointer/ reference to the node which is to be deleted from the linked list of N nodes. 
The task is to delete the node. Pointer/ reference to head node is not given. 
Note: No head reference is given to you. It is guaranteed that the node to be deleted is not a tail node in the linked list.

Example 1:
Input:
N = 2
value[] = {1,2}
node = 1
Output: 2

Explanation: After deleting 1 from the
linked list, we have remaining nodes
as 2.


Example 2:
Input:
N = 4
value[] = {10,20,4,30}
node = 20
Output: 10 4 30

Explanation: After deleting 20 from
the linked list, we have remaining
nodes as 10, 4 and 30.


Your Task:
You only need to complete the function deleteNode that takes reference to the node 
that needs to be deleted. The printing is done automatically by the driver code.

Expected Time Complexity : O(1)
Expected Auxilliary Space : O(1)

Constraints:
1 <= N <= 103
*/

    void deleteNode(Node *del)
    {
       // Your code here
       // easiest approach just changing whole address
       //*(del)=*(del->next);
       
       // Second approach shifting all the values to right and from begin delete the end one
       Node* temp=del;
       while(temp->next!=NULL){
           temp->data = temp->next->data;
           temp=temp->next;
       }
       temp=del;
       while(temp->next->next!=NULL){
           temp=temp->next;
       }
       temp->next=NULL;
    }
