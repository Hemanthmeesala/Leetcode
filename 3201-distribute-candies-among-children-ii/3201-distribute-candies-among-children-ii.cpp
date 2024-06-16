class Solution {
public:
    long long combo(int n){
        return 1ll* n *(n-1)/2;
    }
    long long distributeCandies(int n, int limit) {
        if (n>3*limit) return 0;
        long long res = combo(n + 2);
        if (n>limit)  res -= 3*combo(n-limit+1);
        if (n-2>=2*limit) res += 3*combo(n-2*limit);
        return res;
    }
};