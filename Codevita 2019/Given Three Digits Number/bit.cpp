#include <iostream>
#include <vector>
using namespace std;

vector<int> correctBitScores(vector<int>);
vector<int> bitScore(vector<int>);
int findPairs(vector<int>);

int main() {
    int a, b;
    int pairs = 0;
    vector<int> vec;
    vector<int> bitscore;
    cout << "\nEnter count of nos: ";
    cin >> a;
    for (int i = 0; i < a; i++) {
        cin >> b;
        vec.push_back(b);
    }
    bitscore = bitScore(vec);
    
    pairs = findPairs(bitscore);
    cout << "Max pairs = " << pairs;
    
    return 0;
    
}

vector<int> correctBitScores(vector<int> bis) {
    int temp = 0;
    for (size_t i = 0; i < bis.size(); i++) {
        temp = bis[i];
        int count = 0;
        while (temp > 0) {
            temp = temp / 10;
            count++;
        }
        if (count > 2)
            bis[i] = abs(100 - bis[i]);
    }
    
    return bis;
}

int findPairs(vector<int> vec) {
    int count = 0;
    vector<int> odd;
    vector<int> even;
    for (size_t i = 0; i < vec.size(); i++)
        (i % 2 == 0 ? even.push_back(vec[i]) : odd.push_back(vec[i]));
    
    for (size_t j = 0; j < odd.size(); j++)
        for (size_t k = j + 1; k < odd.size(); k++) {
            if (odd[j] / 10 == odd[k] / 10) {
                count++;
                odd.erase(odd.begin()+j);
            }
        }
    
    for (size_t j = 0; j < even.size(); j++)
        for (size_t k = j + 1; k < even.size(); k++) {
            if (even[j] / 10 == even[k] / 10) {
                count++;
                even.erase(even.begin() + j);
            }
        }
    return count;
}



vector<int> bitScore(vector<int> v) {
    int temp = 0, rem = 0;
    vector<int> bs;
    for (size_t i = 0; i < v.size(); i++) {
        int max = 0, min = 9;
        temp = v[i];
        while (temp > 0) {
            rem = temp % 10;
            if (min > rem)
                min = rem;
            if (max < rem)
                max = rem;
            temp = temp / 10;
        }
        int bscore = (max * 11) + (min * 7);
        bs.push_back(bscore);
    }
    
    bs = correctBitScores(bs);
    return bs;
}
