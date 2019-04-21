#include<bits/stdc++.h>
using namespace std;
#define max 100
int n,pid,arrival_time,cpu_time;
int waiting_time[max],turn_around_time[max];

vector< pair<int,pair<int,int> > > processInfo;

bool comparetor1(pair<int,pair<int,int> > &a,
                 pair<int,pair<int,int> > &b)
{
    return (a.second.second < b.second.second);
}

bool comparetor(pair<int,pair<int,int> > &a,
                pair<int,pair<int,int> > &b)
{
    return (a.second.first < b.second.first);
}

void getWaitingTime()
{
    int remaining_time[max];

    for (int i = 0; i < n; i++)
        remaining_time[i] = processInfo[i].second.second;

    int taskDone=0,currentTime=0,currentMin=INT_MAX,shortestProcess=0,finish_time=0;
    bool flag=false;

    while (taskDone!=n)
    {
        for (int i=0; i<n; i++)
        {
            if((processInfo[i].second.first<=currentTime) && (remaining_time[i]>0 && (remaining_time[i]<currentMin)))
            {
                currentMin=remaining_time[i];
                shortestProcess=i;
                flag=true;
            }
        }

        if (flag==false)
        {
            currentTime++;
            continue;
        }
        remaining_time[shortestProcess]--;

        currentMin=remaining_time[shortestProcess];
        if (currentMin==0)
            currentMin=INT_MAX;

        if (remaining_time[shortestProcess]==0)
        {
            taskDone++;
            flag=false;

            finish_time=currentTime++;

            waiting_time[shortestProcess]=finish_time-processInfo[shortestProcess].second.second-processInfo[shortestProcess].second.first;

            if (waiting_time[shortestProcess] < 0)
                waiting_time[shortestProcess] = 0;

            //continue;
        }
        currentTime++;

    }
}
void getTurnAroundTime(){

    for(int i=0; i<n; i++)
    {
        turn_around_time[i]=processInfo[i].second.second+waiting_time[i];
    }
}
/*
void getWaitingTime(){
    int service_time[n];

    service_time[0]=0;

    for(int i=1; i<n; i++)
    {
        service_time[i]=service_time[i-1]+processInfo[i-1].second.second;
        waiting_time[i]=service_time[i]-processInfo[i].second.first;

        cout<<service_time[i]<<endl;
        if(waiting_time[i]<0)
        {
            waiting_time[i]=0;
        }
    }
}
void getTurnAroundTime(){

    for(int i=0; i<n; i++)
    {
        turn_around_time[i]=processInfo[i].second.second+waiting_time[i];
    }
}
*/
void getAvgTime()
{
    int totalWaitingTime,totalTurnTIme;
    getWaitingTime();
    getTurnAroundTime();

    cout << "Processes "<< " Burst time "<< " Waiting time "<< " Turn around time\n";

    for (int i = 0; i < n; i++)
    {
        totalWaitingTime+=waiting_time[i];
        totalTurnTIme+=turn_around_time[i];
        cout << " " << processInfo[i].first << "\t\t"
             << processInfo[i].second.second<< "\t\t " << waiting_time[i]
             << "\t\t " << turn_around_time[i] << endl;
    }
}
int main()
{
    cin>>n;

    for(int i=0; i<n; i++)
    {
        pid=i+1;
        cin>>arrival_time>>cpu_time;

        processInfo.push_back(make_pair(pid,make_pair(arrival_time,cpu_time)));
    }

   // sort(processInfo.begin(),processInfo.end(),comparetor1);

    getAvgTime();
   /* for(int i=0; i<n; i++)
    {
        cout<< processInfo[i].first<<"\t"<< processInfo[i].second.first
            <<"\t"<<processInfo[i].second.second<<"\t"<<waiting_time[i]
            <<"\t"<<turn_around_time[i]<<endl;
    }*/
}
