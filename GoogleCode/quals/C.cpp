#include <iostream>
#include <queue>

using namespace::std;

int main() {
    int T;
    cin>>T;
    long long N, K;
    for (int i = 1; i <= T; i++) {
        cin>>N>>K;
        long long curr_max = N / 2;
        long long curr_min = N / 2;
        if (curr_max + curr_min == N) {
            if (curr_min > 0) {
                curr_min -= 1;
            }
        }

        if (K < N) {
            priority_queue<int> queue;
            queue.push(curr_max);
            queue.push(curr_min);

            for (int j = 1; j < K; j++) {
                long long current = queue.top();
                queue.pop();
                curr_max = current / 2;
                curr_min = current / 2;
                if (curr_max + curr_min == current) {
                    if (curr_min > 0) {
                        curr_min -= 1;
                    }
                }
                cout<<curr_max<<" "<<curr_min<<'\n';
                queue.push(curr_max);
                queue.push(curr_min);
            }
        } else {
            curr_min = 0;
            curr_max = 0;
        }
        cout<<"Case #"<<i<<": "<<curr_max<<" "<<curr_min<<'\n';
    }
}
