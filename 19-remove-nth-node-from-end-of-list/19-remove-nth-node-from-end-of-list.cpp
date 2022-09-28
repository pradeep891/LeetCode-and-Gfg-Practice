/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    int findLength(ListNode* cur){
        int ct = 0;
        while(cur){
            ct++;
            cur = cur->next;
        }
        return ct;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = findLength(head);
         n = len - n;
        
        if(n == 0) return head->next;
        
        ListNode* cur = head;
        n--;
        while(n--){
            cur = cur->next;
        }
        
        cur->next = cur->next->next;
        
        return head;
    }
};