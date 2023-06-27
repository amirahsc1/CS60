// 4. Problem 8 on page 919
#include <iostream>
#include <set>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
using std::insert_iterator;
double compute(const set<string>& q, const set<string>& d){
    set<string> intersectionSet;
    std::set_intersection(q.begin(), q.end(), d.begin(), d.end(), std::inserter(intersectionSet, intersectionSet.begin()));
    double sim = static_cast<double>(intersectionSet.size()) / std::sqrt(static_cast<double>(q.size() * d.size()));
    return sim;
}

int main(){
    set<string> d;
    set<string> q;
    cout << "Enter the document press 'enter' to input each word" << endl; 
    cout << "press 'enter' twice when done :\n";
    string word;
    while (getline(cin, word) && !word.empty()){
        d.insert(word);
    }
    cout << "Enter the query press 'enter' to input each word" << endl; 
    cout << "press 'enter' twice when done:\n";
    while (getline(cin, word) && !word.empty()){
        q.insert(word);
    }
    double sim = compute(q, d);
    cout << "binary cosine coefficient: " << sim << endl;
    return 0;
}
