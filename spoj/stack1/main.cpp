#include <bits/stdc++.h>

using namespace std;
void push(struct stackn **root,int data);
struct stackn
{
    int data;
    struct stackn *next;
};
struct stackn* newnode(int a)
{
    struct stackn* ne=(struct stackn*)malloc(sizeof(struct stackn));
    ne->data=a;
    ne->next=NULL;
};
void push(struct stackn **root,int data)
{
    struct stackn* neuw=newnode( data);
    neuw->next=*root;
    *root=neuw;
     printf("%d pushed to stack\n", data);
}
int main()
{
    cout << "Hello world!" << endl;
     struct stackn* root = NULL;

    push(&root, 10);
    push(&root, 20);
    push(&root, 30);
    return 0;
}
