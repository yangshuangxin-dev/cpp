#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution
{
    //切绳子
public:
    int cutRope(int number)
    {
        int max = 1;
        if (number <= 3)
            return number - 1;
        while (number > 4)
        {
            max *= 3;
            number -= 3;
        }

        return max * number;
    }

    //第k小节点
    int count_k = 0;
    TreeNode *KthNode(TreeNode *pRoot, int k)
    {
        if (!pRoot)
            return nullptr;

        auto reNode = KthNode(pRoot->left, k);
        if (reNode)
            return reNode;
        if (++count_k == k)
            return pRoot;
        reNode = KthNode(pRoot->right, k);
        if (reNode)
            return reNode;

        return nullptr;
    }

    //机器人走格子
    int movingCount(int threshold, int rows, int cols)
    {
        if (rows <= 0 || cols <= 0 || threshold <= 0)
            return 0;
        vector<bool> flag(cols * rows, false);
        return robot_dfs(threshold, rows, cols, flag, 0, 0);
    }

    int robot_dfs(int k, int rows, int cols, vector<bool> &flag, int i, int j)
    {
        int index = i * cols + j;
        if (i < 0 || i >= rows || j < 0 || j >= cols || getsum(i) + getsum(j) > k || flag[index])
            return 0;

        flag[index] = true;

        return 1 + robot_dfs(k, rows, cols, flag, i + 1, j) + robot_dfs(k, rows, cols, flag, i - 1, j) + robot_dfs(k, rows, cols, flag, i, j + 1) + robot_dfs(k, rows, cols, flag, i, j - 1);
    }

    int getsum(int n)
    {
        int sum = 0;
        while (n > 0)
        {
            sum += (n % 10);
            n /= 10;
        }
        return sum;
    }

    //矩阵查找字符串
    bool hasPath(char *matrix, int rows, int cols, char *str)
    {
        if (!matrix || !str || rows <= 0 || cols <= 0)
            return false;
        vector<bool> flag(rows * cols, false);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (str_dfs(matrix, rows, cols, flag, str, 0, i, j))
                    return true;
            }
        }
        return false;
    }

    bool str_dfs(char *matrix, int rows, int cols, vector<bool> flag, char *str, int k, int i, int j)
    {
        int index = i * cols + j;
        if (i <= 0 || i >= rows || j < 0 || j >= cols || matrix[index] != str[k] || flag[index])
            return false;
        if (str[k + 1] == '\0')
            return true;

        flag[index] = true;
        if (str_dfs(matrix, rows, cols, flag, str, k + 1, i + 1, j) ||
            str_dfs(matrix, rows, cols, flag, str, k + 1, i - 1, j) ||
            str_dfs(matrix, rows, cols, flag, str, k + 1, i, j - 1) ||
            str_dfs(matrix, rows, cols, flag, str, k + 1, i, j + 1))
            return true;

        flag[index] = false;
        return false;
    }

    //滑动窗口
    vector<int> maxInWindows(const vector<int> &num, unsigned int size)
    {
        vector<int> re;
        deque<int> tmp;
        for (int i = 0; i < num.size(); i++)
        {
            while (tmp.size() && num[tmp.back()] <= num[i])
                tmp.pop_back();

            if (tmp.size() && i - tmp.front() >= size)
                tmp.pop_front();
            tmp.push_back(i);
            if (size && i + 1 >= size)
                re.emplace_back(num[tmp.front()]);
        }
        return re;
    }

    //数据流中位数
    priority_queue<int, vector<int>, less<int>> q;
    priority_queue<int, vector<int>, greater<int>> p;

    void Insert(int num)
    {
        if (q.empty() || num < q.top())
            q.push(num);
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
        return (q.size() == p.size()) ? (q.top() + p.top()) / 2.0 : q.top();
    }

    //序列化和反序列化二叉树
    vector<int> buf;
    char *Serialize(TreeNode *root)
    {
        buf.clear();
        dfs_tree(root);
        int *re = new int[buf.size()];
        for (int i = 0; i < buf.size(); i++)
        {
            re[i] = buf[i];
        }
        return (char *)re;
    }

    TreeNode *Deserialize(char *str)
    {
        int *p = (int *)str;
        return dfs_tree2(p);
    }

    void dfs_tree(TreeNode *root)
    {
        if (!root)
        {
            buf.emplace_back('#');
            return;
        }
        buf.emplace_back(root->val);
        dfs_tree(root->left);
        dfs_tree(root->right);
    }

    TreeNode *dfs_tree2(int *&p)
    {
        if (*p == '#')
        {
            p++;
            return nullptr;
        }

        auto root = new TreeNode(*p);
        p++;
        root->left = dfs_tree2(p);
        root->right = dfs_tree2(p);
        return root;
    }

    //从上到下按层打印二叉树
    vector<vector<int>> print_tree;
    vector<vector<int>> Print(TreeNode *pRoot)
    {
        print_tree.clear();
        if (!pRoot)
            return print_tree;

        depth(pRoot, 1);
        return print_tree;
    }

    void depth(TreeNode *root, int k)
    {
        if (!root)
            return;

        if (k > print_tree.size())
        {
            vector<int> f;
            print_tree.emplace_back(f);
        }

        print_tree[k - 1].emplace_back(root->val);
        depth(root->left, k + 1);
        depth(root->right, k + 1);
    }

    //之字打印二叉树
    vector<vector<int>> PrintTreeZ(TreeNode *pRoot)
    {
        vector<vector<int>> re;
        if (!pRoot)
            return re;
        stack<TreeNode *> s1, s2;
        s1.push(pRoot);
        while (s1.size(), s2.size())
        {
            vector<int> v1, v2;
            while (s1.size())
            {
                auto cur = s1.top();
                s1.pop();
                v1.emplace_back(cur->val);
                if (cur->left)
                    s2.push(cur->left);
                if (cur->right)
                    s2.push(cur->right);
            }
            if (v1.size())
                re.emplace_back();

            while (s2.size())
            {
                auto cur = s2.top();
                s2.pop();
                v2.emplace_back(cur->val);
                if (cur->right)
                    s1.push(cur->right);
                if (cur->left)
                    s1.push(cur->left);
            }
            if (v2.size())
                re.emplace_back(v2);
        }
        return re;
    }

    //判断是否对称二叉树
    bool isSymmetrical(TreeNode *pRoot)
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

    //中序遍历下一个节点
    struct TreeLinkNode
    {
        int val;
        struct TreeLinkNode *left;
        struct TreeLinkNode *right;
        struct TreeLinkNode *next;
        TreeLinkNode(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {}
    };

    TreeLinkNode *GetNext(TreeLinkNode *pNode)
    {
        if (!pNode)
            return nullptr;

        if (pNode->right)
        {
            pNode = pNode->right;
            while (pNode->left)
                pNode = pNode->left;
            return pNode;
        }

        while (pNode->next)
        {
            if (pNode == pNode->next->left)
                return pNode->next;

            pNode = pNode->next;
        }

        return nullptr;
    }

    //删除链表重复节点
    struct ListNode
    {
        int val;
        struct ListNode *next;
        ListNode(int x) : val(x), next(nullptr) {}
    };

    ListNode *deleteDuplication(ListNode *pHead)
    {
        if (!pHead)
            return nullptr;

        auto head = new ListNode(-1);
        head->next = pHead;
        auto pre = head, last = pre->next;
        while (last)
        {
            if (last->next && last->val == last->next->val)
            {
                while (last->next && last->val == last->next->next->val)
                {
                    auto tmp = last;
                    last = last->next;
                    delete tmp;
                }

                pre->next = last->next;
                delete last;
                last = pre->next;
            }

            pre->next = pre->next;
            last->next = last->next;
        }

        pHead = head->next;
        delete head;
        return pHead;
    }

    //出现一次的字符
    vector<char> s;
    char hash[256] = {0};
    void Insert(char ch)
    {
        s.emplace_back(ch);
        hash[ch]++;
    }

    char FirstAppearingOnce()
    {
        for (auto i : s)
        {
            if (hash[i] == 1)
                return i;
        }
        return '#';
    }

    //找出链表的环
    ListNode *EntryNodeOfLoop(ListNode *pHead)
    {
        if (!pHead)
            return nullptr;

        auto p1 = pHead, p2 = p1;
        while (p2->next)
        {
            p1 = p1->next;
            p2 = p2->next->next;
            if (p1 == p2)
                break;
        }

        if (!p2->next)
            return nullptr;

        p2 = pHead;
        while (p1 != p2)
        {
            p1 = p1->next;
            p2 = p2->next;
        }

        return p1;
    }

    //正则表达式*和.
    bool match(char *str, char *pattern)
    {
        if (!str || !pattern)
            return false;

        if (!*pattern)
            return !*str;

        if (*(pattern + 1) == '*')
        {
            return match(str, pattern + 2) || (*str == *pattern || *str && *pattern == '.') && match(str + 1, pattern);
        }

        return (*str == *pattern || *str && *pattern == '.') && match(str + 1, pattern + 1);
    }

    //判断字符串是否是数值
    bool isNumeric(char *string)
    {
        if (!string)
            return false;

        bool flag = false;
        if (*string == '+' || *string == '-')
            string++;
        check(string, flag);
        if (*string == '.')
            check(++string, flag);

        if (flag && (*string == 'e' || *string == 'E'))
        {
            string++;
            flag = false;
            if (*string == '+' || *string == '-')
                string++;
            check(string, flag);
        }
        return flag && !*string;
    }

    void check(char *&s, bool &flag)
    {
        while (isdigit(*s))
        {
            s++;
            flag = true;
        }
    }

    //数组中第一个重复的数字
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

    //乘积数组
    vector<int> multiply(const vector<int> &A)
    {
        vector<int> re;
        if (A.empty())
            return re;
        re.emplace_back(1);
        for (auto i : A)
        {
            re.emplace_back(re.back() * i);
        }

        re.pop_back();

        for (int i = A.size() - 1, tmp = 1; i >= 0; i--)
        {
            re[i] *= tmp;
            tmp *= A[i];
        }
        return re;
    }

    //求两整数和
    int Add(int num1, int num2)
    {
        return num2 ? Add(num1 ^ num2, (num1 & num2) << 1) : num1;
    }

    //字符串转整数
    int StrToInt(string str)
    {
        int len = str.size(), s = 1;
        long long res = 0;
        if (len == 0)
            return 0;
        if (str[0] == '-')
            s = -1;
        for (int i = (str[0] == '-' || str[0] == '+') ? 1 : 0; i < str.length(); i++)
        {
            if (!('0' <= str[i] && str[i] <= '9'))
                return 0;
            res = (res << 1) + (res << 3) + (str[i] & 0xf);
        }

        res *= s;
        if (res < INT_MIN || res > INT_MAX)
            return 0;
        return res;
    }

    //幸存者编号
    int LastRemaining_Solution(int n, int m)
    {
        if (n == 0)
            return -1;
        if (n == 1)
            return 0;

        return (LastRemaining_Solution(n - 1, m) + m) % n;
    }

    //连续加法
    int Sum_Solution(int n)
    {
        return mul(n, n + 1) / 2;
    }

    int mul(int a, int b)
    {
        int re = 0;
        (a & 1) && (re += b);
        a >>= 1;
        b <<= 1;
        a && (re += mul(a, b));
        return re;
    }

    //翻转句子单词
    string ReverseSentence(string str)
    {
        restr(str, 0, str.size() - 1);
        int start = 0, i = 0;
        while (i < str.size())
        {
            while (i < str.size() && str[i] == ' ')
                i++;
            start = i;
            while (i < str.size() && str[i] != ' ')
                i++;
            restr(str, start, i - 1);
        }
        return str;
    }

    void restr(string &str, int i, int j)
    {
        while (i < j)
        {
            swap(str[i++], str[j--]);
        }
    }

    //扑克牌顺子
    bool IsContinuous(vector<int> numbers)
    {
        if (numbers.empty())
            return false;

        vector<int> m(14);
        int max = -1, min = 14;

        for (auto i : numbers)
        {
            if (i == 0)
                continue;
            if (++m[i] > 1)
                return false;
            if (i > max)
                max = i;
            if (i < min)
                min = i;
        }

        return (max - min) < 5;
    }

    //找出和为S的两个数
    vector<int> FindNumbersWithSum(vector<int> array, int sum)
    {
        vector<int> re;
        if (array.empty())
            return re;

        int left = 0, right = array.size() - 1;
        while (left < right)
        {
            int s = array[left] + array[right];
            if (s == sum)
            {
                re.emplace_back(array[left]);
                re.emplace_back(array[right]);
                break;
            }
            else
            {
                s < sum ? left++ : right--;
            }
        }
        return re;
    }

    //循环左移
    string LeftRotateString(string str, int n)
    {
        if (str.empty())
            return str;

        restr(str, 0, n - 1);
        restr(str, n, str.size() - 1);
        restr(str, 0, str.size() - 1);
    }

    //两个只出现一次的数字
    void FindNumsAppearOnce(vector<int> data, int *num1, int *num2)
    {
        if (data.empty())
            return;
        int diff = accumulate(data.begin(), data.end(), 0, bit_xor<int>());
        diff &= -diff;
        for (auto i : data)
        {
            if (i & diff)
                *num1 ^= i;
            else
            {
                *num2 ^= i;
            }
        }
        return;
    }

    //连续和为S的序列
    vector<vector<int>> FindContiunousSequence(int sum)
    {
        vector<vector<int>> re;
        int left = 1, right = 2;
        while (left < right)
        {
            int tmp = (left + right) * (right - left + 1) / 2;
            if (tmp == sum)
            {
                vector<int> t;
                for (int i = left; i <= right; i++)
                {
                    t.emplace_back(i);
                }
                re.emplace_back(t);
                left++;
            }
            else
            {
                tmp < sum ? right++ : left++;
            }
        }

        return re;
    }

    //求树的深度
    int TreeDepth(TreeNode *pRoot)
    {
        return pRoot ? max(TreeDepth(pRoot->left), TreeDepth(pRoot->right)) + 1 : 0;
    }

    //判断是否是平衡二叉数
    bool IsBalanced_Solution(TreeNode *pRoot)
    {
        return getDepth(pRoot) != -1;
    }

    int getDepth(TreeNode *pRoot)
    {
        if (!pRoot)
            return 0;
        auto left = getDepth(pRoot->left);
        auto right = getDepth(pRoot->right);
        if (left == -1 || right == -1)
            return -1;

        return abs(left - right) > 1 ? -1 : max(left, right) + 1;
    }

    //找出第一个公共节点
    ListNode *FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2)
    {
        if (!pHead1 || !pHead2)
            return nullptr;

        auto p1 = pHead1, p2 = pHead2;
        while (p1 != p2)
        {
            p1 = p1 ? p1->next : pHead2;
            p2 = p2 ? p2->next : pHead1;
        }

        return p1;
    }

    //数字在排序数组中出现的次数
    int GetNumberOfK(vector<int> data, int k)
    {
        return getIndex(data, k + 0.5) - getIndex(data, k - 0.5);
    }

    int getIndex(vector<int> data, double k)
    {
        int i = 0, j = data.size() - 1;
        while (i <= j)
        {
            int mid = i + (j - i) / 2;
            if (data[mid] < k)
                i = mid;
            else
                j = mid;
        }
        return i;
    }

    //字符串第一个只出现一次的字符的位置
    int FirstNotRepeatingChar(string str)
    {
        char hash[256] = {0};
        for (auto i : str)
        {
            hash[i]++;
        }

        for (int i = 0; i < str.size(); i++)
        {
            if (hash[str[i]] == 1)
                return i;
        }

        return -1;
    }

    //数组中逆序对的个数
    int ans = 0;
    int InversePairs(vector<int> data)
    {
        if (data.empty())
            return 0;
        vector<int> tmp = data;
        solve(data, tmp, 0, data.size());
        return ans;
    }

    void solve(vector<int> &data, vector<int> &tmp, int x, int y)
    {
        if (y - 1 > x)
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
    }

    //正整数数组，打印出拼接起来最小的数字
    string PrintMinNumber(vector<int> numbers)
    {
        if (numbers.empty())
            return "";
        sort(numbers.begin(), numbers.end(),
             [](int a, int b) {
                 return to_string(a) + to_string(b) < to_string(b) + to_string(a);
             });

        string s;
        for (auto i : numbers)
        {
            s += to_string(i);
        }
        return s;
    }

    //丑数
    int GetUglyNumber_Solution(int index)
    {
        if (index <= 0)
            return 0;

        vector<int> ugly(index);
        ugly[0] = 1;
        int t2 = 0, t3 = 0, t5 = 0, i = 1;
        while (i < index)
        {
            ugly[i] = min(ugly[t2] * 2, min(ugly[t3] * 3, ugly[t5] * 5));
            if (ugly[i] == ugly[t2] * 2)
                t2++;
            if (ugly[i] == ugly[t3] * 3)
                t3++;
            if (ugly[i] == ugly[t5] * 5)
                t5++;

            i++;
        }

        return ugly[index - 1];
    }

    //连续子序列最大和
    int FindGreatestSunOfSubArray(vector<int> array)
    {
        if (array.empty())
            return 0;

        int sum = array[0], tmp = sum;
        for (int i = 1; i < array.size(); i++)
        {
            tmp = tmp < 0 ? array[i] : tmp + array[i];
            sum = sum < tmp ? tmp : sum;
        }
        return sum;
    }

    //整数中1出现的次数
    int NumberOf1Between1AndN_Solution(int n)
    {
        int one = 0;
        for (int m = 1; m <= n; m *= 10)
        {
            int a = n / m, b = n % m;
            one += (a + 8) / 10 * m + (a % 10 == 1) * (b + 1);
        }

        return one;
    }

    //重复数字超过数组长度一半
    int MoreThanHalfNum_Solution(vector<int> numbers)
    {
        if (numbers.empty())
            return 0;
        map<int, int> m;
        for (auto i : numbers)
        {
            if (++m[i] > numbers.size() / 2)
                return i;
        }
        return 0;
    }

    //找出最小k个数
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
    {
        vector<int> re;
        if (input.empty() || k > input.size())
            return re;
        multiset<int, greater<int>()> s;
        for (auto i : input)
        {
            if (s.size() < k)
                s.insert(i);
            else
            {
                auto it = s.begin();
                if (i < *it)
                {
                    s.erase(it);
                    s.insert(i);
                }
            }
        }
        re = vector<int>(s.begin(), s.end());
        return re;
    }

    //二叉搜索树变双向链表
    TreeNode *Convert(TreeNode *pRootOfTree)
    {
        if (!pRootOfTree)
            return nullptr;

        TreeNode *cur = pRootOfTree, *pre = nullptr, *re = nullptr;
        while (cur)
        {
            while (cur->left)
            {
                auto tmp = cur->left;
                while (tmp->right)
                    tmp = tmp->right;
                tmp->right = cur;
                tmp = cur->left;
                cur->left = nullptr;
                cur = tmp;
            }

            cur->left = pre;
            if (!pre)
                re = cur;
            else
                pre->right = cur;

            pre = cur;
            cur = cur->right;
        }

        return re;
    }

    //按照字典序字符串所有排列
    vector<string> allStr;
    vector<string> Premutation(string str)
    {
        allStr.clear();
        if (str.empty())
            return allStr;
        findAllStr(str, 0);
        sort(allStr.begin(), allStr.end());
        return allStr;
    }

    void findAllStr(string s, int k)
    {
        if (k + 1 == s.size())
        {
            if (find(allStr.begin(), allStr.end(), s) == allStr.end())
                allStr.emplace_back(s);
        }
        else
        {
            for (int i = k; i < s.size(); i++)
            {
                swap(s[k], s[i]);
                findAllStr(s, k + 1);
                swap(s[k], s[i]);
            }
        }

        return;
    }

    //找到二叉树路径
    vector<int> path;
    vector<vector<int>> allPath;
    vector<vector<int>> FindPath(TreeNode *root, int expectNumber)
    {
        if (!root)
            return allPath;

        findAllPath(root, expectNumber);
        return allPath;
    }

    void findAllPath(TreeNode *root, int k)
    {
        if (!root)
            return;
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

    //复杂链表的复制
    struct RandomListNode
    {
        int label;
        struct RandomListNode *next, *random;
        RandomListNode(int x) : label(x), next(nullptr), random(nullptr) {}
    };

    RandomListNode *Clone(RandomListNode *pHead)
    {
        if (!pHead)
            return pHead;

        map<RandomListNode *, RandomListNode *> m;
        auto p = pHead;
        while (p)
        {
            m[p] = new RandomListNode(p->label);
            p = p->next;
        }

        p = pHead;
        while (p)
        {
            m[p]->next = m[p->next];
            m[p->random] = m[p->random];
            p = p->next;
        }
        return m[pHead];
    }

    //按层从左到右打印二叉树节点
    vector<int> PrintFromTopBottom(TreeNode *root)
    {
        vector<int> re;
        if (!root)
            return re;

        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            auto cur = q.front();
            q.pop();
            re.emplace_back(cur->val);
            if (cur->left)
                q.push(cur->left);
            if (cur->right)
                q.push(cur->right);
        }

        return re;
    }

    //判断是否是后序遍历的二叉树数组
    bool VerifySquenceOfBST(vector<int> sequence)
    {
        if (sequence.empty())
            return false;

        return judge(sequence, 0, sequence.size() - 1);
    }

    bool judge(vector<int> q, int start, int end)
    {
        if (start > end)
            return true;

        int i = end;
        while (i > start && q[i - 1] > q[end])
        {
            i--;
        }
        int j = i - 1;
        while (j >= start)
        {
            if (q[j] > q[end])
                return false;
            j--;
        }

        return judge(q, start, i - 1) && judge(q, i, end - 1);
    }

    //最小元素栈
    stack<int> mystack, mins;
    void push(int val)
    {
        mystack.push(val);
        if (mins.empty() || val < mins.top())
            mins.push(val);
        else
        {
            mins.push(mins.top());
        }
    }

    void pop()
    {
        mystack.pop();
        mins.pop();
    }

    int top()
    {
        return mystack.top();
    }

    int mymin()
    {
        return mins.top();
    }

    //判断是否是栈的弹出序列
    bool IsPopOrder(vector<int> pushV, vector<int> popV)
    {
        if (pushV.empty() || popV.empty())
            return false;

        vector<int> st;
        int i = 0, j = 0;
        while (i < pushV.size())
        {
            st.emplace_back(pushV[i]);
            while (st.back() == popV[j] && j < popV.size())
            {
                st.pop_back();
                j++;
            }
            i++;
        }

        return st.empty();
    }

    //镜像二叉树
    void Mirror(TreeNode *root)
    {
        if (!root)
            return;
        swap(root->left, root->right);
        Mirror(root->left);
        Mirror(root->right);
    }

    //矩阵顺时针打印
    int col, row;
    vector<vector<bool>> flag;
    bool judge_M(int i, int j)
    {
        return i >= 0 && i < row && j >= 0 && j < col && !flag[i][j];
    }
    vector<int> printMatrix(vector<vector<int>> matrix)
    {
        vector<int> re;
        if (matrix.empty())
            return re;

        row = matrix.size();
        col = matrix[0].size();
        flag = vector<vector<bool>>(row, vector<bool>(col, false));
        char D[4][2] = {
            {0, 1},
            {1, 0},
            {0, -1},
            {-1, 0}};

        int i = 0, j = 0, d = 0, T = col * row;
        while (T--)
        {
            re.emplace_back(matrix[i][j]);
            flag[i][j] = true;
            if (!judge_M(i + D[d][0], j + D[d][1]))
                d = (d + 1) % 4;

            i += D[d][0];
            j += D[d][1];
        }

        return re;
    }

    //合并链表
    ListNode *Merge(ListNode *pHead1, ListNode *pHead2)
    {
        if (!pHead1)
            return pHead2;
        if (!pHead2)
            return pHead1;

        if (pHead1->val < pHead2->val)
        {
            pHead1->next = Merge(pHead1->next, pHead2);
            return pHead1;
        }
        else
        {
            pHead2->next = Merge(pHead1, pHead2->next);
            return pHead2;
        }

        return nullptr;
    }

    //B树是否A树的子二叉树
    bool HasSubtree(TreeNode *pRoot1, TreeNode *pRoot2)
    {
        if (!pRoot1 || !pRoot2)
            return false;

        return isSub(pRoot1, pRoot2) ||
               isSub(pRoot1->left, pRoot2) ||
               isSub(pRoot1->right, pRoot2);
    }

    bool isSub(TreeNode *r1, TreeNode *r2)
    {
        if (!r2)
            return true;
        if (!r1)
            return false;

        if (r1->val == r2->val)
        {
            return isSub(r1->left, r2->left) && isSub(r1->right, r2->right);
        }

        return false;
    }

    //链表倒数第k个节点
    ListNode *FindKthToTail(ListNode *pListHead, unsigned int k)
    {
        if (!pListHead || k <= 0)
            return nullptr;

        auto p = pListHead, q = p;
        for (int i = 1; i < k && q; i++)
        {
            q = q->next;
        }

        if (!q)
            return nullptr;

        while (q->next)
        {
            p = p->next;
            q = q->next;
        }

        return p;
    }

    //翻转链表
    ListNode *ReverseList(ListNode *pHead)
    {
        if (!pHead || !pHead->next)
            return pHead;

        auto h = ReverseList(pHead->next);
        pHead->next->next = pHead;
        pHead->next = nullptr;
        return h;
    }

    //求base的exponent次方
    double Power(double base, int exponent)
    {
        int p = abs(base);
        double r = 1.0;
        while (p)
        {
            (p & 1) && (r += base);
            p >>= 1;
            base *= base;
        }
        return exponent < 0 ? 1 / r : r;
    }

    //奇数前部分，偶数后部分
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
    }

    //矩形覆盖
    int rectCover(int number)
    {
        if (number <= 0)
            return 0;
        if (number <= 2)
            return number;

        int a = 1, b = 2;
        for (int i = 2; i < number; i++)
        {
            int tmp = a + b;
            a = b;
            b = tmp;
        }
        return b;
    }

    //二进制的1个数
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

    //能跳1、2级的青蛙
    int jumpFloor(int number)
    {
        if (number <= 0)
            return 0;
        if (number <= 2)
            return number;

        int a = 1, b = 2;
        for (int i = 2; i < number; i++)
        {
            int tmp = a + b;
            a = b;
            b = tmp;
        }

        return b;
    }

    //能跳1、2...n级的青蛙
    int jumpFloor2(int number)
    {
        return 1 << (number - 1);
    }

    //旋转数组最小值
    int minNumberInRoteArray(vector<int> arr)
    {
        if (arr.empty())
            return 0;

        int left = 0, right = arr.size() - 1;
        while (left < right)
        {
            if (arr[left] < arr[right])
                return arr[left];

            int mid = left + (right - left) / 2;
            if (arr[mid] > arr[left])
                left = mid + 1;
            else if (arr[mid] < arr[right])
                right = mid;
            else
                left++;
        }

        return arr[left];
    }

    //斐波那契数列
    int Fibonacci(int n)
    {
        if (n <= 0)
            return 0;

        int a = 1, b = 1;
        for (int i = 2; i < n; i++)
        {
            int tmp = a + b;
            a = b;
            b = tmp;
            return b;
        }
    }

    //重建二叉树
    TreeNode *reConstructBinaryTree(vector<int> pre, vector<int> vin)
    {
        auto root = reTree(pre, 0, pre.size() - 1, vin, 0, vin.size() - 1);
        return root;
    }

    TreeNode *reTree(vector<int> &pre, int preStart, int preEnd, vector<int> vin, int vinStart, int vinEnd)
    {
        if (preStart > preEnd || vinStart > vinEnd)
            return nullptr;

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

    //栈模拟队列
    stack<int> stack1, stack2;
    void myQueuePush(int node)
    {
        stack1.push(node);
    }

    int myQueuePop()
    {
        if (stack2.empty())
        {
            while (!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        int tmp = stack2.top();
        stack2.pop();
        return tmp;
    }

    //空格替换
    void replaceSpace(char *str, int length)
    {
        if (!str)
            return;

        int count = 0;
        for (int i = 0; i < length; i++)
        {
            if (str[i] == ' ')
                count++;
        }

        for (int i = length; i >= 0; i--)
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

    //返回链表倒序
    vector<int> printListFromTailToHead(ListNode *head)
    {
        vector<int> re;
        if (!head)
            return re;
        while (head)
        {
            re.emplace_back(head->val);
            head = head->next;
        }

        int i = 0, j = re.size() - 1;
        while (i < j)
        {
            swap(re[i++], re[j--]);
        }

        return re;
    }

    //排序矩阵找元素
    bool FindKInMatrax(int target, vector<vector<int>> array)
    {
        int row = array.size();
        int col = array.size();
        for (int i = row - 1, j = 0; i >= 0 && j < col;)
        {
            if (array[i][j] == target)
                return true;
            else
                array[i][j] < target ? j++ : i--;
        }
        return false;
    }
};