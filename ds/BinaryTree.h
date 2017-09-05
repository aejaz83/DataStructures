#pragma once
#include <iostream>
#include <algorithm>
#include <queue>
#include <list>


namespace tree
{

    struct TreeNode
    {
        int data;
        TreeNode* left;
        TreeNode* right;
    };

    TreeNode* createNode(int data)
    {
        TreeNode* tmp = new TreeNode();
        tmp->data = data;
        tmp->left = tmp->right = NULL;
        return tmp;
    }
    TreeNode* InsertTree(TreeNode* root, int data)
    {
        if(root == NULL)
        {
            root = createNode(data);
        }
        else if(root->data > data)
        {
            root->left = InsertTree(root->left, data);
        }
        else
        {
            root->right = InsertTree(root->right, data);
        }

        return root;
    }

    bool Search(TreeNode* root, int data)
    {
        if(root == NULL)
        {
            return false;
        }
        else if(root->data == data)
        {
            return true;
        }
        else if(root->data > data)
        {
            return Search(root->left, data);
        }
        else
        {
            return Search(root->right, data);
        }

    }
    TreeNode* SearchNode(TreeNode* root, int data)
    {
        if(root == NULL)
        {
            return root;
        }
        else if(root->data == data)
        {
            return root;
        }
        else if(root->data > data)
        {
            return SearchNode(root->left, data);
        }
        else
        {
            return SearchNode(root->right, data);
        }

    }
    TreeNode* DeleteNode(TreeNode* root, int data)
    {
        if(root == NULL)
        {
            return root;
        }
        else if(root->data == data)
        {
            // case 1. if both the nodes are NULL
            if(root->left == NULL && root->right == NULL)
            {
                delete root;
                root = NULL;
            }
            // case 2. if one of the node is NULL
            else if(root->left == NULL)
            {
                TreeNode* tmp = root;
                root = root->right;
                delete tmp;
            }
            else if(root->right == NULL)
            {
                TreeNode* tmp = root;
                root = root->left;
                delete tmp;
            }// case 2. if both the nodes have values
            //then find the leftmost node in right sub-tree and swap values and delete that node
            else
            {
                TreeNode* curr = root->right;

                while(curr->left != NULL)
                {
                    curr = curr->left;
                }

                root->data = curr->data;
                root->right = DeleteNode(root->right, curr->data);
            }

        }
        else if(root->data > data)
        {
            root->left =  DeleteNode(root->left, data);
        }
        else
        {
            root->right =  DeleteNode(root->right, data);
        }

        return root;

    }
    int MinTree(TreeNode* root)
    {
        if(root == NULL)
        {
            return INT_MAX;
        }

        if(root->left == NULL)
        {
            return root->data;
        }

        return MinTree(root->left);

    }
    int MaxTree(TreeNode* root)
    {
        if(root == NULL)
        {
            return INT_MIN;
        }

        if(root->right == NULL)
        {
            return root->data;
        }

        return MaxTree(root->right);

    }
    int Height(TreeNode* root)
    {
        if(root == NULL)
        {
            return -1;
        }

        return(1 + std::max(Height(root->left), Height(root->right)));
    }

    void BFSTree(TreeNode* root)
    {
        std::queue<TreeNode*> treeQueue;

        if(root != NULL)
        {
            treeQueue.push(root);
        }

        while(!treeQueue.empty())
        {
            TreeNode* ptr = treeQueue.front();
            std::cout << "Visit: " << ptr->data << std::endl;
            treeQueue.pop();

            if(ptr->left != NULL)
            {
                treeQueue.push(ptr->left);
            }

            if(ptr->right != NULL)
            {
                treeQueue.push(ptr->right);
            }


        }

    }
    //Depth first strategies
    void Preorder(TreeNode* root)
    {
        if(root == NULL)
        {
            return;
        }

        std::cout << root->data << ", ";
        Preorder(root->left);
        Preorder(root->right);

    }
    void Inorder(TreeNode* root)
    {
        if(root == NULL)
        {
            return;
        }

        Inorder(root->left);
        std::cout << root->data << ", ";
        Inorder(root->right);

    }
    void Postorder(TreeNode* root)
    {
        if(root == NULL)
        {
            return;
        }

        Postorder(root->left);
        Postorder(root->right);
        std::cout << root->data << ", ";


    }
    //////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////// Problems /////////////////////////////////////////////////////////
    bool IsBSTUtil(TreeNode* root, int min, int max)
    {

        if(root == NULL)
        {
            return true;
        }

        bool res = false;

        if(root->data < max && root->data > min)
        {
            res = IsBSTUtil(root->left, min, root->data);
            res = res && IsBSTUtil(root->right, root->data, max);
        }

        return res;

    }
    bool IsBST(TreeNode* root)
    {
        return IsBSTUtil(root, INT_MIN, INT_MAX);
    }

    TreeNode* InorderSuccessor(TreeNode* root, int data)
    {
        TreeNode* current = SearchNode(root, data);

        if(current == NULL)
        {
            return NULL;
        }

        //case 1. right subtree present
        if(current->right != NULL)
        {
            //return min value in right subtree
            TreeNode* succ = current->right;

            while(succ->left != NULL)
            {
                succ = succ->left;
            }

            return succ;
        }//case 2 if right subtree not pressent
        else
        {
            //return leftmost parent if present
            TreeNode* ancestor = root;
            TreeNode* successor = NULL;

            while(ancestor != current)
            {
                if(ancestor->data > current->data)
                {
                    successor = ancestor;
                    ancestor = ancestor->left;
                }
                else
                {
                    ancestor = ancestor->right;

                }
            }

            return successor;
        }
    }
    // 4.2 MINIMAL TREE : Given a sorted array with increasing elements write an algo to create Binary Search Tree with minimal height
    TreeNode* BSTFromArray(int arr[], int low, int high)
    {
        TreeNode* root = NULL;

        if(low > high)
        {
            return NULL;
        }

        int mid = (low + high) / 2;
        root = createNode(arr[mid]);
        root->left = BSTFromArray(arr, low, mid - 1);
        root->right = BSTFromArray(arr, mid + 1, high);
        return root;
    }
    //4.3: List of Depts: Given a binary tree design an algo which creates listof all nodes ateach level
    //for a tree with depth d you have d linked list
    void ListOfDeptsUtil(TreeNode* root, int level, std::vector<std::list<int>>& depthList);
    std::vector<std::list<int>> ListOfDepts(TreeNode* root)
    {
        std::vector<std::list<int>> depthList(100);
        ListOfDeptsUtil(root, 0, depthList);
        return depthList;

    }
    void ListOfDeptsUtil(TreeNode* root, int level, std::vector<std::list<int>>& depthList)
    {
        if(root != NULL)
        {
            depthList[level].push_back(root->data);
            level++;
            ListOfDeptsUtil(root->left, level, depthList);
            ListOfDeptsUtil(root->right, level, depthList);
        }
    }
    //4.8 first common ancestor
    bool NodeIsPresent(TreeNode* root, TreeNode* curr)
    {
        if(root == NULL)
        {
            return false;
        }

        if(root == curr)
        {
            return true;
        }

        bool res = NodeIsPresent(root->left, curr);

        if(res == false)
        {
            res = NodeIsPresent(root->right, curr);
        }

        return res;
    }
    TreeNode* FirstCommonAncestor(TreeNode* root, TreeNode* first, TreeNode* second)
    {
        if(NodeIsPresent(root->left, first) && NodeIsPresent(root->left, second))
        {
            return FirstCommonAncestor(root->left, first,  second);
        }
        else if(NodeIsPresent(root->right, first) && NodeIsPresent(root->right, second))
        {
            return FirstCommonAncestor(root->right, first, second);

        }

        return root;
    }
    //
    //4.10 check subtree
    //
    bool SameTree(TreeNode* t1, TreeNode* t2)
    {
        if(t1 == NULL && t2 == NULL)
        {
            return true;
        }

        if(t1 == NULL)
        {
            return false;
        }

        if(t2 == NULL)
        {
            return false;
        }

        return (t1->data == t2->data) && SameTree(t1->left, t2->left) && SameTree(t1->right, t2->right);
    }
    bool CheckSubtree(TreeNode* t1, TreeNode* t2)
    {
        if(t1 == NULL)
        {
            return false;
        }

        if(t1->data == t2->data)
        {
            if(SameTree(t1, t2))
            {
                return true;
            }
        }

        return CheckSubtree(t1->left, t2) || CheckSubtree(t1->right, t2);

    }
}