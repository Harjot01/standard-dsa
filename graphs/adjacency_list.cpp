#include<bits/stdc++.h>
using namespace std;

class Graph
{

public:
	vector<vector<int>> adjList;

	Graph(int vertices)
	{
		adjList.resize(vertices);
	}

	void addEdge(int u, int v)
	{
		// for undirected graph
		adjList[u].push_back(v);
		adjList[v].push_back(u);
		// 0 1 2 4 8 5 6 9 3 7 
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

	void bfs(int s, vector<bool> &visited)
	{
		visited[s] = 1;
		queue<int> q;
		q.push(s);

		while(!q.empty())
		{
			int curr = q.front();
			q.pop();
			cout<<curr<< " ";
			for(auto &v : adjList[curr])
			{
				if(!visited[v])
				{
					visited[v] = true;
					q.push(v);	
				}
			}
		}
	}

	void bfsDisconnectedGraph()
	{
		vector<bool> visited(adjList.size(), false);

		for(int i = 0; i < adjList.size(); ++i)
		{
			if(!visited[i])
			{
				bfs(i, visited);
			}
		}
	}

	void dfs(int s, vector<bool> &visited)
	{
		stack<int> st;
		visited[s] = true;
		st.push(s);

		while(!st.empty())
		{
			int top = st.top();
			st.pop();
			cout << top << " ";
			for(auto &v : adjList[top])
			{
				if(!visited[v])
				{
					visited[v] = true;
					st.push(v);
				}
			}
		}
	}

	void display()
	{
		cout << "Adjacency List:" << endl;
        for (int i = 0; i < adjList.size(); ++i)
        {
            cout << "Node " << i << ":";
           
            for (auto &val : adjList[i])
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
	int V = 14;
	Graph g(V);
	g.addEdge(10, 13);
	g.addEdge(0 ,1);
	g.addEdge(0 ,2);
	g.addEdge(0 ,4);
	g.addEdge(0 ,8);
	g.addEdge(1, 5);
	g.addEdge(1, 6);
	g.addEdge(1 ,9);
	g.addEdge(2 ,4);
	g.addEdge(3 ,7);
	g.addEdge(3 ,8);
	g.addEdge(5 ,8);
	g.addEdge(6 ,7);
	g.addEdge(6 ,9);


	g.display();	
	vector<bool> visited(V, false);


	g.dfs(0, visited);

	return 0;
}
