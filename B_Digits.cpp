#include <bits/stdc++.h>
#define ENDL '\n'
#define lli long long
#define pb push_back
#define ff first
#define ss second
#define fore(i, a, b) for (lli i = a; i < b; i++)
#define all(s) begin(s), end(s)
#define sz(s) (lli((s).size()))

#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

using namespace std;
using vi = vector<lli>;
using pii = pair<lli, lli>;

#define LAST_DIGIT(num) (num.back() - '0')
#define SUM_DIGITS(num) (accumulate(all(num), 0LL, [](lli a, char b) { return a + (b - '0'); }))
#define LAST_BLOCK(num, x) (stoi(num.substr(max(0LL, sz(num) - (x)), min(sz(num), lli(x)))))

vi divisors(const string& num) {
    vi result;
    lli sum_digits = SUM_DIGITS(num);
    lli last_digit = LAST_DIGIT(num);

    if (true) result.pb(1); // Divisible por 1
    if (last_digit % 2 == 0) result.pb(2); // Divisible por 2
    if (sum_digits % 3 == 0) result.pb(3); // Divisible por 3
    if (last_digit == 0 || last_digit == 5) result.pb(5); // Divisible por 5
    if (sum_digits % 9 == 0) result.pb(9); // Divisible por 9

    // Divisible por 4
    if (sz(num) >= 2 && LAST_BLOCK(num, 2) % 4 == 0) result.pb(4);
    else if (last_digit % 4 == 0) result.pb(4);

    // Divisible por 7
    if (sz(num) <= 3 && stoi(num) % 7 == 0) result.pb(7);
    else if (sz(num) > 3) {
        lli alternating_sum = 0, sign = 1;
        for (lli i = sz(num); i > 0; i -= 3) {
            alternating_sum += sign * LAST_BLOCK(num, 3);
            sign = -sign;
        }
        if (alternating_sum % 7 == 0) result.pb(7);
    }

    // Divisible por 8
    if (sz(num) >= 3 && LAST_BLOCK(num, 3) % 8 == 0) result.pb(8);
    else if (stoi(num) % 8 == 0) result.pb(8);

    return result;
}

void solve() {

    lli n ;
    cin>>n ;

    if(n%2==0){
        cout<<"YES"<<endl ;
    } else {
        cout<<"NO"<<endl ;
    }
}

int main() {
    IO;
    int t = 1 ;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

