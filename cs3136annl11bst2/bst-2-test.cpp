#include <iostream>
#include <algorithm>
using namespace std;

#include "bst-2.h"

void print_node(BST::Node *node)
{
    cout << node->get() << " ";
}

int main()
{
    srandom(time(NULL));

    // read the number of elements from the user.
    int n;
    cin >> n;

    // Construct an empty tree.
    BST t;

    for (int i = 0; i < n; i++) {
        t.insert(random() % 100);
    }

    cout << "\nThe BST:" << endl;
    t.draw();

    cout << "\nAll nodes in-order:" << endl;
    t.traverse_inorder(print_node);
    cout << endl;

    cout << "\nSome info on the tree:" << endl;
    cout << "height == " << t.height() << endl;;
    cout << "min == " << t.find_min()->get() << endl;
    cout << "max == " << t.find_max()->get() << endl;

    cout << "\nPerforming some lookups:" << endl;
    for (int i = 0; i < 10; i++) {
        int x = random() % 100;
        const BST::Node *node = t.lookup(x);
        if (node) {
            cout << x << " is in there." << endl;
        } else {
            cout << x << " is NOT in there." << endl;
        }
    }

    // copy-construct a new tree t2 out of t.
    BST t2(t);

    while (1) {
        cout << "\nThe remaining BST:" << endl;
        t.draw();
        cout << "\nType the number to remove (-1 to quit): " << endl;
        int x; 
        cin >> x;
        if (cin.eof() || x < 0) {
            break;
        }
        t.remove(x);
    }

    cout << "\nThe original BST:" << endl;
    t2.draw();

    return 0;
}
