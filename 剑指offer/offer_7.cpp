#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

//切绳子
class Solution1
{
    int cutRope(int number)
    {
        int max = 1;
        if (number <= 3)
        {
            return number - 1;
        }

        while (number > 4)
        {
            number -= 3;
            max *= 3;
        }
        return number * max;
    }
};

//排序树第k小的节点
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

//机器人走格子
class Solution3
{
    int movingCount(int threshild, int rows, int cols)
    {
        if (threshild <= 0 || rows <= 0 || cols <= 0)
        {
            return 0;
        }

        vector<bool> flag(rows * cols, false);
        int res = robot_dfs(threshild, rows, cols, flag, 0, 0);
        return res;
    }

    int robot_dfs(int k, int rows, int cols, vector<bool> &flag, int i, int j)
    {
        int index = i * cols + j;
        if (i < 0 || i >= rows || j < 0 || j >= cols || getSum(i) + getSum(j) > k || flag[index])
        {
            return 0;
        }

        flag[index] = true;

        return 1 + robot_dfs(k, rows, cols, flag, i + 1, j) + robot_dfs(k, rows, cols, flag, i - 1, j) + robot_dfs(k, rows, cols, flag, i, j + 1) + robot_dfs(k, rows, cols, flag, i, j - 1);
    }

    int getSum(int n)
    {
        int sum = 0;
        while (n > 0)
        {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
};

//矩阵查找字符串
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
        if (i < 0 || i >= rows || j < 0 || j >= cols || str[k] != matrix[index] || flag[index])
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

//滑动窗口
class Solution5
{
    vector<int> maxInWindwos(vector<int> &num, unsigned size)
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
            if (size && i + 1 >= size)
            {
                res.emplace_back(i);
            }
        }

        return res;
    }
};

//数据流中位数
class Solution6
{
    priority_queue<int, vector<int>, less<int>> q;
    priority_queue<int, vector<int>, greater<int>> p;

    void Insert(int num)
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
        return (p.size() == q.size()) ? (p.top() + q.top()) / 2.0 : q.top();
    }
};

//序列化二叉树
class Solution7
{
    vector<int> buf;

    char *Serialize(TreeNode *root)
    {
        buf.clear();
        dfsTree(root);
        int *res = new int[buf.size()];
        for (int i = 0; i < buf.size(); i++)
        {
            res[i] = buf[i];
        }

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
    }

    TreeNode *dfsTree(int *&p)
    {
        if (*p == '#')
        {
            return nullptr;
        }

        TreeNode *root = new TreeNode(*p);
        p++;
        root->left = dfsTree(p);
        root->right = dfsTree(p);
        return root;
    }
};

//从上到下打印二叉树
class Solution8
{
    vector<vector<int>> printTree;

    vector<vector<int>> Print(TreeNode *root)
    {
        printTree.clear();
        if (!root)
        {
            return printTree;
        }

        depth(root, 1);
        return printTree;
    }

    void depth(TreeNode *root, int k)
    {
        if (!root)
        {
            return;
        }

        if (printTree.size() < k)
        {
            vector<int> floor;
            printTree.emplace_back(floor);
        }
        printTree[k - 1].emplace_back(root->val);
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

//判断是否是对称二叉树
class Solution10
{
    bool isSymmetircal(TreeNode *pRoot)
    {
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

class Solution11
{
    TreeLinkNode *GetNext(TreeLinkNode *pNode)
    {
        if (!pNode)
        {
            return nullptr;
        }

        if (pNode->right)
        {
            pNode = pNode->right;
            while (pNode->left)
            {
                pNode = pNode->left;
            }
            return pNode;
        }

        while (pNode->next)
        {
            if (pNode->next->left == pNode)
            {
                return pNode->next;
            }
            pNode = pNode->next;
        }

        return nullptr;
    }
};

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution12
{
    ListNode *deleteDuplication(ListNode *pHead)
    {
        if (!pHead || !pHead->next)
        {
            return pHead;
        }

        auto head = new ListNode(-1);
        head->next = pHead;
        auto pre = head, last = pre->next;

        while (last)
        {
            if (last->next && last->val == last->next->val)
            {
                while (last->next && last->val == last->next->val)
                {
                    auto tmp = last->next;
                    last->next = tmp->next;
                    delete tmp;
                }

                pre->next = last->next;
                delete last;
                last = pre->next;
            }
            else
            {
                pre = pre->next;
                last = last->next;
            }
        }

        pHead = head->next;
        delete head;
        return pHead;
    }
};

//出现一次的字符
class Solution13
{
    vector<char> str;
    int hash[256] = {0};

    void Insert(char ch)
    {
        str.emplace_back(ch);
        hash[ch]++;
    }

    char FirstAppearingOnce()
    {
        for (char i : str)
        {
            if (hash[i] == 1)
            {
                return i;
            }
        }

        return '#';
    }
};

//找出链表的环
class Solution14
{
    ListNode *EntryNodeLoop(ListNode *pHead)
    {
        if (!pHead)
        {
            return nullptr;
        }

        auto p1 = pHead, p2 = p1;
        while (p2->next)
        {
            p1 = p1->next;
            p2 = p2->next->next;
            if (p1 == p2)
            {
                break;
            }
        }

        if (!p2->next)
        {
            return nullptr;
        }

        p1 = pHead;
        while (p1 != p2)
        {
            p1 = p1->next;
            p2 = p2->next;
        }

        return p1;
    }
};

//正则表达式匹配
class Solution15
{
    bool match(char *str, char *pattern)
    {
        if (!str || !pattern)
        {
            return false;
        }

        if (!*pattern)
        {
            return !*str;
        }

        if (*(pattern + 1) == '*')
        {
            return match(str, pattern + 2) ||
                   (*str == *pattern || *str && *pattern == '.') && match(str + 1, pattern);
        }

        return (*str == *pattern || *str && *pattern == '.') && match(str + 1, pattern + 1);
    }
};

//判断字符串是否是数值
class Solution16
{
    bool isNumber(char *str)
    {
        if (!str)
        {
            return false;
        }

        if (*str == '+' || *str == '-')
        {
            str++;
        }

        bool flag = false;
        check(str, flag);

        if (*str == '.')
        {
            check(++str, flag);
        }

        if (flag && (*str == 'E' || *str == 'e'))
        {
            str++;
            flag = false;
            if (*str == '+' || *str == '-')
            {
                str++;
            }
            check(str, flag);
        }

        return flag && !*str;
    }

    void check(char *&str, bool &flag)
    {
        while (isdigit(*str))
        {
            str++;
            flag = true;
        }
    }
};

//数组中第一个重复数字

class Solution17
{
    bool duplicate(int numbers[], int length, int *duplication)
    {
        for (int i = 0; i < length; i++)
        {
            int index = numbers[i] % length;
            if (numbers[index] >= length)
            {
                *duplication = index;
                return true;
            }

            numbers[index] += length;
        }

        return false;
    }
};

//构建乘积数组
class Solution18
{
    vector<int> multiply(vector<int> A)
    {
        vector<int> res;
        if (A.empty())
        {
            return res;
        }

        res.emplace_back(1);
        for (int i : A)
        {
            res.emplace_back(res.back() * i);
        }
        res.pop_back();

        for (int i = A.size() - 1, tmp = 1; i >= 0; i--)
        {
            res[i] *= tmp;
            tmp *= A[i];
        }

        return res;
    }
};

//求两数之和
class Solution19
{
    int Add(int num1, int num2)
    {
        return num2 ? Add(num1 ^ num2, (num1 & num2) << 1) : num1;
    }
};

//字符串转整数
class Solution20
{
    int StrToInt(string str)
    {
        if (str.empty())
        {
            return 0;
        }

        long long res = 0;
        int flag = (str[0] == '-') ? -1 : 1;
        int i = (str[0] == '+' || str[0] == '-') ? 1 : 0;

        for (; i < str.size(); i++)
        {
            if (!(str[i] >= '0' && str[i] <= '9'))
            {
                return 0;
            }

            res = (res << 1) + (res << 3) + (str[i] & 0xf);
        }

        res *= flag;

        if (res > INT_MAX || res < INT_MIN)
        {
            return 0;
        }

        return res;
    }
};

//幸存者编号
class Solution21
{
    int LastRemaing(int n, int m)
    {
        if (n == 0)
        {
            return -1;
        }

        if (n == 0)
        {
            return 1;
        }

        return (LastRemaing(n - 1, m) + m) % n;
    }
};

//连续加法
class Solution22
{
    int Sum(int n)
    {
        return mul(n, n + 1) / 2;
    }

    int mul(int a, int b)
    {
        int res = 0;
        (a & 1) && (res += b);
        a >>= 1;
        b <<= 1;
        (a) && (res += mul(a, b));
        return res;
    }
};

//翻转句子单词
class Solution23
{
    string ReverSentence(string str)
    {
        if (str.empty())
        {
            return str;
        }

        reStr(str, 0, str.size() - 1);

        int i = 0, start = 0;
        while (i < str.size())
        {
            while (i < str.size() && str[i] == ' ')
            {
                i++;
            }
            start = i;
            while (i < str.size() && str[i] != ' ')
            {
                i++;
            }

            reStr(str, start, i - 1);
        }

        return str;
    }

    void reStr(string &str, int i, int j)
    {
        while (i < j)
        {
            swap(str[i++], str[j--]);
        }
    }
};

//扑克牌顺子
class Solution24
{
    bool IsContinous(vector<int> number)
    {
        if (number.empty())
        {
            return false;
        }

        char hash[14] = {0};
        int max = -1, min = 14;

        for (int i : number)
        {
            if (i == 0)
            {
                continue;
            }

            if (++hash[i] > 1)
            {
                return false;
            }

            max = i > max ? i : max;
            min = i < min ? i : min;
        }

        return (max - min) < 5;
    }
};
//和为S的两个数
class Solution25
{
    vector<int> FindNumbersWithSum(vector<int> array, int sum)
    {
        vector<int> res;
        if (array.empty())
        {
            return res;
        }

        int left = 0, right = array.size() - 1;
        while (left < right)
        {
            int tmp = array[left] + array[right];
            if (tmp == sum)
            {
                res.emplace_back(array[left]);
                res.emplace_back(array[right]);
                break;
            }

            tmp < sum ? left++ : right--;
        }
    }
};

//循环左移
class Solution26
{
    string leftRotateString(string str, int n)
    {
        if (str.empty() || n <= 0)
        {
            return str;
        }

        reStr(str, 0, n - 1);
        reStr(str, n, str.size() - 1);
        reStr(str, 0, str.size() - 1);
        return str;
    }

    void reStr(string &str, int i, int j)
    {
        while (i < j)
        {
            swap(str[i++], str[j--]);
        }
        return;
    }
};

//两个只出现一次的数字

class Solution27
{
    void FindNumsAppearOnce(vector<int> data, int *num1, int *num2)
    {
        if (data.empty())
        {
            return;
        }

        int diff = accumulate(data.begin(), data.end(), 0, bit_xor<int>());
        diff &= -diff;
        for (int i : data)
        {
            if (i & diff)
            {
                *num1 ^= i;
            }
            else
            {
                *num2 ^= i;
            }
        }

        return;
    }
};

//连续和为S的数组
class Solution28
{
    vector<vector<int>> FindCountiunousSequence(int num)
    {
        vector<vector<int>> res;
        int left = 1, right = 2;
        while (left < right)
        {
            int sum = (left + right) * (right - left + 1) / 2;
            if (sum == num)
            {
                vector<int> re;
                for (int i = left; i <= right; i++)
                {
                    re.emplace_back(i);
                }
                res.emplace_back(re);
                left++;
            }
            else
            {
                sum < num ? right++ : left++;
            }
        }

        return res;
    }
};

//求树的深度
class Solution29
{
    int TreeDepth(TreeNode *root)
    {
        return root ? max(TreeDepth(root->left), TreeDepth(root->right)) + 1 : 0;
    }
};

//求是否是平衡二叉树
class Solution30
{
    bool IsBanlanced(TreeNode *root)
    {
        return getDepth(root) != -1;
    }

    int getDepth(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }

        int left = 0, right = 0;

        if ((left = getDepth(root->left)) == -1)
        {
            return -1;
        }

        if ((right = getDepth(root->right)) == -1)
        {
            return -1;
        }

        return abs(left - right) > 1 ? -1 : max(left, right) + 1;
    }
};

//找出公共子节点
class Solution31
{
    ListNode *FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2)
    {
        if (!pHead1 || !pHead2)
        {
            return nullptr;
        }

        auto p1 = pHead1, p2 = pHead2;
        while (p1 != p2)
        {
            p1 = p1 ? p1->next : pHead2;
            p2 = p2 ? p2->next : pHead1;
        }

        return p1;
    }
};

//数字在排序数组中的次数
class Solution32
{
    int GetNumberOfK(vector<int> data, int k)
    {
        if (data.empty())
        {
            return 0;
        }

        return getIndex(data, k + 0.5) - getIndex(data, k - 0.5);
    }

    int getIndex(vector<int> &data, double k)
    {
        int i = 0, j = data.size() - 1;
        while (i <= j)
        {
            int mid = i + (j - i) / 2;
            if (data[mid] < k)
            {
                i = mid;
            }
            else
            {
                j = mid;
            }
        }

        return i;
    }
};

//字符串中只出现一次的字符
class Solution33
{
    int FirstNotRepeatingChar(string str)
    {
        int hash[256] = {0};

        for (auto i : str)
        {
            hash[i]++;
        }

        for (int i = 0; i < str.size(); i++)
        {
            if (hash[i] == 1)
            {
                return i;
            }
        }

        return -1;
    }
};

//数组中的逆序
class Solution34
{
    int ans = 0;

    int InversdeParse(vector<int> data)
    {
        ans = 0;
        if (data.empty())
        {
            return ans;
        }
        vector<int> tmp = data;
        solve(data, tmp, 0, data.size());
        return ans;
    }

    void solve(vector<int> &data, vector<int> &tmp, int x, int y)
    {
        if (x < y - 1)
        {
            int mid = x + (y - x) / 2;
            solve(data, tmp, x, mid);
            solve(data, tmp, mid, y);

            int left = x, right = mid, i = x, t = mid - x;
            while (left < mid || right < y)
            {
                if (right >= y || (left < mid && data[left] < data[right]))
                {
                    t--;
                    tmp[i++] = data[left++];
                }
                else
                {
                    ans += t;
                    tmp[i++] = data[right++];
                }
            }
        }

        for (int i = x; i < y; i++)
        {
            data[i] = tmp[i];
        }

        return;
    }
};

//打印最小拼接字符串
class Solution35
{
    string PrintMinNumber(vector<int> numbers)
    {
        if (numbers.empty())
        {
            return "";
        }

        sort(numbers.begin(), numbers.end(), [](int a, int b) {
            return to_string(a) + to_string(b) < to_string(b) + to_string(a);
        });

        string s;
        for (int i : numbers)
        {
            s += to_string(i);
        }
        return s;
    }
};

//丑数
class Solution36
{
    int GetUglyNumbver(int index)
    {
        if (index <= 0)
        {
            return 0;
        }

        vector<int> ugly(index);
        ugly[0] = 1;

        int t2 = 0, t3 = 0, t5 = 0;
        for (int i = 1; i < index; i++)
        {
            ugly[i] = min(ugly[t2] * 2, min(ugly[t3] * 3, ugly[t5] * 5));

            if (ugly[i] == ugly[t2] * 2)
            {
                t2++;
            }

            if (ugly[t3] * 3)
            {
                t3++;
            }

            if (ugly[t5] * 5)
            {
                t5++;
            }
            
        }

        return ugly[index - 1];
    }
};

//连续子序列最大值
class Solution37
{
    int FindGreatSumOfArray(vector<int> array)
    {
        if (array.empty())
        {
            return 0;
        }

        int sum = array[0], tmp = sum;
        for (int i = 1; i < array.size(); i++)
        {
            tmp = tmp < 0 ? array[i] : tmp + array[i];
            sum = sum < tmp ? tmp : sum;
        }

        return sum;
    }
};

//整数中出现1的个数
class Solution38
{
    int numbersOf1Between1AndN(int n)
    {
        int one = 0;
        for (int i = 1; i <= n; i *= 10)
        {
            int a = n / i;
            int b = n % i;

            one += (a + 8) / 10 * i + (a % 10 == 1) * (b + 1);
        }

        return one;
    }
};

//找出重复数字超过一半的数字
class Solution39
{
    int MoreThanHalfNum(vector<int> numbers)
    {
        if (numbers.empty())
        {
            return 0;
        }

        map<int, int> hash;
        for (int i : numbers)
        {
            if (++hash[i] > numbers.size() / 2)
            {
                return i;
            }
        }

        return '#';
    }
};

//找出最小的k个数
class Solution40
{
    vector<int> GetLeastNumbers(vector<int> inputs, int k)
    {
        vector<int> res;
        if (inputs.empty() || k <= 0)
        {
            return res;
        }

        multiset<int, greater<int>> s;
        for (int i : inputs)
        {
            if (s.size() < k)
            {
                s.insert(i);
            }
            else
            {
                auto tmp = s.begin();
                if (*tmp > i)
                {
                    s.erase(tmp);
                    s.insert(i);
                }
            }
        }

        res = vector<int>(s.begin(), s.end());
        return res;
    }
};

//二叉树变双向链表
class Solution41
{
    TreeNode *Convert(TreeNode *pRoot)
    {
        if (!pRoot)
        {
            return nullptr;
        }

        TreeNode *cur = pRoot, *pre = nullptr, *res = nullptr;

        while (cur)
        {
            while (cur->left)
            {
                auto tmp = cur->left;
                while (cur->right)
                {
                    cur = cur->right;
                }
                tmp->right = cur;
                tmp = cur->left;
                cur->left = nullptr;
                cur = tmp;
            }
            cur->left = pre;
            if (!pre)
            {
                res = cur;
            }
            else
            {
                pre->right = cur;
            }
            pre = cur;
            cur = cur->right;
        }

        return res;
    }
};

//字符串的全排列
class Solution42
{
    vector<string> allStr;

    vector<string> Premutation(string str)
    {
        allStr.clear();
        if (str.empty())
            
        {
            return allStr;
        }

        findAllStr(str, 0);
        sort(allStr.begin(), allStr.end());
        return allStr;
    }

    void findAllStr(string &str, int k)
    {
        if (str.size() - 1 == k)
        {
            if (find(allStr.begin(), allStr.end(), str) == allStr.end())
            {
                allStr.emplace_back(str);
            }
        }
        else
        {
            for (int i = k; i < str.size(); i++)
            {
                swap(str[i], str[k]);
                findAllStr(str, k + 1);
                swap(str[i], str[k]);
            }
        }

        return;
    }
};

//查找二叉树的路径
class Solution43
{
    vector<int> path;
    vector<vector<int>> allPath;

    vector<vector<int>> FindPath(TreeNode *root, int expectNumber)
    {
        path.clear();
        allPath.clear();
        if (!root)
        {
            return allPath;
        }

        findAllPath(root, expectNumber);
        return allPath;
    }

    void findAllPath(TreeNode *root, int k)
    {
        if (!root)
        {
            return;
        }
        path.emplace_back(root->val);
        if (!root->left && !root->right && root->val == k)
        {
            allPath.emplace_back(path);
        }
        else
        {
            findAllPath(root->left, k - root->val);
            findAllPath(root->right, k - root->val);
        }
        path.pop_back();
        return;
    }
};

struct RandomListNode
{
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(nullptr), random(nullptr) {}
};

class Solution44
{
    RandomListNode *Clone(RandomListNode *node)
    {
        if (!node)
        {
            return nullptr;
        }
        map<RandomListNode *, RandomListNode *> hash;
        auto p = node;
        while (p)
        {
            hash[p] = new RandomListNode(p->label);
            p = p->next;
        }

        p = node;
        while (p)
        {
            hash[p]->next = hash[p->next];
            hash[p]->random = hash[p->random];
            p = p->next;
        }

        return hash[node];
    }
};

//按层打印二叉树
class Solution45
{
    vector<int> PrintFromTopBottom(TreeNode *root)
    {
        vector<int> res;
        if (!root)
        {
            return res;
        }

        queue<TreeNode *> q;
        q.push(root);
        while (q.size())
        {
            auto tmp = q.front();
            q.pop();
            res.emplace_back(tmp->val);
            if (tmp->left)
            {
                q.push(tmp->left);
            }

            if (tmp->right)
            {
                q.push(tmp->right);
            }
        }

        return res;
    }
};

//判断是否是后序遍历的二叉排序树
class Solution46
{
    bool VerifySequenceOfBST(vector<int> sequence)
    {
        if (sequence.empty())
        {
            return false;
        }

        return judge(sequence, 0, sequence.size() - 1);
    }

    bool judge(vector<int> se, int start, int end)
    {
        if (start > end)
        {
            return true;
        }

        int i = end - 1;
        while (i > start && se[i] > se[end])
        {
            i--;
        }

        int j = i;
        while (j >= start)
        {
            if (se[j--] > se[end])
            {
                return false;
            }
        }

        return judge(se, start, i) && judge(se, i + 1, end - 1);
    }
};

//最小元素的栈
class Soltion47
{
    stack<int> st1, st2;
    void push(int x)
    {
        st1.push(x);
        if (st2.empty() || st2.top() > x)
        {
            st2.push(x);
        }
        else
        {
            st2.push(st2.top());
        }
    }

    void pop()
    {
        st1.pop();
        st2.pop();
    }

    int top()
    {
        return st1.top();
    }

    int min()
    {
        return st2.top();
    }
};

//判断是否栈弹出队列
class Solution48
{
    bool IsPopOrder(vector<int> pushV, vector<int> popV)
    {
        if (pushV.empty() || popV.empty())
        {
            return false;
        }

        vector<int> st;

        int i = 0, j = 0;
        while (i < pushV.size())
        {
            st.emplace_back(pushV[i++]);
            while (j < popV.size() && st.back() == popV[j])
            {
                st.pop_back();
                j++;
            }
        }

        return st.empty();
    }
};

//镜像二叉树
class Solution49
{
    void Mirror(TreeNode *root)
    {
        if (!root)
        {
            return;
        }

        swap(root->left, root->right);
        Mirror(root->left);
        Mirror(root->right);
        return;
    }
};

//矩阵顺时针打印
class Solution50
{
    int rows, cols;
    vector<vector<bool>> flag;
    bool judge(int i, int j)
    {
        return i >= 0 && i < rows && j >= 0 && j < cols && !flag[i][j];
    }

    vector<int> printMatrix(vector<vector<int>> matrix)
    {
        vector<int> res;
        if (matrix.empty())
        {
            return res;
        }

        rows = matrix.size();
        cols = matrix[0].size();
        flag = vector<vector<bool>>(rows, vector<bool>(cols, false));

        char D[4][2] = {
            {0, 1},
            {1, 0},
            {0, -1},
            {-1, 0}};

        int i = 0, j = 0, d = 0, T = cols * rows;
        while (T--)
        {
            res.emplace_back(matrix[i][j]);

            if (!judge(i + D[d][0], j + D[d][1]))
            {
                d = (d + 1) % 4;
            }

            i += D[d][0];
            j += D[d][1];
        }

        return res;
    }
};

class Solution51
{
    ListNode *Merge(ListNode *pHead1, ListNode *pHead2)
    {
        if (!pHead1)
        {
            return pHead2;
        }

        if (!pHead2)
        {
            return pHead1;
        }

        if (pHead1->val < pHead2->val)
        {
            pHead1->next = Merge(pHead1->next, pHead2);
        }
        else
        {
            pHead2->next = Merge(pHead1, pHead2->next);
        }

        return nullptr;
    }
};

//判断是否B是A的子树
class Solution52
{
    bool HasSubTree(TreeNode *pRoot1, TreeNode *pRoot2)
    {
        if (!pRoot1 || !pRoot2)
        {
            return false;
        }

        return isSub(pRoot1, pRoot2) ||
               isSub(pRoot1->left, pRoot2) ||
               isSub(pRoot1->right, pRoot2);
    }

    bool isSub(TreeNode *r1, TreeNode *r2)
    {
        if (!r1)
        {
            return false;
        }

        if (!r2)
        {
            return true;
        }

        if (r1->val == r2->val)
        {
            return isSub(r1->left, r2->left) && isSub(r1->right, r2->right);
        }

        return false;
    }
};

//链表的倒数第k个节点
class Solution53
{
    ListNode *FindKthToTail(ListNode *pNode, int k)
    {
        if (!pNode || k < 0)
        {
            return nullptr;
        }

        auto p1 = pNode;
        for (int i = 1; i < k && p1; i++)
        {
            p1 = p1->next;
        }

        if (!p1)
        {
            return nullptr;
        }

        auto p2 = pNode;
        while (p1->next)
        {
            p1 = p1->next;
            p2 = p2->next;
        }

        return p2;
    }
};

//翻转链表
class Solution54
{
    ListNode *ReverseList(ListNode *pNode)
    {
        if (!pNode || !pNode->next)
        {
            return pNode;
        }

        auto h = ReverseList(pNode->next);
        pNode->next->next = pNode;
        pNode->next = nullptr;
        return h;
    }
};

//求base的e次方
class Solution55
{
    double Power(double base, int exponent)
    {
        int p = abs(exponent);
        double res = 1;
        while (p)
        {
            (p & 1) && (res *= base);
            p >>= 1;
            base *= base;
        }

        return exponent < 0 ? 1 / res : res;
    }
};

//奇数前部分，偶数后部分
class Solution56
{
    void reOrserArray(vector<int> &array)
    {
        for (int i = 0; i < array.size(); i++)
        {
            for (int j = array.size() - 1; j > i; j--)
            {
                if (array[j] % 2 == 1 && array[j - 1] % 2 == 0)
                {
                    swap(array[j], array[j - 1]);
                }
            }
        }

        return;
    }
};

//矩形覆盖
class Solution57
{
    int rectCover(int number)
    {
        if (number <= 0)
        {
            return 0;
        }

        if (number <= 2)
        {
            return number;
        }

        int a = 1, b = 2;
        for (int i = 2; i < number; i++)
        {
            int tmp = a + b;
            a = b;
            b = tmp;
        }

        return b;
    }
};

//二进制的1的个数
class Solution58
{
    int NumberOf1(int n)
    {
        int count = 0;
        while (n)
        {
            count++;
            n &= (n - 1);
        }

        return count;
    }
};

//能跳1、2级的青蛙
class Solution59
{
    int jumpFloor(int number)
    {
        if (number <= 0)
        {
            return 0;
        }

        if (number <= 2)
        {
            return number;
        }

        int a = 1, b = 2;
        for (int i = 2; i < number; i++)
        {
            int tmp = a + b;
            a = b;
            b = tmp;
        }

        return b;
    }
};

class Solution60
{
    int jumpFloor(int number)
    {
        1 << (number - 1);
    }
};

//旋转数组的最小值
class Solution61
{
    int minNumberInRoteArray(vector<int> array)
    {
        if (array.empty())
        {
            return 0;
        }

        int left = 0, right = array.size() - 1;
        while (left < right)
        {
            if (array[left] < array[right])
            {
                return array[left];
            }

            int mid = left + (right - left) / 2;
            if (array[mid] > array[left])
            {
                left = mid + 1;
            }
            else if (array[mid] < array[right])
            {
                right = mid;
            }
            else
            {
                left++;
            }
        }

        return array[left];
    }
};

//斐波那契数列
class Solution62
{
    int Fibonacci(int n)
    {
        if (n <= 0)
        {
            return 0;
        }

        int a = 1, b = 1;
        for (int i = 2; i < n; i++)
        {
            int tmp = a + b;
            a = b;
            b = tmp;
        }

        return b;
    }
};

//重建二叉树
class Solution63
{
    TreeNode *ReConstructBinaryTree(vector<int> pre, vector<int> vin)
    {
        if (pre.empty() || vin.empty())
        {
            return false;
        }

        auto root = reTree(pre, 0, pre.size() - 1, vin, 0, vin.size() - 1);
        return root;
    }

    TreeNode *reTree(vector<int> &pre, int preStart, int preEnd, vector<int> &vin, int vinStart, int vinEnd)
    {
        if (preStart > preEnd || vinStart > vinEnd)
        {
            return nullptr;
        }

        auto root = new TreeNode(pre[preStart]);
        for (int i = vinStart; i <= vinEnd; i++)
        {
            if (root->val == vin[i])
            {
                root->left = reTree(pre, preStart + 1, preStart + i - vinStart, vin, vinStart, i - 1);
                root->right = reTree(pre, preStart + i - vinStart + 1, preEnd, vin, i + 1, vinEnd);
                break;
            }
        }
        return root;
    }
};

//栈模拟队列
class Solution64
{
    stack<int> st1, st2;

    void push(int x)
    {
        st1.push(x);
    }

    int pop()
    {
        if (st2.empty())
        {
            while (st1.size())
            {
                st2.push(st1.top());
                st1.pop();
            }
        }

        int tmp = st2.top();
        st2.pop();
        return tmp;
    }
};

//空格替换
class Solution65
{
    void replaceSpace(char *str, int length)
    {
        int count = 0;
        for (int i = 0; i < length; i++)
        {
            if (str[i] == ' ')
            {
                count++;
            }
        }

        for (int i = length - 1; i >= 0; i--)
        {
            if (str[i] != ' ')
            {
                str[i + 2 * count] = str[i];
            }
            else
            {
                count--;
                str[i + 2 * count] = '%';
                str[i + 2 * count + 1] = '2';
                str[i + 2 * count + 2] = '0';
            }
        }

        return;
    }
};

//返回链表的倒序
class Solution66
{
    vector<int> printLiatFromTailToHead(ListNode *head)
    {
        vector<int> res;
        while (head)
        {
            res.emplace_back(head->val);
            head = head->next;
        }

        int i = 0, j = res.size() - 1;
        while (i < j)
        {
            swap(res[i++], res[j--]);
        }

        return res;
    }
};

//排序矩阵找元素
class Solution67
{
    bool FindInMarirx(int target, vector<vector<int>> matrix)
    {
        if (matrix.empty())
        {
            return false;
        }

        int rows = matrix.size();
        int cols = matrix[0].size();

        for (int i = rows - 1, j = 0; i >= 0 && j < cols;)
        {
            if (target == matrix[i][j])
            {
                return true;
            }
            else
            {
                target < matrix[i][j] ? i-- : j++;
            }
        }

        return false;
    }
};