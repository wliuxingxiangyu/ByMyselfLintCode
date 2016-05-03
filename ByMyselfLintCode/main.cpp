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

class TreeNode {
public:
	int val;
	TreeNode *left, *right;
	TreeNode(int val) {
		this->val = val;
		this->left = this->right = NULL;
	}
};

int max_sum;
int dfs(const TreeNode *root) {
	if (root  == nullptr) return 0;
	int l = dfs(root->left);
	int r = dfs(root->right);
	int sum = root->val;
	if (l > 0) sum += l;
	if (r > 0) sum += r;
	max_sum = max(max_sum, sum);//全局变量保存返回结果，在每次递归中更新.
	return max(r, l) > 0 ? max(r, l) + root->val : root->val;
}

int maxPathSum(TreeNode *root) {
	max_sum = INT_MIN;
	dfs(root);
	return max_sum;
}

int  main(){
	TreeNode* root=new TreeNode(1);//test1
	root->left=new TreeNode(2);
	root->left->left=new TreeNode(3);

	TreeNode* root2=new TreeNode(1);//test2
	root2->left=new TreeNode(2);
	root2->right=new TreeNode(3);

	cout<< "maxPathSum(root)="<<maxPathSum(root2)<<endl;
	system("pause");
}