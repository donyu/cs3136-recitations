# Recitation 9 #

## Trees ##

### What's a tree? ###
A tree is a data structure with a set of linked nodes in a hierarchical tree-like structure.

### What are the parts of a tree? ###
The root of the tree is the top most node on the tree (Think of it like an upside down real tree).
Two nodes can be related to each other as "parent" and "child" nodes.  The parent node "points" to the child node.
In a graphical represenatation of a tree, the parent is on top of the child.
The leaves of the tree are the nodes that don't have any children. (If the tree consists of one node, that node is both a root anda leaf!)
A "subtree" is a tree whose root is one of the children of a the node the subtree is being compared to.

### Branching Factor ###
The branching factor is the number of children at each non-leaf node.
This number is not always uniform and so the average branching factor is calculated.

### What's a linked list? ###
We worked a lot with linked lists in HW2.  Is a linked list a type of tree?
Yes!  A linked list is a tree with a branching factor of 1!

## Binary Trees ##

### What's a binary tree? ###
A binary tree is a tree in which every node has at most two children.

### Some more vocab ###
```
Directed edge: link from parent to child.
Depth(of a node): The length of the path from the root to a given node.
Level: The set of all nodes at a given depth.
Depth(of a tree): The depth of the deepest node.  Also called height.
Siblings: Nodes that share the same parent.
Size(of a node): Number of descendants it has including itself.
```
### Types of Binary Trees ###
Let's see what different types of binary trees look like in the wild.
```
Full Binary Tree: Every node other than the leaves has 2 children.
Complete Binary Tree: Every level is completely filled except for possibly the last.
Perfect Binary Tree: Complete and Full.  (All leaves are at the same level).
Balanced Binary Tree: The depth of the left and right subtrees of every node differ by one or less.
Degenerate Tree: Is a tree where for each parent node, there is only one associated child node. (Performs like a linked list).
```
### Performance of Binary Trees ###
Because we don't know what kind of binary tree we're dealing with, there is generally poor performance if we just know the tree is binary.
```
Note that in the following, n is the number of nodes in the tree.
lookup(Node n): O(n) 
delete(Node n): O(n)
print_tree: O(n)
delete_Root: O(1)
```

## Binary Search Trees ##
