#include <iostream>
#include <vector>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
	private:
		ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
			ListNode* head = new ListNode(0);
			ListNode* p = head;
			while (l1 && l2) {
				if (l1->val < l2->val) {
					p->next = l1;
					l1 = l1->next;
				} else {
					p->next = l2;
					l2 = l2->next;
				}
				p = p->next;
			}
			if (l1) {
				p->next = l1;
			}
			if (l2) {
				p->next = l2;
			}
			return head->next;
		}
	public:
		ListNode* mergeKLists(std::vector<ListNode*>& lists) {
			if (lists.size() == 0) return NULL;
			if (lists.size() == 1) return lists[0];
			if (lists.size() == 2) return mergeTwoLists(lists[0], lists[1]);
			std::vector<ListNode*> left(lists.begin(), lists.begin() + lists.size() / 2);
			std::vector<ListNode*> right(lists.begin() + lists.size() / 2, lists.end());
			return mergeTwoLists(mergeKLists(left), mergeKLists(right));
		}
};

int main()
{
	ListNode* l1 = new ListNode(1);
	ListNode* l2 = new ListNode(4);
	ListNode* l3 = new ListNode(5);
	l1->next = l2;
	l2->next = l3;

	ListNode* l4 = new ListNode(1);
	ListNode* l5 = new ListNode(3);
	ListNode* l6 = new ListNode(4);
	l4->next = l5;
	l5->next = l6;

	ListNode* l7 = new ListNode(2);
	ListNode* l8 = new ListNode(6);
	l7->next = l8;

	std::vector<ListNode*> lists;
	lists.push_back(l1);
	lists.push_back(l4);
	lists.push_back(l7);

	Solution s;
	ListNode* head = s.mergeKLists(lists);

	while (head) {
		std::cout << head->val << " ";
		head = head->next;
	}

	std::cout << std::endl;

	return 0;
}

