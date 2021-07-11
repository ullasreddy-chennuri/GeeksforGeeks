/*

Given Pointer/Reference to the head of the linked list, the task is to Sort the given linked list using Merge Sort.
Note: If the length of linked list is odd, then the extra node should go in the first list while splitting.


Example 1:
Input:
N = 5
value[]  = {3,5,2,4,1}
Output: 1 2 3 4 5

Explanation: After sorting the given
linked list, the resultant matrix
will be 1->2->3->4->5.


Example 2:
Input:
N = 3
value[]  = {9,15,0}
Output: 0 9 15

Explanation: After sorting the given
linked list , resultant will be
0->9->15.


Your Task:
For C++ and Python: The task is to complete the function mergeSort() which sort the linked list using merge sort function.
For Java: The task is to complete the function mergeSort() and return the node which can be used to print the sorted linked list.

Expected Time Complexity: O(N*Log(N))
Expected Auxiliary Space: O(N)

Constraints:
1 <= T <= 100
1 <= N <= 105
*/

    void find_middle(Node* head,Node **first,Node **second){
        Node* curr = head;
        Node* slow = curr;
        Node* fast = curr->next;
        while(fast!=NULL){
            fast=fast->next;
            if(fast!=NULL){
                fast=fast->next;
                slow=slow->next;
            }
        }
        *first = head;
        *second = slow->next;
        slow->next=NULL;
    }
    
    Node* merge(Node *first,Node *second){
        Node* res=NULL;
        if(first==NULL){
            res = second;
            return res;
        }
        if(second == NULL){
            res = first;
            return res;
        }
        
        if(first->data <= second->data){
            res = first;
            res->next = merge(first->next,second);
        }else{
            res = second;
            res->next = merge(first,second->next);
        }
        return res;
    }
    
    void merge_sort(Node **head){
        Node* first;
        Node* second;
        Node* curr_head = *head;
        if(!curr_head || !curr_head->next){
            return;
        }
        find_middle(curr_head,&first,&second);
        merge_sort(&first);
        merge_sort(&second);
        *head = merge(first,second);
    }
    
    Node* mergeSort(Node* head) {
        // your code here
        merge_sort(&head);
        return head;
    }
