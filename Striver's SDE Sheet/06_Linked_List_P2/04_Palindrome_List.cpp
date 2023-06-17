//& Check if given list is palindrome or not.

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//~ Approach
//* We use slow and fast pointers, we push elements of slow in stack until fast is not NULL.
//* After that until slow becomes NULL we pop from stack and compare it with slow.

bool isPalindrome(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;
    stack<int> st;
    while (fast != NULL && fast->next != NULL)
    {
        st.push(slow->val);
        slow = slow->next;
        fast = fast->next->next;
    }
    //* For odd length we skip middle element.
    if (fast != NULL)
    {
        slow = slow->next;
    }
    while (slow != NULL)
    {
        if (slow->val != st.top())
        {
            return false;
        }
        st.pop();
        slow = slow->next;
    }
    return true;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    return 0;
}