#include<bits/stdc++.h>
using namespace std;

#define max 100

int maxReq[max][max],allocRes[max][max],availRes[max],needRes[max][max],dead[max],safeSeq[max];
int n,r;

bool finish[max];

bool bankersAlgo()
{
    for(int i=0;i<n;i++)
        finish[i]=false;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<r;j++){
            needRes[i][j]=maxReq[i][j]-allocRes[i][j];
        }
    }

    int count = 0;
	while (count < n)
	{

		bool found = false;
		for (int i = 0; i < n; i++)
		{
			if (finish[i] == false)
			{
				int j;
				for (j = 0; j < r; j++)
					if (needRes[i][j] > availRes[j])
						break;
				if (j == r)
				{
					for (int k = 0 ; k < r ; k++)
						availRes[k] += allocRes[i][k];

					safeSeq[count++] = i;
					finish[i] = true;
					found = true;
				}
			}
		}
		if (found == false)
		{
			cout << "System is not in safe state";
			return false;
		}
	}

	cout << "System is in safe state.\nSafe"
		" sequence is: ";
	for (int i = 0; i < n ; i++)
		cout << safeSeq[i] << " ";

	return true;
}

int main(){
    cin>>n;
    cin>>r;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<r; j++)
        {
            cin>>maxReq[i][j];
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<r; j++)
        {
            cin>>allocRes[i][j];
        }
    }

    for(int i=0; i<r; i++)
    {
        cin>>availRes[i];
    }

    bankersAlgo();
}

/*

3
3
3 6 8
4 3 3
3 4 4
3 3 3
2 0 3
1 2 4
1 2 0

*/





























































































































