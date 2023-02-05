#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *mergeKLists(std::vector<ListNode *> &lists) {
        if (lists.size() == 0) return NULL;
        if (lists.size() == 1) return lists[0];
        if (lists.size() == 2) return mergeTwoLists(lists[0], lists[1]);

        std::vector<ListNode *> left(lists.begin(), lists.begin() + lists.size() / 2);
        std::vector<ListNode *> right(lists.begin() + lists.size() / 2, lists.end());

        return mergeTwoLists(mergeKLists(left), mergeKLists(right));
    }

    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;

        ListNode *head = NULL;
        if (l1->val < l2->val) {
            head = l1;
            l1 = l1->next;
        } else {
            head = l2;
            l2 = l2->next;
        }

        ListNode *p = head;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                p->next = l1;
                l1 = l1->next;
            } else {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }

        if (l1 != NULL) p->next = l1;
        if (l2 != NULL) p->next = l2;

        return head;
    }
};

int main() {
    std::vector<ListNode *> nums;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(4);
    head->next->next = new ListNode(5);
    nums.push_back(head);

    head = new ListNode(1);
    head->next = new ListNode(3);
    head->next->next = new ListNode(4);
    nums.push_back(head);

    head = new ListNode(2);
    head->next = new ListNode(6);
    nums.push_back(head);


    Solution s;
    ListNode *p = s.mergeKLists(nums);

    while (p != NULL) {
        std::cout << p->val << std::endl;
        p = p->next;
    }

    return 0;
}

