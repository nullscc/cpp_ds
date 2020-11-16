#include <iostream>
#include <queue>

int get_kth(int m, int k) {
    int i, j=1;
    for(i=0; i<k; i++) j*=10;
    m %= j;

    for(i=1; i<k; i++) {
        m /= 10;
    }
    return m;
}

int get_width(int *l, int n) {
    int max = 0;
    int i, m;
    for(i=0; i<n; i++) {
        if(l[i]>l[max]) max = i; 
    }

    i = 1;
    m = 10;
    while(l[max]/m>0) {
        i++;
        m *= 10;
    }
    return i;
}

void radix(int *l, int n) {
    std::queue<int> qs[10];

    int w = get_width(l, n);
    int i, j, k;
    for(i=0; i<w; i++) {
        for(j=0; j<n; j++) {
            qs[get_kth(l[j], i+1)].push(l[j]);
        }

        k = 0;
        for(j=0; j<10; j++) {
            while(!qs[j].empty()) {
                l[k] = qs[j].front();
                qs[j].pop();
                k++;
            }
        }
    }
}
