#include<bits/stdc++.h>
using namespace std;

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
            if (s.find(pages[i]) == s.end())
            {
                int val = pageQueue.front();
                pageQueue.pop();
                s.erase(val);
                s.insert(pages[i]);
                pageQueue.push(pages[i]);
                page_faults++;
            }
        }
        cout<<endl;
        queue<int>tempQ(pageQueue);
        while(!tempQ.empty())
        {
            cout<<tempQ.front()<<" ";
            tempQ.pop();
        }
        cout<<endl;
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
