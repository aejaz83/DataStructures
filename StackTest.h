#pragma once
#include "Stack.h"
#include <iostream>

namespace Stack
{
    bool testStackArray()
    {
        std::cout << std::endl << "###########################################################################" << std::endl;
        StackArray<int> s;
        std::cout << "Pushing 1 ..." << s.Push(1) << std::endl;
        std::cout << "Pushing 2 ..." << s.Push(2) << std::endl;
        std::cout << "Pushing 3 ..." << s.Push(3) << std::endl;
        std::cout << "Pushing 4 ..." << s.Push(4) << std::endl;
        std::cout << "Pop ..." << s.Pop() << std::endl;
        std::cout << "Pop ..." << s.Pop() << std::endl;
        std::cout << "Pop ..." << s.Pop() << std::endl;
        std::cout << "Pop ..." << s.Pop() << std::endl;
        std::cout << "IsEmpty ..." << s.IsEmpty() << std::endl;
        std::cout << std::endl << "###########################################################################" << std::endl;


        return true;
    }
    bool testStackList()
    {
        std::cout << std::endl << "###########################################################################" << std::endl;

        StackList s;
        std::cout << "Pushing 5 ..." << s.Push(5) << std::endl;
        std::cout << "Pushing 6 ..." << s.Push(6) << std::endl;
        std::cout << "Pushing 7 ..." << s.Push(7) << std::endl;
        std::cout << "Pushing 8 ..." << s.Push(8) << std::endl;
        std::cout << "Pop ..." << s.Pop() << std::endl;
        std::cout << "Pop ..." << s.Pop() << std::endl;
        std::cout << "Pop ..." << s.Pop() << std::endl;
        std::cout << "Pop ..." << s.Pop() << std::endl;
        std::cout << "IsEmpty ..." << s.IsEmpty() << std::endl;

        std::cout << std::endl << "###########################################################################" << std::endl;

        return true;
    }
    bool testBalancedParanthesis()
    {
        std::cout << std::endl << "###########################################################################" << std::endl;
        std::cout << "Testing )( ..." << BalancedParenthesis(")(") << std::endl;
        std::cout << "Testing [{()}] ..." << BalancedParenthesis("[{()}]") << std::endl;
        std::cout << "Testing [{}()()[{()}]] ..." << BalancedParenthesis("[{}()()[{()}]]") << std::endl;
        std::cout << "Testing [{}()()[{()}] ..." << BalancedParenthesis("[{}()()[{()}]") << std::endl;
        std::cout << "Testing (){}[] ..." << BalancedParenthesis("(){}[]") << std::endl;
        std::cout << std::endl << "###########################################################################" << std::endl;

        return true;
    }
    bool testInfixPostFixPrefix()
    {
        std::cout << std::endl << "###########################################################################" << std::endl;
        std::cout << "Testing PostFix expr: 2 3 +  Ans: " << PostfixEvaluation("2 3 + ") << std::endl;
        std::cout << "Testing PostFix expr: 2 3 * 5 4 * + 9 -  Ans: " << PostfixEvaluation("2 3 * 5 4 * + 9 -") << std::endl;
        std::cout << "Testing Convert Infix to PostFix expr: 2*3+5*4-9  Ans: " << InfixToPostfix("2*3+5*4-9") << std::endl;

        std::cout << std::endl << "###########################################################################" << std::endl;

        return true;
    }
    //3.2 How would you design a stack which, in addition to push and pop, also has a function min
    //  which returns the minimum element ?
    //  Push, pop and min should all operate in O(1) time.
    bool testStackMin()
    {
        std::cout << std::endl << "###########################################################################" << std::endl;

        StackMin s;
        std::cout << "Pushing 5 ..." << s.Push(5) << std::endl;
        std::cout << "Pushing 15 ..." << s.Push(5) << std::endl;
        std::cout << "Pushing 0 ..." << s.Push(0) << std::endl;
        std::cout << "Pushing 6 ..." << s.Push(6) << std::endl;
        std::cout << "Pushing 7 ..." << s.Push(7) << std::endl;
        std::cout << "Pushing 8 ..." << s.Push(8) << std::endl;
        std::cout << "Pushing -8 ..." << s.Push(-8) << std::endl;
        std::cout << "Minimum  ..." << s.Min() << std::endl;
        std::cout << "Pop ..." << s.Pop() << std::endl;
        std::cout << "Minimum  ..." << s.Min() << std::endl;
        std::cout << "Pop ..." << s.Pop() << std::endl;
        std::cout << "Minimum  ..." << s.Min() << std::endl;
        std::cout << "Pop ..." << s.Pop() << std::endl;
        std::cout << "Minimum  ..." << s.Min() << std::endl;
        std::cout << "Pop ..." << s.Pop() << std::endl;
        std::cout << "Minimum  ..." << s.Min() << std::endl;
        std::cout << "IsEmpty ..." << s.IsEmpty() << std::endl;

        std::cout << std::endl << "###########################################################################" << std::endl;

        return true;
    }

    void testTowersOfHanoi()
    {
        TowersOfHanoi('A', 'C', 'B', 3);
    }

    //3.5 Implement a MyQueue class which implements a queue using two stacks.
    void testQueueUsingStack()
    {
        std::cout << std::endl << "###########################################################################" << std::endl;
        MyQueue s;
        std::cout << "Pushing 11 ..." << s.Enqueue(11) << std::endl;
        std::cout << "Pushing 12 ..." << s.Enqueue(12) << std::endl;
        std::cout << "Pushing 13 ..." << s.Enqueue(13) << std::endl;
        std::cout << "Pushing 14 ..." << s.Enqueue(14) << std::endl;
        std::cout << "Pop ..." << s.Front();
        std::cout << " res: " << s.Dequeue() << std::endl;
        std::cout << "Pop ..." << s.Front() << " res: ";
        std::cout << " res: " << s.Dequeue() << std::endl;
        std::cout << "Pop ..." << s.Front() << " res: ";
        std::cout << " res: " << s.Dequeue() << std::endl;
        std::cout << "Pop ..." << s.Front() << " res: ";
        std::cout << " res: " << s.Dequeue() << std::endl;
        std::cout << std::endl << "###########################################################################" << std::endl;

    }
    //3.6 Write a program to sort a stack in ascending order.
    //You should not make any assumptions about how the stack is implemented.
    //The following are the only functions that should be used to write
    //this program: push | pop | peek | isEmpty.
    void testSortStack()
    {
        StackList sint;
        sint.Push(1);
        sint.Push(10);
        sint.Push(2);
        sint.Push(20);
        sint.Push(3);
        sint.Push(30);
        sint.Push(4);
        sint.Push(40);
        sint.Push(5);
        sint.Push(50);
        auto send =  SortStack(sint);

        while(!send.IsEmpty())
        {
            std::cout << send.Pop() << ", " << std::endl;
        }

        std::cout << std::endl;
    }

}