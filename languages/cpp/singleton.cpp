#include <iostream>
#include <vector>
#include <thread>

using namespace std;

class Singleton{
	public:
		static Singleton& createInstance(){
			static Singleton instance;
			return instance;
		}

	private:
		Singleton(){
			cout << "Created!\n";
		}

		~Singleton(){
			cout << "Destroyed!\n";
		}

};


int main()
{
	vector<thread> threads;
	for(int i = 0; i < 10; i++){
		threads.emplace_back(
			thread([](){
				Singleton::createInstance();
			})
		);
	}

	for(auto & f: threads){
		if(f.joinable()){
			f.join();
		}
	}

	return 0;
}