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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        multiset<int> st;
        for (ListNode* x: lists) {
            while (x != nullptr) {
                st.insert(x->val);
                x = x->next;
            }
        }
        if (st.size() == 0)
            return NULL;
        multiset<int> :: iterator it = st.begin();
        ListNode* ret = new ListNode(0);
        ListNode* tmp = ret;
        while (it != st.end()) {
            tmp->next = new ListNode(*it);
            tmp = tmp->next;
            it++;
        }

        return ret->next;
    }
};
