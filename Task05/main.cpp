#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    ifstream fin("input.txt");
    vector<int> schools(100);
    int max = -1;
    string a, b, c, d;
    while (fin >> a >> d >> b >> c){
        if (++schools[stoi(b)] > max)
            max = schools[stoi(b)];
    }
    fin.close();
    ofstream fout("output.txt");
    for (int i = 1; i < 100; ++i)
        if (schools[i] == max)
            fout << i << " ";
    fout.close();
    return 0;
}