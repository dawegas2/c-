#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int count(vector<int> a, int n)
{
    int res = 1;
    for (int i = 1; i < n; ++i) {
        if (a[i] > a[i-1])
            res++;
    }
    return res;
}

int main()
{
    ifstream fin("input.txt");
    int n;
    fin >> n;
    vector<int> array(n);
    for (int i = 0; i < n; ++i)
        fin >> array[i];
    fin.close();

    int res = count(array, n);

    ofstream fout("output.txt");
    cout << res;
    fout.close();
    return 0;
}