#include <bits/stdc++.h>
using namespace std;
#define MAX 10
#define INF 99999

typedef class warehouse{
    public:
    int availableSpace;
    class warehouse *next;
}

warehouse;

void updateCapacity(warehouse *wh){
    int i, newCapacity;
    cout<<endl<<"Enter Warehouse Number : ";
    cin>>i;
    cout<<endl<<"Enter new capacity(in percentage) : ";
    cin>>newCapacity;
    
    for(int j=1;j<=i;j++)
    {
        if(j==i)
        {
            wh->availableSpace = newCapacity;
        }
        wh=wh->next;
    }
}

void Display(warehouse *wh){
    cout<<endl;
    for(int i=1;i<=11;i++)
    {
        cout<<"\t Warehouse "<<i<<": Available space is "<< wh->availableSpace <<" percent."<<endl;
        wh=wh->next;
    }

}

void Display70(warehouse *wh){
    cout<<endl;
    for(int i=1;i<=11;i++)
    {
        if(wh->availableSpace<=30)
            cout<<"\t Available space in warehouse "<<i<<" is "<< wh->availableSpace <<" percent."<<endl;
        wh=wh->next;
    }
}

void Djikstra(int G[MAX] [MAX], int n, int start, warehouse *wh){

    int cost [MAX] [MAX], dist[MAX], visited [MAX], pred [MAX]; 
    int i, j, count, mindist, nextnode;

    for (i = 0; i<n; i++)
    {
        for (j = 0; j<n; j++)
        {
            if (G[i][j]==0) 
              cost[i][j] = INF;
            else
            cost[i][j] = G[i][j];
        }
    }

    for (i=0; i<n; i++)
    {
        dist[i] = cost[start][i]; 
        pred[i] = start;
        visited[i] = 0;
    }

    dist[start]=0; 
    visited[start]=1;
    count=1;

    while (count<n-1)
    {
        mindist = INF;
        for (i=0; i <n; i++)
        {
            if (dist[i] < mindist && !visited[i])
            {
                mindist = dist[i]; 
                nextnode = i;
            }
        }
        
        visited[nextnode] = 1;
        
        for (i = 0; i<n; i++)
        {
            if(!visited[i])
            {
                if ((mindist + cost[nextnode][i]) < dist[i]) 
                {
                    dist[i] = mindist + cost[nextnode][i]; 
                    pred[i] = nextnode;
                } 

            }
        }
        count++;
    }

    for (i=0;i<n;i++)
    {
        if (i != start)
        {
            cout<<endl<<"The distance of warehouse "<<i<<" from the farmer is "<<dist[i]<<"."<<endl;
            cout<<"The path is : "<<i;
            j = i;
            do{
                j = pred[j];
                cout<<" <---- "<<j;
            } while (j != start);
        }

    }

    cout<<endl<<endl<<"Available space in warehouses : "<<endl<<endl;

    for (i = 0; i<n; i++)
    {
        if (i != start)
        {
            for (int k = 0; k < 11; k++)
            {
                if(k==i)
                {
                    cout<<"\t Warehouse number "<<k<<" is "<<wh->availableSpace<<" percent vacant."<<endl;
                    wh= wh->next;
                }

                wh= wh->next;
            }

        }
    }

}

void mainProgram(int G[MAX] [MAX], int n, int start, warehouse *wh){
    
    cout<<endl<<"Enter number of warehouses (including farmer) : "; 
    cin>>n;
    cout<<endl<<"Enter the distances between each of the connections:"<<endl<<endl;
    for (int i = 0; i<n; i++)
    {
        for (int j = 0; j<n; j++)
           cin>>G[i][j];
    }

    cout<<endl<<"Enter source/farmer: ";
    cin>>start;
    cout<<endl;
    
    Djikstra(G, n, start, wh);
}

int main()
{
    warehouse *wh0, *wh1, *wh2, *wh3, *wh4, *wh5, *wh6, *wh7, *wh8, *wh9, *wh10;

    wh0 = new warehouse ();
    wh1 = new warehouse ();
    wh2 = new warehouse ();
    wh3 = new warehouse ();
    wh4 = new warehouse ();
    wh5 = new warehouse ();
    wh6 = new warehouse ();
    wh7 = new warehouse ();
    wh8 = new warehouse ();
    wh9 = new warehouse ();
    wh10 = new warehouse ();


    wh1->availableSpace = 30;
    wh1->next = wh2;

    wh2->availableSpace = 70;
    wh2->next = wh3;

    wh3->availableSpace = 40;
    wh3->next = wh4;

    wh4->availableSpace = 50;
    wh4->next = wh5;

    wh5->availableSpace = 55;
    wh5->next = wh6;

    wh6->availableSpace = 70;
    wh6->next = wh7;

    wh7->availableSpace = 80;
    wh7->next = wh8;

    wh8->availableSpace = 10;
    wh8->next = wh9;

    wh9->availableSpace = 20;
    wh9->next = wh10;

    wh10->availableSpace = 30;
    wh10->next = wh0;

    wh0->availableSpace = 50;
    wh0->next = wh1;
    
    cout<<endl<<endl;
    cout<<"\t\t<--------- THIS IS TERMINAL WINDOW --------->"<<endl<<endl<<endl;
    int G[MAX][MAX],n,start;
    int i,j,choice,trigger;

    cout<<"Choose the operator window"<<endl<<endl;
    cout<<"1. User Window"<<endl;
    cout<<"2. Administrator Window"<<endl<<endl;
    cout<<"Enter your operation number (Enter 0 to exit) : ";
    cin>>trigger;
    cout<<endl;

    switch(trigger)
    {
        case 1:
        cout<<endl<<endl;
        cout<<"\t\t<----- Welcome to the User Window ----->"<<endl<<endl;
        cout<<"Select from the following"<<endl<<endl;
        cout<<"1. Create Network"<<endl<<"\t -->will display available routes"<<endl<<"\t -->will dislay available warehouses"<<endl;
        cout<<"2. Exit"<<endl<<endl;

        do{
            cout<<"Enter your operation number (Enter 0 to exit) : ";
            cin>>choice;
            switch(choice)
            {
                case 0:
                cout<<endl<<"Program exited successfully."<<endl<<endl;
                exit(0);

                case 1:
                mainProgram(G,n,start,wh1);
                cout<<endl<<"Executed successfully."<<endl<<endl;
                break;

                case 2:
                cout<<endl<<"Program exited successfully."<<endl<<endl;
                exit(0);

                default:
                cout<<endl<<"Invalid Choice. Closing program now."<<endl<<endl;
                exit(0);
            }
        } while(choice!=2);

        break; 

        case 2:
        cout<<endl<<endl;
        cout<<"\t\t<----- Welcome to Admnistrator window ----->"<<endl<<endl;
        cout<<"Select from the following:"<<endl<<endl;
        cout<<"1. Display network of warehouses"<<endl<<"\t --> Show available spaces"<<endl<<endl;
        cout<<"2. Update capacity of warehouse"<<endl<<endl;
        cout<<"3. Display warehouses ready for quick sell"<<endl<<"\t--> Warehouses with atmost 30 percent capacity"<<endl<<endl;
        cout<<"4. Exit"<<endl<<endl;

        do{
            cout<<endl<<"Enter your operation number (Enter 0 to exit) : ";
            cin>>choice;
            
            switch (choice)
            {
                case 0:
                cout<<endl<<"Program exited successfully."<<endl<<endl;
                exit(0);

                case 1:
                cout<<endl<<"Following are the current capacaties of the warehouses."<<endl<<endl;
                Display (wh1);
                break;
                
                case 2:
                updateCapacity (wh1);
                cout<<endl<<"Following are the updated capacaties of the warehouses."<<endl<<endl;
                Display (wh1);
                cout<<endl<<"Updated succesfully."<<endl<<endl;
                break;
                
                case 3:
                cout<<endl<<"Following are the warehouses ready for quick sell."<<endl<<endl;
                Display70(wh1);
                cout<<endl<<"Displayed succesfully."<<endl<<endl;
                break;
                
                case 4:
                cout<<endl<<"Program exited successfully."<<endl<<endl;
                exit(0);
                
                default:
                cout<<endl<<"Invalid Choice. Closing Program now."<<endl<<endl;
                exit(0);

            } 
        } while(choice!=4);
            
            break;

            default:
            cout<<endl<<"Invalid Choice. Closing Program now."<<endl<<endl;
            exit(0);
  
    }

    return 0;

}
