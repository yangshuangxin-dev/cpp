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
    ListNode *deleteDuplication(ListNode *pNode)
    {
        if (!pNode || !pNode->next)
        {
            return pNode;
        }

        auto head = new ListNode(-1);
        head->next = pNode;
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

        pNode = head->next;
        delete head;
        return pNode;
    }
};

//出现一次的字符
class Solution13
{
    vector<int> str;
    int hash[256] = {0};

    void Insert(char ch)
    {
        str.emplace_back(ch);
        hash[ch]++;
    }

    char FirstAppearingOnce()
    {
        for (auto i : str)
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

class Solution15
{
    bool match(char *str,char *pattern)
    {
        if(!str||!pattern)
        {
            return false;
        }

        if(!*pattern)
        {
            return !*str;
        }

        if(*(pattern+1)=='*')
        {
            return match(str,pattern+2)||
            (*str==*pattern||*str&&*pattern=='.')&&match(str+1,pattern);
        }

        return (*str==*pattern||*str&&*pattern=='.')&&match(str+1,pattern+1);
    }
};

class Solution16
{
    bool isNumber(char *str)
    {
        if(!str)
        {
            return false;
        }

        if(*str=='+'||*str=='-')
        {
            str++;
        }

        bool flag=false;
        check(str,flag);

        if(*str=='.')
        {
            check(++str,flag);
        }

        if(flag&&(*str=='e'||*str=='E'))
        {
            str++;
            flag=false;
            if(*str=='+'||*str=='-')
            {
                str++;
            }

            check(str,flag);
        }

        return flag&&*str;
    }

    void check(char *&str,bool &flag)
    {
        while(isdigit(*str))
        {
            flag=true;
            str++;
        }
    }
};



class Solution18
{
    vector<int> multiply(vector<int> A)
    {
        vector<int> res;
        res.emplace_back(1);
        for(auto i:A)
        {
            res.emplace_back(i*res.back());
        }
        res.pop_back();

        for(int i=A.size()-1,tmp=1;i>=0;i--)
        {
            res[i]*=tmp;
            tmp*=A[i];
        }

        return res;
    }
};

class Solution19
{
    int Add(int num1,int num2)
    {
        return num2?Add(num1^num2,(num1&num2)<<1):num1;
    }
};

class Solution20
{
    int StrToInt(string str)
    {
        if(str.empty())
        {
            return 0;
        }

        long long res;
        int flag=(str[0]=='-')?-1:1;
        int i=(str[0]=='-'||str[0]=='+')?1:0;
        for(;i<str.size();i++)
        {
            if(!(str[i]>='0'&&str[i]<='9'))
            {
                return 0;
            }

            res+=(res<<1)+(res<<3)+(str[i]&0xf);  
        }

        res*=flag;
        if(res>INT_MAX||res<INT_MIN)
        {
            return 0;
        }

        return res;
    }
};

class Solution21
{
    int LastRemaing(int n,int m)
    {
        if(n==0)
        {
            return -1;
        }

        if(n==1)
        {
            return 0;
        }

        return (LastRemaing(n-1,m)+m)%n;


    }
};


class Solution22
{
    int sum(int n)
    {
        return mul(n,n+1)/2;
    }

    int mul(int a,int b)
    {
        int res=0;
        (a&1)&&(res+=b);
        a>>=1;
        b<<=1;
        (a)&&(res+=mul(a,b));
        return res;
    }
};

class Solution23
{
    string ReverSentence(string str)
    {
        if(str.empty())
        {
            return str;
        }

        reStr(str,0,str.size()-1);

        int i=0,start=0;
        while(i<str.size())
        {
            while(i<str.size()&&str[i]==' ')
            {
                i++;
            }

            start=i;

            while(i<str.size()&&str[i]!=' ')
            {
                i++;
            }

            reStr(str,start,i-1);
        }

        return str;
    }

    void reStr(string &str,int i,int j)
    {
        while(i<j)
        {
            swap(str[i++],str[j--]);
        }
    }
};


class Solution24
{
    bool IsContinous(vector<int> number)
    {
        if(number.empty())
        {
            return false;
        }

        char hash[14]={0};

        int max=-1,min=14;
        for(int i:number)
        {
            if(i==0)
            {
                continue;
            }

            if(++hash[i]>1)
            {
                return false;
            }

            max=max>i?max:i;
            min=min<i?min:i;
        }

        return (max-min)<5;
    }
};


class Solution25
{
    vector<int> FindNumbersWithSum(vector<int> array,int sum)
    {
        vector<int> res;

        if(array.empty())
        {
            return res;
        }

        int left=0,right=array.size()-1;
        while(left<right)
        {
            int tmp=array[left]+array[right];
            if(tmp==sum)
            {
                res.emplace_back(array[left]);
                res.emplace_back(array[right]);
                break;
            }
            tmp<sum?left++:right--;
        }

        return res;
    }
};

//循环左移
class Solution26
{
    string leftRotateString(string str,int n)
    {
        if(str.empty()||n<=0)
        {
            return str;
        }

        reStr(str,0,n-1);
        reStr(str,n,str.size()-1);
        reStr(str,0,str.size()-1);
        return str;
    }

    void reStr(string &str,int i,int j)
    {
        swap(str[i++],str[j--]);
    }
};


class Solution27
{
    void FindNumsAppearOnce(vector<int> data,int *num1,int *num2)
    {
        int diff=accumulate(data.begin(),data.end(),0,bit_xor<int>());
        diff&=-diff;
        for(int i:data)
        {
            if(i&diff)
            {
                *num1^=i;
            }
            else
            {
                *num2^=i;
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

        int left=1,right=2;
        while(left<right)
        {
            int sum=(left+right)*(right-left+1)/2;
            if(num==sum)
            {
                vector<int> re;
                for(int i=left;i<=right;i++)
                {
                    re.emplace_back(i);
                }
                res.emplace_back(re);
                left++;
            }
            else
            {
                num>sum?right++:left++;
            }
            
        }

        return res;
    }
};


class Solution29
{
    int TreeDepth(TreeNode *root)
    {
        return root?max(TreeDepth(root->left),TreeDepth(root->right))+1:0;
    }
};


class Solution30
{
    bool IsBance(TreeNode *root)
    {
        return getDepth(root)!=-1;
    }

    int getDepth(TreeNode *root)
    {
        if(!root)
        {
            return 0;
        }

        int left=0,right=0;
        if( (left=getDepth(root->left))==-1 )
        {
            return -1;
        }

        if( (right=getDepth(root->right))==-1 )
        {
            return -1;
        }

        return abs(left-right)>1?-1:max(left,right)+1;
    }
};


