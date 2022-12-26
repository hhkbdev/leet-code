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
		ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
			ListNode* head = new ListNode(0);
			ListNode* p = head;
			while (list1 != nullptr && list2 != nullptr) {
				if (list1->val < list2->val) {
					p->next = list1;
					list1 = list1->next;
				} else {
					p->next = list2;
					list2 = list2->next;
				}
				p = p->next;
			}
			if (list1 != nullptr) {
				p->next = list1;
			}
			if (list2 != nullptr) {
				p->next = list2;
			}
			return head->next;
		}
};

int main()
{
	ListNode* list1 = new ListNode(1);
	list1->next = new ListNode(2);
	list1->next->next = new ListNode(4);

	ListNode* list2 = new ListNode(1);
	list2->next = new ListNode(3);
	list2->next->next = new ListNode(4);

	Solution s;
	ListNode* list3 = s.mergeTwoLists(list1, list2);
	
	while (list3 != nullptr) {
		std::cout << list3->val << std::endl;
		list3 = list3->next;
	}

	return 0;
}

