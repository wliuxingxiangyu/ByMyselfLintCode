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

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode *next;
	TreeNode(int val){
		this->val=val;
		this->left = this->right=this->next = NULL;
	}
};

void traverse(TreeNode *root, size_t level, vector<vector<int>> &result) {
	if (!root) return;
	if (level > result.size())
		result.push_back(vector<int>());
	result[level-1].push_back(root->val);
	traverse(root->left, level+1, result);
	traverse(root->right, level+1, result);
}

vector<vector<int> > levelOrderBottom(TreeNode *root) {
	vector<vector<int>> result;
	traverse(root, 1, result);
	std::reverse(result.begin(), result.end()); // 比上一题多此一行
	return result;
}

int  main(){
	TreeNode* root=new TreeNode(0);//test1
	root->left=new TreeNode(1);
	root->right=new TreeNode(2);

	root->left->left=new TreeNode(3);
	root->left->right=new TreeNode(4);

	//root->right->left=new TreeNode(5);
	// root->right->right=new TreeNode(6);

	root->left->left->right=new TreeNode(7);//3->right=7
	root->left->left->right->right=new TreeNode(11);//7->right=11
	root->left->right->right=new TreeNode(8);//4->right=8
	root->left->right->right->right=new TreeNode(9);//8->right=9
	root->left->right->right->right->right=new TreeNode(10);//9->right=10
	levelOrderBottom(root);
	cout<< "MaxBTDis(root)="<<endl;
	system("pause");
}