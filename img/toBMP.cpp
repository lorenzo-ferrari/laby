#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int SCALING = 30;

int n, m;

vector<vector<bool>> bmp;
vector<vector<bool>> scaled;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.pbm", "w", stdout);

    string s;
    for (n = 0; getline(cin, s); ++n) {
        if (!n) m = s.size();
        bmp.push_back(vector<bool>(0));
        for (char c : s)
            bmp.back().push_back(c == '#');
    }
     bmp.pop_back();
    --n;

    scaled.assign(n * SCALING, vector<bool> (m * SCALING));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            for (int ii = i * SCALING; ii < (i + 1) * SCALING; ++ii)
                for (int jj = j * SCALING; jj < (j + 1) * SCALING; ++jj)
                    scaled[ii][jj] = bmp[i][j];

    cout << "P1" << "\n";
    cout << m * SCALING << " " << n * SCALING << "\n";
    for (int i = 0; i < n * SCALING; ++i)
        for (int j = 0; j < m * SCALING; ++j)
            cout << scaled[i][j] << (j + 1 == m * SCALING ? "\n" : "");
}
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int SCALING = 30;

int n, m;

vector<vector<bool>> bmp;
vector<vector<bool>> scaled;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.pbm", "w", stdout);

    string s;
    for (n = 0; getline(cin, s); ++n) {
        if (!n) m = s.size();
        bmp.push_back(vector<bool>(0));
        for (char c : s)
            bmp.back().push_back(c == '#');
    }
     bmp.pop_back();
    --n;

    scaled.assign(n * SCALING, vector<bool> (m * SCALING));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            for (int ii = i * SCALING; ii < (i + 1) * SCALING; ++ii)
                for (int jj = j * SCALING; jj < (j + 1) * SCALING; ++jj)
                    scaled[ii][jj] = bmp[i][j];

    cout << "P1" << "\n";
    cout << m * SCALING << " " << n * SCALING << "\n";
    for (int i = 0; i < n * SCALING; ++i)
        for (int j = 0; j < m * SCALING; ++j)
            cout << scaled[i][j] << (j + 1 == m * SCALING ? "\n" : "");
}
