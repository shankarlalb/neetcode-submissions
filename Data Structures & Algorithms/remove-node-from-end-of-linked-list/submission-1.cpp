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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto count = [](ListNode* head)->int{
            int ct = 0;
            while(head!=nullptr){
                ct += 1;
                head = head->next;
            }
            return ct;
        };
        auto temptemp = head;
        int nn = count(temptemp);

        int fromStart = nn - n -1;
        if(fromStart==-1){
            return head->next;
        }
        auto tempHead = head;
        int ct = 0;
        while(ct<fromStart){
            ct++;
            tempHead = tempHead->next;
        }
        auto nxt = tempHead->next;
        tempHead->next = tempHead->next->next;
        nxt->next = nullptr;
        return head;
        
    }
};
