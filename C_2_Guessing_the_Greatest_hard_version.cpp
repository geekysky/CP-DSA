#include<bits/stdc++.h>
using namespace std;

int query(int left, int right)
{
    cout << "? " << left << " " << right << endl;
    int x; cin >> x; return x;
}

int left(int l, int r)
{
    int pivot = r+1;
    int answer = l;
    while(l<=r)
    {
        int mid = (l + r)/2;
        if(query(mid, pivot) == pivot)
        {
            answer = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }

    return answer;
}

int right(int l, int r)
{
    int pivot = l-1;
    int answer = r;
    while(l<=r)
    {
        int mid = (l + r)/2;
        if(query(pivot, mid) == pivot)
        {
            answer = mid;
            r = mid-1;
        }
        else l = mid + 1;
    }
    return answer;
}

int main()
{
    int n; cin >> n;

    int pivot = query(1, n);

    if(pivot == 1) pivot = right(pivot+1, n);
    else if(query(1, pivot) == pivot) pivot = left(1, pivot-1);
    else pivot = right(pivot+1, n);
    
    cout << "! " << pivot << endl;
}