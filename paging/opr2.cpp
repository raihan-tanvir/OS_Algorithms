#include<bits/stdc++.h>
using namespace std;

int predict(int pg[], unordered_set<int> s, int pn, int index)
{
    int temp[pn],tempIndex=index;
    for(int i=0; i<pn-index; i++)
    {
        temp[i]=pg[tempIndex++];
    }

    int res = -1, farthest = index;
    for (int i = index; i < pn; i++)
    {
        if (s.find(pg[i]) == s.end())
        {
                return i;
        }
        else
        {
            if (i > farthest)
            {
                farthest = i;
                res = i;
            }
        }
    }

    return (res == -1) ? 0 : res;
}

int pageFaults(int pages[], int n, int capacity)
{
    unordered_set<int> s;
    queue<int> pageQueue;

    int page_faults = 0;
    for (int i=0; i<n; i++)
    {
        if (s.size() < capacity)
        {
            if (s.find(pages[i])==s.end())
            {
                s.insert(pages[i]);
                page_faults++;
                pageQueue.push(pages[i]);
            }
        }
        else
        {
            int j = predict(pages, s, n, i + 1);
            s.erase(j);
            s.insert( pages[i]);
        }
    }

    return page_faults;
}

int main()
{
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4,
                   2, 3, 0, 3, 2
                  };
    int n = sizeof(pages)/sizeof(pages[0]);
    int capacity = 4;
    cout << pageFaults(pages, n, capacity);

    return 0;
}
