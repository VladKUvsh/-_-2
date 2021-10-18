#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;
int comparing (string str1, string str2) {
    unsigned long i = str1.size();
    unsigned long j = str2.size();
    int p = 0, k = 0;
    while ((k <= (i - 1)) || (k <= (j - 1))) {
        if (str1[k] < str2[k]) {
            p = 0;
            break;
        }
        else if (str1[k] > str2[k]) {
            p = 1;
            break;
        }
        else {
            k++;
        }
    }
    return p;
}
void Merging (vector <string> &arr, vector <string> &arr2, int start, int end) {
    vector <string> Buffer_countries;
    vector <string> Buffer_surnames;
    int i = start;
    int mid = start + (end - start) / 2;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= end) {
        if (comparing(arr[i], arr[j]) == 0) {
            Buffer_countries.push_back(arr[i]);
            Buffer_surnames.push_back(arr2[i]);
            i++;
        }
        else {
            Buffer_countries.push_back(arr[j]);
            Buffer_surnames.push_back(arr2[j]);
            j++;
        }
        k++;
    }
    while (i <= mid) {
        Buffer_countries.push_back(arr[i]);
        Buffer_surnames.push_back(arr2[i]);
        i++; k++;
    }
    while (j <= end) {
        Buffer_countries.push_back(arr[j]);
        Buffer_surnames.push_back(arr2[j]);
        j++; k++;
    }
    for (i = 0; i < k; i++) {
        arr[start + i] = Buffer_countries[i];
        arr2[start + i] = Buffer_surnames[i];
    }
}
void MergeSort (vector <string> &arr, vector <string> &surnames, int left, int right) {
        if (left < right) {
        if (right - left == 1) {
            if (comparing(arr[left], arr[right]) == 1) {
                swap(arr[left], arr[right]);
                swap(surnames[left], surnames[right]);
            }
        }
        else {
            MergeSort (arr, surnames, left, left + (right - left) / 2);
            MergeSort (arr, surnames, left + (right - left) / 2 + 1, right);
            Merging (arr, surnames, left, right);
        }
    }
}
int main(int argc, const char * argv[]) {
    int n;
    string temp;
    vector <string> countries;
    vector <string> surnames;
    ifstream fin("race.in");
    ofstream fout("race.out");
    fin >> n;
    for (int i = 0; i < 2*n; i++) {
        fin >> temp;
        if (i % 2 == 0){
            countries.push_back(temp);
        }
        else
            surnames.push_back(temp);
    }
    MergeSort(countries, surnames, 0, n - 1);
    fout << "=== " << countries[0] << " ===" << "\n";
    fout << surnames[0] << "\n";
    for (int i = 1; i < n; i++) {
        if (countries[i] == countries[i - 1])
            fout << surnames[i] << "\n";
        else {
            fout << "=== " << countries[i] << " ===" << "\n";
            fout << surnames[i] << "\n";
        }
    }
    return 0;
}
