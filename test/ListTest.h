#pragma once
#include "List.h"
#include <iostream>
#include "Utility.h"

namespace List
{
    bool testList()
    {
        std::cout << std::endl << "###########################################################################" << std::endl;

        Node* head = NULL;
        std::cout << "inserting in head" << std::endl;
        head = InsertHead(head, 4);
        head = InsertHead(head, 5);
        head = InsertHead(head, 6);
        head = InsertHead(head, 7);
        head = InsertHead(head, 9);
        Print(head);
        std::cout << std::endl << "inserting in position" << std::endl;

        head = InsertPosition(head, 11, 2);
        Print(head);
        head = InsertPosition(head, 0, 0);
        Print(head);
        std::cout << std::endl << "removing in position" << std::endl;
        head = RemovePosition(head, 0);
        Print(head);
        head = RemovePosition(head, 3);
        Print(head);
        std::cout << std::endl << "List after reversal" << std::endl;
        head = ReverseList(head);
        Print(head);
        head = ReverseRecursion(head);
        Print(head);
        PrintReverse(head);
        //2.2 kth last element
        std::cout << std::endl << "kth last element Test" << std::endl;
        Print(head);
        std::cout << std::endl << "2 last element: " << (KthLastElem(head, 2))->data << std::endl;
        std::cout << std::endl << "4 last element: " << (KthLastElem(head, 4))->data << std::endl;
        //2.3 Delete Middle Node
        std::cout << std::endl << "Delete Middle Node (6) Test" << std::endl;
        Print(head);
        DeleteMiddleNode(head->next->next);
        Print(head);
        std::cout << std::endl << "Reverese list using stack" << std::endl;
        head = ReverseUsingStack(head);
        Print(head);
        std::cout << std::endl << "###########################################################################" << std::endl;

        return false;
    }

    //2.1 delete duplicates
    bool testDeleteDuplicates()
    {
        std::cout << std::endl << "###########################################################################" << std::endl;

        Node* head = NULL;
        std::cout << "inserting in head" << std::endl;
        head = InsertHead(head, 4);
        head = InsertHead(head, 5);
        head = InsertHead(head, 4);
        head = InsertHead(head, 5);
        //head = InsertHead(head, 9);
        //head = InsertHead(head, 9);
        //head = InsertHead(head, 29);
        //head = InsertHead(head, 19);

        //2.2 kth last element
        std::cout << std::endl << "delete duplicates" << std::endl;
        Print(head);
        DeleteDuplicates(head);
        std::cout << std::endl << "After delete duplicates" << std::endl;
        Print(head);

        std::cout << std::endl << "###########################################################################" << std::endl;

        return false;
    }

    //2.1 delete duplicates
    bool testAddLists()
    {
        std::cout << std::endl << "###########################################################################" << std::endl;

        Node* head1 = NULL;
        std::cout << "inserting in head" << std::endl;
        head1 = InsertHead(head1, 5);
        head1 = InsertHead(head1, 1);
        head1 = InsertHead(head1, 3);

        Node* head2 = NULL;
        head2 = InsertHead(head2, 2);
        head2 = InsertHead(head2, 9);
        head2 = InsertHead(head2, 5);

        //2.2 kth last element
        std::cout << std::endl << "Adding 3,1,5 and 5,9,2" << std::endl;
        Print(head1);
        Print(head2);
        Node* node = AddLists(head1, head2, 0);
        std::cout << std::endl << "After Addition" << std::endl;
        Print(node);

        std::cout << std::endl << "###########################################################################" << std::endl;

        return false;
    }

    //2.5 find the beginning of a loop in linked list
    bool testFindBeginning()
    {
        std::cout << std::endl << "###########################################################################" << std::endl;

        Node* head1 = NULL;
        Node* nod2, *nod1;
        std::cout << "inserting in head" << std::endl;
        head1 = nod1 = InsertHead(head1, 11);
        head1 = InsertHead(head1, 10);
        head1 = InsertHead(head1, 9);
        head1 = InsertHead(head1, 8);
        head1 = InsertHead(head1, 7);
        head1 = InsertHead(head1, 6);
        head1 = InsertHead(head1, 5);
        head1 = nod2 = InsertHead(head1, 4);
        head1 = InsertHead(head1, 3);
        head1 = InsertHead(head1, 2);
        head1 = InsertHead(head1, 1);

        Print(head1);
        std::cout << std::endl << "Loop detected: " << BoolToStr(FindBeginning(head1) != NULL) << std::endl;

        std::cout << std::endl << "Introducing loop at 4" << std::endl;
        nod1->next = nod2;
        std::cout << std::endl << "Loop detected at: " << (FindBeginning(head1))->data << std::endl;

        std::cout << std::endl << "###########################################################################" << std::endl;

        return false;
    }
}