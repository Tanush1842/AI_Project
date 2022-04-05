#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define pii     pair<int,int>


class Graph {
    vector<pair<int, int>> *adj;
    int V; //total vertices in a graph

public:

    Graph(int n)
    {
        V = n;
        adj = new vector<pair<int, int>> [n]; //adjacency list of n - vertices is created.
    }

    //function for creation of adjacency list
    void addEdge(int x, int y, int w)
    {
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }

    //this will return the length of the mst
    int prim_mst(int src)
    {
        priority_queue<pii, vector<pii>, greater<pii>> q;


        //have a another array to store that MST-SET[]
        //visited array - to check that the node is inserted in MST-sEt or not.
        bool *visited = new bool[V] {0};
        int ans = 0;

        // begin
        q.push({0, src}); //{weight,node_value}

        while (!q.empty())
        {
            //pick out the min weighted edge
            auto best = q.top();
            q.pop();

            int to = best.second;
            int weight = best.first;

            if (visited[to])
            {
                //discard the edge
                continue;
            }

            //other wise - take currnet edge
            ans += weight;
            visited[to] = 1;

            //add the new edges in the queue
            for (auto x : adj[to])
            {
                if (!visited[x.first])
                {
                    q.push({x.second, x.first});
                }
            }
        }
        return ans;
    }
};


int main()
{
    int n, m, src;
    cout << "Number of Vertices :"; cin >> n;
    cout << "Number of Edges : "; cin >> m;
    Graph g(n);
    cout << "Input " << m << " Edges below :" << endl;
    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        cout << "u :"; cin >> x;
        cout << "v :"; cin >> y;
        cout << "weight of edge :"; cin >> w;
        cout << "\n------------\n";
        g.addEdge(x - 1, y - 1, w);
    }
    cout << "Enter the SRC Node : ";
    cin >> src;
    cout << "Weight of Minimum Spanning Tree : " << g.prim_mst(src - 1) << endl;

}


