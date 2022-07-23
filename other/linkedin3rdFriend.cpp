#include <iostream>
#include <list>
#include <vector>

using namespace std;

class friends{
    vector<list<int>> edge;
    int size;
    public:
        friends(int _size){
            size = _size;
            edge.resize(size);
        }
        
        void addFriend(int x, int y){
            edge[x].push_back(y);
            edge[y].push_back(x);
        }
        
        bool isFriend(int x, int y){
            vector<bool> visited(size);
            list<int> q;
            q.push_back(x);
            int cur;
            int level = 0;
            while(!q.empty())
            {
                cur = q.front();
                level++;
                q.pop_front();
                
                for(auto it = edge[cur].begin(); it != edge[cur].end(); it++){
                    if(!visited[*it]){
                        visited[*it] = true;
                    }
                    
                    if(*it == y)
                        if(level != 3) return false;
                        else return true;
                    q.push_back(*it);
                }
            }
        }
        
        void display(){
            for(auto it = edge.begin(); it != edge.end(); it++){
                for(auto x = it->begin(); x != it->end(); x++){
                    cout << *x << " -> ";
                }
                cout << endl;
            }
        }
};


int main()
{
    friends f(10);
    f.addFriend(1, 8);
    f.addFriend(1, 3);
    f.addFriend(1, 2);
    f.addFriend(1, 5);
    f.addFriend(2, 8);
    f.addFriend(2, 6);
    f.addFriend(2, 9);
    f.addFriend(3, 4);
    f.addFriend(3, 8);
    f.addFriend(3, 5);
    f.addFriend(3, 6);
    f.addFriend(4, 7);

    f.display();
    
    bool result = f.isFriend(1, 6);
    cout << "Output : " << result << endl;
    return 0;    
}
