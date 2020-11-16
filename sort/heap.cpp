
void swap(int *l, int i, int j) {
    int tmp;
    tmp = l[i];
    l[i] = l[j];
    l[j] = tmp;
}

void heap_adjust(int *ll, int m, int n) {
    int k;
    while(2*m<=n) {
        if(2*m+1<=n) {
            if(ll[2*m+1] > ll[2*m]) k = 2*m + 1;
            else k = 2*m;
        } else {
            k = 2*m;
        }

        if(ll[k]<=ll[m]) break;

        swap(ll, k, m);
        m = k;
    }
}

void build_heap(int *ll, int n) {
    int i;
    
    for(i=n/2; i>0; i--) {
        heap_adjust(ll, i, n);
    }
}

void heap_sort(int *l, int n) {
    int i;
    int *ll = new int[n+1];

    for(i=0; i<n; i++) {
        ll[i+1] = l[i];
    }

    build_heap(ll, n);

    for(i=1; i<n; i++) {
        swap(ll, 1, n-i+1);
        heap_adjust(ll, 1, n-i);
    }

    for(i=0; i<n; i++) {
        l[i] = ll[i+1];
    }
    delete[] ll;
}
