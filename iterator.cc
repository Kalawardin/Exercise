#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {10, 20, 30};
    cout << "Forward traversal: ";
    for (auto it = v.begin(); it != v.end(); ++it)
        cout << *it << " ";
    cout << endl;

    cout << "Reverse traversal: ";
    for (auto rit = v.rbegin(); rit != v.rend(); ++rit) 
        cout << *rit << " ";
    cout << endl;
    
    for(auto it = v.begin(); it !=v.end(); ++it)
        if (*it > 25)
        cout << *it << " is greater than 25" << endl;
        else
        cout << *it << " is less than 25" << endl;

    return 0;
}
