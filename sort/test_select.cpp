#include <iostream>
#include "select.cpp"

using namespace std;

int main() {
    int i;
    int l[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    
    select(l, 9);

    for(i=0; i<9; i++) {
        cout<<l[i]<<" ";
    }
    cout<<endl;

    return 0;
}
