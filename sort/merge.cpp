// TODO: 非递归实现

void merge(int *tmp, int *l, int start, int mid, int end) {
    int k = mid+1;
    int i, j;
    i = j = start;

    while(start<=mid && k<=end) {
        if(l[start]<l[k]) {
            tmp[j++] = l[start++];
        } else {
            tmp[j++] = l[k++];
        }
    }

    while(start<=mid) {
        tmp[j++] = l[start++];
    }
    while(k<=end) {
        tmp[j++] = l[k++];
    }

    for(; i<=end; i++) {
        l[i] = tmp[i];
    }
}

void sort(int *l, int start, int end, int *tmp) {
    if(start <= end) return;

    int mid = (start+end)/2;
    sort(l, start, mid, tmp);
    sort(l, mid+1, end, tmp);
    merge(tmp, l, start, mid, end);
}

void Merge(int *l, int n) {
    // 这里辅助空间的实现有两种方式，一种是这里写的，一种是《大话数据结构》上的，说不清哪个好哪个坏
    // 不过大话上的实现很容易出错，而且非常难调试
    int *tmp = new int[n];

    sort(l, 0, n-1, tmp);

    delete[] tmp;
}
