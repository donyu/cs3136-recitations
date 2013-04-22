#ifndef __BST_2_H__
#define __BST_2_H__

#include <iostream>

using namespace std;

class BSTNode {

    public:
        int get() const { return data; }

        friend class BST;

    private:
        int data;
        BSTNode *left;
        BSTNode *right;

        BSTNode(int x) {
            data = x;
            left = NULL;
            right = NULL;
        }

        // disallow copy ctor & op=()
        BSTNode(const BSTNode&);
        BSTNode& operator=(const BSTNode&);
};

class BST {

    public:
        BST() : root(NULL) {}
        ~BST();
        BST(const BST&);
        BST& operator=(const BST&);

        void insert(int x);
        void remove(int x);

        typedef BSTNode Node;

        const Node *lookup(int x) const;

        void draw();
        void traverse_inorder(void (*f)(Node *));

        int height() const;
        const Node *find_min() const;
        const Node *find_max() const;

    private:
        Node *root;

        Node *insert(int x, Node *node);
        void remove(int x, Node*& node);
        const Node *lookup(int x, const Node *node) const;

        void remove_all_nodes(Node *node);
        void draw(Node *node, int depth, const char *edge);
        void traverse_inorder(Node *node, void (*f)(Node *));

        int height(const Node *node) const;
        const Node *find_min(const Node *node) const;
        const Node *find_max(const Node *node) const;

        Node *clone(const Node *) const;
};

#endif /* #ifndef __BST_2_H__ */
