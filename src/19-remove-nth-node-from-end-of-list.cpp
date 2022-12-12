#include <iostream>
#include <vector>

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(NULL) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
	public:
		ListNode* removeNthFromEnd(ListNode* head, int n) {
			ListNode *p = head;
			ListNode *q = head;
			for (int i = 0; i < n; i++) {
				q = q->next;
			}
			if (q == NULL) {
				return head->next;
			}
			while (q->next != NULL) {
				p = p->next;
				q = q->next;
			}
			p->next = p->next->next;
			return head;
		}

};

int main()
{
	ListNode *exam1 = new ListNode(1);
	exam1->next = new ListNode(2);
	exam1->next->next = new ListNode(3);
	exam1->next->next->next = new ListNode(4);
	exam1->next->next->next->next = new ListNode(5);

	Solution s;
	ListNode *p1 = s.removeNthFromEnd(exam1, 4);
	while (p1) {
		std::cout << p1->val << std::endl;
		p1 = p1->next;
	}

	ListNode *exam2 = new ListNode(1);
	ListNode *p2 = s.removeNthFromEnd(exam2, 1);
	while (p2) {
		std::cout << p2->val << std::endl;
		p2 = p2->next;
	}


	ListNode *exam3 = new ListNode(1);
	exam3->next = new ListNode(2);
	ListNode *p3 = s.removeNthFromEnd(exam3, 1);
	while (p3) {
		std::cout << p3->val << std::endl;
		p3 = p3->next;
	}

	return 0;
}

