#include <iostream>
#include <vector>
#include <string>
#include <sstream> 
#include <stack> 
#include <iostream>
#include <algorithm>
#include <math.h>
#include <limits.h>
using namespace std;

struct TreeLinkNode {
	int val;
	TreeLinkNode *left;
	TreeLinkNode *right;
	TreeLinkNode *next;
	TreeLinkNode(int val){
		this->val=val;
		this->left = this->right=this->next = NULL;
	}
};

void process(TreeLinkNode *cur,TreeLinkNode *nextNode){
	if(cur==NULL) {
		return;
	}
	if(nextNode==NULL) {
		cur->next=NULL;
		return;
	}
	cur->next=nextNode;

	process(cur->left,cur->right);  
	process(cur->right,cur->next->left);  
}

void   preProcess(TreeLinkNode *root){
	if(root == NULL) return;
	root->next=root;
	preProcess(root->right);
}

void   afterProcess(TreeLinkNode *root){
	if(root == NULL) return;
	root->next=NULL;
	afterProcess(root->right);
}

void connect(TreeLinkNode *root) {
	if(root == NULL) return;
	preProcess(root);
	process(root->left,root->right);  
	process(root->right,root->next->left);  
	afterProcess(root);


}

int  main(){
	TreeLinkNode* root=new TreeLinkNode(0);//test1
	root->left=new TreeLinkNode(1);
	root->right=new TreeLinkNode(2);

	root->left->left=new TreeLinkNode(3);
	root->left->right=new TreeLinkNode(4);

	root->right->left=new TreeLinkNode(5);
	root->right->right=new TreeLinkNode(6);
	
	connect(root);
	cout<< "maxPathSum(root)="<<endl;
	system("pause");
}