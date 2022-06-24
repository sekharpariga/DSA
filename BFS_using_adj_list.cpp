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
		~Graph();
		void addEdge(int vx1, int vx2);
		void BFS(int vertex);
};

Graph::Graph(int size)
{
	v = size;
	adj.resize(v);
}

Graph::~Graph()
{
	cout << "clearing all the adj doubly linked list" << endl;

	for(auto it = adj.begin(); it != adj.end(); it++)
		it->clear();
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
	int size = 0;

	cout << "enter the number of vertecies: ";
	cin >> size;

	Graph *gp = new Graph(size);
	
	for(int i = 0; i < size; i++)
	{
		cout << "adding " << i+1 << " edge\n";
		int v1, v2;
		cin >> v1 >> v2;
		gp->addEdge(v1, v2);
	}
	int startVx = 0;
	cout << "enter starting vertex with which BFS should run from: ";
	cin >> startVx;
	gp->BFS(startVx);

	return 0;
}

