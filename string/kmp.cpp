#include<bits/stdc++.h>

using namespace std;

// 将next数组当作函数值返回在字符串比较长的时候不太合适，但是这样写起来好点，而且模式串一般比较短，最重要我喜欢用返回值风格的，so...
vector<int> get_next(const string &p) {
	vector<int> r;
	r.push_back(-1);

	int len_p = p.size();
	int i=0, j=-1;
	while(i<len_p) {
		if(j == -1 || p.at(i) == p.at(j)) {
			i++;
			j++;
			if(i<len_p && j<len_p && p.at(i)==p.at(j)) {
				int tmp = r.at(j);
				r.push_back(tmp);
			} else {
				r.push_back(j);
			}
		} else {
			j = r.at(j);
		}
	}

	return r;
}

int kmp(const string &s, const string &p) {
	auto next_v = get_next(p);

	int i=0, j=0;
	int len_p = p.size();
	int len_s = s.size();
	while(i<len_s && j<len_p) {
		if(j == -1 || s.at(i)==p.at(j)) {
			i++;
			j++;
		} else {
			j = next_v[j];
		}
	
	}
	if(j>=(len_p-1)) {
		return i-len_p;
	}
	return -1;
}


int main() {
	string s, p;
	cout<<kmp("aaabaaaab", "ba")<<endl;

	return 0;
}
