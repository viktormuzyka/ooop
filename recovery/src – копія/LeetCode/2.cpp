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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       ListNode* answer = new ListNode();
	ListNode* current = answer;
	bool a = 0;
	bool e = 0;
	while (l1 || l2) {
		if (e)
		{
			current->next = new ListNode();
			current = current->next;
		}
		if (l1 && l2) {
			current->val = l1->val + l2->val + a;
			if (current->val>9)
			{
				current->val %= 10;
				a = 1;
			}
			else {
				a = 0;
			}
			l1 = l1->next;
			l2 = l2->next;
		}
		else if (l1) {
			current->val = l1->val + a;
			if (current->val > 9)
			{
				current->val %= 10;
				a = 1;
				
			}
			else {
				a = 0;
			}
			l1 = l1->next;
			
		}
		else {
			current->val = l2->val + a;
			if (current->val > 9)
			{
				current->val %= 10;
				a = 1;
				
			}
			else {
				a = 0;
			}
			l2 = l2->next;
		}
		e = 1;
	}
	if (a)
	{
		current->next = new ListNode(1);
	}
	return answer;
    }
};