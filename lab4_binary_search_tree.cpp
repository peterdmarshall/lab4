#include <iostream>
#include "lab4_binary_search_tree.hpp"

using namespace std;

// Recursive Helper Functions
BinarySearchTree::TaskItem* BinarySearchTree::insertTaskItem(BinarySearchTree::TaskItem* item, BinarySearchTree::TaskItem val) {
	if(item == NULL) {
	    item = new TaskItem(val);
	    item->right = item->left = NULL;
	    size++;
	} else if(item->priority < val.priority) {
	    item->right = insertTaskItem(item->right, val);
	} else {
	    item->left = insertTaskItem(item->left, val);
	}
	return item;
}

BinarySearchTree::TaskItem* BinarySearchTree::removeTaskItem(BinarySearchTree::TaskItem* item, BinarySearchTree::TaskItem val) {
    if(item == NULL) return NULL;

    if(val.priority < item->priority) {
        item->left = removeTaskItem(item->left, val);
    } else if(val.priority > item->priority) {
        item->right = removeTaskItem(item->right, val);
    } else {
        if(item->left == NULL) {
            TaskItem* temp = item->right;
            delete item;
            item = NULL;
            size--;
            return temp;
        } else if(item->right == NULL) {
            TaskItem* temp = item->left;
            delete item;
            item = NULL;
            size--;
            return temp;
        }

        TaskItem* temp = search(item, findMin(item->right));
        item->priority = temp->priority;
        item->description = temp->description;
        item->right = removeTaskItem(item->right, *temp);
    }
    return item;
}

BinarySearchTree::TaskItem* BinarySearchTree::search(BinarySearchTree::TaskItem* item, BinarySearchTree::TaskItem val) const{
	if(item == NULL) {
		return NULL;
	} else if(item->priority == val.priority) {
		return item;
	} else if(item->priority < val.priority) {
		return search(item->right, val);
	} else {
		return search(item->left, val);
	}
}

BinarySearchTree::TaskItem BinarySearchTree::findMax(BinarySearchTree::TaskItem* item) const{
	if(item == NULL) {
		return TaskItem(-1, "N/A");
	} else if(item->right == NULL) {
		return *item;
	} else {
		return findMax(item->right);
	}
}

BinarySearchTree::TaskItem BinarySearchTree::findMin(BinarySearchTree::TaskItem* item) const{
	if(item == NULL) {
		return TaskItem(-1, "N/A");
	} else if(item->left == NULL) {
		return *item;
	} else {
		return findMin(item->left);
	}
}

int BinarySearchTree::getHeight(BinarySearchTree::TaskItem* item) const {
    if(item == NULL || (item->right == NULL && item->left == NULL)) {
        return 0;
    }

    int lh = getHeight(item->left);
    int rh = getHeight(item->right);

    return 1 + maxInt(lh, rh);
}

// PURPOSE: Default/empty constructor
BinarySearchTree::BinarySearchTree() {
	root = NULL;
	size = 0;
}

// PURPOSE: Explicit destructor of the class BinarySearchTree
BinarySearchTree::~BinarySearchTree() {
    while(size > 0) {
        remove(max());
    }
}

// PURPOSE: Returns the number of nodes in the tree
unsigned int BinarySearchTree::get_size() const {
	return size;
}

// PURPOSE: Returns the maximum value of a node in the tree
// if the tree is empty, it returns (-1, "N/A")
BinarySearchTree::TaskItem BinarySearchTree::max() const {
	return findMax(root);
}

// PURPOSE: Returns the minimum value of a node in the tree
// if the tree is empty, it returns (-1, "N/A")
BinarySearchTree::TaskItem BinarySearchTree::min() const {
	return findMin(root);
}

// PURPOSE: Returns the tree height
unsigned int BinarySearchTree::height() const {
	return getHeight(root);
}

// PURPOSE: Prints the contents of the tree; format not specified
void BinarySearchTree::print() const {

}

// PURPOSE: Returns true if a node with the value val exists in the tree	
// otherwise, returns false
bool BinarySearchTree::exists( BinarySearchTree::TaskItem val ) const {
	if(search(root, val) == NULL) {
	    return false;
	} else {
	    return true;
	}
}

// PURPOSE: Optional helper function that returns a pointer to the root node
BinarySearchTree::TaskItem* BinarySearchTree::get_root_node() {
    return root;
}

// PURPOSE: Optional helper function that returns the root node pointer address
BinarySearchTree::TaskItem** BinarySearchTree::get_root_node_address() {
    return &root;
}

// PURPOSE: Optional helper function that gets the maximum depth for a given node
int BinarySearchTree::get_node_depth( BinarySearchTree::TaskItem* n ) const {
	return 0;
}

// PURPOSE: Inserts the value val into the tree if it is unique
// returns true if successful; returns false if val already exists
bool BinarySearchTree::insert( BinarySearchTree::TaskItem val ) {
	int prevSize = size;
	root = insertTaskItem(root, val);
	return size > prevSize;
}

// PURPOSE: Removes the node with the value val from the tree
// returns true if successful; returns false otherwise
bool BinarySearchTree::remove( BinarySearchTree::TaskItem val ) {
    int prevSize = size;
    root = removeTaskItem(root, val);
    return size < prevSize;
}
