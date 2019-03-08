#include <bits/stdc++.h>

using namespace std;
float getmedian(vector<int> count,int d)
{
int k =0;
    if(d%2!=0)
    {
    int mid = (d+1)/2;
        for(int i =0;i<=200;i++)
        {
            if(count[i]>=1)
            {
                k+=count[i];
            }
            if(k>=mid)
            {
                return i;
            }

        }

    }
    else{
        int first = d/2;
        int second = d/2+1;
        int median1 = -1;
        int median2 = -1;
        float median=-1;
        for(int i =0;i<=200;i++)
        {
            if(count[i]>=1)
            {
                k+=count[i];
            }
            if(k>=first && k>=second && median1==-1)
            {
                return i;
            }
            if(k>=first && median1==-1)
            {
                median1 = i;
                cout<<"first median"<<i;
            }
            if(k>=second)
            {
                cout<<"second median"<<i;
                median = (float)(median1+i)/2;
                cout<<"averaga is :"<<median<<endl;
                return median;
            }


        }
    }

}


// Complete the activityNotifications function below.
int activityNotifications(vector<int> expenditure, int d) {
//queue<int> q;
vector<int> count(201);
float median = 0;
int notification = 0;
int n = expenditure.size();

for(int i =0;i<d;i++){
    count[expenditure[i]]++;
}
for(int i =d;i<n;i++)
{

    median = getmedian(count,d);
    if(expenditure[i]>=2*median)
    {
        notification++;
    }

    count[expenditure[i-d]]--;
    count[expenditure[i]]++;
    //cout<<median<<endl;
}
    //q.push(expenditure);
return notification;

}

int main()
{
   int n,d;

    cin>>n>>d;


    vector<int> expenditure(n);

    for (int i = 0; i < n; i++) {
       cin>>expenditure[i];
    }

    int result = activityNotifications(expenditure, d);

    cout <<result << "\n";

    //fout.close();

    return 0;
}

