// To search the element in the BST
#include <iostream>
#include <queue>
using namespace std;
class node
{
private:
    int data;
    node *left;
    node *right;

public:
    node()
    {
        this->data = 0;

        left = right = NULL;
    }              // Default constructor
    node(int data) // Now using the constructor
    {
        this->data = data;
        left = right = NULL;
    }

    node *Insert(node *root, int value)
    {
        if (root == NULL)
        {
            // Insert if the root is null value
            return new node(value);
        }
        else if (value > root->data)
        {
            // Process the right node
            root->right = Insert(root->right, value);
        }
        else
        {
            root->left = Insert(root->left, value);
        }
        // return root node after insertion
        return root;
    }
    void preoder(node *root, priority_queue<int> &pq)
    {

        if (root != NULL) // Root is Null
        {
            pq.push(root->data);//Its time compelxity is O(logn)
            // cout << root->data << endl;
            preoder(root->left, pq);
            preoder(root->right, pq);
        }
        // This will take O(logn) for the traversal
    }
    int KLargestElementInBst(node *root, int k)
    {
        priority_queue<int> pq;//Its space complexity is O(N)
        node BST;
        BST.preoder(root, pq);
        int count = 0; // To keep track of the element
        while (!pq.empty())
        {
            if (count == k - 1)
            {
                return pq.top();
            }
            count++;
            pq.top();//Tis time coplexity is O(1)
            pq.pop();//Its time compleixty is O(Logn )
        }
        return -1;

    }

};

int main()
{
    node BST;
    node *root = NULL;
    root = BST.Insert(root, 19);
    root = BST.Insert(root, 9);
    root = BST.Insert(root, 89);
    root = BST.Insert(root, 90);
    root = BST.Insert(root, 67);
    // BST.preoder(root);
    int value = BST.KLargestElementInBst(root, 3);
    cout << value << " ";

    return 0;
}