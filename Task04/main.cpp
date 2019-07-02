#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ifstream fin("input.txt");
    int n, k;
    fin >> n >> k;
    vector<int> array(n);
    for (int i = 0; i < n; ++i){
        int r1, r2, r3;
        fin >> r1 >> r2 >> r3;
        if (r1 < 40 || r2 < 40 || r3 < 40)
            array[i] = 0;
        else
            array[i] = r1 + r2 + r3;
    }
    fin.close();

    sort(array.begin(), array.end(), greater<int>());
    while (array[k - 1] == array[k])
        k--;

    ofstream fout("output.txt");
    cout << array[k - 1];
    fout.close();
    return 0;
}