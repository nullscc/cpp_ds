#include <iostream>

// 折半查找
int Search(int *l, int n, int e) {
    int high, low;

    high = n - 1;
    low = 0;

    int half;
    while(high>=low) {
        half = (low + high) / 2;

        if(l[half] == e) return half;
        
        if(l[half] > e) {
            high = half - 1;
        } else {
            low = half + 1;
        }
    }

    return -1;
}

// 插值查找
int InterpolationSearch(int *l, int n, int e) {
    int high, low;

    high = n - 1;
    low = 0;

    int m;
    while(high>=low) {
        m = low + (high-low)*(e-l[low])/(l[high]-l[low]);

        if(l[m] == e) return m;
        
        if(l[m] > e) {
            high = m - 1;
        } else {
            low = m + 1;
        }
    }

    return -1;
}
