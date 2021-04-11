#include <iostream>
#include <cstring>

using namespace std;

const int MAX_N = 1e7 + 5;
int divisor_sum[MAX_N], answer[MAX_N];

void sieve()
{
    memset(divisor_sum, 0, sizeof(divisor_sum));
    memset(answer, -1, sizeof(answer));

    for(int i = 1; i < MAX_N; i++)
    {
        for(int multiple = i; multiple < MAX_N; multiple += i)
        {
            divisor_sum[multiple] += i;
        }

        if(divisor_sum[i] < MAX_N && answer[divisor_sum[i]] == -1)
        {
            answer[divisor_sum[i]] = i;
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    cout << answer[n] << "\n";
}

int main()
{
    sieve();

    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}
