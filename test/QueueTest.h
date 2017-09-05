#pragma once
#pragma once
#include "Queue.h"
#include <iostream>

namespace Queue
{
    bool testQueueArray()
    {
        std::cout << std::endl << "###########################################################################" << std::endl;
        QueueArray<int> s;
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

        std::cout << "IsEmpty ..." << s.IsEmpty() << std::endl;
        std::cout << std::endl << "###########################################################################" << std::endl;


        return true;
    }
    bool testQueueList()
    {
        std::cout << std::endl << "###########################################################################" << std::endl;
        QueueList<int> s;
        std::cout << "Pushing 21 ..." << s.Enqueue(21) << std::endl;
        std::cout << "Pushing 22 ..." << s.Enqueue(22) << std::endl;
        std::cout << "Pushing 23 ..." << s.Enqueue(23) << std::endl;
        std::cout << "Pushing 24 ..." << s.Enqueue(24) << std::endl;
        std::cout << "Pop ..." << s.Front();
        std::cout << " res: " << s.Dequeue() << std::endl;
        std::cout << "Pop ..." << s.Front() << " res: ";
        std::cout << " res: " << s.Dequeue() << std::endl;
        std::cout << "Pop ..." << s.Front() << " res: ";
        std::cout << " res: " << s.Dequeue() << std::endl;
        std::cout << "Pop ..." << s.Front() << " res: ";
        std::cout << " res: " << s.Dequeue() << std::endl;

        std::cout << "IsEmpty ..." << s.IsEmpty() << std::endl;
        std::cout << std::endl << "###########################################################################" << std::endl;


        return true;
    }

}
