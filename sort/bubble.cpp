
void bubble(int *l, int n) {
    int i, j, tmp;
    bool flag;
    for(i=0; i<n-1; i++) {
        flag = false;

        for(j=n-1; j>=1; j--) {
            if(l[j] < l[j-1]) {
                tmp = l[j];
                l[j] = l[j-1];
                l[j-1] = tmp;
                
                flag = true;
            }
        }

        if(!flag) break;
    }
}
