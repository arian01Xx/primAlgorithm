#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>

//floyd warshall's algorithm
//dijkstra's algorithm

using namespace std;

//trying prim's algorithm
void prim(int n, int startNode, vector<vector<pair<int,int>>>& graph){
	vector<bool> visited(n, false);
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	visited[startNode]=true;
	for(auto &edge: graph[startNode]){
		int weight=edge.first;
		int node=edge.second;
		pq.push({weight,node});
	}
	while(!pq.empty()){
		auto[weight,node]=pq.top();
		pq.pop();
		if(!visited[node]){
			visited[node]=true;
			for(auto &edge: graph[node]){
				int newWeight=edge.first;
				int adjacentNode=edge.second;
				if(!visited[adjacentNode]){
					pq.push({newWeight,adjacentNode});
				}
			}
		}
	}
}

vector<vector<pair<int,int>>> convertGraph(int n, vector<vector<int>>& graph){
	vector<vector<pair<int,int>>> adjList(n);
	for(const auto &edge: graph){
		int node1=edge[0];
		int node2=edge[1];
		int weight=edge[2];

		adjList[node1].push_back({weight,node2});
		adjList[node2].push_back({weight,node1});
	}
	return adjList;
}

int main(){

	cout<<"use the code by whatever you want!"<<endl;
	return 0;
}