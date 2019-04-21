#include<bits/stdc++.h>
using namespace std;

#define max 100
int n;
int pid[max],cpu_time[max],arrival_time[max],priority[max],waiting_time[max],turn_around_time[max],compTime[max];

void getWaitingTime()
{
    int service_time[n];

    service_time[0]=0;

    for(int i=1; i<n; i++)
    {
        service_time[i]=service_time[i-1]+cpu_time[i-1];
        waiting_time[i]=service_time[i]-arrival_time[i];

        if(waiting_time[i]<0)
        {
            waiting_time[i]=0;
        }
    }
}

void getTurnAroundTime()
{

    for(int i=0; i<n; i++)
    {
        turn_around_time[i]=cpu_time[i]+waiting_time[i];
    }
}

void getAvgTime()
{

    int totalWaitingTime,totalTurnAroundTime;
    getWaitingTime();
    getTurnAroundTime();

    for(int i=0; i<n; i++)
    {
        totalWaitingTime+=waiting_time[i];
        totalTurnAroundTime+=turn_around_time[i];
        compTime[i]=turn_around_time[i]+arrival_time[i];
    }
    float avgWaitingTime,avgTurnAroundTime;
    avgWaitingTime=totalWaitingTime/n;
    avgTurnAroundTime=totalTurnAroundTime/n;

    cout<<"pid\tcpu_time\tarrival_time\twaiting_time\tturn_around_time\n";
    for(int i=0; i<n; i++)
    {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n",pid[i],cpu_time[i],arrival_time[i],waiting_time[i],turn_around_time[i]);
    }
}
int main()
{
    cout<<"Enter n:"<<"\n";
    cin>>n;

    cout<<"Enter Process arrival time and cpu time:"<<"\n";
    for(int i=0; i<n; i++)
    {
        pid[i]=i+1;
        cin>>arrival_time[i]>>cpu_time[i]>>priority[i];
    }


    getAvgTime();
}
