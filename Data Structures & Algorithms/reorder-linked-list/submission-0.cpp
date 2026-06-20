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
    void reorderList(ListNode* head) {
        vector<ListNode*>v;
        while(head!=nullptr){
            v.push_back(head);
            head = head->next;
        }
        vector<ListNode*>nv;
        int n = v.size();
        int i = 0;
        int j = n-1;
        int isI = 1;
        while(nv.size()<n){
            if(isI){
                nv.push_back(v[i++]);
            }else{
                nv.push_back(v[j--]);
            }
            isI = 1-isI;
        }
        for(int i = 0;i<n-1;i++){
            nv[i]->next = nv[i+1];
        }
        nv.back()->next =nullptr;
    
    }
};
