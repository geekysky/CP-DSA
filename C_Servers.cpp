#include <iostream>
#include <vector>
#include <numeric> // Required for std::accumulate

int main() {
    // It's good practice to use std::ios_base::sync_with_stdio(false) for faster I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, q;
    std::cin >> n >> q;

    // server_free_time[i] stores the time when server i+1 becomes free.
    // Initialized to 0, meaning all are free at the beginning.
    std::vector<int> server_free_time(n, 0);

    for (int task_num = 0; task_num < q; ++task_num) {
        int t, k, d;
        std::cin >> t >> k >> d;

        // Step 1: Find all servers that are free at time 't'
        std::vector<int> free_server_indices;
        for (int i = 0; i < n; ++i) {
            // A server is free if its 'free time' is less than or equal to the task's start time.
            if (server_free_time[i] <= t) {
                free_server_indices.push_back(i);
            }
        }

        // Step 2: Check if we have enough free servers
        if (free_server_indices.size() < k) {
            // Not enough servers, ignore the task
            std::cout << -1 << "\n";
        } else {
            // Enough servers, perform the task
            long long sum_of_ids = 0;
            
            // Step 3: Assign the task to the first 'k' free servers and update their state
            for (int i = 0; i < k; ++i) {
                int server_index = free_server_indices[i];
                // Server IDs are 1-based, indices are 0-based
                sum_of_ids += (server_index + 1); 
                // Update this server's free time
                server_free_time[server_index] = t + d;
            }
            std::cout << sum_of_ids << "\n";
        }
    }

    return 0;
}