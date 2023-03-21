#include <iostream>
#include <vector>



using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumber(ListNode* L1, ListNode* L2)
{
    vector<ListNode*> solution ;
    int val = 0;
    int res = 0;
    while(L1 != nullptr)
    {
        if(L2 == nullptr)
        {
            val = L1->val + res;
        }
        else
        {
            val = L1->val + res + L2->val;
            L2 = L2->next;
        }
        if(val >= 10 )
        {
            val = val -10;
            res = 1;
        }
        else
        {
            res = 0;
        }
        solution.push_back(new ListNode(val));
        L1 = L1->next;

    }

    if(L2 != nullptr)
    {
        while(L2 != nullptr)
        {
            val = L2->val + res;
            if(val >= 10 )
            {
                val = val -10;
                res = 1;
            }
            else
            {
                res = 0;
            }
            solution.push_back(new ListNode(val));
            L2 = L2->next;

        }
    }

    if(res == 1){
        solution.push_back(new ListNode(1));
    }

    for(int i  = 0 ; i < (int) solution.size() - 1 ; i++){
        solution[i]->next = solution[i+1];
    }
    return solution[0];
}

int main()
{

    ListNode* L11 = new ListNode(2);
    ListNode* L12 = new ListNode(4);
    ListNode* L13 = new ListNode(3);
    ListNode* L21 = new ListNode(5);
    ListNode* L22 = new ListNode(6);
    ListNode* L23 = new ListNode(4);
    ListNode* solution = new ListNode();
    L11->next = L12;
    L12->next = L13;
    L21->next = L22;
    L22->next = L23;
    solution = addTwoNumber(L11, L21);
     while(solution != nullptr){
         cout << solution->val<<endl;
         solution = solution->next;
     }



    return 0;
}
