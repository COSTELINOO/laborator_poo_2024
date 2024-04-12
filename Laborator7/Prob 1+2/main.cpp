#include <iostream>
#include "temperature_literals.h" 
#include "tree_template.h" 

int main() {
    float a = 300.0_Kelvin;
    float b = 120.0_Fahrenheit;

    std::cout << "300 Kelvin in Celsius: " << a << std::endl;
    std::cout << "120 Fahrenheit in Celsius: " << b << std::endl;

    TreeNode<int>* root1 = new TreeNode<int>(10);
    TreeNode<int>* child11 = new TreeNode<int>(5);
    TreeNode<int>* child22 = new TreeNode<int>(15);
    TreeNode<int>* child33 = new TreeNode<int>(8);
    root1->add_node(child11);
    root1->add_node(child22);
    root1->add_node(child33);

    TreeNode<int>* foundNode1 = root1->find([](const int& val) { return val == 5; });
    if (foundNode1 != nullptr) {
        std::cout << "Nodul cu valoarea 5 a fost gasit.\n";
    }
    else {
        std::cout << "Nodul cu valoarea 5 nu a fost gasit.\n";
    }

    root1->sort(compare<int>);
    std::cout << "Nodurile sortate: ";
    for (int i = 0; i < 10; ++i) {
        if (root1->children[i] != nullptr) {
            std::cout << root1->children[i]->value << " ";
        }
    }
    std::cout << "\n";

    std::cout << "Numărul total de noduri: " << root1->count() << "\n";

    delete root1;
    delete child11;
    delete child22;
    delete child33;
    

   
    TreeNode<char*>* root = new TreeNode<char*>(const_cast<char*>("root"));

    TreeNode<char*>* child1 = new TreeNode<char*>(const_cast<char*>("child3"));
    TreeNode<char*>* child2 = new TreeNode<char*>(const_cast<char*>("child1"));
    TreeNode<char*>* child3 = new TreeNode<char*>(const_cast<char*>("child2"));
    root->add_node(child1);
    root->add_node(child2);
    root->add_node(child3);

    TreeNode<char*>* foundNode = root->find([](const char* val) { return std::strcmp(val, "child2") == 0; });
    if (foundNode != nullptr) {
        std::cout << "Nodul cu valoarea 'child2' a fost gasit.\n";
    }
    else {
        std::cout << "Nodul cu valoarea 'child2' nu a fost gasit.\n";
    }

    root->sort(compareStrings);
    std::cout << "Nodurile sortate: ";
    for (int i = 0; i < 10; ++i) {
        if (root->children[i] != nullptr) {
            std::cout << root->children[i]->value << " ";
        }
    }
    std::cout << "\n";

    std::cout << "Numărul total de noduri: " << root->count() << "\n";

    delete root;
    delete child1;
    delete child2;
    delete child3;

    return 0;
}
