#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void compress(vector<int>& array, int n)
{
    bool first = false;
    int pos = -1;
    for (int i = 0; i < n; ++i) {
        if (!first && array[i] == 0){
            pos = i;
            first = true;
        }
        if (first && array[i] != 0){
            array[pos++] = array[i];
            array[i] = 0;
        }
    }
    int c = 0;
}

int main()
{
    ifstream fin("input.txt");
    int N;
    fin >> N;
    vector<int> array(N);
    for (int i = 0; i < N; ++i)
        fin >> array[i];
    fin.close();

    compress(array, N);

    ofstream fout("output.txt");
    for (int i = 0; i < N; ++i)
        fout << array[i] << " ";
    fout.close();
    return 0;
}