/*
 * =====================================================================================
 *
 *       Filename:  amazon_pair_logins.cpp
 *
 *    Description: find the pair logins of a family account 
 *
 *        Version:  1.0
 *        Created:  18/07/2022 02:24:11
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Sekhar Pariga (mn), sekharpariga@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <set>
using namespace std;

int countp(vector<string> arr){
    int result = 0;
    set<string> lookup;
    set<pair<string, string> > check;
    string temp;
    
    for(auto x : arr) lookup.insert(x);
    
    for(auto value : arr){
        for(auto p : value){
            if(p >= 'a' && p < 'z')
                temp.push_back(p+1);
            else if (p == 'z')
                temp.push_back('a');
        }
        if((lookup.find(temp) != lookup.end()) && 
                check.find({value, temp}) == check.end()){
            result++;
            check.insert({value,temp});
        }
        temp = "";
    }
    
    return result;
}

int main() {
    // Write C++ code here
    vector<string> arr = {"abc", "bcd", "zab", "cde", "cdg"};
    for(auto x : arr) cout << x << "  ";
    cout << endl;

    int result = countp(arr);
    cout << "result: " << result << endl;

    return 0;
}


