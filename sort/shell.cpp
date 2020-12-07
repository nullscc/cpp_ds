
void shell(int *l, int n) {
    int i, j, inc, k;
    int *ll = new int[n+1];

    for(i=0; i<n; i++) {
        ll[i+1] = l[i];
    }

    for(inc=n/2; inc>=1; inc/=2) {
        for(i=inc+1; i<=n; i++) {
            if(ll[i]>ll[i-inc]) continue;

            ll[0] = ll[i];
            for(j=i; ll[j-inc]>ll[0]; j-=inc) {
                ll[j] = ll[j-inc];
            }
            ll[j] = ll[0];
        }
    }


    for(i=0; i<n; i++) {
        l[i] = ll[i+1];
    }
    delete[] ll;
}
