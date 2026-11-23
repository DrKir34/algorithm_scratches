#include <vector>
using namespace std;

int n;
std::vector<int> fen;

inline int prev(int i) {return i & i + 1;} 
inline int next(int i) {return i | i + 1;}
 
int prsum(int i) {
    int res = 0;
    while (i >= 0) {
        res += fen[i];
        i = prev(i) - 1;
    }
    return res;
}

int sum(int l, int r) {return prsum(r) - prsum(l - 1);}
 
void update(int i, int x) {
    for (int j = i; j < n; j = next(j)) {fen[j] += x;}
}
