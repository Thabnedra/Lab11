#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <string>
using namespace std;
typedef pair<int, int> pii;
//dijkstra algorithm for SSSP
vector<int> DijkstraAlgo(vector<vector<pii>>& graph, int start) {
    vector<int> distance(graph.size(), numeric_limits<int>::max()); // intialize relaxtion
    distance[start] = 0;
    //introduce priority queue name temprory priority queu(tempPQ)
    priority_queue<pii, vector<pii>, greater<pii>> tempPQ;
    tempPQ.push(make_pair(0, start));

    while (!tempPQ.empty()) { // check tempPQ empty or not.
        int u = tempPQ.top().second; //take root node  
        int currentDistance = tempPQ.top().first; // take root node distance
        tempPQ.pop();

        // Skip if the popped vertex has already been processed
        if (currentDistance > distance[u]) continue;

        for (pii neighbor : graph[u]) { //take neighbours of root node
            int v = neighbor.first; // take neighbour element
            int weight = neighbor.second; // take  u v path weight
            if (distance[v] > distance[u] + weight) {  // relaxtation 
                distance[v] = distance[u] + weight;
                tempPQ.push(make_pair(distance[v], v));
            }
        }
    }

    return distance;
}
//print sorteset time of each cities
void PrintSortestPathfromSourcetoOther(vector<int> distance,int start) { // distance array, source node
    int total=0; // calculate sum of time 
    for (int i = 0; i < distance.size(); i++) {
        if(start!=i){
        cout<<"City "<<to_string(start)<<" to "<<"City "<<to_string(i)<<" :"<<to_string(distance[i])<<endl;
        total+=distance[i];
        }
    }
    cout<<"Avarage time City "<<to_string(start)<<" to other is: "<<to_string(total/5)<<endl; // find average 

    cout<<endl;
}

//add values in adj matrix for graph
void AddAjancenceMatrix(vector<vector<pii>>& graph, int u,int v,int weight){ // graph,from,to, weight of path
     //un direct graph
    graph[u].push_back(make_pair(v, weight));
    graph[v].push_back(make_pair(u, weight));
}

int main(){
    vector<vector<pii>> graph(6); // 6 cities
    // add values in graph represent as adj matrix
    AddAjancenceMatrix(graph, 0,1,10);
    AddAjancenceMatrix(graph, 0,4,15);
    AddAjancenceMatrix(graph, 0,5,5);
    AddAjancenceMatrix(graph, 1,2,10);
    AddAjancenceMatrix(graph, 1,3,30);
    AddAjancenceMatrix(graph, 2,3,12);
    AddAjancenceMatrix(graph, 2,4,5);
    AddAjancenceMatrix(graph, 3,5,20);
    // get shortest path from source node to other node
    // source node is city 0
    cout<<"Source node is City 0"<<endl;
    PrintSortestPathfromSourcetoOther(DijkstraAlgo(graph, 0),0);
    // source node is city 1
    cout<<"Source node is City 1"<<endl;
    PrintSortestPathfromSourcetoOther(DijkstraAlgo(graph, 1),1);
    // source node is city 2
    cout<<"Source node is City 2"<<endl;
    PrintSortestPathfromSourcetoOther(DijkstraAlgo(graph, 2),2);
    // source node is city 3
    cout<<"Source node is City 3"<<endl;
    PrintSortestPathfromSourcetoOther(DijkstraAlgo(graph, 3),3);
    // source node is city 4
    cout<<"Source node is City 4"<<endl;
    PrintSortestPathfromSourcetoOther(DijkstraAlgo(graph, 4),4);
    // source node is city 5
    cout<<"Source node is City 5"<<endl;
    PrintSortestPathfromSourcetoOther(DijkstraAlgo(graph, 5),5);
    return 0;
}