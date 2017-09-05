#pragma once
#include "Trie.h"

using std::cout;
using std::endl;


namespace trie
{

    void testTrie()
    {
        InitTree();
        InsertWord("ant");
        InsertWord("and");
        InsertWord("are");
        InsertWord("their");
        InsertWord("there");
        InsertWord("this");
        InsertWord("the");
        InsertWord("zoo");

        if(Search("zoo"))
        {
            cout << "zoo found" << std::endl;
        }

        if(!Search("thisis"))
        {
            cout << "thisis not found" << std::endl;
        }

        if(Search("the"))
        {
            cout << "the found" << std::endl;
        }

        cout << "Number of occurence of th: " << PrefixOccurrence("th") << std::endl;
        cout << "Number of occurence of z: " << PrefixOccurrence("z") <<  std::endl;
    }


}