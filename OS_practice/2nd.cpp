#include <bits/stdc++.h>
using namespace std;
#define int long long int

struct process {
    int id;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
    int priority;
};

bool compare(process a, process b) {
    return a.arrival_time < b.arrival_time;
}

void print_avg(double tat, double wt, int n) {
    cout << "The average turnaround time and waiting time respectively are: ";
    cout << tat / n << " " << wt / n << endl;
}

void FCFS() {
    int n;
    cout << "Enter the no of jobs to schedule:";
    cin >> n;
    int ct = 0;
    double tat = 0, wt = 0;
    vector<process> p(n);

    for (int i = 0; i < n; i++) {
        cout << "Enter the arrival time and burst time of process " << i + 1 << " :";
        cin >> p[i].arrival_time >> p[i].burst_time;
        p[i].id = i + 1;
    }
    sort(p.begin(), p.end(), compare);

    for (int i = 0; i < n; i++) {
        if (p[i].arrival_time > ct)
            ct = p[i].arrival_time;
        ct += p[i].burst_time;

        p[i].turnaround_time = ct - p[i].arrival_time;
        p[i].waiting_time = p[i].turnaround_time - p[i].burst_time;
        tat += p[i].turnaround_time;
        wt += p[i].waiting_time;
    }

    print_avg(tat, wt, n);
}

void SJF() {
    int n;
    cout << "Enter the no of jobs:";
    cin >> n;

    int ct = 0;
    double tat = 0, wt = 0;
    vector<process> p(n);
    vector<bool> done(n, false);

    for (int i = 0; i < n; i++) {
        cout << "Enter the arrival time and burst time of process " << i + 1 << " :";
        cin >> p[i].arrival_time >> p[i].burst_time;
        p[i].id = i + 1;
    }

    sort(p.begin(), p.end(), compare);
    int completed = 0;

    while (completed < n) {
        int curr = -1;
        int mini = LLONG_MAX;

        for (int i = 0; i < n; i++) {
            if (!done[i] && p[i].arrival_time <= ct && p[i].burst_time < mini) {
                mini = p[i].burst_time;
                curr = i;
            }
        }

        if (curr == -1) {
            ct++;
            continue;
        }

        ct += p[curr].burst_time;
        p[curr].turnaround_time = ct - p[curr].arrival_time;
        p[curr].waiting_time = p[curr].turnaround_time - p[curr].burst_time;
        done[curr] = true;
        tat += p[curr].turnaround_time;
        wt += p[curr].waiting_time;
        completed++;
    }

    print_avg(tat, wt, n);
}

void SRTF() {
    int n;
    cout << "Enter the number of jobs: ";
    cin >> n;

    vector<process> p(n);
    vector<int> remaining_time(n);
    vector<bool> done(n, false);

    for (int i = 0; i < n; i++) {
        cout << "Enter arrival time and burst time for process " << i + 1 << ": ";
        cin >> p[i].arrival_time >> p[i].burst_time;
        p[i].id = i + 1;
        remaining_time[i] = p[i].burst_time;
    }

    int ct = 0, completed = 0;
    double tat = 0, wt = 0;

    while (completed < n) {
        int idx = -1;
        int min_rt = LLONG_MAX;

        for (int i = 0; i < n; i++) {
            if (!done[i] && p[i].arrival_time <= ct && remaining_time[i] < min_rt) {
                min_rt = remaining_time[i];
                idx = i;
            }
        }

        if (idx == -1) {
            ct++;
            continue;
        }

        remaining_time[idx]--;
        ct++;

        if (remaining_time[idx] == 0) {
            done[idx] = true;
            completed++;
            p[idx].turnaround_time = ct - p[idx].arrival_time;
            p[idx].waiting_time = p[idx].turnaround_time - p[idx].burst_time;
            tat += p[idx].turnaround_time;
            wt += p[idx].waiting_time;
        }
    }

    print_avg(tat, wt, n);
}

void Priority_np() {
    int n;
    cout << "Enter the no of jobs :";
    cin >> n;

    int ct = 0;
    double wt = 0, tat = 0;
    vector<process> p(n);
    vector<bool> done(n, false);

    for (int i = 0; i < n; i++) {
        cout << "Enter the arrival time and burst time and priority no for the " << i + 1 << " th job :";
        cin >> p[i].arrival_time >> p[i].burst_time >> p[i].priority;
        p[i].id = i + 1;
    }

    int completed = 0;

    while (completed < n) {
        int idx = -1;
        int highp = LLONG_MAX;

        for (int i = 0; i < n; i++) {
            if (!done[i] && p[i].arrival_time <= ct && p[i].priority < highp) {
                idx = i;
                highp = p[i].priority;
            }
        }

        if (idx == -1) {
            ct++;
            continue;
        }

        ct += p[idx].burst_time;
        p[idx].turnaround_time = ct - p[idx].arrival_time;
        p[idx].waiting_time = p[idx].turnaround_time - p[idx].burst_time;
        done[idx] = true;
        tat += p[idx].turnaround_time;
        wt += p[idx].waiting_time;
        completed++;
    }

    print_avg(tat, wt, n);
}

void Priority_premptive() {
    int n;
    cout << "Enter the no of jobs :";
    cin >> n;

    int ct = 0;
    double wt = 0, tat = 0;
    vector<process> p(n);
    vector<int> remaining_time(n);
    vector<bool> done(n, false);

    for (int i = 0; i < n; i++) {
        cout << "Enter the arrival time and burst time and priority no for the " << i + 1 << " th job :";
        cin >> p[i].arrival_time >> p[i].burst_time >> p[i].priority;
        p[i].id = i + 1;
        remaining_time[i] = p[i].burst_time;
    }

    int completed = 0;

    while (completed < n) {
        int idx = -1;
        int highp = LLONG_MAX;

        for (int i = 0; i < n; i++) {
            if (!done[i] && p[i].arrival_time <= ct && p[i].priority < highp && remaining_time[i] > 0) {
                idx = i;
                highp = p[i].priority;
            }
        }

        if (idx == -1) {
            ct++;
            continue;
        }

        remaining_time[idx]--;
        ct++;

        if (remaining_time[idx] == 0) {
            done[idx] = true;
            completed++;
            p[idx].turnaround_time = ct - p[idx].arrival_time;
            p[idx].waiting_time = p[idx].turnaround_time - p[idx].burst_time;
            tat += p[idx].turnaround_time;
            wt += p[idx].waiting_time;
        }
    }

    print_avg(tat, wt, n);
}

void Round_Robin() {
    int n;
    cout << "Enter the no of jobs :";
    cin >> n;

    vector<process> p(n);
    vector<int> remaining_time(n);
    vector<bool> done(n, false);
    double wt = 0, tat = 0;
    int ct = 0, completed = 0;

    for (int i = 0; i < n; i++) {
        cout << "Enter the arrival time and burst time of the " << i + 1 << " th process :";
        cin >> p[i].arrival_time >> p[i].burst_time;
        p[i].id = i + 1;
        remaining_time[i] = p[i].burst_time;
    }

    int tq;
    cout << "Enter the time quantum for round robin scheduling :";
    cin >> tq;

    queue<int> q;
    int time = 0;
    vector<bool> in_queue(n, false);
    sort(p.begin(), p.end(), compare);

    int i = 0;
    while (i < n && p[i].arrival_time <= time) {
        q.push(i);
        in_queue[i] = true;
        i++;
    }

    while (!q.empty()) {
        int idx = q.front();
        q.pop();

        int exec_time = min(tq, remaining_time[idx]);
        time += exec_time;
        remaining_time[idx] -= exec_time;

        for (; i < n && p[i].arrival_time <= time; i++) {
            if (!in_queue[i]) {
                q.push(i);
                in_queue[i] = true;
            }
        }

        if (remaining_time[idx] > 0) {
            q.push(idx);
        } else {
            completed++;
            done[idx] = true;
            p[idx].turnaround_time = time - p[idx].arrival_time;
            p[idx].waiting_time = p[idx].turnaround_time - p[idx].burst_time;
            tat += p[idx].turnaround_time;
            wt += p[idx].waiting_time;
        }
    }

    print_avg(tat, wt, n);
}

signed main() {
    bool flag = true;

    while (flag) {
        int choice;
        cout << "\n==== CPU Scheduling Menu ====\n";
        cout << "1. FCFS\n2. SJF\n3. SRTF\n4. Priority Non-Preemptive\n5. Priority Preemptive\n6. Round Robin\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: FCFS(); break;
        case 2: SJF(); break;
        case 3: SRTF(); break;
        case 4: Priority_np(); break;
        case 5: Priority_premptive(); break;
        case 6: Round_Robin(); break;
        case 7: flag = false; break;
        default: cout << "Invalid choice\n"; break;
        }
    }

    return 0;
}
