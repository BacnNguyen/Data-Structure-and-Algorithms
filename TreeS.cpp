#include<iostream>
#include<math.h>
#include<algorithm>
#include<queue>
#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	struct node *left;
	struct node *right;
};
typedef node *tree;
node *Make_Node(int value){
	node *tmp;
	tmp = new node();
	tmp->data = value;
	tmp->left = NULL;
	tmp->right = NULL;
	return tmp;
}
void insert(tree &root,int x)
{	
	if(root!=NULL)
	{
//		cout<<root->data<<"\n";
		if(root->data==x)
		{
			return;
		}
		else if(x<root->data)
		{
			insert(root->left,x);
		}
		else insert(root->right,x);
	}
	else{
		node *p=Make_Node(x);
		root=p;
	}
}

void inoder(node *root){
	if(root!=NULL){
		if(root->left==NULL&&root->right==NULL){
			cout<<root->data<<" ";
		}
		else {
			inoder(root->left);
			inoder(root->right);
		}
	}
}

void preoder(node *root){
	if(root!=NULL){
		preoder(root->left);
		cout<<root->data<<" ";
		preoder(root->right);
	}
}

void posoder(node *root){
	if(root!=NULL){
		posoder(root->left);
		posoder(root->right);
		cout<<root->data<<" ";
	}
}

void makeRoot(node *root,int value){
	if(root==NULL){
		node *tmp = Make_Node(value);
		root = tmp;
		tmp->left = NULL;
		tmp ->right=NULL;
	}
	else {
		cout<<"Cay da co goc\n";
	}
}




int main(){
	int t;
	cin>>t;
	while(t--){
		int N;
		cin>>N;
		int x;
		cin>>x;
		tree root = Make_Node(x);
		for(int i = 2;i<=N;i++){
			cin>>x;
			insert(root,x);
		}
		inoder(root);
		cout<<endl;
	}
}

