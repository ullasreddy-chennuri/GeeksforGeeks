/*

Given a linked list and a value x, partition it such that all nodes less than x come first, 
then all nodes with value equal to x and finally nodes with value greater than or equal to x. 
The original relative order of the nodes in each of the three partitions should be preserved. 
The partition must work in-place.
 
 
Example 1:
Input:
1->4->3->2->5->2->3,
x = 3
Output:
1->2->2->3->3->4->5

Explanation: 
Nodes with value less than 3 come first, 
then equal to 3 and then greater than 3.


Example 2:
Input:
1->4->2->10 
x = 3
Output: 
1->2->4->10

Explanation:
Nodes with value less than 3 come first,
then equal to 3 and then greater than 3.


Your task:
You don't need to read input or print anything. Your task is to complete the function partition() 
which takes the head of the inked list and an integer x as input, 
and returns the head of the modified linked list after arranging the values according to x.
 
Expected time complexity : O(n)
Expected Auxiliary Space: O(n)
 
Constraints:
1 <= N <= 105
1 <= k <= 105

*/

struct Node* partition(struct Node* head, int x) {
    // code here
    Node* small=NULL,*equal=NULL,*large=NULL;
    Node* small_head=NULL,*equal_head=NULL,*large_head=NULL;
    Node* temp = head;
    while(temp!=NULL){
        if(temp->data < x){
            if(small==NULL){
                small = temp;
                small_head = temp;
            }else{
                small->next = temp;
                small = temp;
            }
        }else if(temp->data == x){
            if(equal==NULL){
                equal = temp;
                equal_head=temp;
            }else{
                equal->next = temp;
                equal = temp;
            }
        }else{
            if(large==NULL){
                large = temp;
                large_head=temp;
            }else{
                large->next = temp;
                large = temp;
            }
        }
        temp=temp->next;
    }
    if(large!=NULL){
        large->next=NULL;
    }
    
    if(small_head == NULL){
        if(equal_head == NULL){
            return large_head;
        }
        equal->next = large_head;
        return equal_head;
    }
    
    if(equal_head==NULL){
        small->next = large_head;
        return small_head;
    }
    
    small->next = equal_head;
    equal->next = large_head;
    return small_head;
   // return small_head;
    
}
