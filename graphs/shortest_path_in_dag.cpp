#include <iostream>
#include <list>
#include <stack>
using namespace std;

class AdjListNode
{
public:
	int v;
	int weight;

	AdjListNode(int _v, int _w)
	{
		v = _v;
		weight = _w;
	}
	int getV() { return v; }
	int getWeight() { return weight; }
};

class Graph
{
	int V;

	vector<list<AdjListNode>> arr;

	void topologicalSortUtil(int s, vector<bool> &visited, stack<int> &st);

public:
	Graph(int V);

	void addEdge(int u, int v, int weight);

	void shortestPath(int s);
};

Graph::Graph(int V) : V(V), arr(V)
{
	// Constructor initializer list initializes adj with V lists
	// or adj.resize(V) acc to old c++
}

void Graph::addEdge(int u, int v, int weight)
{
	AdjListNode node(v, weight);
	arr[u].push_back(node);
}

void Graph::topologicalSortUtil(int s, vector<bool> &visited, stack<int> &st)
{
	visited[s] = true;

	for (auto ele : arr[s])
	{
		if (visited[ele.getV()] == false)
		{
			topologicalSortUtil(ele.getV(), visited, st);
		}
	}

	st.push(s);
}

void Graph::shortestPath(int s)
{
	vector<bool> visited(V, false);
	vector<int> dist(V, INT_MAX);
	stack<int> st;

	for (int i = 0; i < V; i++)
	{
		if (visited[i] == false)
		{
			topologicalSortUtil(i, visited, st);
		}
	}

	dist[s] = 0;

	while (st.empty() == false)
	{
		int top = st.top();
		st.pop();

		// calculating distance

		for (auto num : arr[top])
		{
			if (dist[num.getV()] != INT_MAX)
			{
				if (dist[num.getV()] > dist[top] + num.getWeight())
				{
					dist[num.getV()] = dist[top] + num.getWeight();
				}
			}
		}

		// print

		for (int i = 0; i < V; i++)
		{
			(dist[i] == INT_MAX) ? cout << "INF " : cout << dist[i] << " ";
		}
	}
}

int main()
{
	/*
		2       3       6
	0 ----> 1 ----> 2 ----> 3
	|             ↗         ▲
	| 1        ↗            |
	|      ↗    2           |
	v   ↗                   |
	4 ----> 5 --------------▲
		4         1

	*/
	Graph g(6);
	g.addEdge(0, 1, 2);
	g.addEdge(0, 4, 1);
	g.addEdge(1, 2, 3);
	g.addEdge(4, 2, 2);
	g.addEdge(4, 5, 4);
	g.addEdge(2, 3, 6);
	g.addEdge(5, 3, 1);

	int s = 0;
	cout << "Following are shortest distances from source " << s << " \n";
	g.shortestPath(s);

	return 0;
}
