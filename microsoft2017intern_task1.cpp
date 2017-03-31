#include <iostream>

using namespace std;

int min(int a, int b){
    if (a <= b) return a;
    return b;
}

double expectation(int p, int q, int n, int l, int d, int original_p){
    double e;
    if (l == n){
        return d;    
    }
    if (p == 100) {
        p = original_p;
        e = expectation((int)(p/(2^(l))), q, n, l+1, d+1, 0);       
    }else{
        if (min(p + q, 100) >= 100){
            e = (p * expectation((int)(p/(2^(l))), q, n, l+1, d+1, 0) + (100 - p) * expectation(min(p + q, 100), q, n, l, d+1, p))/100;
        }else{
            e = (p * expectation((int)(p/(2^(l))), q, n, l+1, d+1, 0) + (100 - p) * expectation(min(p + q, 100), q, n, l, d+1, 0))/100;
        }
        
    }
    cout << "e is" << e << endl;
    return e;
}

int main(){
    int p, q, n;
    cin >> p;
    cin >> q;
    cin >> n;
    double e;
    e = expectation(p, q, n, 0, 0, 0);
    cout << e << endl;
}