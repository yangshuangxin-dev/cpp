#include <bits/stdc++.h>

using namespace std;
#define MAX_SIZE 100
class MiniMemoryPool
{
public:
    vector<int> memPool;
    MiniMemoryPool()
    {
        memPool.resize(100, -1);
    }

    int Request(int size)
    {
        if (size > 100 || size <= 0)
        {
            return -1;
        }

        int start = 0;
        int end = 0;
        while (end < memPool.size() && (end - start) < size)
        {
            if (memPool[end] != -1)
            {
                start = end + 1;
            }
            end++;
        }

        if ((end - start) == size)
        {
            for (int i = start; i < end; i++)
            {
                memPool[i] = start;
            }
            return start;
        }

        return -1;
    }

    bool Release(int startAddr)
    {
        if (memPool[startAddr] != startAddr)
        {
            return false;
        }

        for (int i = startAddr; i < memPool.size() && memPool[i] == startAddr; i++)
        {
            memPool[i] = -1;
        }
        return true;
    }
};

int main()
{
    int num;
    cin >> num;

    MiniMemoryPool pool;
    for (int loop = 0; loop < num; loop++)
    {
        string line;
        cin >> line;

        string commond = line.substr(0, line.find_first_of('='));
        if (commond == "REQUEST")
        {
            int size = stoi(line.substr(line.find_first_of('=') + 1));
            int result = pool.Request(size);
            if (result != -1)
            {
                cout << result << endl;
            }
            else
            {
                cout << "error" << endl;
            }
        }
        else if (commond == "RELEASE")
        {
            int addr = stoi(line.substr(line.find_first_of('=') + 1));
            if (!pool.Release(addr))
            {
                cout << "error" << endl;
            }
        }
    }

    return 0;
}