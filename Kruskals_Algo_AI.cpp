#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class DSU {

    int *parent; //we need to store the parent of each node
    int *rank;  //used to store the rank of each node

public:
    //intialize the DSU with n-vertices of the graph
    DSU(int n)
    {
        parent = new int[n];
        rank = new int[n];

        for (int i = 0; i < n; i++) {
            parent[i] = -1;
            rank[i] = 1;
        }

    }

    //find function
    int find(int i)
    {
        //base case
        if (parent[i] == -1)return i;

        //otherwise
        return parent[i] = find(parent[i]);
    }



    //unite(union) function
    void unite(int x, int y)
    {
        //find the set to which node - x belong
        int s1 = find(x);
        //find the set to which node - y belong
        int s2 = find(y);

        if (s1 != s2)
        {
            //union is done by rank
            if (rank[s1] < rank[s2]) {
                parent[s1] = s2;
                rank[s2] += rank[s1];
            }
            else
            {
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
        }
    }
};


class Graph {

    vector<vector<int>> edgelist;
    int v;

public:
    Graph(int n) {
        v = n;
    }

    void addEdge(int x, int y, int w)
    {
        edgelist.push_back({w, x, y});
    }

    int kruskal_mst()
    {
        //sort all edges based upon weight
        sort(edgelist.begin(), edgelist.end()); //O(ElogE)

        //intialize DSU
        DSU s(v); // O(V).

        int ans = 0;

        for (auto edge : edgelist) // O(E)
        {
            int w = edge[0];
            int x = edge[1];
            int y = edge[2];

            if (s.find(x) != s.find(y)) //find ~  take O(1)
            {
                s.unite(x, y);//union take ~ O(1)
                ans += w;
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
    cout << "Weight of Minimum Spanning Tree : " << g.kruskal_mst() << endl;
}