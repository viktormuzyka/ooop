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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	ListNode* new_root = nullptr;
	ListNode* current;
	ListNode* current_l1 = l1;
	ListNode* current_l2 = l2;
	while (current_l1 || current_l2)
	{
		if (current_l1 && current_l2)
		{
			int new_data;
			if (current_l1->val < current_l2->val)
			{
				new_data = current_l1->val;
				current_l1 = current_l1->next;
			}
			else
			{
				new_data = current_l2->val;
				current_l2 = current_l2->next;
			}
			if (new_root)
			{
				current->next= new ListNode(new_data);
				current = current->next;
			}
			else {
				new_root = new ListNode(new_data);
				current = new_root;
			}

			continue;
		}
		if (current_l1)
		{
			if (new_root)
			{
				current->next = new ListNode(current_l1->val);
				current = current->next;
			}
			else {
				new_root = new ListNode(current_l1->val);
				current = new_root;
			}
			current_l1 = current_l1->next;
			continue;
		}
		if (current_l2)
		{
			if (new_root)
			{
				current->next = new ListNode(current_l2->val);
				current = current->next;
			}
			else {
				new_root = new ListNode(current_l2->val);
				current = new_root;
			}
			current_l2 = current_l2->next;

		}

	}
	return new_root;

    }
};