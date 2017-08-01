#include<bits/stdc++.h>
using namespace std;
template <class T>
struct N
{
    T value;
    N *left;
    N *right;
    N(T val)
    {
        this->value=val;
    }
    N(T val,N<T> left,N <T> right)
    {
        this->value=val;
        this->left=left;
        this->right=right;
    }
};

template <class T>
class BST
{
private:
    N<T> *root;
    void addnode(N<T> *root,T val){
        if(val<root->value)
        {
            if(!root->left)
                root->left=new N<T>(val);
            else
                addnode(root->left, val);
        }
        else
        {
            if(!root->right)
                 root->right=new N<T>(val);
           else
                 addnode(root->right, val);

        }
    }

     void printinorder(N<T> *root)
     {
         if(!root)return;
         printinorder(root->left);
         cout<<root->value<<"   "<<endl;
         printinorder(root->right);
     }

public:
                        void add(T val)
                      {
                          if(root){
                           this->addnode(root,val);
                      }
                      else
                        root= new N<T>(val);
                      }
                      void print(){
                          printinorder(this->root);
                      }
};

  int main(){
      BST<int> *bst= new BST<int>();
      bst->add(11);
      bst->add(5);
      bst->add(15);
      bst->add(14);
      bst->add(6);
      bst->print();
  }
