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

	void bfs(int s, int V, vector<bool> &visited)
	{
		visited[s] = true;
		queue<int> q;
		q.push(s);

		while(!q.empty())
		{
			int curr = q.front();
			q.pop();
			cout << curr << " ";

			for(int i = 0; i < V; ++i)
			{
				if(adjMatrix[curr][i] == 1 && !visited[i])
				{
					visited[i] = true;
					q.push(i);
				}
			}


		}
	}

	void bfsDisconnectedGraph()
	{
		vector<bool> visited(adjMatrix.size(), false);

		for(int i = 0; i < adjMatrix.size(); ++i)
		{
			if(!visited[i])
				bfs(i, adjMatrix.size(), visited);
		}
	}

	void display()
	{
		cout << "Adjacency Matrix:" << endl;
        for (int i = 0; i < adjMatrix.size(); ++i)
        {
            cout << "Node " << i << ":";
           
            for (auto &val : adjMatrix[i])
            {
	            cout << " -> " << val;
            }
            
            cout << endl;
        }
        cout<<endl;
	}

};

int main()
{
	// Implement a graph using adjacency matrix

	int V = 5;
	Graph g(V);
	g.addEdge(0, 1);
	g.addEdge(0, 4);
	g.addEdge(4, 1);
	g.addEdge(4, 3);
	g.addEdge(1, 3);
	g.addEdge(1, 2);
	g.addEdge(3, 2);

	vector<bool> visited(V, false);
	g.display();

	g.bfsDisconnectedGraph();




	return 0;
}
