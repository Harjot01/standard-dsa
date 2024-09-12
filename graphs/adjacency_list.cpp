#include<bits/stdc++.h>
using namespace std;

class Graph
{
private:
	vector<vector<int>> adjList;
public:
	Graph(int vertices)
	{
		adjList.resize(vertices);
	}

	void addEdge(int u, int v)
	{
		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}

	void removeEdgeFromList(vector<int> &vec, int vertex)
	{
		auto position = find(vec.begin(), vec.end(), vertex);
		if(position != vec.end())
		{
			vec.erase(position);
		}
	}

	void removeEdge(int u, int v)
	{
		removeEdgeFromList(adjList[u], v);
		removeEdgeFromList(adjList[v], u);
	}

	void display()
	{
		for(auto &adj : adjList)
		{
			for(auto &val : adj)
				cout<<val<<" ";
			cout<<endl;
		}
	}

};

int main()
{
	Graph g(5);
	g.addEdge(0, 1);
	g.addEdge(0, 4);
	g.addEdge(4, 1);
	g.addEdge(4, 3);
	g.addEdge(1, 3);
	g.addEdge(1, 2);
	g.addEdge(3, 2);

	g.removeEdge(2, 1);

	g.display();



	return 0;
}