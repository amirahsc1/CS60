
#include <iostream>
#include <vector>
using namespace std;
int main(){
int n = 0;
int eliminate = 0;
std::vector<int> suitor;
cout << "Number of suitors who arrived for marriage? ";
cin >> n;
for (int i = 1; i <= n; ++i){
suitor.push_back(i);
}// This is to create my vector
while (suitor.size() != 1){
    for (int i = 0; i < suitor.size(); i++){
            eliminate++;
        if (eliminate%3 == 0){
            cout << "Eliminated Suitor " << suitor[i] << endl;
            suitor.erase(suitor.begin() + i);
            if ((i-1) == suitor.size()-1)
                continue;
                eliminate++;
            }
        }
    }
cout << "The numbered postion you should stand in order to be eve's chosen suitor is:  " << suitor[0] << endl;

return 0;
}