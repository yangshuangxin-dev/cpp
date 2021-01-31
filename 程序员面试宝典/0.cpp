// 确定字符互异
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
