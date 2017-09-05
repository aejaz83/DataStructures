#pragma once
#pragma once
#include<string>
#include"Utility.h"

namespace Queue
{
    template<class T> class QueueArray
    {

    private:
        static const unsigned int MAX_SIZE = 1001;
        static const unsigned int N = 100;
        T arr[N];
        int front, back;

    public:
        QueueArray() : front(-1), back(-1) {}
        bool Enqueue(T x)
        {
            if(IsEmpty())
            {
                front = back = 0;
            }
            //  else if(back == MAX_SIZE - 1) //IsFull
            else if((back + 1 % N) == front) //IsFull
            {
                std::cerr << "Queue is Full" << std::endl;
                return false;
            }
            else
            {
                // back++;
                back = (back + 1) % N;
            }

            arr[back] = x;

        }
        bool Dequeue()
        {
            if(IsEmpty())
            {
                std::cerr << "Queue is empty" << std::endl;

                return false;
            }
            else if(front == back)
            {
                front = back = -1;
            }
            else
            {
                //  front++;
                front = (front + 1) % N;

            }

            return true;
        }
        bool IsEmpty()
        {
            return (front == -1) && (back == -1);
        }
        T Front()
        {
            if(IsEmpty())
            {
                std::cerr << "Queue is empty" << std::endl;
            }

            return arr[front];
        }

    };

    template <class T>
    class QueueList
    {

    private:
        struct Node
        {
            T data;
            Node* next;
        };
        Node* front;
        Node* tail;

    public:
        QueueList() : front(NULL), tail(NULL) {}
        bool Enqueue(T x)
        {
            //create  a new node
            Node* tmp = new Node();
            tmp->data = x;
            tmp->next = NULL;

            if(IsEmpty())
            {
                front = tail = tmp;
            }
            else
            {
                tail->next = tmp;
                tail = tmp;
            }

            return true;
        }
        bool Dequeue()
        {
            if(IsEmpty())
            {

                return false;
            }
            else if(front == tail)
            {
                delete front;
                front = tail = NULL;
            }
            else
            {
                Node* tmp = front;
                front = front->next;

            }

            return true;
        }
        bool IsEmpty()
        {
            return (front == NULL) && (tail == NULL);
        }
        T Front()
        {
            if(IsEmpty())
            {
                std::cerr << "Queue is empty" << std::endl;
            }

            return front->data;
        }

    };

}
