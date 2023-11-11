#include<bits/stdc++.h>
#define ENDL '\n'
#define pb push_back
#define f first
#define s second
#define fore(i,a,b) for(lli i=(a), ThxMK = (b); i < ThxMK; ++i)
#define sz(s) lli(s.size())
//freopen("Round1.in", "r", stdin);
// r = read  || stdin = standard input
//freopen("out", "w", stdout);
// w = write || stdout = standard output

using namespace std;
typedef long long lli;
 //g++ main.cpp && a < input.txt > output.txt

using Hash = lli; // maybe an arrray<lli, 2>
const lli N = 1e6 + 5;
Hash pw[N], ipw[N];

lli inv(lli a, lli m) {
  a %= m;
  assert(a);
  return a == 1 ? 1 : m - 1LL * inv(m, a) * m / a;
}

struct Hashing {
  static constexpr lli P = 1016624, M = 107077779;
  vector<Hash> h;

  static void init() {
    const lli Q = inv(P, M);
    pw[0] = ipw[0] = 1;
    fore (i, 1, N) {
      pw[i] = 1LL * pw[i - 1] * P % M;
      ipw[i] = 1LL * ipw[i - 1] * Q % M;
    }
  }

  Hashing(string& s) : h(sz(s) + 1, 0) {
    fore (i, 0, sz(s)) {
      lli x = s[i] - 'a' + 1;
      h[i + 1] = (h[i] + x * pw[i]) % M;
    }
  }

  Hash query(lli l, lli r) {
    return 1LL * (h[r + 1] - h[l] + M) * ipw[l] % M;
  }

  Hash full() {
    return h.back();
  }

  static pair<Hash, lli> merge(vector<pair<Hash, lli>>& cuts) {
    pair<Hash, lli> ans = {0, 0};
    fore (i, sz(cuts), 0) {
      ans.f = (cuts[i].f + 1LL * ans.f * pw[cuts[i].s] % M) % M;
      ans.s += cuts[i].s;
    }
    return ans;
  }
};

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Hashing::init();
    int n = 2000 ;
    for(int i=0; i<n; ++i)
    {
      cout<<'a';
    }
    return 0;
}
