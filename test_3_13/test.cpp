//class Solution
//{
//public:
//    string tree2str(TreeNode* root)
//    {
//        if (root == nullptr)
//            return "";
//
//        if (root->left == nullptr && root->right == nullptr)
//            return to_string(root->val);
//
//        if (root->right == nullptr)
//            return to_string(root->val) + "(" + tree2str(root->left) + ")";
//
//        return to_string(root->val) + "(" + tree2str(root->left) + ")(" + tree2str(root->right) + ")";
//    }
//};

//class Solution
//{
//public:
//    vector<vector<int>> levelOrder(TreeNode* root)
//    {
//        queue<TreeNode*> que;
//        vector<vector<int>> res;
//
//        if (root != nullptr)
//            que.push(root);
//
//        while (!que.empty())
//        {
//            vector<int> tmp;
//            for (int i = que.size(); i > 0; i--)
//            {
//                root = que.front();
//                que.pop();
//                tmp.push_back(root->val);
//
//                if (root->left != nullptr)
//                    que.push(root->left);
//                if (root->right != nullptr)
//                    que.push(root->right);
//            }
//            res.push_back(tmp);
//        }
//        return res;
//    }
//};

//class Solution
//{
//public:
//    vector<vector<int>> levelOrderBottom(TreeNode* root)
//    {
//        queue<TreeNode*> que;
//        vector<vector<int>> res;
//
//        if (root != nullptr)
//            que.push(root);
//
//        while (!que.empty())
//        {
//            vector<int> tmp;
//            for (int i = que.size(); i > 0; i--)
//            {
//                root = que.front();
//                que.pop();
//                tmp.push_back(root->val);
//
//                if (root->left != nullptr)
//                    que.push(root->left);
//                if (root->right != nullptr)
//                    que.push(root->right);
//            }
//            res.insert(res.begin(), tmp);
//        }
//        return res;
//    }
//};

//class Solution
//{
//public:
//    bool GetPath(TreeNode* root, TreeNode* x, stack<TreeNode*>& path)
//    {
//        if (root == nullptr)
//            return false;
//
//        path.push(root);
//        if (root == x)
//            return true;
//
//        if (GetPath(root->left, x, path))
//            return true;
//
//        if (GetPath(root->right, x, path))
//            return true;
//
//        path.pop();
//        return false;
//    }
//
//    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
//    {
//        stack<TreeNode*> pPath, qPath;
//        GetPath(root, p, pPath);
//        GetPath(root, q, qPath);
//
//        while (pPath.size() != qPath.size())
//        {
//            if (pPath.size() > qPath.size())
//                pPath.pop();
//            else
//                qPath.pop();
//        }
//
//        while (pPath.top() != qPath.top())
//        {
//            pPath.pop();
//            qPath.pop();
//        }
//
//        return pPath.top();
//    }
//};

//class Solution
//{
//public:
//	vector<TreeNode*> vTN;
//
//	void inOrder(TreeNode* pRootOfTree)
//	{
//		if (pRootOfTree == nullptr)
//			return;
//		inOrder(pRootOfTree->left);
//		vTN.push_back(pRootOfTree);
//		inOrder(pRootOfTree->right);
//	}
//
//	TreeNode* Convert(TreeNode* pRootOfTree)
//	{
//		if (pRootOfTree == nullptr)
//			return nullptr;
//
//		inOrder(pRootOfTree);
//		for (int i = 0; i < vTN.size() - 1; i++)
//		{
//			vTN[i]->right = vTN[i + 1];
//			vTN[i + 1]->left = vTN[i];
//		}
//
//		return vTN[0];
//	}
//};