#include <bits/stdc++.h>

using namespace std;

bool len_ok(string a, string b){
    return abs((int)a.size() - (int)b.size()) <= 2;
}

bool letter_by_letter(string a, string b, int index_a, int index_b, int dif){
    if(dif > 2)
        return false;
    if(index_a <= a.size() - 1 && index_b <= b.size() - 1){
        if(a[index_a] != b[index_b])
            return  letter_by_letter(a, b, index_a + 1, index_b, dif + 1) or
                    letter_by_letter(a, b, index_a, index_b + 1, dif + 1) or
                    letter_by_letter(a, b, index_a + 1, index_b + 1, dif + 1);
        return letter_by_letter(a, b, index_a + 1, index_b + 1, dif);
    }
    else if(index_a <= a.size() - 1 and index_b == b.size())
        return letter_by_letter(a, b, index_a + 1, index_b, dif + 1);
    else if(index_a == a.size() and index_b <= b.size() - 1)
        return letter_by_letter(a, b, index_a, index_b + 1, dif + 1);
    else
        return !(dif > 2);
}

void solve(vector<string> dic, vector<string> words){
    vector<string> ans;
    for(int i = 0; i < words.size(); i++){
        for(int j = 0; j < dic.size(); j++){
            if(len_ok(words[i], dic[j]))
                if(letter_by_letter(words[i], dic[j], 0, 0, 0))
                    ans.push_back(dic[j]);
        }
        if(!ans.empty())
            for(auto& x: ans)
                cout << x << " ";
        printf("\n");
        ans.clear();
    }
}

int main() {
    int n, m;
    vector <string> dic, words;
    string temp;
    if(scanf("%d %d", &n, &m) != 2){
        printf("Number of inputs are different than expected\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 1; i <= n; i++){
        cin >> temp;
        dic.push_back(temp);
    }
    for (int i = 1; i <= m; i++){
        cin >> temp;
        words.push_back(temp);
    }
    solve(dic, words);
    return 0;
}