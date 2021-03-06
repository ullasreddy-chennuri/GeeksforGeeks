/*

Given two numbers represented by two linked lists, write a function that returns Sum list. 
The sum list is linked list representation of addition of two input numbers.


Example 1:
Input:
S1 = 3, S2 = 3
ValueS1 = {2,3,4}
ValueS2 = {3,4,5}
Output: 5 7 9

Explanation: After adding the 2 numbers
the resultant number is 5 7 9.


Example 2:
Input:
S1 = 1, S2 = 2
ValueS1 = {9}
ValueS2 = {8,7}
Output: 9 6

Explanation: Add 9 and 7 we get 16.
1 is carry here and is added to 8.
So the answer is 9 6

Your Task:
The task is to complete the function addSameSize() addCarryToRemaining().

Constraints:
1 <= S1, S2 <= 100

*/

// First Adding the sums of lists with equal sizes 
Node* addSameSize(Node* head1, Node* head2, int* carry) 
{ 
	// Your code here
	if(head1==NULL){
	    return NULL;
	}
	int sum;
	
	Node* new_list = new Node(0);
	
	new_list->next=addSameSize(head1->next,head2->next,carry);
	
	sum = head1->data+head2->data + *carry;
	*carry = sum/10;
	sum=sum%10;
	new_list->data = sum;
	
	return new_list;
	
} 

//Function to add remaining carry.
// Adding xarry to the extra part of larger linked list
void addCarryToRemaining(Node* head1, Node* curr, int* carry, Node** result) 
{ 
	// Your code here
	int sum;
	if(head1!=curr){
	    addCarryToRemaining(head1->next,curr,carry,result);
	    sum = head1->data + *carry;
	    *carry = sum/10;
	    sum=sum%10;
	    push(result,sum);
	}
}
