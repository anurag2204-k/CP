#include <iostream>
#include <vector>
#include<queue>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int val){
        data=val;
        left=nullptr;
        right=nullptr;
    }
};

Node* create(vector<int> v)
{
    int n = v.size();
    Node *head = new Node(v[0]);
    queue<Node*> q;
    q.push(head);
    int i=1;
    while(i<n){
        Node *temp = q.front();
        q.pop();
        temp->left=new Node(v[i++]);
        q.push(temp->left);
        if(i<n){
            temp->right = new Node(v[i++]);
            q.push(temp->right);
        }
    }
    return head;
}   

void inOrder(Node *head){
    if(!head){
        return ;
    }

    inOrder(head->left);
    cout<<head->data<<" ";
    inOrder(head->right);
    return;
}

int main(){
    cout<<"Hello to the tree"<<endl;
    int n;
    
    cin>>n;
    vector<int> v(n);
    cout<<"Please provide the values"<<endl;
    for(int i=0; i<n; i++) cin>>v[i];
    
    Node *head = create(v);
    inOrder(head);

    return 0;
}