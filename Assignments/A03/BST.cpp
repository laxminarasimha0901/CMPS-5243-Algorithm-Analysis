#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};

class GraphvizBST {
public:
    static void saveDotFile(const std::string& filename, const std::string& dotContent) {
        std::ofstream outFile(filename);
        if (outFile.is_open()) {
            outFile << dotContent;
            outFile.close();
            std::cout << "DOT file saved: " << filename << std::endl;
        }
        else {
            std::cerr << "Error: Could not open file " << filename << std::endl;
        }
    }

    static std::string generateDot(const Node* root) {
        std::string dot = "digraph BST {\n";
        dot += "    node [fontname=\"Arial\"];\n";
        dot += generateDotHelper(root);
        dot += "}\n";
        return dot;
    }

private:
    static std::string generateDotHelper(const Node* node) {
        if (!node)
            return "";
        std::string result;
        if (node->left) {
            result += "    " + std::to_string(node->data) + " -> " + std::to_string(node->left->data) + " [label=\"L\"];\n";
            result += generateDotHelper(node->left);
        }
        else {
            std::string nullNode = "nullL" + std::to_string(node->data);
            result += "    " + nullNode + " [shape=point];\n";
            result += "    " + std::to_string(node->data) + " -> " + nullNode + ";\n";
        }
        if (node->right) {
            result += "    " + std::to_string(node->data) + " -> " + std::to_string(node->right->data) + " [label=\"R\"];\n";
            result += generateDotHelper(node->right);
        }
        else {
            std::string nullNode = "nullR" + std::to_string(node->data);
            result += "    " + nullNode + " [shape=point];\n";
            result += "    " + std::to_string(node->data) + " -> " + nullNode + ";\n";
        }
        return result;
    }
};

class Bst {
    Node* root;

    void _print(Node* subroot) {
        if (!subroot) {
            return;
        }
        else {
            _print(subroot->left);
            cout << subroot->data << " ";
            _print(subroot->right);
        }
    }

    void _insert(Node*& subroot, int x) {
        if (!subroot) {
            subroot = new Node(x);
        }
        else {
            if (x < subroot->data) {
                _insert(subroot->left, x);
            }
            else {
                _insert(subroot->right, x);
            }
        }
    }

    Node* _findMin(Node* subroot) {
        while (subroot->left != nullptr) {
            subroot = subroot->left;
        }
        return subroot;
    }

    Node* _deleteNode(Node* subroot, int key) {
        if (!subroot) return nullptr;

        if (key < subroot->data) {
            subroot->left = _deleteNode(subroot->left, key);
        }
        else if (key > subroot->data) {
            subroot->right = _deleteNode(subroot->right, key);
        }
        else {
            // Case 1: No child (leaf node)
            if (!subroot->left && !subroot->right) {
                delete subroot;
                return nullptr;
            }
            // Case 2: One child
            else if (!subroot->left) {
                Node* temp = subroot->right;
                delete subroot;
                return temp;
            }
            else if (!subroot->right) {
                Node* temp = subroot->left;
                delete subroot;
                return temp;
            }
            // Case 3: Two children
            else {
                Node* temp = _findMin(subroot->right);
                subroot->data = temp->data;
                subroot->right = _deleteNode(subroot->right, temp->data);
            }
        }
        return subroot;
    }

    int _ipl(Node* root, int depth = 0) {
        if (!root)
            return 0;
        return depth + _ipl(root->left, depth + 1) + _ipl(root->right, depth + 1);
    }

public:
    Bst() { root = nullptr; }
    void insert(int x) { _insert(root, x); }
    bool search(int key) { return 0; }
    void print() { _print(root); cout << endl; }
    void saveDotFile(const std::string& filename) {
        std::string dotContent = GraphvizBST::generateDot(root);
        GraphvizBST::saveDotFile(filename, dotContent);
    }
    int ipl() { return _ipl(root); }

    void deleteNode(int key) {
        root = _deleteNode(root, key);
    }
};

bool unique_value(int* arr, int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return false;
        }
    }
    return true;
}

int main() {
    Bst tree;
    int root = pow(2, 15) / 2;
    int max = pow(2, 15) - 1;
    vector<int> arr;
    arr.push_back(root);
    tree.insert(root);

    for (int i = 1; i < 5000; i++) {
         int r = rand() % max;
         while (!unique_value(arr.data(), arr.size(), r)) {
             r = rand() % max;
         }
         tree.insert(r);
         arr.push_back(r);
     }

    tree.print();
    tree.saveDotFile("bst_snapshot.dot");

    Bst tree2;
    tree2.insert(10);
    tree2.insert(5);
    tree2.insert(15);
    tree2.insert(2);
    tree2.insert(7);
    tree2.insert(20);

    cout << "Internal Path Length: " << tree2.ipl() << endl;

    // Testing deletion
    cout << "BST before deletion:" << endl;
    tree2.print();

   tree2.deleteNode(5); // Deleting a node with two children
    cout << "BST after deleting 5:" << endl;
    tree2.print();

    tree2.deleteNode(2); // Deleting a leaf node
    cout << "BST after deleting 2:" << endl;
   tree2.print();

    tree2.deleteNode(10); // Deleting the root node
    cout << "BST after deleting root 10:" << endl;
    tree2.print();

    return 0;
}
