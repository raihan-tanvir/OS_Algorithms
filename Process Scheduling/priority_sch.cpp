#include<bits/stdc++.h>
#include<tuple>
using namespace std;
#define max 100
int n,pid,at,bt,pr,wt,tat,ct;

vector<tuple<int,int,int,int,int,int,int>> processInfo;

bool comparetor( tuple<int,int,int,int,int,int,int> &a,
                 tuple<int,int,int,int,int,int,int> &b)
{
    if( get<1>(a) == get<1>(b) )
        return get<3>(a) > get<3>(b);
    else
        return get<1>(a) < get<1>(b);
}

void getWaitingTime()
{
    int service_time[n];

    service_time[0]=0;

    for(int i=1; i<n; i++)
    {
        service_time[i]=service_time[i-1]+get<2>(processInfo[i-1]);
        cout<<"st : "<<service_time[i]<<endl;

        get<4>(processInfo[i])=service_time[i]-get<1>(processInfo[i]);

        if(get<4>(processInfo[i])<0)
        {
            get<4>(processInfo[i])=0;
        }
        cout<<get<4>(processInfo[i-1])<<endl;
    }

}
void getTurnAroundTime()
{


}

void getAvgTime()
{

}
int main()
{
    cin>>n;

    for(int i=0; i<n; i++)
    {
        pid=i+1;
        wt=0;
        tat=0;
        ct=0;
        cin>>at>>bt>>pr;

        processInfo.push_back(make_tuple(pid,at,bt,pr,wt,tat,ct));

    }

    sort(processInfo.begin(),processInfo.end(),comparetor);



    getAvgTime();
    getWaitingTime();
}

/*
5
1 3 3
2 5 4
3 1 1
4 7 7
5 4 8
*/
