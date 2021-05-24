/*
Given a singly linked list of size N. The task is to rotate the linked list counter-clockwise by k nodes, 
where k is a given positive integer smaller than or equal to length of the linked list.

Example 1:
Input:
N = 5
value[] = {2, 4, 7, 8, 9}
k = 3
Output: 8 9 2 4 7

Explanation:
Rotate 1: 4 -> 7 -> 8 -> 9 -> 2
Rotate 2: 7 -> 8 -> 9 -> 2 -> 4
Rotate 3: 8 -> 9 -> 2 -> 4 -> 7


Example 2:
Input:
N = 8
value[] = {1, 2, 3, 4, 5, 6, 7, 8}
k = 4
Output: 5 6 7 8 1 2 3 4
 

Your Task:
You don't need to read input or print anything. Your task is to complete the function rotate() 
which takes a head reference as the first argument and k as the second argument, and returns the head of the rotated linked list.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= N <= 103
1 <= k <= N */


 Node* rotate(Node* head, int k)
    {
        // Brute force approach
        // while(k--){
        //     Node* temp = head;
        //     //head=head->next;
        //     while(temp->next!=NULL){
        //         temp=temp->next;
        //     }
        //     temp->next=head;
        //     Node* temp1=head;
        //     head=head->next;
        //     temp1->next=NULL;
        // }
        
        // return head;
        
        
        // optimised approach
        Node* temp=head;
        while(k>1){
            temp=temp->next;
            k--;
        }
        Node* tr=temp->next;
        Node* temp1 = temp->next;
        temp->next=NULL;
        while(temp1!=NULL && temp1->next!=NULL){
            temp1=temp1->next;
        }
        if(temp1!=NULL){
             temp1->next=head;
            head=tr;
        }
       
        return head;
        
    }
