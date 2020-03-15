#include<iostream>
#include"Tree.hpp"
using std::cout;
using std::endl;
using namespace ariel;
int main(){

   Tree emptytree ;
   emptytree.insert(5);
   emptytree.insert(3);
   cout<<emptytree.contains(5)<<endl;

    return 0 ;
}