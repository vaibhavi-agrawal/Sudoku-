#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
void sudoku(int n,vector<vector<int>> &grid) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}
bool validConditions(vector <vector<int>> & grid,int i,int j,int k,int n){
    int sq = sqrt(n);
    for(int l =0;l<n;l++){
        if(grid[i][l]==k){
            return false;
        }
        if(grid[l][j]==k){
            return false;
        }
        if(grid[sq*(i/sq)+i/sq][sq*(j/sq)+j%sq]==k){
            return false;
        }
    }
    return true;
}
bool solve(int n,vector<vector<int>> &grid) {
    int i, j;
    bool empty = true;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (grid[i][j] == 0) {
                empty = false;
                break;
            }
        }
        if (!empty) {
            break;
        }
    }
    if (empty) {
        return true;
    }
    for (int k = 1; k <= n; k++) {
        if (validConditions(grid, i, j, k, n)) {
            grid[i][j] = k;

            if (solve(n,grid)) {
                return true;
            }
            grid[i][j] = 0;
        }
    }
    return false;
}
bool ValidSudoku(vector<vector<int>> &grid, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] != 0) {
                int k = grid[i][j];
                grid[i][j] = 0;

                if (!validConditions(grid, i, j, k, n)) {
                    return false;
                }

                grid[i][j] = k;
            }
        }
    }
    return true;
}
int main(){
    int n;
    cin>>n;
    int num;
    vector <vector<int>> grid;
    for(int i=0;i<n;i++){
        vector <int> v;
        for(int j=0;j<n;j++){
            cin>>num;
            v.push_back(num);
        }
        grid.push_back(v);
    }
    if(!ValidSudoku(grid,n)){
        cout<<"Invalid Sudoku"<<endl;
    }
    else if(solve(n,grid)){
        cout<<"Required Sudoku is:"<<endl;
        sudoku(n,grid);
    }

}