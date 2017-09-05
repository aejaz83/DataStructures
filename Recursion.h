#pragma once
#pragma once
#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::vector;
using std::string;

namespace recursion
{
    //8.1 triple steps, child can hop 1, 2 or 3 steps, get all possible ways it can reach n

    int CountWays(int n)
    {
        if(n == 1 || n == 0)
        {
            return 1;
        }

        if(n == 2)
        {
            return 2;
        }

        return CountWays(n - 1) + CountWays(n - 2) + CountWays(n - 3);
    }
    int CountWaysDP(int n, std::vector<int>& cache)
    {
        if(n == 1 || n == 0)
        {
            return 1;
        }

        if(n == 2)
        {
            return 2;
        }

        if(cache[n] != -1)
        {
            return cache[n];
        }
        else
        {

            cache[n] = CountWays(n - 1) + CountWays(n - 2) + CountWays(n - 3);
            return cache[n];
        }
    }


    void testCountWays()
    {

        cout << CountWays(3) << endl;
        cout << CountWays(35) << endl;
        std::vector<int> ivec(36, -1);
        cout << CountWaysDP(35, ivec) << endl;
    }

    /* Question 9.2 Imagine a robot sitting on the upper left corner of an X by Y grid.
    The robot can only move in two directions: right and down. How many possible paths are there for the robot to go from (0, 0) to (X, Y) ?
    FOLLOW UP
    Imagine certain spots are "off limits," such that the robot cannot step on them.
    Design an algorithm to find a path for the robot from the top left to the bottom right.
    http://www.geeksforgeeks.org/backttracking-set-2-rat-in-a-maze/
    */
    int X = 4;
    int Y = 4;
    bool RobotRide(int arr[4][4], int row, int col)
    {
        if(row > 3 || col > 3)
        {
            return false;
        }

        if(row == 3 && col == 3)
        {
            if(arr[row][col] == 1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        if(arr[row][col + 1] == 1)
        {
            if(RobotRide(arr, row, col + 1))
            {
                return true;
            }
        }

        if(arr[row + 1][col] == 1)
        {
            if(RobotRide(arr, row + 1, col))
            {
                return true;
            }
        }

        return false;
    }

    void testRobotRide()
    {
        int maze[4][4] = { { 1, 0, 0, 0 },
            { 1, 1, 0, 1 },
            { 0, 1, 0, 0 },
            { 1, 1, 1, 1 }
        };

        if(RobotRide(maze, 0, 0))
        {
            cout << "maze solved" << endl;
        }
        else
        {
            cout << "maze not solved" << endl;

        }
    }

    /* Question 9.3 A magic index in an array A[1...n-1] is defined to be an index such that A[i] = i.
    Given a sorted array of distinct integers, write a method to find a magic index, if one exists, in array A.
    FOLLOW UP
    What if the values are not distinct?
    */
    int MagicIndex(int arr[], int  low, int high)
    {
        if(low > high)
        {
            return -1;
        }

        int mid = (low + high) / 2;

        if(mid == arr[mid])
        {
            return mid;
        }
        else if(mid > arr[mid])
        {
            return MagicIndex(arr, mid + 1, high);

        }
        else
        {
            return MagicIndex(arr, low, mid - 1);

        }

    }


    void testMagicIndex()
    {
        int arr[] = { -3, -2, -1,  0,  4, 10 };
        int num = MagicIndex(arr, 0, 5);

        if(num == (-1))
        {
            cout << "Magic Index not found" << endl;
        }
        else
        {
            cout << "Magic Index found at: " << num << endl;

        }
    }

    void PowerSet(std::string str, int pos, std::vector<std::string>& set)
    {
        if(pos >= str.length())
        {
            return;
        }

        char ch = str[pos];
        PowerSet(str, pos + 1, set);
        auto copy = set;

        for(auto var : copy)
        {

            string temp = ch + var;
            // cout << "temp: " << temp << endl;
            set.push_back(temp);
        }

        //cout << "string ch,1: " << string(1, ch) << endl;
        set.push_back(string(1, ch));
    }
    void testPowerSet()
    {
        std::string str = "abc";
        std::vector<std::string> vec;
        PowerSet(str, 0, vec);
        cout << "power set is: ";

        for(auto var : vec)
        {
            cout << var << " ";
        }

        cout << endl;


    }
    //8.6: Towers of Hanoi
    void TowersOfHanoi(char src, char dest, char aux, int disks)
    {
        // static int count = 0;
        // count++;

        if(disks == 0)
        {
            return;
        }

        TowersOfHanoi(src, aux, dest, disks - 1);
        cout << "Moving disk " << disks << " from " << src << " to " << dest << endl;
        TowersOfHanoi(aux, dest, src, disks - 1);
        //cout << "count: " << count << endl;
    }
    //8.7: write a method to compute permutations of a unique

    vector<string> MyPermutation(string str)
    {
        vector<string> ret;

        if(str.length() == 1)
        {
            ret.push_back(str);
            return ret;
        }

        char pivot = str[0];
        //generate permuations for str[1...n]
        auto subPerm = MyPermutation(str.substr(1, str.length() - 1));

        for(auto var : subPerm)
        {
            string elem;

            for(int i = 0; i < var.length(); i++)
            {
                string first = var.substr(0, (i - 0 + 1));
                string last = var.substr(0, (i - 0 + 1));
            }

        }

        return ret;

    }
    void SwapChar(string& str, int pos1, int pos2)
    {
        auto tmp = str[pos1];
        str[pos1] = str[pos2];
        str[pos2] = tmp;
    }
    void Permuations(string& str, int pos)
    {
        if(pos == str.length() - 1)
        {
            cout << str << endl;
            return;
        }

        for(int i = pos; i < str.length(); i++)
        {
            SwapChar(str, pos, i);
            Permuations(str, pos + 1);
            //backtrack
            SwapChar(str, pos, i);
        }

    }
    void testPermuations()
    {
        string str = "abcd";
        Permuations(str, 0);
    }
    //8.10
    // Dimentions of paint screen
#define M 8
#define N 8
    void PaintFill(int arr[][N], int row, int col, int oldcolor, int newcolor)
    {
        if((row < 0) || (row >= M) || (col < 0) || (col >= N))
        {
            return;
        }

        if(arr[row][col] != oldcolor)
        {
            return;
        }

        //set it to newcolor
        arr[row][col] = newcolor;
        //recurse
        PaintFill(arr, row + 1, col, oldcolor, newcolor);
        PaintFill(arr, row - 1, col, oldcolor, newcolor);
        PaintFill(arr, row, col + 1, oldcolor, newcolor);
        PaintFill(arr, row, col - 1, oldcolor, newcolor);
    }

    void testPaintFill()
    {
        int screen[M][N] = { { 1, 1, 1, 1, 1, 1, 1, 1 },
            { 1, 1, 1, 1, 1, 1, 0, 0 },
            { 1, 0, 0, 1, 1, 0, 1, 1 },
            { 1, 2, 2, 2, 2, 0, 1, 0 },
            { 1, 1, 1, 2, 2, 0, 1, 0 },
            { 1, 1, 1, 2, 2, 2, 2, 0 },
            { 1, 1, 1, 1, 1, 2, 1, 1 },
            { 1, 1, 1, 1, 1, 2, 2, 1 },
        };
        int x = 4, y = 4, newC = 3;
        PaintFill(screen, x, y, screen[x][y], newC);

        cout << "Updated screen after call to floodFill: \n";

        for(int i = 0; i < M; i++)
        {
            for(int j = 0; j < N; j++)
            {
                cout << screen[i][j] << " ";
            }

            cout << endl;
        }
    }
    //8.11 no of ways of representing n cents given, quarters-25, dimes-10, nickels-10 , 1-pennies;

    int CountChange(int n)
    {
        int count = 0;

        for(int i = 0; (i * 25) <= n; i++)
            for(int j = 0; (j * 10) <= n; j++)
                for(int k = 0; ; k++)
                {
                    int val = (i * 25) + (j * 10) + (k * 5);

                    if(val <= n)
                    {
                        count++;
                    }
                    else
                    {
                        break;
                    }
                }

        return count;

    }
    void testCountChange()
    {
        cout << "No of ways to make change for 100: " << CountChange(100) << endl;
        cout << "No of ways to make change for 20: " << CountChange(20) << endl;
    }
    //8.12: N Queens: backtracking
#define CHESSSIZE 8

}