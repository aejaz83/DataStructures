#pragma once
#include<string>
#include<climits>
#include"Utility.h"

namespace Stack
{
    template<class T> class StackArray
    {

    private:
        static const unsigned int MAX_SIZE = 1001;
        T arr[MAX_SIZE];
        int top;

    public:
        StackArray(): top(-1) {}
        bool Push(T x)
        {
            if(top == (MAX_SIZE - 1))
            {
                return false;
            }

            arr[++top] = x;
            return true;
        }
        T Pop()
        {
            if(top == (- 1))
            {
                return -1;
            }

            return arr[top--];
        }
        bool IsEmpty()
        {
            return (top == -1);
        }
        T Top()
        {
            if(top == (-1))
            {
                return -1;
            }

            return arr[top];
        }

    };

    class StackList
    {

    private:
        struct Node
        {
            int data;
            Node* next;
        };
        Node* top;
    public:
        StackList() : top(NULL) {}
        bool Push(int x)
        {
            Node* tmp = new Node();
            tmp->data = x;
            tmp->next = top;
            top = tmp;

            return true;
        }
        int Pop()
        {
            if(top == (NULL))
            {
                return -1;
            }

            Node* tmp = top;
            int x = tmp->data;
            top = top->next;
            delete tmp;
            return x;
        }
        int Peek()
        {
            if(top == (NULL))
            {
                return -1;
            }

            return top->data;
        }
        bool IsEmpty()
        {
            return (top == NULL);
        }

    };

    //check for balance parenthesis using stack
    //str = {[()]}
    bool BalancedParenthesis(std::string str)
    {
        StackArray<char> st;

        for(int i = 0; i < str.length(); i++)
        {
            if((str[i] == '{') || (str[i] == '[') || (str[i] == '('))
            {
                st.Push(str[i]);
            }
            else if((str[i] == '}') || (str[i] == ']') || (str[i] == ')'))
            {
                if(st.IsEmpty())
                {
                    return false;
                }

                char ch = st.Pop();

                if(str[i] == '}')
                {
                    if(ch != '{')
                    {
                        return false;
                    }
                }
                else if(str[i] == ']')
                {
                    if(ch != '[')
                    {
                        return false;
                    }

                }
                else
                {
                    if(ch != '(')
                    {
                        return false;
                    }

                }
            }
            else
            {
                return false;
            }
        }

        return st.IsEmpty();
    }

    int PostfixEvaluation(std::string expr)
    {
        StackArray<int> st;

        for(int i = 0; i < expr.length(); i++)
        {
            if(isspace(expr[i]))
            {
                continue;
            }
            else if(isdigit(expr[i]))
            {
                int num = expr[i] - '0';
                st.Push(num);
            }
            else if((expr[i] == '*') || (expr[i] == '/') || (expr[i] == '+') || (expr[i] == '-'))
            {
                int op2 = st.Pop();
                int op1 = st.Pop();
                st.Push(PerformOperation(expr[i], op1, op2));

            }
            else
            {
                return INT_MIN;
            }
        }

        return st.Pop();
    }
    std::string InfixToPostfix(std::string infix)
    {
        std::string postfix;
        StackArray<char> st;

        for(int i = 0; i < infix.length(); i++)
        {
            if(isspace(infix[i]))
            {
                continue;
            }
            else if(isdigit(infix[i]))
            {
                postfix += infix[i];
            }
            else if((infix[i] == '*') || (infix[i] == '/') || (infix[i] == '+') || (infix[i] == '-'))
            {

                while(!st.IsEmpty() && HasHigherPrecedence(st.Top(), infix[i]))
                {
                    postfix += st.Top();
                    st.Pop();
                }

                st.Push(infix[i]);

            }
        }

        while(!st.IsEmpty())
        {
            postfix += st.Top();
            st.Pop();
        }

        return postfix;
    }

    //3.2 How would you design a stack which, in addition to push and pop, also has a function min
    //  which returns the minimum element ?
    //  Push, pop and min should all operate in O(1) time.

    class StackMin : public StackList
    {
        StackList smin;
    public:
        StackMin() : StackList(), smin()
        {

        }
        int Peek()
        {
            return StackList::Peek();
        }

        bool Push(int x)
        {
            if(x < Min())
            {
                smin.Push(x);
            }

            return StackList::Push(x);

        }
        int  Min()
        {
            if(smin.IsEmpty())
            {
                return INT_MAX;
            }

            return smin.Peek();
        }
        int Pop()
        {
            int val = StackList::Pop();

            if(val = smin.Peek())
            {
                smin.Pop();
            }

            return val;
        }
        bool IsEmpty()
        {
            return (StackList::IsEmpty());
        }

    };
    ////http://www.geeksforgeeks.org/recursive-functions/
    //      3.4 In the classic problem of the Towers of Hanoi, you have 3 rods and N disks of different sizes which can slide onto any tower.The puzzle starts with disks sorted in ascending order of size from top to bottom(e.g., each disk sits on top of an even larger one).You have the following constraints :
    //      (A)Only one disk can be moved at a time.
    //          (B)A disk is slid off the top of one rod onto the next rod.
    //          (C)A disk can only be placed on top of a larger disk.
    //          Write a program to move the disks from the first rod to the last using Stacks.

    void TowersOfHanoi(char source, char destination, char auxillary, int n)
    {
        if(n == 0)
        {
            return;
        }

        //Move n-1 disks from source to auxillary using destination as auxillary
        TowersOfHanoi(source, auxillary, destination, n - 1);
        //Move nth disk from source to destination
        std::cout << "Moving disk " << n << " from " << source << " to " << destination << std::endl;
        //Move n-1 disks from auxillary to destination using source as auxillary
        TowersOfHanoi(auxillary, destination, source, n - 1);
    }

    //3.5 Implement a MyQueue class which implements a queue using two stacks.
    class MyQueue
    {
        StackArray<int> s1;
        StackArray<int> s2;
    public:
        MyQueue() : s1(), s2()
        {

        }
        bool Enqueue(int x)
        {
            s1.Push(x);
            return true;
        }
        bool Dequeue()
        {
            if(s2.IsEmpty())
            {
                if(s1.IsEmpty())
                {
                    return false;
                }

                while(!s1.IsEmpty())
                {
                    s2.Push(s1.Pop());
                }
            }

            s2.Pop();
            return true;
        }
        int Front()
        {
            if(s2.IsEmpty())
            {
                if(s1.IsEmpty())
                {
                    return INT_MAX;
                }

                while(!s1.IsEmpty())
                {
                    s2.Push(s1.Pop());
                }
            }

            return s2.Top();

        }
    };

    //3.6 Write a program to sort a stack in ascending order.
    //You should not make any assumptions about how the stack is implemented.
    //The following are the only functions that should be used to write
    //this program: push | pop | peek | isEmpty.
    StackList SortStack(StackList& sint)
    {
        StackList saux;

        while(!sint.IsEmpty())
        {
            int tmp = sint.Pop();

            while(!saux.IsEmpty() && saux.Peek() > tmp)
            {
                sint.Push(saux.Peek());
            }

            saux.Push(tmp);
        }

        return saux;

    }
}
