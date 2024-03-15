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