#include <iostream>
using namespace std;
  struct ListNode
  {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

  class Solution
  {
  public:
      bool hasCycle(ListNode *head)
      {
          int count = 0;
          while (head)
          {
              if (count > 100002)
                  return true;
              head = head->next;
              count++;
          }
          return false;
      }
  };