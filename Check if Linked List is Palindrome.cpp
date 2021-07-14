/*
Given a singly linked list of size N of integers. The task is to check if the given linked list is palindrome or not.

Example 1:

Input:
N = 3
value[] = {1,2,1}
Output: 1
Explanation: The given linked list is
1 2 1 , which is a palindrome and
Hence, the output is 1.
Example 2:

Input:
N = 4
value[] = {1,2,3,4}
Output: 0
Explanation: The given linked list
is 1 2 3 4 , which is not a palindrome
and Hence, the output is 0.
Your Task:
The task is to complete the function isPalindrome() which takes head as reference as the only parameter and returns true or false if linked list is palindrome or not respectively.

Expected Time Complexity: O(N)
Expected Auxialliary Space Usage: O(1)  (ie, you should not use the recursive stack space as well)

Constraints:
1 <= N <= 105

*/

    void reverse(Node** head){
        Node* prev=NULL,*next;
        Node* curr = *head;
        while(curr!=NULL){
            next = curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        *head = prev;
    }
    bool compareList(Node* head1,Node* head2){
        while(head1!=NULL && head2!=NULL){
            if(head1->data!=head2->data){
                return false;
            }
            head1=head1->next;
            head2=head2->next;
        }
        if(head1!=NULL || head2!=NULL){
            return false;
        }
        return true;
    }
    bool isPalindrome(Node *head)
    {
        //Your code here
        if(head->next==NULL){
            return true;
        }
        Node* fast=head;
        Node* slow=head;
        Node* prev_slow=slow;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            prev_slow=slow;
            slow=slow->next;
        }
        if(fast!=NULL){
            slow=slow->next;
        }
        Node* sec_head=slow;
        prev_slow->next=NULL;
        reverse(&sec_head);
        return compareList(head,sec_head);
    }
