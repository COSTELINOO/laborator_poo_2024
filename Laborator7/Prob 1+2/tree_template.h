#ifndef TREE_TEMPLATE_H
#define TREE_TEMPLATE_H

#include <iostream>
#include <functional>


template<typename T>
bool compare(const T& a, const T& b) {
    return a > b; 
}

bool compareStrings(const char* a, const char* b) {
    return std::strcmp(a, b) > 0;
}

template <typename T>
class TreeNode {
public:
    T value;
    TreeNode<T>* parent;
    TreeNode<T>* children[10];

    TreeNode(T val, TreeNode<T>* par = nullptr) : value(val), parent(par) {
        for (int i = 0; i < 10; ++i)
            children[i] = nullptr;
    }

    void add_node(TreeNode<T>* newNode) {
        newNode->parent = this;
        for (int i = 0; i < 10; ++i) {
            if (children[i] == nullptr) {
                children[i] = newNode;
                break;
            }
        }
    }

    TreeNode<T>& get_node(TreeNode<T>* par = nullptr) {
        if (par == nullptr)
            return *this;
        return *par;
    }

    void delete_node() {
        if (parent == nullptr)
            return; 

        for (int i = 0; i < 10; ++i) {
            if (parent->children[i] == this) {
                parent->children[i] = nullptr;
                delete this;
                break;
            }
        }
    }
    TreeNode<T>* find(std::function<bool(const T&)> comparator) {
        if (comparator(value))
            return this;

        for (int i = 0; i < 10; ++i) {
            if (children[i] != nullptr) {
                TreeNode<T>* result = children[i]->find(comparator);
                if (result != nullptr)
                    return result;
            }
        }
        return nullptr;
    }



    void insert(TreeNode<T>* newNode, int index) {
        if (index < 0 || index >= 10)
            return; 

        newNode->parent = this;
        if (children[index] == nullptr)
            children[index] = newNode;
        else
            newNode->add_node(children[index]);
    }

    void sort(bool (*comparator)(const T&, const T&) = nullptr) {
        if (comparator == nullptr)
            return; 

        
        for (int i = 0; i < 10; ++i) {
            for (int j = i + 1; j < 10; ++j) {
                if (children[i] != nullptr && children[j] != nullptr &&
                    comparator(children[i]->value, children[j]->value)) {
                    std::swap(children[i], children[j]);
                }
            }
        }
    }

    int count(const TreeNode<T>* node = nullptr) const {
        if (node == nullptr)
            node = this;

        int nodeCount = 0;  
        for (int i = 0; i < 10; ++i) {
            if (node->children[i] != nullptr)
                nodeCount += 1 + count(node->children[i]); 
        }
        return nodeCount;
    }

   

};


template <>
class TreeNode<char*> {
public:
    char* value;
    TreeNode<char*>* parent;
    TreeNode<char*>* children[10];

    TreeNode(char* val, TreeNode<char*>* par = nullptr) : value(val), parent(par) {
        for (int i = 0; i < 10; ++i)
            children[i] = nullptr;
    }

    void add_node(TreeNode<char*>* newNode) {
        newNode->parent = this;
        for (int i = 0; i < 10; ++i) {
            if (children[i] == nullptr) {
                children[i] = newNode;
                break;
            }
        }
    }

    TreeNode<char*>& get_node(TreeNode<char*>* par = nullptr) {
        if (par == nullptr)
            return *this;
        return *par;
    }

    void delete_node() {
        if (parent == nullptr)
            return;

        for (int i = 0; i < 10; ++i) {
            if (parent->children[i] == this) {
                parent->children[i] = nullptr;
                delete this;
                break;
            }
        }
    }

    TreeNode<char*>* find(std::function<bool(const char*)> comparator) {
        if (comparator(value))
            return this;

        for (int i = 0; i < 10; ++i) {
            if (children[i] != nullptr) {
                TreeNode<char*>* result = children[i]->find(comparator);
                if (result != nullptr)
                    return result;
            }
        }
        return nullptr;
    }

    void insert(TreeNode<char*>* newNode, int index) {
        if (index < 0 || index >= 10)
            return;

        newNode->parent = this;
        if (children[index] == nullptr)
            children[index] = newNode;
        else
            newNode->add_node(children[index]);
    }

    void sort(bool (*comparator)(const char*, const char*) = nullptr) {
        if (comparator == nullptr)
            return;

        for (int i = 0; i < 10; ++i) {
            for (int j = i + 1; j < 10; ++j) {
                if (children[i] != nullptr && children[j] != nullptr &&
                    comparator(children[i]->value, children[j]->value)) {
                    std::swap(children[i], children[j]);
                }
            }
        }
    }

    int count(const TreeNode<char*>* node = nullptr) const {
        if (node == nullptr)
            node = this;

        int nodeCount = 0;
        for (int i = 0; i < 10; ++i) {
            if (node->children[i] != nullptr)
                nodeCount += 1 + count(node->children[i]);
        }
        return nodeCount;
    }
};

#endif // TREE_TEMPLATE_H

