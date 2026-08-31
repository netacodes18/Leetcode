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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        int idx = 0;
        vector<int> cp;

        while (curr != NULL && curr->next != NULL) {
            
            if (prev != NULL) {
                if (curr->val > prev->val && curr->val > curr->next->val) {
                    cp.push_back(idx);
                }

                if (curr->val < prev->val && curr->val < curr->next->val) {
                    cp.push_back(idx);
                }
            }

            prev = curr;
            curr = curr->next;
            idx++;
        }
        if(cp.size()<2) return {-1,-1};

        int mn=INT_MAX;
        int mx=cp.back()-cp.front();

        for(int i=1;i<cp.size();i++){
            mn=min(mn,cp[i]-cp[i-1]);
        }
        return {mn,mx};
    }
};