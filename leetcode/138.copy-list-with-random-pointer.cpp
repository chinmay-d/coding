/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        Node* temp = head;
        while(temp){
            Node* node = new Node(temp->val);      // create a new node with val as temp->val;
            node->next = temp->next;               // insert that node
            temp->next = node;                     // in between temp and temp->next;
            temp = temp->next->next;
        }
        
        temp = head;
        while(temp){
            if(temp->random and temp->random->next) temp->next->random = temp->random->next;   // now the value temp->next->random will be mapped to temp->random->next;
            temp = temp->next->next;                                                           // this is the mapping of our random pointer;
        }
        
        // create a new list by seperating the older list;
        Node* curr = head;
        Node* newhead = NULL;
        Node* newList = NULL;
        while(curr){
            Node *next = curr->next;
            if(!newhead){
                newhead = next;
                newList = newhead;
            }
            else{
                newList->next = next;       
                newList = newList->next;
            }
            curr->next = next->next;
            curr = next->next;
        }
        return newhead;
        
    }
};
// @lc code=end

