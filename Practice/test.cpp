#include <bits/stdc++.h>
#include <iostream>
using namespace std;
bool check_position(vector<vector<int> > &board, int i, int j, int n)
{
    for(int i1 = 0; i1 < n; i1++) {
        if (board[i1][j] != 0) {
            return false;
        }
    }
    for(int j1 = 0; j1 < n; j1++) {
        if (board[i][j1] != 0) {
            return false;
        }
    }
    int i1 = i, j1 = j;
    int i2 = i, j2 = j;

    while (i1 < n && j1 < n) {
        if (board[i1][j1] != 0) {
            return false;
        }
        i1++;
        j1++;
    }

    while (i2 >= 0 && j2 >= 0) {
        if (board[i2][j2] != 0) {
            return false;
        }
        i2--;
        j2--;
    }

    return true;
}
bool recur(vector<vector<int> > &board, int n, int pending_queens)
{
    if (pending_queens <= 0) {
        return true;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if (check_position(board, i, j, n)) {
                board[i][j] = 1;
                bool result = recur(board, n, pending_queens-1);
                if (result) 
                {
                    return true;
                }
                else 
                {
                    board[i][j] = 0;
                }
            }
        }
    }
    return false;
}
int main()
{
    int n;
    cin >> n;

    vector<vector<int> > board(n, vector<int>(n, 0));

    bool found_result = recur(board, n, n);

    if (found_result) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cout << board[i][j] << " ";
            }
            cout << '\n';
        }
    } else {
        cout << "could not find a solution\n";
    }

    return 0;
}