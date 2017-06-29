#include <iostream>
#include <string>
#include <queue>
#include <set>
#include <map>

using namespace::std;

int countMinuses(string S) {
    int count = 0;
    for (int i = 0; i < S.length(); i++) {
        if (S[i] == '-') {
            count += 1;
        }
    }
    return count;
}

int main() {
    int T;
    cin>>T;
    for (int i = 0; i < T; i++) {
        string S;
        cin>>S;
        int K;
        cin>>K;
        cout<<"Case #"<<i+1<<": ";
        int max_length = S.length();
        int count = countMinuses(S);
        if (count == 0) {
            cout<<0<<'\n';
        } else if (count > 1) {
            if (K == S.length()) {
                cout<<"IMPOSSIBLE\n";
            } else {
                map<string, int> depth;
                set<string> seen;
                queue<string> nodes;
                nodes.push(S);
                depth[S] = 0;

                bool possible = false;
                while (!nodes.empty()) {
                    string curr = nodes.front();
                    nodes.pop();
                    int curr_depth = depth[curr];
                    seen.insert(curr);
                    // Check if done
                    int count = countMinuses(curr);
                    if (count == 0) {
                        cout<<curr_depth<<'\n';
                        possible = true;
                        break;
                    } else if (count > 1) {
                        // flip
                        int left = 0;
                        while (left < max_length - K + 1) {
                            string copy = "";
                            for (int j = 0; j < left; j++) {
                            copy += curr[j];
                            }
                            for (int j = left; j < left + K; j++) {
                                if (curr[j] == '-') {
                                    copy += '+';
                                } else {
                                    copy += '-';
                                }
                            }
                            for (int j = left + K; j < max_length; j++) {
                                copy += curr[j];
                            }

                            if (seen.find(copy) == seen.end()) {
                                nodes.push(copy);
                                depth[copy] = curr_depth + 1;
                            }
                            left++;
                        }
                    }
                }
                if (!possible) {
                    cout<<"IMPOSSIBLE\n";
                }
            }
        } else {
            cout<<"IMPOSSIBLE\n";
        }
    }
    return 0;
}
