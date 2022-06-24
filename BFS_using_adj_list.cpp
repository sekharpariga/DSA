#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Graph
{
	int v;
	vector<list<int>> adj;

	public:
		Graph(int size);
		void addEdge(int vx1, int vx2);
		void BFS(int vertex);
};

Graph::Graph(int size)
{
	v = size;
	adj.resize(v);
}

void Graph::addEdge(int vx1, int vx2)
{
	adj[vx1].push_back(vx2);
}

void Graph::BFS(int vertex)
{
	vector<bool> visited;
	visited.resize(v, false);
	list<int> queue;

	queue.push_back(vertex);
	visited[vertex] = true;

	while(!queue.empty())
	{
		int cv = queue.front();
		queue.pop_front();
		cout << "current vertex visits :" << cv << endl;

		for(auto value : adj[cv])
		{
			visited[value] = true;
			queue.push_back(value);
			cout << cv << " -> " << endl;
		}

	}
}


int main()
{
	Graph gp(6);

	gp.addEdge(1, 4);
	gp.addEdge(1, 6);
	gp.addEdge(1, 3);
	gp.addEdge(2, 6);
	gp.addEdge(2, 3);
	gp.addEdge(2, 5);
	gp.addEdge(3, 1);
	gp.addEdge(3, 2);
	gp.addEdge(3, 4);
	gp.addEdge(3, 5);
	gp.addEdge(4, 6);
	gp.addEdge(4, 5);
	gp.addEdge(4, 3);
	gp.addEdge(4, 2);
	gp.addEdge(4, 1);
	gp.addEdge(5, 4);
	gp.addEdge(5, 6);
	gp.addEdge(5, 2);
	gp.addEdge(6, 4);
	gp.addEdge(6, 5);

	gp.BFS(1);

	return 0;
}

