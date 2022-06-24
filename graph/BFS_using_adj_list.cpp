#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Graph
{
	int v;
	vector< list<int> > adj;

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
	visited[vertex] = true;
	queue.push_back(vertex);

	while(!queue.empty())
	{
		int cv = queue.front();
		queue.pop_front();

		cout << cv << "\t";

		for(auto adjacent : adj[cv])
		{
			if(!visited[adjacent])
			{
				visited[adjacent] = true;
				queue.push_back(adjacent);
			}
		}
	}
}


int main()
{
	Graph gp(5);

	gp.addEdge(0, 1);
	gp.addEdge(0, 2);
	gp.addEdge(1, 2);
	gp.addEdge(2, 3);
	gp.addEdge(3, 2);
	gp.addEdge(3, 0);
	gp.addEdge(3, 4);
	gp.addEdge(4, 0);

	gp.BFS(0);
	return 0;
}

