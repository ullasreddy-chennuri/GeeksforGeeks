/*

Given a singly linked list, the task is to rearrange it in a way that all odd position nodes are together and all even positions node are together.
Assume the first element to be at position 1 followed by second element at position 2 and so on.


Example 1:
Input:
LinkedList: 1->2->3->4
Output: 1 3 2 4 

Explanation: 
Odd elements are 1, 3 and even elements are 
2, 4. Hence, resultant linked list is 
1->3->2->4.


Example 2:
Input:
LinkedList: 1->2->3->4->5
Output: 1 3 5 2 4 

Explanation: 
Odd elements are 1, 3, 5 and even elements are
2, 4. Hence, resultant linked list is
â€‹1->3->5->2->4.


Your Task:
The task is to complete the function rearrangeEvenOdd() 
which rearranges the nodes in the linked list as required and doesn't return anything.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= Size of the linked list <= 10000
1 <= values of linked list<= 1000
*/

class Solution
{
    public:
    void rearrangeEvenOdd(Node *head)
    {
       // Your Code here
       Node* odd_head=NULL,*even_head=NULL;
       Node* odd_ptr=NULL,*even_ptr=NULL;
       Node* temp=head;
       if(temp==NULL || temp->next==NULL){
           return;
       }
       int k=1;
       while(temp){
           if(k%2==0){
               if(even_head==NULL){
                   even_head = temp;
                   even_ptr=even_head;
               }else{
                   even_ptr->next = temp;
                   even_ptr = temp;
               }
           }else{
               if(odd_head==NULL){
                   odd_head=temp;
                   odd_ptr=odd_head;
               }else{
                   odd_ptr->next = temp;
                   odd_ptr=temp;
               }
           }
           temp=temp->next;
           k++;
       }
       if(odd_head==NULL){
           even_ptr->next=NULL;
           head = even_head;
           return;
       }
       if(even_head==NULL){
           odd_ptr->next = NULL;
           head = odd_head;
           return;
       }
       odd_ptr->next = even_head;
       even_ptr->next = NULL;
       head = odd_head;
       return;
    }
};
