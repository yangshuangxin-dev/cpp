#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    struct TreeNode *left, *right;
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution1
{
    int cutRope(int number)
    {
        int max = 1;
        if (number <= 0)
        {
            return 0;
        }

        if (number <= 3)
        {
            return number - 1;
        }

        while (number > 4)
        {
            max *= 3;
            number -= 3; //
        }

        return number * max;
    }
};

class Solution2
{
    int count = 0;
    TreeNode *KthNode(TreeNode *pRoot, int k)
    {
        if (!pRoot)
        {
            return nullptr;
        }

        TreeNode *left = nullptr, *right = nullptr;

        if ((left = KthNode(pRoot->left, k)) != nullptr)
        {
            return left;
        }

        if (++count == k)
        {
            count = 0;
            return pRoot;
        }

        if ((right = KthNode(pRoot->right, k)) != nullptr)
        {
            return right;
        }

        return nullptr;
    }
};

class Solution3
{
    int movingCount(int threshild, int rows, int cols)
    {
        if (threshild <= 0 || rows <= 0 || cols <= 0)
        {
            return 0;
        }

        vector<bool> flag(rows * cols, false);
        return robotDfs(threshild, rows, cols, flag, 0, 0);
    }

    int robotDfs(int k, int rows, int cols, vector<bool> &flag, int i, int j)
    {
        int index = i * cols + j;
        if (i < 0 || i >= rows || j < 0 || j >= cols || getSum(i) + getSum(j) > k || flag[index])
        {
            return 0;
        }

        flag[index] = true;
        return 1 + robotDfs(k, rows, cols, flag, i + 1, j) + robotDfs(k, rows, cols, flag, i - 1, j) + robotDfs(k, rows, cols, flag, i, j + 1) + robotDfs(k, rows, cols, flag, i, j - 1);
    }

    int getSum(int x)
    {
        int sum = 0;
        while (x > 0)
        {
            sum += x % 10;
            x /= 10;
        }
        return sum;
    }
};

//查找字符串
class Solution4
{
    bool hasPath(char *matrix, int rows, int cols, char *str)
    {
        if (!matrix || rows <= 0 || cols <= 0 || !str)
        {
            return false;
        }

        vector<bool> flag(rows * cols, false);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (strDfs(matrix, rows, cols, flag, str, 0, i, j))
                {
                    return true;
                }
            }
        }

        return false;
    }

    bool strDfs(char *matrix, int rows, int cols, vector<bool> &flag, char *str, int k, int i, int j)
    {
        int index = i * cols + j;
        if (i < 0 || i >= rows || j < 0 || j >= cols || str[k] != matrix[index] || flag[index] == false)
        {
            return false;
        }

        if (str[k + 1] == '\0')
        {
            return true;
        }

        flag[index] = true;
        if (
            strDfs(matrix, rows, cols, flag, str, k + 1, i + 1, j) ||
            strDfs(matrix, rows, cols, flag, str, k + 1, i - 1, j) ||
            strDfs(matrix, rows, cols, flag, str, k + 1, i, j + 1) ||
            strDfs(matrix, rows, cols, flag, str, k + 1, i, j - 1))
        {
            return true;
        }

        flag[index] = false;
        return false;
    }
};

class Solution5
{
    vector<int> maxInWindows(vector<int> &num, unsigned size)
    {
        vector<int> res;
        deque<int> tmp;

        for (int i = 0; i < num.size(); i++)
        {
            while (tmp.size() && num[tmp.back()] < num[i])
            {
                tmp.pop_back();
            }

            if (tmp.size() && i - tmp.front() >= size)
            {
                tmp.pop_front();
            }

            tmp.push_back(i);
            if (size && i >= size - 1)
            {
                res.emplace_back(num[tmp.front()]);
            }
        }

        return res;
    }
};

class Solution6
{
    priority_queue<int, vector<int>, less<int>> q;
    priority_queue<int, vector<int>, greater<int>> p;

    void push(int num)
    {
        if (q.empty() || q.top() > num)
        {
            q.push(num);
        }
        else
        {
            p.push(num);
        }

        if (q.size() == p.size() + 2)
        {
            p.push(q.top());
            q.pop();
        }

        if (q.size() + 1 == p.size())
        {
            q.push(p.top());
            p.pop();
        }
    }

    double GetMedian()
    {
        if (q.size() == p.size())
        {
            return (q.top() + p.top()) / 2.0;
        }
        else
        {
            return q.top();
        }
    }
};

class Solution7
{
    vector<int> buf;

    char *Serialize(TreeNode *root)
    {
        buf.clear();

        if (!root)
        {
            return nullptr;
        }

        dfsTree(root);
        int *res = new int[buf.size()];
        return (char *)res;
    }

    TreeNode *Deserialize(char *str)
    {
        int *p = (int *)str;
        return dfsTree(p);
    }

    void dfsTree(TreeNode *root)
    {
        if (!root)
        {
            buf.emplace_back('#');
            return;
        }

        buf.emplace_back(root->val);
        dfsTree(root->left);
        dfsTree(root->right);
        return;
    }

    TreeNode *dfsTree(int *&p)
    {
        if (*p == '#')
        {
            p++;
            return;
        }

        TreeNode *root = new TreeNode(*p);
        p++;
        root->left = dfsTree(p);
        root->right = dfsTree(p);
        return root;
    }
};

class Solution8
{
    vector<vector<int>> tree;

    vector<vector<int>> printTree(TreeNode *root)
    {
        tree.clear();
        if (!root)
        {
            return tree;
        }
        depth(root, 1);
        return tree;
    }

    void depth(TreeNode *root, int k)
    {
        if (!root)
        {
            return;
        }

        if (k > tree.size())
        {
            vector<int> floor;
            tree.emplace_back(floor);
        }

        tree[k - 1].emplace_back(root->val);
        depth(root->left, k + 1);
        depth(root->right, k + 1);
        return;
    }
};

//之字打印二叉树
class Solution9
{
    vector<vector<int>> PrintZ(TreeNode *root)
    {
        vector<vector<int>> res;
        if (!root)
        {
            return res;
        }

        stack<TreeNode *> st1, st2;
        st1.push(root);
        while (st1.size() || st2.size())
        {
            vector<int> tmp1, tmp2;
            while (st1.size())
            {
                auto cur = st1.top();
                st1.pop();
                tmp1.emplace_back(cur->val);
                if (cur->left)
                {
                    st2.push(cur->left);
                }

                if (cur->right)
                {
                    st2.push(cur->right);
                }
            }

            if (tmp1.size())
            {
                res.emplace_back(tmp1);
            }

            while (st2.size())
            {
                auto cur = st2.top();
                st2.pop();
                tmp2.emplace_back(cur->val);
                if (cur->right)
                {
                    st1.push(cur->right);
                }

                if (cur->left)
                {
                    st1.push(cur->left);
                }
            }

            if (tmp2.size())
            {
                res.emplace_back(tmp2);
            }
        }

        return res;
    }
};

class Solution10
{
    bool isSymmetircal(TreeNode *pRoot)
    {
        if (!pRoot)
        {
            return false;
        }

        return aux(pRoot, pRoot);
    }

    bool aux(TreeNode *r1, TreeNode *r2)
    {
        if (r1 && r2 && r1->val == r2->val)
        {
            return aux(r1->left, r2->right) && aux(r1->right, r2->left);
        }

        return !r1 && !r2;
    }
};

struct TreeLinkNode
{
    int val;
    struct TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(nullptr), next(nullptr) {}
};
