#include <bits/stdc++.h>
using namespace std;
class Different
{
public:
    bool checkDifferent(string iniString)
    {
        if (iniString.empty())
        {
            return true;
        }

        int len = iniString.length();
        if (len > 256)
        {
            return false;
        }

        for (int i = 0; i < len; i++)
        {
            for (int j = i + 1; j < len; j++)
            {
                if (iniString[i] == iniString[j])
                {
                    return false;
                }
            }
        }

        return true;
    }
};

class Reverse
{
public:
    string reverseString(string iniString)
    {
        int i = 0, j = iniString.size() - 1;
        while (i < j)
        {
            swap(iniString[i++], iniString[j--]);
        }

        return iniString;
    }
};

class Same
{
public:
    bool checkSam(string stringA, string stringB)
    {
        char count[256] = {0};
        if (stringA.size() != stringB.size())
        {
            return false;
        }

        for (int i = 0; i < stringA.size(); i++)
        {
            count[stringA[i]]++;
            count[stringB[i]]--;
        }

        for (auto i : count)
        {
            if (i)
            {
                return false;
            }
        }

        return true;
    }
};

class Replacement
{
public:
    string replaceSpace(string iniString, int length)
    {
        int count = 0;
        for (int i = 0; i < length; i++)
        {
            if (iniString[i] == ' ')
            {
                count++;
            }
        }

        iniString.resize(length + 2 * count);
        for (int i = length - 1; i >= 0; i--)
        {
            if (iniString[i] != ' ')
            {
                iniString[i + 2 * count] = iniString[i];
            }
            else
            {
                count--;
                iniString[i + 2 * count] = '%';
                iniString[i + 2 * count + 1] = '2';
                iniString[i + 2 * count + 2] = '0';
            }
        }

        return iniString;
    }
};

class Zipper
{
public:
    string zipString(string iniString)
    {
        string str;
        int i = 0, j = 0;
        while (i < iniString.size())
        {
            while (iniString[i] == iniString[j])
            {
                i++;
            }

            str += iniString[j];
            str += to_string(i - j);
            j = i;
        }

        return iniString.size() < str.size() ? iniString : str;
    }
};

class TransForm
{
public:
    vector<vector<int>> transformImage(vector<vector<int>> mat, int n)
    {
        for (int i = 0; i < n / 2; i++)
        {
            for (int j = 0; j < n; j++)
            {
                swap(mat[i][j], mat[n - 1 - i][j]);
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                swap(mat[i][j], mat[j][i]);
            }
        }

        return mat;
    }
};

class Clearer
{
public:
    vector<vector<int>> clearZero(vector<vector<int>> mat, int n)
    {
        vector<pair<int, int>> stc;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == 0)
                {
                    stc.emplace_back(pair<int, int>(i, j));
                }
            }
        }

        int row, col;
        for (auto i : stc)
        {
            row = i.first;
            col = i.second;
            for (int z = 0; z < n; z++)
            {
                mat[row][z] = 0;
                mat[z][col] = 0;
            }
        }

        return mat;
    }
};

class ReverseEqual
{
public:
    bool checkReverseEual(string s1, string s2)
    {
        int size1 = s1.size();
        int size2 = s2.size();
        if (!size1 || !size2)
        {
            return false;
        }

        string str = s1 + s2;
        if (str.find(s2) == -1)
        {
            return false;
        }

        return true;
    }
};

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Remove
{
public:
    bool removeNode(ListNode *pNode)
    {
        if (!pNode || !pNode->next)
        {
            return false;
        }

        pNode->val = pNode->next->val;
        auto tmp = pNode->next;
        pNode->next = pNode->next->next;
        delete tmp;
        return true;
    }
};

class Partition
{
public:
    ListNode *partition(ListNode *pHead, int x)
    {
        if (!pHead)
        {
            return nullptr;
        }

        ListNode *smallList = new ListNode(-1);
        ListNode *bigList = new ListNode(-1);

        auto ps = smallList, pb = bigList, cur = pHead;
        while (cur)
        {
            if (cur->val < x)
            {
                ps->next = cur;
                ps = cur;
            }
            else
            {
                pb->next = cur;
                pb = cur;
            }
        }

        pb->next = nullptr;
        ps->next = bigList->next;
        pHead = smallList->next;
        delete smallList;
        delete bigList;
        return pHead;
    }
};

class Plus
{
public:
    ListNode *plusAB(ListNode *a, ListNode *b)
    {
        auto head = new ListNode(-1);
        auto pa = a, pb = b, p = head;
        int c = 0, sum = 0, value1, value2;
        while (pa || pb || c)
        {
            value1 = pa ? pa->val : 0;
            value2 = pb ? pb->val : 0;
            sum = value1 + value2 + c;
            c = sum / 10;
            auto node = new ListNode(sum % 10);

            p->next = node;
            p = node;
            pa = pa ? pa->next : pa;
            pb = pb ? pb->next : pb;
        }

        auto tmp = head->next;
        delete head;
        return tmp;
    }
};

class Palindrome
{
public:
    bool isPalindrom(ListNode *pHead)
    {
        if (!pHead)
        {
            return true;
        }

        static ListNode *p = nullptr;
        if (!p)
        {
            p = pHead;
        }

        if (isPalindrom(pHead->next) && (p->val == pHead->val))
        {
            p = p->next;
            return true;
        }

        p = nullptr;
        return false;
    }
};

class SetOfStacks
{
public:
    vector<vector<int>> setOfStacks(vector<vector<int>> ope, int size)
    {
        vector<vector<int>> st;
        vector<int> tmp;
        for (auto i : ope)
        {
            switch (i[0])
            {
            case 1:
                if (tmp.size() == size)
                {
                    st.emplace_back(tmp);
                    tmp.clear();
                    tmp.emplace_back(i[1]);
                }
                else
                {
                    tmp.emplace_back(i[1]);
                }
                break;

            case 2:
                if (tmp.size())
                {
                    tmp.pop_back();
                }
                else if (st.size())
                {
                    tmp = st.back();
                    tmp.pop_back();
                    st.pop_back();
                }
                break;

            default:
                break;
            }
        }

        if (tmp.size())
        {
            st.emplace_back(tmp);
        }

        return st;
    }
};

class TwoStacks
{
public:
    vector<int> twoStacksSort(vector<int> numbers)
    {
        vector<int> stack1;
        while (!numbers.empty())
        {
            int num = numbers.back();
            numbers.pop_back();
            while (!stack1.empty() && num > stack1.back())
            {
                numbers.emplace_back(stack1.back());
                stack1.pop_back();
            }
            stack1.emplace_back(num);
        }

        return stack1;
    }
};

class CatDogAsylum
{
public:
    vector<int> asylum(vector<vector<int>> ope)
    {
        queue<pair<int, int>> cat;
        queue<pair<int, int>> dog;
        vector<int> res;
        int uuid = 0;
        for (auto op : ope)
        {
            switch (op[0])
            {
            case 1:
                if (op[1] > 0)
                {
                    dog.push(make_pair(op[1], uuid++));
                }
                else
                {
                    cat.push(make_pair(op[1], uuid++));
                }
                break;

            case 2:
                int tp = op[1];
                if (tp == 0)
                {
                    int d = dog.empty() ? INT_MAX : dog.front().second;
                    int c = cat.empty() ? INT_MAX : cat.front().second;
                    if (d < c)
                    {
                        res.emplace_back(dog.front().first);
                        dog.pop();
                    }
                    if (d > c)
                    {
                        res.emplace_back(cat.front().first);
                        cat.pop();
                    }
                }

                if (tp == 1)
                {
                    if (!dog.empty())
                    {
                        res.emplace_back(dog.front().first);
                        dog.pop();
                    }
                }

                if (tp == -1)
                {
                    if (!cat.empty())
                    {
                        res.emplace_back(cat.front().first);
                        cat.pop();
                    }
                }
                break;

            default:
                break;
            }
        }

        return res;
    }
};

struct TreeNode
{
    int val;
    struct TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Balance
{
public:
    bool isBalance(TreeNode *root)
    {
        return getDep(root) != -1;
    }

    int getDep(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }

        auto left = getDep(root->left);
        auto right = getDep(root->right);
        if (left == -1 || right == -1)
        {
            return -1;
        }

        return abs(left - right) > 1 ? -1 : max(left, right) + 1;
    }
};

struct UndirectedGraphNode
{
    int label;
    vector<struct UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {}
};

class Path
{
public:
    bool checkPath(UndirectedGraphNode *a, UndirectedGraphNode *b)
    {
        return check(a, b) || check(b, a);
    }

    bool check(UndirectedGraphNode *a, UndirectedGraphNode *b)
    {
        if (a == nullptr || b == nullptr)
        {
            return false;
        }

        if (a == b)
        {
            return true;
        }

        if (a->label == -1)
        {
            return false;
        }

        a->label = -1;
        for (int i = 0; i < a->neighbors.size(); i++)
        {
            if (check(a->neighbors[i], b))
            {
                return true;
            }
        }

        return false;
    }
};

class MinimalBST
{
public:
    int buildMinimalBST(vector<int> vals)
    {
        int height = 0;
        BuildMinimalBST(vals, 0, vals.size() - 1, height);
        return height;
    }

    TreeNode *BuildMinimalBST(vector<int> &vals, int start, int end, int &height)
    {
        if (start > end)
        {
            height = 0;
            return nullptr;
        }

        int mid = start + (end - start) / 2;
        TreeNode *root = new TreeNode(vals[mid]);
        int left = 0, right = 0;
        root->left = BuildMinimalBST(vals, start, mid - 1, left);
        root->right = BuildMinimalBST(vals, mid + 1, end, right);
        height = (left >= right ? left : right) + 1;

        return root;
    }
};

class TreeLevel
{
    ListNode *ln = new ListNode(-1);
    ListNode *p = ln;

public:
    ListNode *getTreeLevel(TreeNode *root, int dep)
    {
        if (root == nullptr || dep <= 0)
        {
            return nullptr;
        }

        if (dep == 1)
        {
            p->next = new ListNode(root->val);
            p = p->next;
        }
        else
        {
            getTreeLevel(root->left, dep - 1);
            getTreeLevel(root->right, dep - 1);
        }

        return ln->next;
    }
};

class Checker
{
public:
    bool checkBST(TreeNode *root)
    {
        return method2(root, INT_MIN, INT_MAX);
    }

    bool method2(TreeNode *root, int min, int max)
    {
        if (root == nullptr)
        {
            return true;
        }

        if (root->val < min || root->val > max)
        {
            return false;
        }

        return method2(root->left, min, root->val) && method2(root->right, root->val, max);
    }
};