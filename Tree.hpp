#include <iostream>
namespace ariel
{
using namespace std;

class Node
{
public:
   int data;
   Node *parent;
   Node *right;
   Node *left;
}; 


class Tree
{
private:
  size_t _size;
  Node *head;
  int help_print(Node *root);

 public:
    Tree();
    ~Tree();
    void insert(int value);
    void remove(int value);
    bool contains(int value);
    int size();
    int print();
    int parent(int value);
    int left(int value);
    int right(int value);
    int root();
    void Clear(Node *root);
};
} // namespace ariel