
void select(int *l , int n) {
    int i, j, tmp;
    int min;

    for(i=0; i<n-1; i++) {
        min = i;
        for(j=i; j<n; j++) {
            if(l[j] < l[min]) {
                min = j;
            }
        }
        
        if(min != i) {
            tmp = l[min];
            l[min] = l[i];
            l[i] = tmp;
        }
    }
}
