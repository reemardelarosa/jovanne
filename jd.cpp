    #include <iostream>
    #include <cstdlib>
    #include<algorithm>
    #include <math.h>
    using namespace std;
    //main variable declaration
    int bursttime[100],waitingtime[100],completiontime[100];

    int mainmenu(int);
    int FCFS();
    int PF();
    int SJF();
    int RR();


    int main()
    {
        int a=0;
            cout<<"MENU\n";
            cout<<"\n1. FIRST COME FIRST SERVED";
            cout<<"\n2. PRIORITY FIRST";
            cout<<"\n3. SHORTEST JOB FIRST";
            cout<<"\n4. ROUND ROBIN";
            cout<<"\n5. EXIT";
            cout<<"\n\nEnter your choice:\t";
            cin>>a;
            switch(a)
            {
                case 1:FCFS();break;
                case 2:PF();break;
                case 3:SJF();break;
                case 4:RR();break;
                case 5:return 0;break;
            }
    }

    int findSmallestElement(int arr[], int n){
       int temp = arr[0];
       for(int i=0; i<n; i++) {
          if(temp>arr[i]) {
             temp=arr[i];
          }
       }
       return temp;
    }
    int FCFS()
    {
        int np,a,b,c,avewaittime=0,avecomtime=0, maxChar = 100;
        cout<<"\nFIRST COME FIRST SERVED SCHEDULING";
        cout<<"\nEnter total number of process: ";
        cin>>np;
        cout<<"Enter Process Burst Time:\n";
        int bursttime[np];
        for (a=0;a<np;a++)
        {
            cout<<"P["<<a+1<<"]: ";
            cin>>bursttime[a];
        }
        waitingtime[0]=0;
        for (a=1;a<np;a++)
        {
            waitingtime[a]=0;
            for (b=0;b<a;b++)
            {
                waitingtime[a]+=bursttime[b];
            }
        }
        cout<<"\nProcess\t\tBurst Time\tWaiting Time\tCompletion Time";
        for(a=0;a<np;a++)
        {
            completiontime[a]=bursttime[a]+waitingtime[a];
            avewaittime+=waitingtime[a];
            avecomtime+=completiontime[a];
            cout<<"\n P["<<a+1<<"]"<<"\t\t   "<<bursttime[a]<<"\t\t    "<<waitingtime[a]<<"\t\t    "<<completiontime[a];
        }
        avewaittime/=a;
        avecomtime/=a;
        cout<<"\n\nAverage Waiting Time:"<<avewaittime;
        cout<<"\nAverage Turnaround Time:"<<avecomtime<<'\n';
        cout<<'\n';
        cout<<"GANTT CHART\n";
        int total = completiontime[np-1];
        int min = findSmallestElement(bursttime, np);
        int bursttimeratio[np] = {};
        copy(bursttime, bursttime+np, bursttimeratio);
        if (total >= 100) { //check if beyond the maxchar per line
            for (a=0;a<np;a++)
            {
                bursttimeratio[a] = ceil(bursttime[a]/min) + 2;
            }
        }
        cout<<'\n';
        cout<<"+";
        // upper line
        for(a=0;a<np;a++)
        {
            for (b=0;b<bursttimeratio[a];b++)
            {
                cout<<"-";
            }
            cout<<"+";
        }
        cout<<"\n|";
        cout<<" ";
        // middle numbers
        for(a=0;a<np;a++)
        {
            int toSubtract = (bursttime[a] % 2 == 0) ? 3 : 4;
            for(b=0;b<(bursttimeratio[a]-1)/2;b++)
            {
                cout<<" ";
            }
            cout<<bursttime[a];
            for (b=0;b<(bursttimeratio[a]- toSubtract + a)/2;b++)
            {
                cout<<" ";
            }
            cout<<"|";


        }
        cout<<"\n+";
        // lower line
        for (a=0;a<np;a++)
        {
            for (b=0;b<bursttimeratio[a];b++)
            {
                cout<<"-";
            }
            cout<<"+";
        }
        cout<<"\n";
        cout<<"0";
        // lower numbers
        for(a=0;a<np;a++)
        {
            for (b=0;b<bursttimeratio[a];b++)
            {
                cout<<" ";

            }
            if(completiontime[a]>np)
            {
                cout<<"\b";
            }
            cout<<completiontime[a];
        }
        cout<<"\n";
    }

    int PF()
    {
        cout<<"PRIORITY FIRST SCHEDULING";
    }

    int SJF()
    {
        cout<<"SHORTEST JOB FIRST SCHEDULING";
    }

    int RR()
    {
        cout<<"ROUND ROBIN SCHEDULING";
    }
