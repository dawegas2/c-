#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <stdlib.h>
#include <algorithm>

using namespace std;

vector<int> find_pick(int* a, int n);

int main()
{
    int len;
    int* arr = nullptr;
    vector<int> res;

    ifstream fin;
    fin.open("input.txt");
    if (fin.is_open())
    {
        fin >> len;
        arr = new int[len];
        for (int i = 0; i < len; i++)
            fin >> arr[i];
        fin.close();
    }
    if (len > 1)
        res = find_pick(arr, len);
    else
        res.push_back(arr[0]);

    fstream fout;
    fout.open("output.txt", ios::out);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    fout.close();

    delete[] arr;
    return 0;
}

vector<int> find_pick(int* a, int n){
    vector<int> res;
    int begin = 0, end = n - 1;
    while (begin != end && a[begin] == a[begin + 1])
        begin++;
    while (begin != end && a[end] == a[end - 1])
        end--;
    res.push_back(a[begin]);
    if (begin == end)
        return res;
    bool up = a[begin] > a[begin + 1];
    int pick = a[begin + 1];
    for (int i = begin; i < n - 1; ++i) {
        if (up) {
            if (a[i] < a[i + 1]) {
                pick = min(pick, a[i]);
                res.push_back(pick);
                up = false;
            } else {
                pick = min(pick, a[i]);
            }
        } else {
            if (a[i] > a[i + 1]) {
                pick = max(pick, a[i]);
                res.push_back(pick);
                up = true;
            } else {
                pick = max(pick, a[i]);
            }
        }
    }
    if (up)
        pick = min(pick, a[end]);
    else
        pick = max(pick, a[end]);
    res.push_back(pick);
    return res;
}