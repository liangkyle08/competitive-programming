#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N, C, P;
int globalAns = 0;
string globalString;

void solve2(int t1, int t2, vector<string> noun, vector<string> transVerb, vector<string> intransVerb, vector<string> conj) {
    vector<pair<string, int>> type1, type2;
    // Intransitive Verbs (Type 1)
    while (!intransVerb.empty() && t1 > 0) {
        if (noun.empty()) break;
        string verb = intransVerb.back();
        intransVerb.pop_back();
        string noun1 = noun.back();
        noun.pop_back();
        type1.push_back({noun1+" "+verb, 2});
        t1--;
    }
    // Transitive Verbs (Type 2)
    while (!transVerb.empty() && t2 > 0) {
        if ((int)noun.size() < 2) break;
        string verb = transVerb.back();
        transVerb.pop_back();
        string noun1 = noun.back();
        noun.pop_back();
        string noun2 = noun.back();
        noun.pop_back();
        type2.push_back({noun1+" "+verb+" "+noun2, 3});
        t2--;
    }
    // Add commas
    while(!noun.empty() && C > 0) {
        if (type2.empty()) break;
        type2.back().fi += ", "+noun.back();
        type2.back().se += 1;
        noun.pop_back();
        C--;
    }
    // Add conjugations
    vector<pair<string, int>> all, comp;
    for (auto s: type1) all.push_back(s);
    for (auto s: type2) all.push_back(s);
    while (!conj.empty()) {
        if ((int)all.size() < 2) break;
        int total = 0;
        string sent1 = all.back().fi;
        total += all.back().se;
        all.pop_back();
        string sent2 = all.back().fi;
        total += all.back().se;
        all.pop_back();
        comp.push_back({sent1+" "+conj.back()+" "+sent2, total+1});
        conj.pop_back();
    }
    int ans = 0;
    string final;
    while (!comp.empty() && P > 0) {
        ans += comp.back().se;
        final += comp.back().fi+". ";
        comp.pop_back();
        P--;
    }
    while (!all.empty() && P > 0) {
        ans += all.back().se;
        final += all.back().fi+". ";
        all.pop_back();
        P--;
    }
    if ((int)final.size() > 0) final.pop_back();
    cout << ans << "\n";
    cout << final << "\n";
    if (ans > globalAns) {
        globalAns = ans;
        globalString = final;
    }
}

void solve() {
    cin >> N >> C >> P;
    vector<string> noun, transVerb, intransVerb, conj;
    for (int i = 0; i < N; i++) {
        string s, t;
        cin >> s >> t;
        if (t == "noun") noun.push_back(s);
        if (t == "transitive-verb") transVerb.push_back(s);
        if (t == "intransitive-verb") intransVerb.push_back(s);
        if (t == "conjunction") conj.push_back(s);
    }
    for (int i = 0; i <= (int)intransVerb.size(); i++) {
        for (int j = 0; j <= (int)transVerb.size(); j++) {
            solve2(4, 4, noun, transVerb, intransVerb, conj);
        }
    }
    cout << globalAns << "\n";
    cout << globalString << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
