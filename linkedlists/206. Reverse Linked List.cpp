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
    ListNode* headRET;
    void reverse (ListNode* head, ListNode* prev) {
        if (head->next == nullptr) {
            headRET = head;
            head->next = prev;
            return;
        }
        reverse(head->next, head);
        head->next = prev;
    }
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr)
            return nullptr;
        reverse(head, nullptr);
        return headRET;
    }
};
