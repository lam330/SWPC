#include <iostream>
#include <vector>
#include <set>
#include <bits.h>

using namespace std;


int n, m;//so luong dinh, canh
const int maxn = 100;// So luong dinh max
vector<pair<int, int>> adj[maxn];//Danh sách kề có trọng số => pair

void enterInput() {
    cout << "Enter n and m: " << endl;
    cin >> n;
    cout << endl << n << " vertexs" << endl;
    cin >> m;
    cout << endl << m  << " edges" << endl;

    for(int i = 0; i < m; i++) {//Nhap theo canh
        int x, y, w;
        cout << "x, y, w" << endl;
        cin >> x >> y >> w;//dinh x => y co trong so w
        adj[x].push_back({y,w});
//        adj[y].push_back(x, w); //vo huong
    }
}

void showGraph(vector<pair<int, int>> adj[], const int m) {
    for(int i = 1; i <= n; i++) {//Show theo dinh
        cout << i << " => ";
        for(int j = 0; j < adj[i].size(); j++) {
            cout << "{" << adj[i][j].first << "," << adj[i][j].second << "}  ";
        }
        cout << endl;
    }
}

const int INF = 1e9;
int pre[maxn];//Trace path from s -> t

void dijkstra(int start, int destination) {
    vector<int> distance(n + 1, INF); //distance from s to each vertex = INF
    distance[start] = 0;
    pre[start] =  start;
    vector<bool> visited(n + 1, false);

    multiset<pair<int, int>> queue;//Store {khoang cach, dinh} + sort theo khoang cach => get min

    queue.insert({0, start});
    while(!queue.empty()) {
        //Select min dinstance (s -> u)
        pair<int, int> first = *queue.begin();
        queue.erase(queue.begin());

        int u = first.second;
        int kc = first.first;

//        if(kc > distance[u]) continue;
        if(visited[u]) continue;
        visited[u] = true;
        //Relaxation: Update distance (s => every points adjacent to u
        for(auto it : adj[u]) {
            int v = it.first;//element of danh sach ke`{point, distance} # element in queue
            int w = it.second;
            if(distance[v] > distance[u] + w) { //(s -> v) > (s -> u) + (u -> v)
                distance[v] = distance[u] + w;
                queue.insert({distance[v],v});

                pre[v] = u;//s -> u -> v
            }
        }
    }
    //result
    for(int i = 1; i <= n; i++) {
        cout << distance[i] << ' ' ;
    }

    cout << "shortest from " << start << " to " << destination << " = " << distance[destination];

    //track path
    vector<int> path;
    while(1) {
        path.push_back(destination);
        if(destination == start) break;
        destination = pre[destination];
    }
    //reverse
    for(int x = path.size(); x >= 0; x-- ) {
        cout << path[x] << " -> ";
    }
}

int main()
{
    enterInput();
    showGraph(adj, m);
    int start = 0;
    cout << "Enter start: " << endl;
    cin >> start;
    cout << endl << "start = " << start << endl;
    dijkstra(start, 2);


    return 0;
}
