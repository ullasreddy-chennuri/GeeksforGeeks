/*
Given a singly linked list: A0→A1→…→An-1→An, reorder it to: A0→An→A1→An-1→A2→An-2→…
For example: Given 1->2->3->4->5 its reorder is 1->5->2->4->3.

Note: It is recommended do this in-place without altering the nodes' values.


Example 1:
Input:
LinkedList: 1->2->3
Output: 1 3 2


Example 2:
Input:
LinkedList: 1->7->3->4
Output: 1 4 7 3.


Your Task:
The task is to complete the function reorderList() which should reorder the list as required.
The reorder list is automatically printed by the driver's code.

Note: Try to solve without using any auxilliary space.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 <= N <= 104

*/


void reverseList(Node** head){
    Node* curr = *head;
    Node* prev=NULL,*next;
    while(curr!=NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}

void reorderList(Node* head) {
    // Your code here
    Node* slow = head,*fast = slow->next;
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    
     Node* head1 = head;
     Node* next_first = slow->next;
     slow->next=NULL;
    
    // reversing second half
    reverseList(&next_first);
   
    // adding dummy pointer to keep track
    head = newNode(0);
    Node* curr = head;
    while(head1 || next_first){
        if(head1){
            curr->next = head1;
            curr=curr->next;
            head1=head1->next;
        }
        if(next_first){
            curr->next = next_first;
            curr=curr->next;
            next_first=next_first->next;
        }
    }
   head = head->next;
}
