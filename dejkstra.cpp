#include <iostream>
#include <vector>
#include <list>
using namespace std;


list<int> Dejkstra(int n, int ST, int dest)
{

    vector<vector<int>> matrix(n);
    for (int i = 0; i < n; i++)
        matrix[i].resize(n);

    for (int i = 0; i < n - 1; i++) {
        matrix[i][i + 1] = matrix[i + 1][i] = 1;
    }
    matrix[0][n - 1] = matrix[n - 1][0] = 1;



    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    int infin = 1000000;

    vector <int> d(n, infin);
    vector <bool> s(n, false);
    vector <list<int>> path(n);

    d[ST] = 0;
    s[ST] = true;

    int o = ST;

    for (int j = 0; j < n - 1; j++) {

        for (int i = 0; i < n; i++) {
            if (s[i] == false && matrix[o][i] != 0 && d[o] + matrix[o][i] < d[i]) {
                d[i] = d[o] + matrix[o][i];
                path[i] = path[o];
                path[i].push_back(i);
            }
        }


        int min = infin;
        for (int i = 0; i < n; i++) {
            if (s[i] == false && d[i] < min) {
                min = d[i];
                o = i;
            }
        }

        s[o] = true;

    }

    for (int n : path[dest])
        cout << n << " ";

    return path[dest];
}

int main()
{
    int n = 6;
    vector<int> route(n, -1);
    list<int> t = Dejkstra(6, 1, 4);

    int temp = 1;
    for (auto it = t.begin(); it != t.end(); it++) {
        route[*it] = temp;
        temp = *it;
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << i << " " << route[i] << endl;
        route[i] = -1;
    }

    auto it = t.begin();
    auto at = ++t.begin();
    route[1] = *it;
    for (; at != t.end(); it++, at++) {
        route[*it] = *at;
    }

    for (int i = 0; i < n; i++) {
        cout << i << " " << route[i] << endl;
        route[i] = -1;
    }

}
