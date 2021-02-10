// 确定字符互异
#include <bits/stdc++.h>
using namespace std;
class Different
{
public:
    bool checkDifferent(string iniString)
    {
        // write code here
        if (iniString.empty())
            return true;
        int len = iniString.size();
        if (len > 256)
            return false;
        for (int i = 0; i < len; i++)
        {
            for (int j = i + 1; j < len; j++)
            {
                if (iniString[i] == iniString[j])
                    return false;
            }
        }
        return true;
    }
};
// 原串翻转
class Reverse
{
public:
    string reverseString(string iniString)
    {
        // write code here
        int i = 0, j = iniString.size() - 1;
        while (i < j)
        {
            swap(iniString[i++], iniString[j--]);
        }
        return iniString;
    }
};

// 	确定两串乱序同构
class Same
{
public:
    bool checkSam(string stringA, string stringB)
    {
        // write code here
        char count[256] = {0};
        if (stringA.size() != stringB.size())
            return false;
        for (int i = 0; i < stringA.size(); i++)
        {
            count[stringA[i]]++;
            count[stringB[i]]--;
        }
        for (auto i : count)
        {
            if (i)
                return false;
        }
        return true;
    }
};

// 	空格替换
class Replacement
{
public:
    string replaceSpace(string iniString, int length)
    {
        // write code here
        int count = 0;
        for (int i = 0; i < length; i++)
        {
            if (iniString[i] == ' ')
                count++;
        }
        iniString.resize(length + 2 * count);
        for (int i = length; i >= 0; i--)
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

// 基本字符串压缩
class Zipper
{
public:
    string zipString(string iniString)
    {
        // write code here
        string str;
        int i = 0, j = 0;
        while (i < iniString.size())
        {
            while (iniString[i] == iniString[j])
                i++;
            str += iniString[j];
            str += to_string(i - j);
            j = i;
        }
        return iniString.length() < str.length() ? iniString : str;
    }
};
// 像素翻转
class Transform
{
public:
    vector<vector<int>> transformImage(vector<vector<int>> mat, int n)
    {
        // write code here
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

// 清除行列
class Clearer
{
public:
    vector<vector<int>> clearZero(vector<vector<int>> mat, int n)
    {
        // write code here
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

// 翻转子串
class ReverseEqual
{
public:
    bool checkReverseEqual(string s1, string s2)
    {
        // write code here
        int size1 = s1.size();
        int size2 = s2.size();
        if (!size1 || !size2)
        {
            return false;
        }
        string str = s1 + s1;
        if (str.find(s2) == -1)
        {
            return false;
        }
        return true;
    }
};
// 访问单个节点的删除

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Remove
{
public:
    bool removeNode(ListNode *pNode)
    {
        // write code here
        if (!pNode || !pNode->next)
            return false;
        pNode->val = pNode->next->val;
        auto tmp = pNode->next;
        pNode->next = pNode->next->next;
        delete tmp;
        return true;
    }
};

// 链表分割

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Partition
{
public:
    ListNode *partition(ListNode *pHead, int x)
    {
        // write code here
        if (!pHead)
            return nullptr;

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
            cur = cur->next;
        }
        pb->next = nullptr;
        ps->next = bigList->next;
        pHead = smallList->next;
        delete smallList;
        delete bigList;
        return pHead;
    }
};

// 链式A+B

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Plus
{
public:
    ListNode *plusAB(ListNode *a, ListNode *b)
    {
        // write code here
        auto head = new ListNode(-1);
        auto pa = a, pb = b, p = head;
        int c = 0, sum, val1, val2;
        while (pa || pb || c)
        {
            val1 = (pa ? pa->val : 0);
            val2 = (pb ? pb->val : 0);
            sum = val1 + val2 + c;
            c = sum / 10;
            auto node = new ListNode(sum % 10);

            p->next = node;
            p = node;
            pa = (pa ? pa->next : pa);
            pb = (pb ? pb->next : pb);
        }
        auto tmp = head->next;
        delete head;
        return tmp;
    }
};
//**************************************************************************************************
// 回文链表

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Palindrome
{
public:
    bool isPalindrome(ListNode *pHead)
    {
        // write code here
        if (!pHead)
            return true;
        static ListNode *p = nullptr;
        if (!p)
        {
            p = pHead;
        }
        if (isPalindrome(pHead->next) && (p->val == pHead->val))
        {
            p = p->next;
            return true;
        }
        p = nullptr;
        return false;
    }
};

// 集合栈

class SetOfStacks
{
public:
    vector<vector<int>> setOfStacks(vector<vector<int>> ope, int size)
    {
        // write code here
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
                    tmp.pop_back();
                else if (st.size())
                {
                    tmp = st.back();
                    tmp.pop_back();
                    st.pop_back();
                }
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

// 双栈排序
class TwoStacks
{
public:
    vector<int> twoStacksSort(vector<int> numbers)
    {
        // write code here
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

// 猫狗收容所

class CatDogAsylum
{
public:
    vector<int> asylum(vector<vector<int>> ope)
    {
        // write code here
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
                    dog.push(make_pair(op[1], uuid++));
                else
                    cat.push(make_pair(op[1], uuid++));
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
            }
        }
        return res;
    }
};
// 二叉树平衡检查

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL)
    {
    }
};

class Balance
{
public:
    bool isBalance(TreeNode *root)
    {
        // write code here
        return getdep(root) != -1;
    }

    int getdep(TreeNode *root)
    {
        if (!root)
            return 0;
        auto left = getdep(root->left);
        auto right = getdep(root->right);
        if (left == -1 || right == -1)
            return -1;
        return abs(left - right) > 1 ? -1 : max(left, right) + 1;
    }
};

// 有向路径检查

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
        // write code here
        return check(a, b) || check(b, a);
    }
    bool check(UndirectedGraphNode *a, UndirectedGraphNode *b)
    {
        if (a == nullptr || b == nullptr)
            return false;
        if (a == b)
            return true;
        if (a->label == -1)
            return false;

        a->label = -1;
        for (int i = 0; i < a->neighbors.size(); i++)
        {
            if (check(a->neighbors[i], b))
                return true;
        }
        return false;
    }
};

// 高度最小的BST
class MinimalBST
{
public:
    int buildMinimalBST(vector<int> vals)
    {
        int height = 0; //初始化
        buildMinimalBST(vals, 0, vals.size() - 1, height);
        return height;
    }
    TreeNode *buildMinimalBST(vector<int> vals, int start, int end, int &height)
    {
        if (start > end)
        { //递归终止条件
            height = 0;
            return NULL;
        }
        int mid = start + (end - start) / 2;
        TreeNode *root = new TreeNode(vals[mid]);                 //根节点
        int left, right;                                          //左右子树
        root->left = buildMinimalBST(vals, start, mid - 1, left); //左子树
        root->right = buildMinimalBST(vals, mid + 1, end, right); //右子树
        height = (left >= right ? left : right) + 1;              //计算当前高度
        return root;
    }
};

// 输出单层结点

/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class TreeLevel
{
    ListNode *ln = new ListNode(-1);
    ListNode *p = ln;

public:
    ListNode *getTreeLevel(TreeNode *root, int dep)
    {
        // write code here
        if (root == nullptr || dep <= 0)
            return nullptr;
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

// 检查是否为BST

/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/

class Checker
{
public:
    bool checkBST(TreeNode *root)
    {
        // write code here
        return method2(root, INT_MIN, INT_MAX);
    }
    bool method2(TreeNode *root, int min, int max)
    {
        if (root == NULL)
            return true;
        if (root->val < min || root->val > max)
            return false;
        return method2(root->left, min, root->val) && method2(root->right, root->val, max);
    }
};

// 寻找下一个结点
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/

class Successor
{
public:
    int findSucc(TreeNode *root, int p)
    {
        // write code here
        bool sign = 0;
        return findSucc1(root, p, sign);
    }
    int findSucc1(TreeNode *root, int p, bool &sign)
    {
        if (root == NULL)
            return -1;
        int left = findSucc1(root->left, p, sign);
        if (left != -1)
            return left;
        if (sign == true)
            return root->val;
        if (root->val == p)
            sign = true;
        return findSucc1(root->right, p, sign);
    }
};

// 最近公共祖先
class LCA
{
public:
    int getLCA(int a, int b)
    {
        // write code here
        while (a != b)
        {
            if (a > b)
                a /= 2;
            else
                b /= 2;
        }
        return a;
    }
};

//****************************************************************
// 二进制插入

class BinInsert
{
public:
    int binInsert(int n, int m, int j, int i)
    {
        // write code here
        m <<= j;
        return n | m;
    }
};

// 二进制小数

class BinDecimal
{
public:
    string printBin(double num)
    {
        // write code here
        string str("0.");
        double base = 0.5;
        while (num > 0)
        {
            if (num >= base)
            {
                num -= base;
                str += "1";
            } //if
            else
            {
                str += "0";
            } //else
            base /= 2;
            if (str.size() > 32)
            {
                str = "Error";
                break;
            } //if
        }     //while
        return str;
    }
};

// 最接近的数
class CloseNumber
{
public:
    vector<int> getCloseNumber(int x)
    {
        // write code here
        vector<int> result;
        int c01 = 0; //拖尾0的个数
        int c11 = 0; //拖尾0左方全为1的个数

        int c1 = 0;       //拖尾1的个数
        int c0 = 0;       //拖尾1左方全为0的位个数
        int c = x, d = x; //临时变量
                          //分别求取
        while (((c & 1) == 0) && (c != 0))
        {
            c01++;
            c >>= 1;
        }
        while ((c & 1) == 1)
        {
            c11++;
            c >>= 1;
        }
        while ((d & 1) == 1)
        {
            c1++;
            d >>= 1;
        }
        while (((d & 1) == 0) && (d != 0))
        {
            c0++;
            d >>= 1;
        }

        result.push_back((x - (1 << (c1)) - (1 << (c0 - 1)) + 1));
        result.push_back((x + (1 << (c11 - 1)) + (1 << c01) - 1));
        return result;
    }
};

// 整数转化
class Transform
{
public:
    int calcCost(int A, int B)
    {
        // write code here
        int res = A ^ B;
        int count = 0;
        while (res != 0)
        {
            count++;
            //去掉最后一位的1 例如 1111 & （1111-1） = 1110 将最后一位1 去掉
            res &= (res - 1);
        }
        return count;
    }
};

// 奇偶位交换
class Exchange
{
public:
    int exchangeOddEven(int x)
    {
        // write code here
        int oddVal = (x & 0xAAAAAAAA);  // bit 1 3 5 ... 31
        int evenVal = (x & 0x55555555); // bit 0 2 4 ... 30
        return (oddVal >> 1) + (evenVal << 1);
    }
};

// 找出缺失的整数

class Finder
{
public:
    int findMissing(vector<vector<int>> numbers, int n)
    {
        // write code here
        for (int i = 0; i < n; i++)
            if (i % 2 != numbers[i][0])
                return i;
        return n;
    }
};

// 像素设定

class Render
{
public:
    vector<int> renderPixel(vector<int> screen, int x, int y)
    {
        // write code here
        for (int i = x; i <= y; i++)
        {
            int k = i % 8;
            int t = i / 8;
            screen[t] = screen[t] | (1 << k);
        }

        return screen;
    }
};

// 碰撞的蚂蚁

class Ants
{
public:
    double antsCollision(int n)
    {
        // write code here
        return (1.0 - (1.0 / (1 << (n - 1))));
    }
};

// 判断直线相交
class CrossLine
{
public:
    bool checkCrossLine(double s1, double s2, double y1, double y2)
    {
        // write code here
        return s1 != s2 || y1 == y2;
    }
};

// 加法运算替代

class AddSubstitution
{
public:
    int calc(int a, int b, int type)
    {
        // write code here
        int res = 0;
        int count = 0;
        int tmp = 0;
        switch (type)
        {
        case 1:
            tmp = 0;
            for (int i = 0; i < b; i++)
            {
                tmp += a;
            }
            res = tmp;
            break;
        case 0:
            tmp = a;
            count = 0;
            while (tmp > 0 && tmp >= b)
            {
                tmp = tmp + (~b) + 1;
                count++;
            }
            res = count;
            break;
        case -1:
            res = a + (~b) + 1;
            break;
        }
        return res;
    }
};

// 平分的直线

struct Point
{
    int x;
    int y;
    Point() : x(0), y(0)
    {
    }
    Point(int xx, int yy)
    {
        x = xx;
        y = yy;
    }
};
class Bipartition
{
public:
    vector<double> getBipartition(vector<Point> A, vector<Point> B)
    {
        // write code here
        double x1 = (A[0].x + A[2].x) / 2; //第一个中心点横坐标
        double x2 = (B[0].x + B[2].x) / 2;
        double y1 = (A[0].y + A[2].y) / 2; //第一个中心点纵坐标
        double y2 = (B[0].y + B[2].y) / 2;

        double s = (y1 - y2) / (x1 - x2); //斜率
        double y = y1 - s * x1;           //截距，也可以代入第二个中心点计算

        vector<double> ans;
        ans.emplace_back(s);
        ans.emplace_back(y);
        return ans; //返回结果
    }
};

// 穿点最多的直线
/*
struct Point {
    int x;
    int y;
    Point() :
            x(0), y(0) {
    }
    Point(int xx, int yy) {
        x = xx;
        y = yy;
    }
};*/
class DenseLine
{
public:
    vector<double> getLine(vector<Point> p, int n)
    {
        // write code here
        map<pair<double, double>, int> lines;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                ++lines[calLine(p[i], p[j])];
            }
        }
        auto it = lines.begin();
        auto maxLine = it;
        int max = 0;
        while (it != lines.end())
        {
            if (it->second > max)
                maxLine = it;
            it++;
        }
        vector<double> res;
        res.push_back(maxLine->first.first);
        res.push_back(maxLine->first.second);
        return res;
    }

    //计算斜率
    pair<double, double> calLine(Point p1, Point p2)
    {
        double k = (double)(p1.y - p2.y) / (double)(p1.x - p2.x);
        double s = (double)p1.y - (double)k * p1.x;
        return make_pair(k, s);
    }
};

// 第k个数
class KthNumber
{
public:
    int findKth(int k)
    {
        // write code here
        if (k < 1)
            return 0;
        vector<int> nums(k + 1);
        nums[0] = 1;
        int n3 = 0;
        int n5 = 0;
        int n7 = 0;
        int index = 0;
        while (index < k)
        {
            index++;
            nums[index] = min(nums[n3] * 3, min(nums[n5] * 5, nums[n7] * 7));
            if (nums[n3] * 3 == nums[index])
                n3++;
            if (nums[n5] * 5 == nums[index])
                n5++;
            if (nums[n7] * 7 == nums[index])
                n7++;
        }
        return nums[index];
    }
};

// 上楼梯

class GoUpstairs
{
public:
    int countWays(int n)
    {
        // write code here
        if (n < 0)
            return 0;
        if (n < 2)
            return n;
        if (n == 3)
            return 4;
        int a = 1;
        int b = 2;
        int c = 4;
        for (int i = 4; i <= n; i++)
        {
            int temp = ((a + b) % 1000000007 + c) % 1000000007;
            a = b;
            b = c;
            c = temp;
        }
        return c;
    }
};

// 机器人走方格I
class Robot
{
public:
    int countWays(int x, int y)
    {
        // write code here
        if (x <= 0 || y <= 0)
            return 0;
        if (x == 1 || y == 1)
            return 1;
        return countWays(x - 1, y) + countWays(x, y - 1);
    }
};

// 机器人走方格II
class Robot
{
public:
    int countWays(vector<vector<int>> map, int x, int y)
    {
        // write code here
        vector<int> dp(y);
        const int Mod = 1000000007;
        dp[0] = 1;
        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                if (map[i][j] != 1)
                    dp[j] = 0;
                else if (j > 0)
                    dp[j] = dp[j] % Mod + dp[j - 1] % Mod;
            }
        }
        return dp[y - 1] % Mod;
    }
};

// 魔术索引I
class MagicIndex
{
public:
    bool findMagicIndex(vector<int> A, int n)
    {
        // write code here
        int i = 0, j = n - 1, m;
        do
        {
            m = (i + j) >> 1;
            if (A[m] > m)
            {
                j = m - 1;
            }
            else if (A[m] < m)
            {
                i = m + 1;
            }
            else
            {
                return true;
            }
        } while (i <= j);

        return false;
    }
};

// 魔术索引II
class MagicIndex
{
public:
    bool findMagicIndex(vector<int> A, int n)
    {
        // write code here
        if (0 == n)
            return true;
        int i;
        for (i = 0; i < n;)
        {
            if (A[i] == i)
                return true;
            else if (A[i] < i)
                i++;
            else
                i = A[i];
        }
        return false;
    }
};

// 集合的子集

class Subset
{
public:
    vector<vector<int>> getSubsets(vector<int> A, int n)
    {
        // write code here
        sort(A.begin(), A.end());
        int size = 1 << n;
        vector<vector<int>> subsets;
        for (int i = size - 1; i > 0; --i)
        {
            vector<int> subset;
            for (int j = n - 1; j >= 0; --j)
            {
                if ((i >> j) & 1)
                {
                    subset.push_back(A[j]);
                }
            }
            subsets.push_back(subset);
        }
        return subsets;
    }
};

// 字符串排列
class Permutation
{
public:
    vector<string> getPermutation(string A)
    {
        vector<string> res;
        if (A.size() == 0)
            return res;
        permutation(A, res, 0);
        sort(res.begin(), res.end(), greater<string>()); //排序
        return res;
    }

    void permutation(string A, vector<string> &res, int cur)
    {
        int len = A.size();
        if (cur == len - 1)
        { //到最后一个字符，就插入结果
            res.push_back(A);
            return;
        }
        for (int i = cur; i < len; ++i)
        {
            swap(A[i], A[cur]);           //交换元素
            permutation(A, res, cur + 1); //递归调用
            swap(A[i], A[cur]);           //换回来
        }
    }
};

// 合法括号序列判断
class Parenthesis
{
public:
    bool chkParenthesis(string A, int n)
    {
        // write code here
        if (n % 2 == 1) //先排除奇数情况
            return false;
        stack<char> s1;
        for (int i = 0; i < A.size(); i++)
        {
            if (A[i] == '(')
                s1.push(A[i]);
            else if (A[i] == ')')
            {
                if (s1.empty())
                    return false;
                s1.top();
            }
            else
                return false;
        }
        if (s1.empty())
            return true;
    }
};

// 洪水
class Flood
{
public:
    struct P
    {
        int x, y, t;
        P(int x, int y, int t) : x(x), y(y), t(t) {}
    };
    int floodFill(vector<vector<int>> map, int n, int m)
    {
        bool vis[n][m];
        memset(vis, false, sizeof(vis));
        int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        queue<P> q;
        q.push(P(0, 0, 0));
        while (!q.empty())
        {
            P p = q.front();
            q.pop();
            if (p.x == n - 1 && p.y == m - 1)
                return p.t;
            vis[p.x][p.y] = true;
            for (int i = 0; i < 4; i++)
            {
                int x = p.x + dir[i][0];
                int y = p.y + dir[i][1];
                int t = p.t + 1;
                if (x >= 0 && x < n && y >= 0 && y < m && map[x][y] == 0 && !vis[x][y])
                    q.push(P(x, y, t));
            }
        }
        return -1;
    }
};

// 硬币表示
class Coins
{
public:
    int countWays(int n)
    {
        // write code here
        int coins[4] = {1, 5, 10, 25};
        int dp[100001] = {0};
        dp[0] = 1;
        for (int i = 0; i < 4; ++i)
        {
            for (int j = coins[i]; j <= n; ++j)
            {
                dp[j] = (dp[j] + dp[j - coins[i]]) % 1000000007;
            }
        }
        return dp[n];
    }
};

// n皇后问题
class Queens
{
public:
    int nQueens(int n)
    {
        // write code here
        upperlim = (1 << n) - 1;
        test(0, 0, 0);
        return Ans;
    }

    int Ans = 0;
    int upperlim;

    void test(int row, int ld, int rd)
    {
        int pos, p;
        if (row != upperlim)
        {
            pos = upperlim & (~(row | ld | rd));
            while (pos)
            {
                p = pos & (~pos + 1);
                pos = pos - p;
                test(row | p, (ld | p) << 1, (rd | p) >> 1);
            }
        }
        else
            ++Ans;
    }
};

// 堆箱子
class Box
{
    int f[501] = {0}; //存放n个箱子的最大上升高度
public:
    int getHeight(vector<int> w, vector<int> l, vector<int> h, int n)
    {

        for (int i = w.size() - 1; i > 0; i--)
        {
            for (int j = w.size() - 1; j > w.size() - 1 - i; j--)
            {
                if (w[j] >= w[j - 1] /*&& l[j] >= l[j-1]*/)
                {
                    swap(w[j], w[j - 1]);
                    swap(l[j], l[j - 1]);
                    swap(h[j], h[j - 1]);
                }
            }
        }
        f[0] = h[0];
        int maxv = f[0];
        for (int i = 1; i < n; i++)
        {
            f[i] = h[i];
            int tmax = 0;
            for (int j = i - 1; j >= 0; j--)
            {
                if (w[i] < w[j] && l[i] < l[j])
                {
                    tmax = max(tmax, f[j]);
                }
            }
            f[i] += (tmax);
            maxv = max(maxv, f[i]);
        }
        return maxv;
    }
};

// 约瑟夫问题I
class Joseph
{
public:
    int getResult(int n, int m)
    {
        if (n <= 0 || m <= 0)
            return -1;
        int s = 0;
        for (int i = 2; i <= n; i++)
            s = (s + m) % i;
        return s + 1;
    }
};

// 约瑟夫问题II
class Joseph
{
public:
    int getResult(int n)
    {
        // write code here
        return ysf(n, 2);
    }

    int ysf(int n, int m)
    {
        int tmp = n % m == 0 ? n / m : n / m + 1;
        if (tmp <= m + 1)
        {
            return (tmp - 1) * m + 1; //终止条件
        }
        int path = ysf(tmp, m + 1); //m+1次时最后一人编号的位置
        return (path - 2) * m + 1;
    }
};

// 变位词排序
class SortString
{
public:
    vector<string> sortStrings(vector<string> str, int n)
    {
        // write code here
        vector<string> res;
        sort(str.begin(), str.end());
        set<string> set;
        for (const string &s : str)
        {
            string temp(s);
            sort(temp.begin(), temp.end());
            if (set.count(temp) == 0)
            {
                set.insert(temp);
                res.push_back(s);
            }
        }
        return res;
    }
};

// 元素查找
class Finder
{
public:
    int findElement(vector<int> A, int n, int x)
    {
        // write code here
        int i = 0, j = n - 1, mid;
        while (i <= j)
        {
            mid = (i + j) / 2;
            if (A[mid] == x)
                return mid;
            if (A[mid] < x)
            {
                if (A[mid] < A[i] && x > A[j])
                    j = mid - 1;
                else
                    i = mid + 1;
            }
            else
            {
                if (A[mid] > A[i] && x < A[i])
                    i = mid + 1;
                else
                    j = mid - 1;
            }
        }
        return -1;
    }
};

// 找出字符串
class Finder
{
public:
    int findString(vector<string> str, int n, string x)
    {
        // write code here
        int l = 0, r = str.size() - 1, m = 0;
        while (l <= r)
        {
            while (str[l] == "" && l < r)
                l++;
            while (str[r] == "" && l < r)
                r--;
            m = (l + r) >> 1;
            if (str[m] == x)
                return m;
            while (str[m] == "" && l < r)
                m--;
            if (str[m] > x)
                r = m - 1;
            else
                l = m + 1;
        }
        return -1;
    }
};

// 矩阵元素查找
class Finder
{
public:
    vector<int> findElement(vector<vector<int>> matrix, int row, int col, int x)
    {
        // write code here
        vector<int> result;
        if (row == 0 || col == 0)
        {
            return result;
        } //if
        int i = 0, j = col - 1;
        while (i < row && j >= 0)
        {
            // 大于目标 剔除这个数字所在的列
            if (matrix[i][j] > x)
            {
                --j;
            } //if
            // 小于目标 剔除这个数字所在的行
            else if (matrix[i][j] < x)
            {
                ++i;
            } //else
            else
            {
                result.push_back(i);
                result.push_back(j);
                return result;
            } //else
        }     //while
        return result;
    }
};

// 叠罗汉I
class Stack
{
public:
    int getHeight(vector<int> men, int n)
    {
        // write code here
        vector<int> ret(n, 1);
        ret[0] = 1;
        int maxlen = 1;
        for (int i = 1; i < n; i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (men[i] > men[j])
                    ret[i] = max(ret[i], ret[j] + 1);
            }
            maxlen = max(ret[i], maxlen);
        }
        return maxlen;
    }
};

// 叠罗汉II
class Stack
{
public:
    int getHeight(vector<vector<int>> actors, int n)
    {
        // write code here
        int Max = 0, dp[n];
        memset(dp, 0, sizeof(dp));
        sort(actors.begin(), actors.end(), cmp);
        dp[0] = 1;
        for (int i = 1; i < n; i++)
        {
            int t = 0;
            for (int j = 0; j < i; j++)
                if (actors[i][1] > actors[j][1])
                    t = max(t, dp[j]);
            dp[i] = t + 1;
            Max = max(Max, dp[i]);
        }
        return Max;
    }

    static bool cmp(vector<int> a, vector<int> b)
    {
        return a[0] < b[0];
    }
};

// 维护x的秩

class Rank
{
public:
    vector<int> getRankOfNumber(vector<int> A, int n)
    {
        // write code here
        multiset<int>::iterator iter;
        vector<int> result;
        multiset<int> set;
        for (int i = 0; i < n; ++i)
        {
            set.insert(A[i]);
            iter = set.upper_bound(A[i]);
            int len = 0;
            multiset<int>::iterator cur = set.begin();
            while (cur != iter)
            {
                len++;
                cur++;
            }
            result.push_back(len - 1);
        }
        return result;
    }
};

// 数组中的逆序对
class AntiOrder
{
public:
    int count(vector<int> A, int n)
    {
        // write code here
        int ret = 0;
        multiset<int> mset;
        multiset<int>::iterator cur, end;

        for (int i = 0; i < n; i++)
        {
            mset.insert(A[i]);
            cur = mset.upper_bound(A[i]);
            end = mset.end();
            while (cur != end)
            {
                ret++;
                cur++;
            }
        }

        return ret;
    }
};

// 无缓存交换
class Exchange
{
public:
    vector<int> exchangeAB(vector<int> AB)
    {
        // write code here
        AB[0] = AB[0] ^ AB[1];
        AB[1] = AB[0] ^ AB[1];
        AB[0] = AB[0] ^ AB[1];
        return AB;
    }
};

// 井字棋
class Board
{
public:
    bool checkWon(vector<vector<int>> board)
    {
        // write code here
        if (board[0][0] + board[1][1] + board[2][2] == 3)
            return true;
        if (board[0][2] + board[1][1] + board[2][0] == 3)
            return true;
        for (int i = 0; i < 3; i++)
        {
            if (board[i][0] + board[i][1] + board[i][2] == 3)
                return true;
            if (board[0][i] + board[1][i] + board[2][i] == 3)
                return true;
        }
        return false;
    }
};
// 无判断max

class Max
{
public:
    int getMax(int a, int b)
    {
        // write code here
        b = a - b;          //此时b>>31为1则b小于0即a<b,若b>>31为0 则a>b
        a -= b & (b >> 31); //若a< a=a-(a-b),若a>b a=a-0
        return a;
    }
};

// 珠玑妙算

class Result
{
public:
    vector<int> calcResult(string A, string guess)
    {
        // write code here
        vector<int> res(2, 0);
        for (int i = 0; i < 4; ++i)
        {
            if (A[i] == guess[i])
            {
                res[0]++;
                A[i] = '0';
                guess[i] = '0';
            }
        }
        for (int i = 0; i < 4; ++i)
        {
            if (guess[i] == '0')
                continue;
            for (int j = 0; j < 4; ++j)
            {
                if (guess[i] == A[j])
                {
                    res[1]++;
                    A[j] = '0';
                    break;
                }
            }
        }
        return res;
    }
};
// 阶乘尾零
class Factor
{
public:
    int getFactorSuffixZero(int n)
    {
        // write code here
        if (n < 5)
            return 0;
        int count = 0;
        for (int i = 5; n / i > 0; i *= 5)
            count += n / i;
        return count;
    }
};

// 最小调整有序
class Rearrange
{
public:
    vector<int> findSegment(vector<int> A, int n)
    {
        // write code here

        vector<int> vec(A);
        sort(vec.begin(), vec.end());
        int start = 0, end = 0;
        bool turn = false, first = true;

        for (int i = 0; i < A.size(); ++i)
        {
            if (A[i] != vec[i])
            {
                start = i;
                break;
            }
        }
        for (int i = A.size() - 1; i >= 0; --i)
        {
            if (A[i] != vec[i])
            {
                end = i;
                break;
            }
        }
        vector<int> result;
        result.push_back(start);
        result.push_back(end);
        return result;
    }
};

// 数字发音
vector<string> digits = {"One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
vector<string> teens = {"Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
vector<string> tens = {"Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
vector<string> bigs = {"", "Thousand", "Million"};

class ToString
{
public:
    string numToString100(int number)
    {
        string str = "";

        /*转换百位数的地方*/
        if (number >= 100)
        {
            str += digits[number / 100 - 1] + " Hundred ";
            number %= 100;
        }

        //转换十位数的地方
        if (number >= 11 && number <= 19)
        {
            return str += teens[number - 11] + " ";
        }
        else if (number == 10 || number >= 20)
        {
            str += tens[number / 10 - 1] + " ";
            number %= 10;
        }

        //转换个位的地方
        if (number >= 1 && number <= 9)
        {
            str += digits[number - 1] + " ";
        }
        return str;
    }

    void removeLastSpace(string &str)
    {
        if (str[str.length() - 1] == ' ')
            str.erase(str.length() - 1, str.length());
    }
    string toString(int x)
    {
        // write code here
        if (x == 0)
            return "zero";
        else if (x < 0)
            return "Negative" + toString(abs(x));

        int count = 0;
        string str = "";

        while (x > 0)
        {
            //这句话很关键，处理1000的发音
            //前面+一个函数处理100以下的数字发音
            if (x % 1000 != 0)
            {
                if (str != "")
                    str = numToString100(x % 1000) + bigs[count] + "," + str;
                else
                    str = numToString100(x % 1000) + bigs[count];
            }
            x /= 1000;
            count++;
        }
        removeLastSpace(str);
        return str;
    }
};

// 最大连续数列和

class MaxSum
{
public:
    int getMaxSum(vector<int> A, int n)
    {
        // write code here
        int dp0 = A[0], max = A[0];
        for (int i = 1; i < n; i++)
        {
            if (dp0 + A[i] > A[i])
                dp0 = dp0 + A[i];
            else
                dp0 = A[i];
            if (dp0 > max)
                max = dp0;
        }
        return max;
    }
};

// 词频统计
class Frequency
{
public:
    int getFrequency(vector<string> article, int n, string word)
    {
        // write code here
        unordered_map<string, int> hashtable;
        for (int i = 0; i < n; i++)
        {
            hashtable[article[i]]++;
        }

        return hashtable[word];
    }
};

// 整数对查找
class FindPair
{
public:
    int countPairs(vector<int> A, int n, int sum)
    {
        // write code here
        unordered_map<int, int> cnt;
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            int want = sum - A[i];
            ans += cnt[want];
            cnt[A[i]]++;
        }
        return ans;
    }
};
// 树转链表

/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Converter
{
public:
    ListNode *treeToList(TreeNode *root)
    {
        // write code here
        ListNode *result = new ListNode(-1);
        ListNode *move = result;
        midErgodic(root, move);
        return result->next;
    }

    void midErgodic(TreeNode *&node, ListNode *&preNode)
    {
        if (node == NULL)
        {
            return;
        }
        midErgodic(node->left, preNode);
        preNode->next = new ListNode(node->val);
        preNode = preNode->next;
        midErgodic(node->right, preNode);
    }
};

// 另类加法
class UnusualAdd
{
public:
    int addAB(int A, int B)
    {
        // write code here
        return B ? addAB(A ^ B, (A & B) << 1) : A;
    }
};

// 2的个数
class Count2
{
public:
    int countNumberOf2s(int n)
    {
        // write code here
        if (n <= 1)
            return 0;

        long res = 0, m;
        for (m = 1; m <= n; m *= 10)
        {
            int tmp1 = n / m, tmp2 = n % m;

            res += (tmp1 + 7) / 10 * m + (tmp1 % 10 == 2) * (tmp2 + 1);
        }
        return res;
    }
};

// 下一个较大元素
class NextElement
{
public:
    vector<int> findNext(vector<int> A, int n)
    {
        // write code here
        vector<int> result(n, -1);
        stack<int> sta;
        for (int i = 0; i < n; i++)
        {
            while (!sta.empty())
            {
                if (A[i] <= A[sta.top()])
                {
                    break;
                }
                else
                {
                    result[sta.top()] = A[i];
                    sta.pop();
                }
            }
            sta.push(i);
        }
        return result;
    }
};

// 下一个较大元素II
class NextElement
{
public:
    vector<int> findNext(vector<int> A, int n)
    {
        // write code here
        set<int> ss;
        vector<int> result;
        for (int i = n - 1; i >= 0; --i)
        {
            auto pos = ss.lower_bound(A[i]);
            if (pos != ss.end() && *pos == A[i])
                ++pos;

            if (pos == ss.end())
            {
                result.push_back(-1);
            }
            else
            {
                result.push_back(*pos);
            }
            ss.insert(A[i]);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

// 单词最近距离
class Distance
{
public:
    int getDistance(vector<string> article, int n, string x, string y)
    {
        // write code here
        if (n <= 0)
            return -1;
        int mindis = n;
        int point = -1;
        for (int i = 0; i < n; i++)
        {
            if (article[i] == x || article[i] == y)
            {
                if (point != -1 && article[i] != article[point] && mindis > i - point)
                    mindis = i - point;
                point = i;
            }
        }
        return mindis;
    }
};

// 最长合成字符串
class LongestString
{
public:
    static bool cmp(string a, string b)
    {
        return a.size() < b.size();
    }
    int getLongest(vector<string> str, int n)
    {
        // write code here
        sort(str.begin(), str.end(), cmp);
        for (int i = n - 1; i >= 0; i--)
        {
            string t = str[i];
            int x;
            for (int j = i - 1; j >= 0; j--)
                while ((x = t.find(str[j])) != -1)
                    t.erase(x, str[j].size());
            if (t.empty())
                return str[i].size();
        }
        return -1;
    }
};

// 子串判断
class Substr
{
public:
    vector<bool> chkSubStr(vector<string> p, int n, string s)
    {
        // write code here
        vector<bool> result;
        for (int i = 0; i < n; ++i)
        {
            if (s.find(p[i]) != -1)
            {
                result.push_back(true);
            } //if
            else
            {
                result.push_back(false);
            } //else
        }     //for
        return result;
    }
};

// 实时中位数
class Middle
{
public:
    vector<int> getMiddle(vector<int> A, int n)
    {
        // write code here
        priority_queue<int, vector<int>, less<int>> small;
        priority_queue<int, vector<int>, greater<int>> big;
        vector<int> ans;

        for (int i = 0; i < A.size(); ++i)
        {
            if (small.empty() || A[i] <= small.top())
                small.push(A[i]);
            else
                big.push(A[i]);
            if (small.size() == big.size() + 2)
            {
                big.push(small.top());
                small.pop();
            }
            else if (small.size() == big.size() - 1)
            {
                small.push(big.top());
                big.pop();
            }
            ans.push_back(small.top());
        }
        return ans;
    }
};

// 字符串变换
class Change
{
public:
    int countChanges(vector<string> dic, int n, string s, string t)
    {
        // write code here
        if (s == t)
            return 0;
        return BFS(dic, s, t);
    }

    int BFS(vector<string> dic, string s, string e)
    {
        if (s == e)
            return 0;
        queue<pair<string, int>> q;
        q.push(make_pair(s, 0));
        vector<string> v;
        v.push_back(s);
        while (!q.empty())
        {
            pair<string, int> p = q.front();
            q.pop();
            string w = p.first;
            int n = w.length();
            for (int i = 0; i < n; i++)
            {
                string t(w);
                for (int j = 0; j < 26; j++)
                {
                    t[i] = 'a' + j;
                    if (t == e)
                        return p.second + 1;
                    if (find(dic.begin(), dic.end(), t) != dic.end() && find(v.begin(), v.end(), t) == v.end())
                    {
                        v.push_back(t);
                        q.push(make_pair(t, p.second + 1));
                    }
                }
            }
        }
        return -1;
    }
};

// 最大子方阵
class SubMatrix
{
public:
    int maxSubMatrix(vector<vector<int>> mat, int n)
    {
        // write code here
        int maxLen = 1;
        for (int i = 0; i < n - maxLen; ++i)
        {
            for (int j = 0; j < n - maxLen; ++j)
            {
                for (int k = maxLen + 1; max(i, j) + k - 1 < n; ++k)
                {
                    if (checkRec(mat, i, j, k))
                        maxLen = max(maxLen, k);
                }
            }
        }

        return maxLen;
    }

    bool checkRec(vector<vector<int>> &mat, int x, int y, int len)
    {
        int digit = mat[x][y];
        for (int i = 0; i < len; ++i)
            if (mat[x + i][y] != digit || mat[x + i][y + len - 1] != digit)
                return false;
        for (int j = 0; j < len; ++j)
            if (mat[x][y + j] != digit || mat[x + len - 1][y + j] != digit)
                return false;
        return true;
    }
};

// 最大和子矩阵
class SubMatrix
{
public:
    int sumOfSubMatrix(vector<vector<int>> mat, int n)
    {
        // write code here
        if (n <= 0)
            return 0;
        int maxVal = 0xffffffff;
        for (int i = 0; i < n; i++)
        {
            vector<int> temp(mat[i]);
            maxVal = max(maxVal, helper(temp)); //得到第一行的最大和
            for (int j = i + 1; j < n; j++)     //循环下面的n-1行
            {
                for (int k = 0; k < n; k++) //将行的n个元素加到上一行，然后计算最大和
                {
                    temp[k] += mat[j][k];
                }
                maxVal = max(maxVal, helper(temp)); //依次0~k行的最大和
            }
        }
        return maxVal;
    }
    //求连续数组最大和，动态规划思想
    int helper(vector<int> &vec) //求一维数组最大和
    {
        int f = vec[0];
        int result = f;
        for (int i = 1; i < vec.size(); i++)
        {
            f = max(f + vec[i], vec[i]);
            result = max(result, f);
        }
        return result;
    }
};

// 最大字母矩阵
class AlphaMatrix
{
public:
    int findAlphaMatrix(vector<string> dic, int n)
    {
        // write code here
        map<string, int> mapp;
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            mapp[dic[i]]++;
            int t = dic[i].length() * mapp[dic[i]];
            res = max(res, t);
        }
        return res;
    }
};