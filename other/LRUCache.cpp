#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

class LRUCache
{
	list<int> dq;
	unsigned int csize;
	unordered_map<int, list<int>::iterator> ma;

	public:
		LRUCache(unsigned int size);
		void refer(int element);
		void display();
};

LRUCache::LRUCache(unsigned int size)
{
	csize = size;
}

void LRUCache::refer(int element)
{
	if(ma.find(element) == ma.end())
	{
		if(dq.size() == csize)
		{
			int last = dq.back();
			dq.pop_back();
			ma.erase(last);
		}
	}else
		dq.erase(ma[element]);

	dq.push_front(element);
	ma[element] = dq.begin();
}

void LRUCache::display()
{
	for(auto it = dq.begin(); it != dq.end(); it++)
		cout << *it << " ";
	cout << "\n";
}

int main()
{
	LRUCache lc(4);
	lc.refer(1);
	lc.refer(3);
	lc.refer(3);
	lc.refer(3);
	lc.display();
	lc.refer(5);
	lc.display();
	lc.refer(11);
	lc.refer(22);
	lc.display();

	return 0;
}
