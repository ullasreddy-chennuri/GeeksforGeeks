/*
Given an integer K and a queue of integers, we need to reverse the order of the first K elements of the queue, 
leaving the other elements in the same relative order.

Only following standard operations are allowed on queue.

enqueue(x) : Add an item x to rear of queue
dequeue() : Remove an item from front of queue
size() : Returns number of elements in queue.
front() : Finds front item.


Example 1:
Input:
5 3
1 2 3 4 5

Output: 
3 2 1 4 5

Explanation: 
After reversing the given
input from the 3rd position the resultant
output will be 3 2 1 4 5.


Example 2:
Input:
4 4
4 3 2 1

Output: 
1 2 3 4


Explanation: 
After reversing the given
input from the 4th position the resultant
output will be 1 2 3 4.

Your Task:
Complete the provided function modifyQueue that takes queue and k as parameters and returns a modified queue.
The printing is done automatically by the driver code.

Expected TIme Complexity : O(n)
Expected Auxilliary Space : O(n)

Constraints:
1 <= N <= 1000
1 <= K <= N
*/

queue<int> modifyQueue(queue<int> q, int k)
{
    //add code here.
    int n=q.size();
    stack<int> st;
    for(int i=0;i<k;i++){
        st.push(q.front());
        q.pop();
    }
    queue<int> q1;
    for(int i=k;i<n;i++){
        q1.push(q.front());
        q.pop();
    }
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }
    while(!q1.empty()){
        q.push(q1.front());
        q1.pop();
    }
    return q;
}
