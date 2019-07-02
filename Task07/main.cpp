#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void bubble_sort(vector<int>& a, int len){
    int flag;
    int pos = len - 1;
    int last = pos;
    for (int i = 0; i < len - 1; ++i) {
        flag = false;
        for (int j = 0; j < pos; ++j) {
            if (a[j] > a[j + 1]){
                swap(a[j], a[j + 1]);
                flag = true;
                last = j + 1;
            }
        }
        pos = last;
        if (!flag)
            return;
    }
}

int main() {
    int n;
    ifstream in("input.txt");
    in >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        in >> v[i];
    }
    in.close();

    bubble_sort(v, n);

    ofstream out("output.txt");
    for (int j = 0; j < n; ++j) {
        cout << v[j] << " ";
    }
    out.close();

    return 0;
}