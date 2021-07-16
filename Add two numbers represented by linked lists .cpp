/*

Given two numbers represented by two linked lists of size N and M. The task is to return a sum list. 
The sum list is a linked list representation of the addition of two input numbers from the last.


Example 1:
Input:
N = 2
valueN[] = {4,5}
M = 3
valueM[] = {3,4,5}
Output: 3 9 0  

Explanation: For the given two linked
list (4 5) and (3 4 5), after adding
the two linked list resultant linked
list will be (3 9 0).


Example 2:
Input:
N = 2
valueN[] = {6,3}
M = 1
valueM[] = {7}
Output: 7 0

Explanation: For the given two linked
list (6 3) and (7), after adding the
two linked list resultant linked list
will be (7 0).

Your Task:
The task is to complete the function addTwoLists() which has node reference of both the linked lists and returns the head of the new list.        

Expected Time Complexity: O(N+M)
Expected Auxiliary Space: O(Max(N,M))

Constraints:
1 <= N, M <= 5000
*/

void insert_at_begin(int data,Node* &head){
    Node* newNode = new Node(data);
    if(head==NULL){
        head = newNode;
        return;
    }else{
        newNode->next=head;
        head=newNode;
    }
}


void reverse(Node **head){
    Node* curr = *head;
    Node* prev=NULL;
    Node* next;
    while(curr!=NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        if(first==NULL && second==NULL){
            return NULL;
        }
        if(first==NULL){
          return second;
        }
        if(second==NULL){
            return first;
        }
        reverse(&first);
        reverse(&second);
        Node* h=NULL;
        Node* temp1=first;
        Node* temp2=second;
        int carry=0;
        while(temp1!=NULL && temp2!=NULL){
            int sum = temp1->data + temp2->data + carry;
            if(sum>=10){
                sum = sum%10;
                carry=1;
            }else{
                carry=0;
            }
            insert_at_begin(sum,h);
            temp1=temp1->next;
            temp2=temp2->next;
        }
        while(temp1!=NULL){
            int sum = temp1->data + carry;
            if(sum>=10){
                sum = sum%10;
                carry=1;
            }else{
                carry=0;
            }
            insert_at_begin(sum,h);
            temp1=temp1->next;
        }
        while(temp2!=NULL){
            int sum = temp2->data + carry;
            if(sum>=10){
                sum = sum%10;
                carry=1;
            }else{
                carry=0;
            }
            insert_at_begin(sum,h);
            temp2=temp2->next;
        }
       if(carry){
           insert_at_begin(carry,h);
       }
        return h;
    }
};
