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
        vector<ListNode*> v;
        ListNode* tmp = head;
        while (head != nullptr) {
            v.push_back(head);
            head = head->next;
        }
        int sz = v.size();
        int x = sz - n;
        if (x == 0) {
            if (sz == 1) {
                return nullptr;
            }
            else {
                return v[1];
            }
        }
        else if (x == sz - 1) {
            v[sz-2]->next = nullptr;
        }
        else {
            for (int i = 0; i < sz; i++) {
                if (i == x) {
                    v[i - 1]->next = v[i + 1];
                }
            }
        }
        return tmp;
    }
};
