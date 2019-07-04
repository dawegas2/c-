// practice 2019
// Chelbaev Mikhail
// IDE: CLion
// Done: everything

#include <fstream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

int bubble_sort(vector<int> a, int n); //bubble sort

int bubble_sort_A1(vector<int> a, int n); //bubble sort with Iverson condition 1

int bubble_sort_A2(vector<int> a, int n); //bubble sort with Iverson condition 1 + 2

int insertion_sort(vector<int> a, int n); //insertion sort

int insertion_binary_sort(vector<int> a, int n); //binary insertion sort

int counting_sort(vector<int> a, int n); //counting sort

int radix_sort(vector<int> a, int n); //radix sort

int binarySearch(vector<int> a, int r, int x, int& k); //binary search

void writeInFile(vector<int> first, vector<int> second, vector<int> third, vector<int> fourth); // function for writing results in file

int main() {

    vector<int> first(8000); // random elements from 0 to 9
    vector<int> second(8000); // random elements from 0 to 10.000
    vector<int> third(8000); // almost ordered
    vector<int> fourth (8000); // reverse order

    srand(time(0));

    for (int i = 0; i < 8000; ++i) {
        first[i] = rand() % 10;
        second[i] = rand() % 10000;
        third[i] = i;
        fourth[i] = 8000 - i - 1;
    }

    swap(third[234], third[463]);
    swap(third[164], third[893]);
    swap(third[996], third[124]);
    swap(third[346], third[392]);
    swap(third[235], third[416]);
    swap(third[196], third[392]);
    swap(third[153], third[328]);
    swap(third[213], third[672]);
    swap(third[821], third[932]);

    writeInFile(first, second, third, fourth);

    return 0;
}

void writeInFile(vector<int> first, vector<int> second, vector<int> third, vector<int> fourth){
    ofstream file("Sorting.csv");
    string line = "Array size;Bubble(random from 0 to 9;Bubble(random from 0 to 10.000);Bubble(almost ordered);Bubble(reverse order);"
                     "Bubble_A1(random from 0 to 9;Bubble_A1(random from 0 to 10.000);Bubble_A1(almost ordered);Bubble_A1(reverse order);"
                     "Bubble_A2(random from 0 to 9;Bubble_A2(random from 0 to 10.000);Bubble_A2(almost ordered);Bubble_A2(reverse order);"
                     "Insertion(random from 0 to 9;Insertion(random from 0 to 10.000);Insertion(almost ordered);Insertion(reverse order);"
                     "InsertionBinary(random from 0 to 9;InsertionBinary(random from 0 to 10.000);"
                     "InsertionBinary(almost ordered);InsertionBinary(reverse order);"
                     "Counting(random from 0 to 9;Counting(random from 0 to 10.000);Counting(almost ordered);Counting(reverse order);"
                     "Radix(random from 0 to 9;Radix(random from 0 to 10.000);Radix(almost ordered);Radix(reverse order);\n";
    file << line;

    for (int i = 1; i < 9; i++){
        int n = 1000 * i;
        file << n << ";" << bubble_sort(first, n) << ";" << bubble_sort(second, n) << ";" << bubble_sort(third, n) << ";" << bubble_sort(fourth, n) << ";"
                << bubble_sort_A1(first, n) << ";" << bubble_sort_A1(second, n) << ";" << bubble_sort_A1(third, n) << ";" << bubble_sort_A1(fourth, n) << ";"
                << bubble_sort_A2(first, n) << ";" << bubble_sort_A2(second, n) << ";" << bubble_sort_A2(third, n) << ";" << bubble_sort_A2(fourth, n) << ";"
                << insertion_sort(first, n) << ";" << insertion_sort(second, n) << ";" << insertion_sort(third, n) << ";" << insertion_sort(fourth, n) << ";"
                << insertion_binary_sort(first, n) << ";" << insertion_binary_sort(second, n) << ";" << insertion_binary_sort(third, n) << ";" << insertion_binary_sort(fourth, n) << ";"
                << counting_sort(first, n) << ";" << counting_sort(second, n) << ";" << counting_sort(third, n) << ";" << counting_sort(fourth, n) << ";"
                << radix_sort(first, n) << ";" << radix_sort(second, n) << ";" << radix_sort(third, n) << ";" << radix_sort(fourth, n) << ";";
        if (i != 8)
            file << "\n";
    }

    file.close();

}

int bubble_sort(vector<int> a, int n){
    int temp;
    int k = 3; // i = 0, i < n - 1
    for (int i = 0; i < n - 1; ++i) {
        k += 4; // i < n – 1; ++i
        k += 4; // j = 0; j < n – i -1;
        for (int j = 0; j < n - i -1; ++j) {
            k += 5; // j < n – i - 1; ++j;
            k += 4; // a[j] > a[j + 1]
            if (a[j] > a[j + 1]){
                k += 9; // swap
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    return k;
}

int bubble_sort_A1(vector<int> a, int n){
    int temp;
    bool flag;
    int k = 3; // i = 0, i < n - 1
    for (int i = 0; i < n - 1; ++i) {
        flag = false;
        k += 5; // i < n – 1; ++i, flag = false;
        k += 4; // j = 0; j < n – i -1;
        for (int j = 0; j < n - i -1; ++j) {
            k += 5; // j < n – i - 1; ++j;
            k += 4; // a[j] > a[j + 1]
            if (a[j] > a[j + 1]){
                k += 10; // swap; flag = true
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                flag = true;
            }
        }
        k += 1; //comparison
        if (!flag)
            break;
    }
    return k;
}

int bubble_sort_A2(vector<int> a, int n){
    int temp, s;
    int bound = n - 1; //position of the last swap
    int k = 5; // i = 0, i < n - 1; bound = n - 1;
    for (int i = 0; i < n - 1; ++i) {
        k += 4; // i < n – 1; ++i;
        k += 2; // j = 0; j < bound;
        for (int j = 0; j < bound; ++j) {
            k += 3; // j < bound; ++j;
            k += 4; // a[j] > a[j + 1]
            if (a[j] > a[j + 1]){
                k += 10; //swap; s = i;
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                s = j;
            }
        }
        k += 1; // comparison
        if (s == 0)
            break;
        else{
            bound = s;
            k += 1; // bound = s;
        }
    }
    return k;
}

int insertion_sort(vector<int> a, int n){
    int temp, j;
    int k = 2; //i = 1; i < n;
    for (int i = 1; i < n; ++i) {
        k += 4; // i < n; ++i; j = i;
        j = i;
        k += 4; // a[j] < a[j - 1];
        while (a[j] < a[j - 1]){
            k += 14; // a[j] < a[j - 1]; swap; j--;
            temp = a[j];
            a[j] = a[j - 1];
            a[j - 1] = temp;
            j--;
        }
    }
    return k;
}

int insertion_binary_sort(vector<int> a, int n){
    int temp, pos;
    int k = 2; // i = 1; i < n;
    for (int i = 1; i < n; ++i) {
        k += 5; // i < n; ++i; j = i; j > pos;
        pos = binarySearch(a, i, a[i], k);
        for (int j = i; j > pos; j--){
            k += 3; // j > pos; j--;
            k += 9; // swap
            temp = a[j];
            a[j] = a[j - 1];
            a[j - 1] = temp;
        }
    }
    return k;
}

int binarySearch(vector<int> a, int r, int x, int& k){
    int l = -1;
    k += 3; // l = -1; r > l + 1;
    while (r > l + 1){
        k += 4; // r > l + 1; (l + r) >> 1
        int m = (l + r) >> 1;
        k += 3; // a[m] <= x; l = m or r = m
        if (a[m] <= x){
            l = m;
        }else{
            r = m;
        }
    }
    k += 1; // l + 1
    return l + 1;
}

int counting_sort(vector<int> a, int n){
    int max = -1;
    int k = 3; // max = -1; j = 0; j < n
    for (int j = 0; j < n; ++j) {
        k += 5; // j < n; ++j; a[j] > max
        if (a[j] > max){
            max = a[j]; k += 2;
        }
    }
    vector<int> c(max + 1);
    vector<int> b(n);
    k += max + 1 + n; // c[0..max] = 0; b[0..n - 1] = 0;
    k += 2; // i = 0; i < n;
    for (int i = 0; i < n; ++i) {
        k += 7; // i < n; ++i; c[a[i]]++
        c[a[i]]++;
    }
    k += 2; // i = 1; i <= max
    for (int i = 1; i <= max; ++i) {
        k += 8; // i <= max; ++i; c[i] += c[i - 1]
        c[i] += c[i - 1];
    }
    k += 3; // i = n - 1; i >= 0
    for (int i = n - 1; i >= 0; --i) {
        k += 3; // i >= 0; --i;
        b[c[a[i]] - 1] = a[i]; k += 6;
        c[a[i]]--; k += 4;
    }
    return k;
}

int radix_sort(vector<int> a, int n){
    vector<int> c(10);
    vector<int> b(n);
    int divider = 1;
    int k = n + 11; //c[0..9] = 0; b[0..n-1] = 0; divider = 1;
    int max = -1;
    k += 3; // max = -1; j = 0; j < n
    for (int j = 0; j < n; ++j) {
        k += 5; // j < n; ++j; a[j] > max
        if (a[j] > max){
            max = a[j]; k += 2;
        }
    }
    k += 2; // max / divider > 0;
    while (max / divider > 0){
        k += 2; // max / divider > 0;
        k += 2; // i = 0; i < n;
        for (int i = 0; i < n; ++i) {
            k += 3; // i < n; i += 1;
            k += 7; // c[(a[i] % (divider * 10)) / divider]++;
            c[(a[i] % (divider * 10)) / divider]++;
        }
        k += 2; // i = 1; i < 10;
        for (int i = 1; i < 10; ++i) {
            k += 7; // i < 10; ++i; c[i] += c[i - 1];
            c[i] += c[i - 1];
        }
        k += 3; // i = n - 1; i >= 0;
        for (int i = n - 1; i >= 0; --i) {
            k += 3; // i >= 0; --i;
            k += 5; // pos = (a[i] % (divider * 10)) / divider
            int pos = (a[i] % (divider * 10)) / divider;
            b[c[pos] - 1] = a[i]; k += 5;
            c[pos]--; k += 3;
        }
        divider *= 10; k += 2;
        k += 2; // i = 0; i < n;
        for (int i = 0; i < n; i++){
            k += 5; // i < n; i++; a[i] = b[i];
            a[i] = b[i];
        }
        k += 2; // i =0; i < 10;
        for (int i = 0; i < 10; i ++){
            k += 4; //i < 10; i++; c[i] = 0;
            c[i] = 0;
        }
    }
    return k;
}