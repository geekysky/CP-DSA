#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    int n;
    cout << "Enter the no of processes :";
    cin >> n;

    int types;
    cout << "Enter the no of types of resources :" << endl;
    cin >> types;

    vector<vector<int>> allocated, maximum, remaining, available;
    vector<int> extras;
    
    // allocated resources for the processes
    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        for (int j = 0; j < types; j++)
        {
            int val;
            cout << "Enter the allocated resources of " << j + 1 << "th type for " << i + 1 << " th process ";
            cin >> val;

            temp.push_back(val);
        }
        allocated.push_back(temp);
    }

    // maximum needs for each of the processes
    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        for (int j = 0; j < types; j++)
        {
            int val;
            cout << "Enter the maximum need of " << j + 1 << "th type for " << i + 1 << " th process ";
            cin >> val;

            temp.push_back(val);
        }
        maximum.push_back(temp);
    }

    // calculating remaining needs for each of the processes
    for (int i = 0; i < n; i++)
    {
        vector<int> curr = maximum[i];
        vector<int> temp = allocated[i];

        for (int j = 0; j < types; j++)
        {
            curr[j] -= temp[j];
        }

        remaining.push_back(curr);
    }

    for (int i = 0; i < types; i++)
    {
        int val;
        cout << "Enter the extra available instances of the " << i + 1 << " th type of resource :";
        cin >> val;

        extras.push_back(val);
    }

    vector<int> done(n, -1);
    int completed = 0;
    bool safe = true;
    vector<int> sequence;
    vector<int> curr = extras;
    while (completed < n)
    {
        int idx = -1;
        for (int i = 0; i < n; i++)
        {
            if (done[i] == -1)
            {
                // could this process be completed ?
                bool flag = true;
                for (int j = 0; j < types; j++)
                {
                    if (remaining[i][j] > curr[j])
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag == false)
                {
                    continue;
                }

                idx = i;
                done[i] = 0;
                completed++;
                for (int j = 0; j < types; j++)
                {
                    curr[j] += allocated[i][j];
                }
                sequence.push_back(i + 1);
            }
        }

        // no process could be found which could be completed..hence we have landed in an unsafe state
        if (idx == -1)
        {
            safe = false;
            break;
        }
    }

    if (safe)
    {
        cout << "We are in a safe state, the safe sequence is as follows :" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << "Process " << sequence[i] << "-->";
        }
        cout << endl;
    }
    else
    {
        cout << "We are in an unsafe state !" << endl;
    }

    return 0;
}