#include <iostream>
#include <vector>
#include <string>
#include <string.h>
using namespace std;
class TreeNode {
public:
	int val;
	TreeNode *left, *right;
	TreeNode(int val) {
		this->val = val;
		this->left = this->right = NULL;
	}
};

void process(TreeNode* root,vector<char> vc,vector<string>&  v){
	if (root != NULL && root->left == NULL && root->right == NULL) {
		vc.push_back(root->val + '0');
		string str="";
		for (vector<char>::iterator it=vc.begin();it!=vc.end();it++){ 
			str += *it;
			// str += "->";
		}
		v.push_back(str);
		return ; 
	}

	vc.push_back(root->val + '0');//int 10+48_'0'=58_':'

	if(root->left != NULL){
		vc.push_back('-');
		vc.push_back('>');
		process(root->left,vc ,v);
		vc.pop_back();
		vc.pop_back();
	}

	if(root->right != NULL){
		vc.push_back('-');
		vc.push_back('>');
		process(root->right,vc,v);
		vc.pop_back();
		vc.pop_back();
	}

	//从vc中删除尾字符，往上回溯。进入下一个分支。
	vc.pop_back();
}

vector<string> binaryTreePaths(TreeNode* root) {
	vector<string>  v;
	if (root == NULL) return v;
	vector<char> vc;
	process(root,vc,v);
	return v;
}

int  main(){
	TreeNode* root=new TreeNode(10);
	//root->left=new TreeNode(2);
	//root->right=new TreeNode(3);

	//root->left->left=NULL;
	//root->left->right=new TreeNode(5);

	binaryTreePaths(root);
	system("pause");
}