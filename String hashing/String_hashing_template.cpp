#include <bits/stdc++.h>
#include<vector>
using namespace std;

const vector<int> MODS = {1000000007, 1000000009}; // List of modulo values
const int P = 31;



long long expo(long long a, long long b, long long mod) {long long res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}

                                 // Prime base value
long long  mminvprime(long long  a, long long  b) {return expo(a, b - 2, b);}

long long mod_mul(long long a, long long b, long long m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
long long mod_sub(long long a, long long b, long long m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
long long mod_div(long long a, long long b, long long m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m

vector<vector<long long>> powers_of_base(string &a){
    int n=a.length();
    int primes = MODS.size();

    vector<vector<long long>> powersOfBase;
    powersOfBase.resize(primes);

        for(int i = 0; i < MODS.size(); i++) {
            powersOfBase[i].resize(n + 1);
            powersOfBase[i][0] = 1;
            for(int j = 1; j <= n; j++){
                powersOfBase[i][j] = (P * powersOfBase[i][j - 1]) % MODS[i];
            }
        }
    return powersOfBase;
}
vector<vector<long long >> Hash_prefixes(string &a,vector<vector<long long>> &powersOfBase){
        vector<vector<long long>> hashValues;

        int primes = MODS.size();
        hashValues.resize(primes);
        long long int n = a.length(); 
        for(int i = 0; i < MODS.size(); i++) {
            hashValues[i].resize(n);
            for(int j = 0; j < n; j++){
                hashValues[i][j] = ((a[j] - 'a' + 1) * powersOfBase[i][j]) % MODS[i];
                hashValues[i][j] = (hashValues[i][j] + (j > 0 ? hashValues[i][j - 1] : 0ll)) % MODS[i];
            }
        }
        return hashValues;
    }
vector<long long> substringHash(long long int l, long long int r,vector<vector<long long>> &hashValues,vector<vector<long long>> powersOfBase){ // extra O(log) factor
        vector<long long> hash(2);
        for(int i = 0; i < 2; i++){
            long long val1 = hashValues[i][r];
            long long val2 = l > 0 ? hashValues[i][l - 1] : 0ll;
            hash[i] = mod_mul(mod_sub(val1, val2, MODS[i]), mminvprime(powersOfBase[i][l], MODS[i]), MODS[i]);
        }
        return hash;
    }
int main() {
    
    
    
    return 0;
}
