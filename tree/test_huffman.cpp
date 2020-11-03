#include <iostream>
#include <cassert>
#include <map>
#include "huffman.cpp"

using namespace std;

int main() {
    map<char, int> ch_w;
    ch_w['a'] = 45;
    ch_w['b'] = 13;
    ch_w['c'] = 12;
    ch_w['d'] = 16;
    ch_w['e'] = 9;
    ch_w['f'] = 5;
    pNode T = Build(ch_w);
    map<char, string> code = GenCode(T, 6);
    assert(code['a']=="0");
    assert(code['b']=="101");
    assert(code['c']=="100");
    assert(code['d']=="111");
    assert(code['e']=="1101");
    assert(code['f']=="1100");

    string encode = Encode("abcdef", code);
    assert(encode=="010110011111011100");

    string decode = Decode("1001111101", T, 6);
    assert(decode=="cde");
}
