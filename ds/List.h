#pragma once
#include <stack>
namespace List
{
    struct Node
    {
        int data;
        Node* next;
    };

    Node* createNode(int data)
    {
        Node* tmp = new Node();
        tmp->data = data;
        tmp->next = NULL;
        return tmp;
    }

    Node* InsertHead(Node* head, int value)
    {

        Node* tmp = createNode(value);
        tmp->next = head;
        head = tmp;
        return head;

    }

    //9 -> 7 -> 6 -> 5 -> 4
    //  0    1    2    3    4

    //  InsertPosition( head, 11, 2)

    //  9 -> 7 -> 11 -> 6 -> 5 -> 4
    Node* InsertPosition(Node* head, int value, int pos)
    {
        if(head == NULL || pos == 0)
        {
            return InsertHead(head, value);
        }
        else
        {
            Node* prev = NULL;
            int n = 0;

            for(prev = head; (n <= (pos - 1)) && (prev != NULL); n++, prev = prev->next);

            auto tmp = createNode(value);
            tmp->next = prev->next;
            prev->next = tmp;

        }

        return head;
    }
    Node* RemovePosition(Node* head,  int pos)
    {
        if(head == NULL)
        {
            return NULL;
        }
        else if(pos == 0)
        {
            Node* tmp = head->next;
            delete head;
            head = tmp;
            return head;
        }
        else
        {
            Node* prev = NULL;
            int n = 0;

            for(prev = head; (n <= (pos - 1)) && (prev != NULL); n++, prev = prev->next);

            auto tmp = prev->next;
            prev->next = tmp->next;
            delete tmp;

        }

        return head;
    }
    void Print(Node* head)
    {
        while(head != NULL)
        {
            std::cout << head->data << " , ";
            head = head->next;
        }

        std::cout << std::endl;
    }
    void PrintReverse(Node* head)
    {
        if(head == NULL)
        {
            return;
        }

        PrintReverse(head->next);

        std::cout << head->data << " , ";

    }
    Node* ReverseList(Node* head)
    {
        Node* curr, *prev;
        curr = head;
        prev = NULL;

        while(curr != NULL)
        {
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;

    }
    Node* ReverseRecursion(Node* head)
    {
        if(head->next == NULL)
        {
            return head;
        }

        Node* headTmp = ReverseRecursion(head->next);
        head->next->next = head;
        head->next = NULL;
        return headTmp;


    }
    ///////////////////////////////////////////////////// questions //////////////////////////////////////////////
    // 2.1 Write code to remove duplicates from an unsorted linked list.
    void DeleteDuplicates(Node* head)
    {
        if(head == NULL)
        {
            return;
        }

        Node* prev = head;
        Node* curr = head->next;

        while(curr != NULL)
        {
            Node* runner = head;

            if(runner != curr)
            {
                if(runner->data == curr->data)
                {
                    Node* tmp = curr->next;
                    prev->next = tmp;
                    delete curr;
                    curr = tmp;
                    break;// all other dups have already been removed
                }

                runner = runner->next;
            }

            if(runner == curr)
            {
                prev = curr;
                curr = curr->next;
            }
        }
    }

    //2.2 kth to last element
    Node* KthLastElem(Node* head, int k)
    {
        if(k < 0 || head == NULL)
        {
            return 0;
        }

        Node* curr = head;

        for(int i = 0; i < k; i++)
        {
            curr = curr->next;
        }

        Node* knode = head;

        while(curr != NULL)
        {
            curr = curr->next;
            knode = knode->next;

        }

        return knode;
    }
    //2.3 delete middle node
    //given access to only middle node delete the node
    //Ans: copy the next node data in middle node and delete next node
    void DeleteMiddleNode(Node* middle)
    {
        if(middle == NULL)
        {
            return;
        }

        Node* next = middle->next;
        middle->data = next->data;
        middle->next = next->next;
        delete next;

    }

    Node* ReverseUsingStack(Node* head)
    {
        std::stack<Node*> S;
        Node* tmp = head;

        while(tmp != NULL)
        {
            S.push(tmp);
            tmp = tmp->next;
        }

        tmp = S.top();
        S.pop();
        head = tmp;

        while(!S.empty())
        {
            tmp->next = S.top();
            S.pop();
            tmp = tmp->next;
        }

        tmp->next = NULL;
        return head;
    }

    //2.4 You have two numbers represented by a linked list, where each node contains a single digit.The digits are stored in reverse order, such that the 1’s digit is at the head of the list.Write a function that adds the two numbers and returns the sum as a linked list.
    //  EXAMPLE
    //  Input : (3 -> 1 -> 5), (5 -> 9 -> 2)
    //  Output : 8 -> 0 -> 8

    Node* AddLists(Node* head1, Node* head2, int carry)
    {
        if((head1 == NULL) || (head2 == NULL))
        {
            return NULL;
        }

        int num = head1->data + head2->data + carry;
        Node* link = createNode(num % 10);
        link->next = AddLists(head1->next, head2->next, (num / 10));
        return link;

    }

    //2.5 Given a circular linked list, implement an algorithm which returns node at the beginning of the loop.
    //  DEFINITION
    //  Circular linked list : A(corrupt) linked list in which a node’s next pointer points to an earlier node, so as to make a loop in the linked list.
    //  EXAMPLE
    //  Input : A->B->C->D->E->C[the same C as earlier]
    //  Output : C
    Node* FindBeginning(Node* head)
    {
        Node* res = NULL;
        Node* slow = head;
        Node* fast = head;

        while(fast && (fast->next))
        {
            fast = fast->next->next;
            slow = slow->next;

            if(fast == slow)
            {
                break;
            }
        }

        if(fast == slow)
        {
            res = head;

            while(res != fast)
            {
                fast = fast->next;
                res = res->next;

            }
        }

        return res;

    }
}
