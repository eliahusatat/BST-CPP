#include <iostream>
#include "Tree.hpp"

using namespace ariel;

Tree::Tree() 
: head(nullptr), _size(0)
{

}

Tree::~Tree()
{
  Clear(this->head);
}

void Tree::Clear(Node *head)
{
    if (head == nullptr)
        return; // if Tree is empty
    if (head->left != nullptr)
         Clear(head->left); // go left and delete
    if (head->right != nullptr)
         Clear(head->right); // go right and delete
    delete head;
    return;
}


int Tree::size(){
    int ans = (int)_size;
    return ans;
}

void Tree::insert(int value){
   if(this->contains(value)){
        throw std::invalid_argument("The input integer is already in the tree");
   }
   else{
       if(head == nullptr){
           head = new Node;
           head->data = value;
           head->left = head->right = head->parent = nullptr;
           _size++; 
       }
       else
       {
           Node *current = head;
           bool exit  = false;
           while(!exit ){
               if(current->data > value){
                   if (current->left == nullptr)
                   {
                    current->left = new Node;
                    current->left->data = value;
                    current->left->left = current->left->right = nullptr;
                    current->left->parent = current;
                    exit = true;
                    _size++; 
                   }
                   else
                   {
                    current = current->left;
                   }
               }
               else{
                   	if(current->right == nullptr) {
                    current->right = new Node;
                    current->right->data = value;
                    current->right->left = current->right->right = nullptr;
                    current->right->parent = current;
                    exit = true;
                    _size++; 
					}
                    else
                    {
                      current = current->right;  
                    }
               }
           }
       }   
   }
}


bool Tree::contains(int value){
    Node *current = head;
    while(current != nullptr) {
			if(current->data == value) return true;
			else if(value < current->data) 
				current = current->left;
			else 
				current = current->right;
		}
		return false;
}


    void Tree::remove(int value){
       	if(!contains(value)){
               throw std::invalid_argument("The input integer is not in the tree");
           }
        else{
		// find node to delete
		Node *current = head;
		while(current->data != value) {
			if(value < current->data)
				current = current->left;
			else 
				current = current->right;
		}

		Node *father = current->parent;

		// case 1: leaf
		if(current->left == nullptr && current->right == nullptr) {
			if(father == nullptr) // special case: current is head
				head = nullptr;
			else if(value < father->data) 
				father->left= nullptr;
			else 
				father->right= nullptr;
		}

		// case 2: current has only one child
		else if (current->left == nullptr) {
			if(father == nullptr) { // special case: current is head
				head = current->right;
				head->parent = nullptr;
			}
			else if(value < father->data) { 
				father->left = current->right;
				current->right->parent = father;
			}
			else {
				father->right=current->right;
				current->right->parent = father;
			}
		}

		else if (current->right == nullptr) {
			if(father == nullptr) { // special case: current is head
				head = current->left;
				head->parent = nullptr;
			}
			else if(value < father->data) { 
                father->left=current->left;
				current->left->parent = father;
			}
			else {
                father->right = current->left;
                current->left->parent =father;
			}
		}

		// case 3: current has two children
		else {
			// find replacement - largest on the left side
			Node *replace = current->left;
			while(replace->right!= nullptr)
				replace = replace->right;
			// remove replacement node
			remove(replace->data);
            _size++;
			// replace data
			current->data= replace->data;
		}
        _size--;
    }
    }

    int Tree::print(){
         	if( head != nullptr) {
            cout<<"the tree is: ";
			help_print(head->right);
            cout<<head->data<<" ";
			help_print(head->left);
            cout<<endl;
            return 0;
		}
        else{
             cout<<"the tree is: ";
             return 0;
        }
    }

        int Tree::help_print(Node *root){
         	if( root != nullptr) {
			help_print(root->right);
            cout<<root->data<<" ";
			help_print(root->left);
		}
        return 0 ;
    }
    int Tree::parent(int value){
        if(!contains(value)){
           throw std::invalid_argument("The input integer is not in the tree!");
        }
        if(head->data == value){
            throw std::invalid_argument("Thetrying to get the root father!");
        }
        Node *current = head;
        while(current != nullptr) {
			if(current->data == value) return current->parent->data;
			else if(value < current->data) 
				current = current->left;
			else 
				current = current->right;
		}
		return 0;
    }

    int Tree::left(int value){
            if(!contains(value)){
           throw std::invalid_argument("The input integer is not in the tree!");
        }
        Node *current = head;
        while(current != nullptr) {
			if(current->data == value){ 
                if(current->left == nullptr){
                  throw std::invalid_argument("The input has not have left son!");
                }
                else
                {
                    return current->left->data;
                }
            }
			else if(value < current->data) 
				current = current->left;
			else 
				current = current->right;
		}
		return 0;
    }

    int Tree::right(int value){
            if(!contains(value)){
           throw std::invalid_argument("The input integer is not in the tree!");
        }
        Node *current = head;
        while(current != nullptr) {
			if(current->data == value){ 
                if(current->right == nullptr){
                  throw std::invalid_argument("The input has not have right son!");
                }
                else
                {
                    return current->right->data;
                }
            }
			else if(value < current->data) 
				current = current->left;
			else 
				current = current->right;
		}
		return 0;
    }

    int Tree::root(){
        if(head == nullptr){
           throw std::invalid_argument("The tree is empty!");
        }
        else{
            return head->data;
        }
    }

int main(){

   Tree emptytree ;
   cout<<"size: "<<emptytree.size()<<endl;
   emptytree.insert(5);
    emptytree.insert(1);
    emptytree.insert(4);
    emptytree.insert(7);
    emptytree.insert(9);
    emptytree.insert(11);
    emptytree.insert(10);
    emptytree.insert(34);
    emptytree.insert(634);
    emptytree.insert(475);
    emptytree.insert(456);
    emptytree.insert(3);
    emptytree.insert(6);
   
   cout<<"size: "<<emptytree.size()<<endl;
   cout<<"5 "<<emptytree.contains(5)<<endl;
   cout<<"2 "<<emptytree.contains(2)<<endl;
   cout<<"3 "<<emptytree.contains(3)<<endl;
   cout<<"parent 3 "<<emptytree.parent(3)<<endl;
   cout<<"parent 6 "<<emptytree.parent(6)<<endl;
   cout<<"left 5 "<<emptytree.left(5)<<endl;
   cout<<"right 5 "<<emptytree.right(5)<<endl;
   cout<<"root "<<emptytree.root()<<endl;
   cout<<"size: "<<emptytree.size()<<endl;
   emptytree.remove(5);
   cout<<"size: "<<emptytree.size()<<endl;
   emptytree.remove(3);
   cout<<"size: "<<emptytree.size()<<endl;
   emptytree.remove(6);
   cout<<"size: "<<emptytree.size()<<endl;
   emptytree.print();
   return 0 ;
}



