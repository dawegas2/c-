#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

void move(vector<int>& a, const int n, const int s)
{
    {
        if(s>=0) {
            for (int i = 0; i < s; ++i) {
                int temp = a[0];

                for (int j = 0; j < n - 1; ++j) {
                    a[j] = a[j + 1];
                }

                a[n - 1] = temp;
            }
        }
        else {
            for (int i = 0; i < abs(s) ; ++i) {
                int temp = a[n - 1];

                for (int j = n - 1; j > 0; --j) {
                    a[j] = a[j - 1];
                }

                a[0] = temp;
            }
        }
    }
}

int main()
{
    ifstream fin("input.txt");
    int n, s;
    fin >> n >> s;
    vector<int> array(n);
    for (int i = 0; i < n; ++i)
        fin >> array[i];
    fin.close();

    move(array, n, s);

    ofstream fout("output.txt");
    for (int i = 0; i < n; ++i)
        cout << array[i] << " ";
    fout.close();
    return 0;
}