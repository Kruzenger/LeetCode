
// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    // I believe it is bad idea to modify parameter pointers
    ListNode* l1_next = l1;
    ListNode* l2_next = l2;

    // Result: answer is begin of answer and answer_next is moveble pointer

    ListNode* answer = new ListNode(0);
    ListNode* answer_next = answer;

    // Let's run through linked lists
    while (l1_next != nullptr || l2_next != nullptr) {
      answer_next->next = new ListNode(answer_next->val / 10);
      answer_next->val %= 10;
      // Not forget of extra unit of higher rank
      answer_next = answer_next->next;
      if (l1_next != nullptr) {
        answer_next->val += l1_next->val;
        l1_next = l1_next->next;
      }
      if (l2_next != nullptr) {
        answer_next->val += l2_next->val;
        l2_next = l2_next->next;
      }
    }

    // Another extra unit
    if (answer_next->val > 9) {
      answer_next->next = new ListNode(answer_next->val / 10);
      answer_next->val %= 10;
    }

    // Do not forget to delete first node
    answer_next = answer;
    answer = answer->next;
    delete answer_next;

    return answer;
  }
};