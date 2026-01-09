#include <bits/stdc++.h>
using namespace std;
#define int long long int

struct cmp1
{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) const
    {
        return a.second < b.second;
    }
};

struct cmp2
{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) const
    {
        return a.second > b.second;
    }
};

void first_fit()
{
    int n;
    cout << "Enter the no of slots :";
    cin >> n;
    multiset<pair<int, int>> ff;

    for (int i = 0; i < n; i++)
    {
        int sz;
        cout << "Enter the partition size for the " << i + 1 << " th slot: ";
        cin >> sz;

        ff.insert({i + 1, sz});
    }

    vector<int> requests;
    int req;
    cout << "Enter the no of requests :";
    cin >> req;

    for (int i = 0; i < req; i++)
    {
        int val;
        cout << "Enter the size of the current request :";
        cin >> val;

        requests.push_back(val);
    }

    for (int i = 0; i < req; i++)
    {
        int ele = requests[i];
        bool flag = false;
        for (auto it = ff.begin(); it != ff.end(); it++)
        {
            if (it->second >= ele)
            {
                cout << "Allocating the request in slot " << it->first << endl;
                flag = true;
                pair<int, int> curr = *it;
                auto now = it;
                ff.erase(now);
                curr.second = max(0ll, curr.second - ele);

                if (curr.second != 0)
                {
                    ff.insert(curr);
                }

                break;
            }
        }

        if (flag == false)
        {
            cout << "This request could not be allocated according to First Fit Memory Allocation" << endl;
        }
    }
}

void next_fit()
{
    int n;
    cout << "Enter the no of slots :";
    cin >> n;
    vector<pair<int, int>> nf;

    for (int i = 0; i < n; i++)
    {
        int sz;
        cout << "Enter the partition size for the " << i + 1 << " th slot: ";
        cin >> sz;

        nf.push_back({i + 1, sz});
    }

    vector<int> requests;
    int req;
    cout << "Enter the no of requests :";
    cin >> req;

    for (int i = 0; i < req; i++)
    {
        int val;
        cout << "Enter the size of the current request :";
        cin >> val;

        requests.push_back(val);
    }

    int last_alloc = -1;
    int completed = 0;
    for (int i = 0; i < req; i++)
    {
        int ele = requests[i];
        bool r = false, l = false;
        // let's put two loops -> one going towards right side one from left
        for (int right = last_alloc + 1; right < n; right++)
        {
            if (nf[right].second >= ele)
            {
                cout << "Allocating the " << i + 1 << " th request to slot " << right + 1 << endl;
                r = true;
                nf[right].second -= ele;
                last_alloc=right;
                break;
            }
        }

        if (!r)
        {
            for (int left = 0; left < last_alloc; left++)
            {
                if (nf[left].second >= ele)
                {
                    cout << "Allocating the " << i + 1 << "  request to slot" << left + 1 << endl;
                    l = true;
                    nf[left].second -= ele;
                    last_alloc=left;
                    break;
                }
            }
        }

        if(!l and !r){
            cout<<"This request could not be allocated."<<endl;
        }
    }
}

void best_fit()
{
    int n;
    cout << "Enter the no of slots :";
    cin >> n;
    vector<pair<int, int>> bf;

    for (int i = 0; i < n; i++)
    {
        int sz;
        cout << "Enter the partition size for the " << i + 1 << " th slot: ";
        cin >> sz;

        bf.push_back({i + 1, sz});
    }

    vector<int> requests;
    int req;
    cout << "Enter the no of requests :";
    cin >> req;

    for (int i = 0; i < req; i++)
    {
        int val;
        cout << "Enter the size of the current request :";
        cin >> val;

        requests.push_back(val);
    }

    sort(bf.begin(),bf.end(),cmp1());
    for(int i=0;i<req;i++){
        int ele=requests[i];
        bool flag=false;

        for(int j=0;j<n;j++){
            if(bf[j].second>=ele){
                cout<<"Allocating the request in slot "<<bf[j].first<<endl;
                flag=true;
                bf[j].second-=ele;
                sort(bf.begin(),bf.end(),cmp1());
                break;
            }
        }

        if(!flag){
            cout<<"This request could not be allocated according to Best Fit Memory Allocation"<<endl;
        }
    }
}

void worst_fit()
{
    int n;
    cout << "Enter the no of slots :";
    cin >> n;
    vector<pair<int, int>> bf;

    for (int i = 0; i < n; i++)
    {
        int sz;
        cout << "Enter the partition size for the " << i + 1 << " th slot: ";
        cin >> sz;

        bf.push_back({i + 1, sz});
    }

    vector<int> requests;
    int req;
    cout << "Enter the no of requests :";
    cin >> req;

    for (int i = 0; i < req; i++)
    {
        int val;
        cout << "Enter the size of the current request :";
        cin >> val;

        requests.push_back(val);
    }

    sort(bf.begin(),bf.end(),cmp2());
    for(int i=0;i<req;i++){
        int ele=requests[i];
        bool flag=false;

        for(int j=0;j<n;j++){
            if(bf[j].second>=ele){
                cout<<"Allocating the request in slot "<<bf[j].first<<endl;
                flag=true;
                bf[j].second-=ele;
                sort(bf.begin(),bf.end(),cmp2());
                break;
            }
        }

        if(!flag){
            cout<<"This request could not be allocated according to Worst Fit Memory Allocation"<<endl;
        }
    }
}

signed main()
{
    // best fit , next fit , first fit , worst fit
    multiset<pair<int, int>> ff, nf;
    multiset<pair<int, int>, cmp1> bf;
    multiset<pair<int, int>, cmp2> wf;

    bool flag = true;
    while (flag)
    {
        int choice;
        cout << "\n==== Memory Allocation Menu ====\n";
        cout << "1. First Fit\n2. Next Fit\n3. Best Fit\n4. Worst Fit\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            first_fit();
            break;

        case 2:
            next_fit();

        case 3:
            best_fit();
            break;

        case 4:
            worst_fit();
            break;

        case 5:
            flag = false;
            break;

        default:
            cout << "Invalid Choice !" << endl;
            break;
        }
    }

    return 0;
}