#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    int n;
    cin >> n;

    vector<tuple<int, int, int>> customers(n); // {arrival, departure, index}
    for (int i = 0; i < n; ++i)
    {
        int arrival, departure;
        cin >> arrival >> departure;
        customers[i] = {arrival, departure, i};
    }

    // Step 1: Sort customers by arrival time
    sort(customers.begin(), customers.end());

    set<pair<int, int>> active_rooms; // {departure_time, room_number}
    vector<int> room_assignment(n);   // Room assignment for each customer
    int total_rooms = 0;

    // Step 2: Process each customer
    for (const auto &customer : customers)
    {
        int arrival = get<0>(customer);
        int departure = get<1>(customer);
        int index = get<2>(customer);
        // Step 3: Find the first room that is free
        auto it = active_rooms.upper_bound({arrival, 0});
        if (it != active_rooms.begin())
        {
            --it; // Move to the room whose departure is ≤ arrival
            int room_number = it->second;
            active_rooms.erase(it); // Reuse this room
            active_rooms.insert({departure, room_number});
            room_assignment[index] = room_number;
        }
        else
        {
            // Step 4: Allocate a new room
            ++total_rooms;
            active_rooms.insert({departure, total_rooms});
            room_assignment[index] = total_rooms;
        }
    }

    // Output total rooms and room assignments
    cout << total_rooms << endl;
    for (int room : room_assignment)
    {
        cout << room << " ";
    }
    cout << endl;

    return 0;
}
