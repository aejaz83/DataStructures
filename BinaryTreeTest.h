#pragma once
#include "BinaryTree.h"
#include "Utility.h"

namespace tree
{
    bool testBinarySearchTree()
    {
        TreeNode* root = NULL;
        root = InsertTree(root, 10);
        root = InsertTree(root, 12);
        root = InsertTree(root, 7);
        root = InsertTree(root, 11);
        root = InsertTree(root, 15);
        root = InsertTree(root, 5);
        root = InsertTree(root, 9);
        std::cout << "search for 10: " << BoolToStr(Search(root, 10)) << std::endl;
        std::cout << "search for 20: " << BoolToStr(Search(root, 20)) << std::endl;
        std::cout << "search for 5: " << BoolToStr(Search(root, 5)) << std::endl;
        std::cout << "search for 3: " << BoolToStr(Search(root, 3)) << std::endl;
        std::cout << "Preorder: ";
        Preorder(root);
        std::cout << std::endl;
        std::cout << "Min elem: " << MinTree(root) << std::endl;
        std::cout << "Max elem: " << MaxTree(root) << std::endl;
        std::cout << "Height: " << Height(root) << std::endl;
        std::cout << "Breadth First Search: ";
        BFSTree(root);
        std::cout << "Inorder: ";
        Inorder(root);
        std::cout << std::endl;
        std::cout << "Postorder: ";
        Postorder(root);
        std::cout << std::endl;
        std::cout << "Is BST: " << BoolToStr(IsBST(root)) << std::endl;
        TreeNode* root2 = createNode(10);
        root2->left = createNode(15);
        root2->right = createNode(1);
        std::cout << "Is BST root2: " << BoolToStr(IsBST(root2)) << std::endl;
        std::cout << "Inorder Successor of 10 : " << (InorderSuccessor(root, 10))->data << std::endl;
        std::cout << "Inorder Successor of 9 : " << (InorderSuccessor(root, 9))->data << std::endl;
        //std::cout << "Inorder Successor of 15 : " << (InorderSuccessor(root, 15))->data << std::endl;

        std::cout << "Deleting 9: " << BoolToStr(DeleteNode(root, 9)) << std::endl;
        std::cout << "Inorder: ";
        Inorder(root);
        std::cout << std::endl;
        std::cout << "Deleting 0: " << BoolToStr(DeleteNode(root, 10)) << std::endl;
        std::cout << "Inorder: ";
        Inorder(root);
        std::cout << std::endl;
        return true;
    }
    bool testBstFromArray()
    {
        int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

        TreeNode* node = BSTFromArray(arr, 0, 9);
        std::cout << "Binary Search Tree from Array is: ";
        Inorder(node);
        std::cout << std::endl;
        return true;
    }
    bool testListOfDepths()
    {

        TreeNode* root = NULL;
        root = InsertTree(root, 10);
        root = InsertTree(root, 12);
        root = InsertTree(root, 7);
        root = InsertTree(root, 11);
        root = InsertTree(root, 15);
        root = InsertTree(root, 5);
        root = InsertTree(root, 9);
        std::cout << "Inorder: ";
        Inorder(root);
        std::cout << std::endl;
        auto VecOfLists = ListOfDepts(root);
        std::cout << "List of Lists: ";

        for(auto singleList : VecOfLists)
        {
            for(auto val : singleList)
            {
                std::cout << val << ", ";
            }

            std::cout << std::endl;
        }

        return true;
    }
    int findFCA()
    {
        // Let us create the Binary Tree shown in above diagram.
        TreeNode* root = createNode(1);
        root->left = createNode(2);
        root->right = createNode(3);
        root->left->left = createNode(4);
        root->left->right = createNode(5);
        root->right->left = createNode(6);
        root->right->right = createNode(7);
        std::cout << "LCA(4, 5) = " << (FirstCommonAncestor(root, root->left->left, root->left->right))->data;
        std::cout << "\nLCA(4, 6) = " << (FirstCommonAncestor(root, root->left->left, root->right->left))->data;
        std::cout << "\nLCA(3, 4) = " << (FirstCommonAncestor(root, root->right, root->left->left))->data;
        std::cout << "\nLCA(2, 4) = " << (FirstCommonAncestor(root, root->left, root->left->left))->data;
        return 0;
    }
}