
void insert(int *l, int n) {
    int i, j;

    int *ll = new int[n+1];
    for(i=1; i<=n; i++) {
        ll[i] = l[i-1];
    }


    for(i=2; i<=n; i++) {
        if(ll[i] > ll[i-1]) continue;

        ll[0] = ll[i];
        for(j=i; ll[j-1]>ll[0]; j--) {
            ll[j] = ll[j-1];
        }
        ll[j] = ll[0];
    }

    for(i=0; i<n; i++) {
        l[i] = ll[i+1];
    }
    
    delete[] ll;
}
