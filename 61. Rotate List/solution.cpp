/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr) return head;
        ListNode* newHead = getNewHead(head, k);
        ListNode* result = new ListNode(newHead->val);
        ListNode* newHeadCopy = newHead;
        ListNode* resultCopy = result;
        
        /* Copy from new head until end of original list*/
        while (newHeadCopy->next != nullptr) {
            resultCopy->next = new ListNode(newHeadCopy->next->val);
            resultCopy = resultCopy->next;
            newHeadCopy = newHeadCopy->next;
        }
        /* Copy from original head until new head */
        while (head != newHead) {
            resultCopy->next = new ListNode(head->val);
            resultCopy = resultCopy->next;
            head = head->next;
        }
        return result;
    }
    
    ListNode* getNewHead(ListNode* head, int k) {
        ListNode* slow = head;
        ListNode* fast = head;
        int listSize = 0;

        while (fast != nullptr) {
            fast = fast->next;
            listSize++;
        }
       
        /* k can get very large, so figure out "true" number of rotations */
        int trueK = k % listSize;
            
        if (trueK == 0) return head; // No need for rotation
        
        /* Calculate how much further fast pointer will be */
        fast = head;
        while (trueK > 0) {
            fast = fast->next;
            trueK--;
        }
        
        /* Calculate new head using the help of the fast pointer */
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};