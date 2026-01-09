#include <bits/stdc++.h>
using namespace std;
#define int long long int


//there is no updation on recurring requests
void FIFO()
{
    int n;
    cout << "Enter the number of page requests: ";
    cin >> n;

    vector<int> requests;
    for (int i = 0; i < n; i++)
    {
        int val;
        cout << "Enter the request" << i + 1;
        cin >> val;

        requests.push_back(val);
    }

    int frames;
    cout << "Enter the number of page frames :";
    cin >> frames;

    vector<int> table(frames, -1);

    deque<pair<int, int>> order;

    int fault = 0;
    for (int i = 0; i < n; i++)
    {
        int ele = requests[i];
        bool found = false;
        int idx = -1;
        for (int j = 0; j < frames; j++)
        {
            if (table[j] == ele)
            {
                found = true;
                break;
            }
            if (table[j] == -1)
            {
                idx = j;
                break;
            }
        }

        if (!found)
        {
            fault++;
            cout << "It's a page fault." << endl;
            if (idx != -1)
            {
                cout << "Assigning request to " << idx << " frame" << endl;
                order.push_back({idx, ele});
                table[idx] = ele;
            }

            else
            {
                // the frame table is full -> we need to replace the first entered frame
                pair<int, int> temp = order.front();
                table[temp.first] = ele;
                order.pop_front();
                order.push_back({temp.first, ele});
            }
        }
        else
        {
            cout << "It's a page hit !" << endl;
        }
    }

    cout << "Page Fault Percentage is :" << (fault * 100) / n << endl;
}

void LRU(){
    int n;
    cout << "Enter the number of page requests: ";
    cin >> n;

    vector<int> requests;
    for (int i = 0; i < n; i++)
    {
        int val;
        cout << "Enter the request" << i + 1;
        cin >> val;

        requests.push_back(val);
    }

    int frames;
    cout << "Enter the number of page frames :";
    cin >> frames;

    vector<int> table(frames, -1);
    map<int,int> mp;
    int fault=0;

    for (int i = 0; i < n; i++)
    {
        int ele = requests[i];
        bool found = false;
        int idx = -1;
        for (int j = 0; j < frames; j++)
        {
            if (table[j] == ele)
            {   
                //page hit 
                found = true;
                mp[ele]=i;
                break;
            }
            if (table[j] == -1)
            {   
                //empty frame found 
                idx = j;
                break;
            }
        }

        if (!found)
        {
            fault++;
            cout << "It's a page fault." << endl;
            if (idx != -1)
            {
                cout << "Assigning request to " << idx << " frame" << endl;
                mp[ele]=i;
                table[idx] = ele;
            }

            else
            {
                // the frame table is full -> we need to replace the frame which was used last among the frames in the table 
                int key=LLONG_MAX,value=LLONG_MAX;
                //the smallest request no 
                for(auto it:mp){
                    if(it.second<value){
                        key=it.first;
                        value=it.second;
                    }
                }

                for(int j=0;j<frames;j++){
                    if(table[j]==key){
                        table[j]=ele;
                        break;
                    }
                }

                mp.erase(key);
                mp[ele]=i;
                cout<<"Assigning request by replacing "<<key<<endl;
                
            }
        }
        else
        {
            cout << "It's a page hit !" << endl;
        }
    }

    cout<<"The page fault percentage is :"<<(fault*100)/n<<endl;
}

void opt(){
    int n;
    cout << "Enter the number of page requests: ";
    cin >> n;

    vector<int> requests;
    for (int i = 0; i < n; i++)
    {
        int val;
        cout << "Enter the request" << i + 1;
        cin >> val;

        requests.push_back(val);
    }

    int frames;
    cout << "Enter the number of page frames :";
    cin >> frames;

    vector<int> table(frames, -1);
    int fault=0;

    for(int i=0;i<n;i++){
        int ele=requests[i];
        bool found=false;
        int idx=-1;

        for(int j=0;j<frames;j++){
            if(table[j]==ele){
                found=true;
                break;
            }
            if(table[j]==-1){
                idx=j;
                break;
            }
        }

        if(!found){
            fault++;
            cout<<"It's a page fault!"<<endl;
            if(idx==-1){
                cout<<"Assigning request to "<<idx<<" frame"<<endl;
                table[idx]=ele;
            }

            else{
                //table is full and we need to evict that page from our table which is not going to be used for the longest time 
                int key=-1,value=LLONG_MIN;
                vector<int> temp(frames,LLONG_MAX);
                for(int j=0;j<frames;j++){
                    int curr=table[j];

                    for(int k=i+1;k<n;k++){
                        if(requests[k]==curr){
                            temp[j]=(k-i);
                            break;
                        }
                    }
                }

                //now which gives highest temp value 
                for(int j=0;j<frames;j++){
                    if(temp[j]>value){
                        key=table[j];
                        value=temp[j];
                    }
                }

                //now replace key with ele in table 
                for(int j=0;j<frames;j++){
                    if(table[j]==key){
                        table[j]=ele;
                        cout<<"Assigning request by replacing "<<key<<" from table"<<endl;
                        break;
                    }
                }
            }
        }
        else{
            cout<<"It's a page hit!"<<endl;
        }
    }

    cout<<"The page fault percentage is :"<<(fault*100)/n<<endl;
}

signed main()
{

    bool flag = true;
    int choice;

    while (flag)
    {
        cout << " === PAGE REPLACEMENT === " << endl;
        cout << " Enter 1 for FIFO" << endl;
        cout << "Enter 2 for LRU" << endl;
        cout << "Enter 3 for Optimal" << endl;
        cout << "Enter 4 to exit" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            FIFO();
            break;

        case 2:
            LRU();
            break;

        case 3:
            opt();
            break;

        case 4:
            flag = false;
            break;

        default:
            cout << "Invalid Choice !" << endl;
            break;
        }
    }

    return 0;
}