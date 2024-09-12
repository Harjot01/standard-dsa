#include<bits/stdc++.h>
using namespace std;

class Graph
{
private:
	int numVertices;
	vector<vector<int>> adjMatrix;
public:
	Graph(int numVertices)
	{
		this->numVertices = numVertices;
		adjMatrix.resize(numVertices, vector<int> (numVertices, 0));
	}

	void addEdge(int u, int v)
	{
		if(u >= 0 && u < numVertices && v >= 0 && v < numVertices)
		{
			adjMatrix[u][v] = 1;
			adjMatrix[v][u] = 1;
		}
	}

	void removeEdge(int u, int v)
	{
		if(u >= 0 && u < numVertices && v >= 0 && v < numVertices)
		{
			adjMatrix[u][v] = 0;
			adjMatrix[v][u] = 0;
		}
	}

	void display()
	{
		for(auto &row : adjMatrix)
		{
			for(auto &val : row)
				cout<<val<<" ";
			cout<<endl;
		}
	}

};

int main()
{
	// Implement a graph using adjacency matrix

	Graph g(5);
	g.addEdge(0, 1);
	g.addEdge(0, 4);
	g.addEdge(4, 1);
	g.addEdge(4, 3);
	g.addEdge(1, 3);
	g.addEdge(1, 2);
	g.addEdge(3, 2);

	g.removeEdge(4, 3);

	g.display();



	return 0;
}