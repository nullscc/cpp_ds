#include <iostream>
#include <map>

typedef struct Node{
    int l, r;
    int parent;
    int w;
    char ch;
}Node, *pNode;

typedef struct {
    int m1;
    int m2;
}Min;

// TODO: 改成从堆中获取两个最小值
std::pair<int, int> PickMin(pNode l, int m) {
    int m1, m2;
    int i;
    int min = INT_MAX;
    int p_min;
    
    for(i=0; i<=m; i++) {
        if(l[i].parent == -1 && l[i].w < min) {
            min = l[i].w;
            p_min = i;
        }
    }
    m1 = p_min;

    min = INT_MAX;
    p_min = -1;
    for(i=0; i<=m; i++) {
        if(l[i].parent == -1 && i != m1 && l[i].w < min) {
            min = l[i].w;
            p_min = i;
        }
    }
    m2 = p_min;

    return std::make_pair(m1, m2);
}

pNode Build(std::map<char, int> ch_w) {
    int n = ch_w.size();
    int i = 0;
    pNode T = new Node[2*n-1];
    std::map<char,int>::iterator it = ch_w.begin();
    while(it != ch_w.end()) {
        T[i].l = T[i].r = -1;
        T[i].parent = -1;
        T[i].ch = it->first;
        T[i].w = it->second;
        i++;
        it++;
    }

    std::pair<int, int> tmp;
    i = n;
    for(; i<2*n-1; i++) {
        tmp = PickMin(T, i);
        T[i].l = tmp.first;
        T[i].r = tmp.second;
        T[i].parent = -1;
        T[i].w = T[tmp.first].w + T[tmp.second].w;
        T[tmp.first].parent = i;
        T[tmp.second].parent = i;
    }
    T[2*n-1].parent = -1;
    return T;
}

std::string Decode(std::string s, pNode T, int n) {
    std::string ret = "";
    int cur = 2*n - 2;
    std::string::iterator it = s.begin();
    while(it != s.end()) {
        if(*it == '0') {
            cur = T[cur].l;
        } else {
            cur = T[cur].r;
        }
        
        if(T[cur].l == -1) {
            ret += T[cur].ch;
            cur = 2*n - 2;
        }
        it++;
    }

    return ret;
}

std::map<char, std::string> GenCode(pNode T, int n) {
    std::map<char, std::string> ret;
    int i;
    for(i=0; i<n; i++) {
        std::string tmp = "";
        int p = i;
        while(p != -1) {
            if(T[T[p].parent].l == p) {
                tmp += '0';
            } else if(T[T[p].parent].r == p) {
                tmp += '1';
            }
            p = T[p].parent;
        }
        reverse(tmp.begin(), tmp.end());
        ret[T[i].ch] = tmp;
    }
    return ret;
}

std::string Encode(std::string s, std::map<char, std::string> code) {
    std::string ret = "";
    std::string::iterator it = s.begin();
    while(it != s.end()) {
        ret += code[*it];
        it++;
    }
    return ret;
}
