#include <iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
	public:
		ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
			ListNode *head = new ListNode(0);
			ListNode *p = head;
			int carry = 0;
			while (l1 || l2 || carry) {
				int sum = carry;
				if (l1) {
					sum += l1->val;
					l1 = l1->next;
				}
				if (l2) {
					sum += l2->val;
					l2 = l2->next;
				}
				carry = sum / 10;
				p->next = new ListNode(sum % 10);
				p = p->next;
			}
			return head->next;
		}
};

int main() {
	ListNode *l1 = new ListNode(2);
	l1->next = new ListNode(4);
	l1->next->next = new ListNode(3);
	ListNode *l2 = new ListNode(5);
	l2->next = new ListNode(6);
	l2->next->next = new ListNode(4);
	Solution s;
	ListNode *l3 = s.addTwoNumbers(l1, l2);
	while (l3) {
		std::cout << l3->val << " ";
		l3 = l3->next;
	}
	std::cout << std::endl;
	return 0;
	
}
