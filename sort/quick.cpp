// TODO: 优化 and 非递归的实现

int partition(int *l, int low, int high) {
    int pivot_value;
    int pivot = low;

    pivot_value = l[pivot];
    while(low<high) {
        while(l[high] > pivot_value && low<high) high--;
        l[pivot] = l[high];

        while(l[low] < pivot_value && low<high) low++;
        l[high] = l[low];
    }
    l[low] = pivot_value;

    return low;
}

void quick(int *l, int low, int high) {
    if(low >= high) return;
    int pivot;
    pivot = partition(l, low, high);

    if(low < pivot-1) {
        quick(l, low, pivot-1);
    }
    if(pivot+1 < high) {
        quick(l, pivot+1, high);
    }
}
