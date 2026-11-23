#include <vector>
using namespace std;

int maxX, maxY;
std::vector<std::vector<int>> fen;

inline int prev(int i) {return i & i + 1;} 
inline int next(int i) {return i | i + 1;}
 
int prsum(int x, int y) {
    int res = 0;
    for (int i = x; i >= 0; i = prev(i) - 1) {
        for (int j = y; j >= 0; j = prev(j) - 1) {
            res += fen[i][j];
        }
    }
    return res;
}
 
int sum(int xl, int yl, int xr, int yr) {
    int res = 0;
    res += prsum(xr, yr);
    res -= prsum(xr, yl - 1);
    res -= prsum(xl - 1, yr);
    res += prsum(xl - 1, yl - 1);
    return res;
}
 
void update(int x, int y, int t) {
    for (int i = x; i < maxX; i = next(i)) {
        for (int j = y; j < maxY; j = next(j)) {
            fen[i][j] += t;
        }
    }
}
