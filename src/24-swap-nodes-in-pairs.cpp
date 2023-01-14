#include <iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
	public:
		ListNode* swapPairs(ListNode* head) {
			if (head == NULL || head->next == NULL) return head;
			ListNode *p = head, *q = head->next, *r = head->next->next;
			q->next = p;
			p->next = swapPairs(r);
			return q;
		}
};

int main()
{
	Solution s;
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);

	ListNode *p = s.swapPairs(head);

	while (p != NULL) {
		std::cout << p->val << std::endl;
		p = p->next;
	}

	return 0;
}

