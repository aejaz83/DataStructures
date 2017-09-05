#pragma

#include <iostream>

using std::string;
namespace trie
{
    const unsigned int ALPHABET_SIZE = 26;
    struct trienode
    {
        trienode* children[ALPHABET_SIZE];
        bool isLeaf;
        int occurrence;
    }* root;


    void InitTree()
    {
        root = new trienode();
        root->isLeaf = false;
        root->occurrence = -1;
    }

    void InsertWord(string word)
    {
        auto curr = root;

        for(int i = 0; i < word.length(); i++)
        {
            int letter = word[i] - 'a';

            if(curr->children[letter] == nullptr)
            {
                curr->children[letter] = new trienode();
            }

            curr->children[letter]->occurrence++;
            std::cout << "letter: " << char('a' + letter) << " occurence: " << curr->children[letter]->occurrence << std::endl;
            curr = curr->children[letter];
        }

        curr->isLeaf = true;
    }

    bool Search(string word)
    {
        auto curr = root;

        for(int i = 0; i < word.length(); i++)
        {
            int letter = word[i] - 'a';

            if(curr->children[letter] == nullptr)
            {
                return false;
            }

            curr = curr->children[letter];
        }

        return curr->isLeaf;
    }


    int PrefixOccurrence(string word)
    {
        auto curr = root;

        for(int i = 0; i < word.length(); i++)
        {
            int letter = word[i] - 'a';

            if(curr->children[letter] == nullptr)
            {
                return 0;
            }

            curr = curr->children[letter];
        }

        return curr->occurrence;
    }

}
