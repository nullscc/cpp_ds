int Search(int *l, int n, int e) {
    l[0] = e;
    int i = n-1;
    while(l[i] != e) i--;

    return i;
}
