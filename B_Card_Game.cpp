#include <bits/stdc++.h>
using namespace std;
#define int long long int

int suneet_wins_ways(int a1, int a2, int b1, int b2)
{
    vector<pair<int, int>> pos_pairing = {{a1, b1}, {a1, b2}, {a2, b1}, {a2, b2}};

    int suneet_wins = 0;

    for (auto each_round : pos_pairing)
    {
        int suneet = 0;
        int slavic = 0;

        // first round
        if (each_round.first > each_round.second)
        {
            suneet += 1;
        }
        else if (each_round.first < each_round.second)
        {
            slavic += 1;
        }

        // second round

        // remaining card after first round
        int suneet_second = (each_round.first == a1) ? a2 : a1;
        int slavic_second = (each_round.second == b1) ? b2 : b1;

        if (suneet_second > slavic_second)
        {
            suneet += 1;
        }
        else if (suneet_second < slavic_second)
        {
            slavic += 1;
        }

        if (suneet > slavic)
        {
            suneet_wins += 1;
        }
    }

    return suneet_wins;
}

signed main()
{
    int t;
    cin >> t;
    vector<int> pair_cards;

    for (int i = 0; i < t; i++)
    {
        int a1, a2, b1, b2;
        cin >> a1 >> a2 >> b1 >> b2;
        pair_cards.push_back(suneet_wins_ways(a1, a2, b1, b2));
    }

    for (int result : pair_cards)
    {
        cout << result << endl;
    }

    return 0;
}
