#include<iostream>
#include<vector>
using namespace std;

const int MAX = 9999999;

void prims(int n, vector<vector<int>>& cost){
    vector<int> visit(n+1,0);
    int mincost = 0;

    int s;
    cout<<"Enter the starting vertex (1 to "<<n<<"): ";
    cin>>s;
    visit[s]=1;

    cout<<"Selected Edges: "<<endl;
    for(int k = 1; k< n; ++k){
        int min = MAX;
        int r,c;

        for(int i = 1; i<=n; ++i){
            if(visit[i]==1){
                for(int j = 1; j<=n; ++j){
                    if(visit[j]==0 && cost[i][j]!=-1 && min>cost[i][j]){
                        min =cost[i][j];
                        r =i;
                        c =j;
                    }
                }
            }
        }
        cout<<"Edge: "<<r<<"-"<<c<<endl;
        mincost +=min;
        visit[c] = 1;
        cost[r][c]=-1;
        cost[c][r]=-1;
    }
    cout<<"Total: "<<mincost<<endl;
}

int main(){
    int n;
    cout<<"Enter number of vertices: ";
    cin>>n;
    string cities[n];
    for(int i= 0; i<n; i++){
        cout<<"Enter City"<<i+1<<" :";
        cin.ignore();
        getline(cin,cities[i]);
    }
    vector<vector<int>> cost(n+1, vector<int>(n+1,0));
    
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++)
        {
            cout << "Enter cost to connect " << cities[i - 1] << " and " << cities[j - 1] <<": ";
            cin >> cost[i][j];
            cost[j][i] = cost[i][j];
        }
    }
    prims(n, cost);
    return 0;    
}