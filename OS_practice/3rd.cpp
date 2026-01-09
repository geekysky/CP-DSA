#include <bits/stdc++.h>
#include <unistd.h>
#include <errno.h>
using namespace std;

int main()
{
    int pipe1[2], pipe2[2];

    pid_t pid;

    // Create the pipes
    if (pipe(pipe1) == -1 || pipe(pipe2) == -1)
    {
        perror("Error While Creating The Pipes");
        exit(1);
        // exit 1 means fail
    }

    pid = fork();

    if (pid == 0)
    {
        // child process
        close(pipe1[1]);
        close(pipe2[0]);

        char msgfromparent[100];
        read(pipe1[0], msgfromparent, sizeof(msgfromparent));

        if (strlen(msgfromparent) == 0)
        {
            cout << "No message from parent received !" << endl;
            exit(1);
        }

        cout << "Message from Parent is " << msgfromparent << endl;

        // reply to parent
        char msgtoparent[100];
        cout << "CHILD : Enter Message to Parent :";
        cin.getline(msgtoparent, sizeof(msgtoparent));

        write(pipe2[1], msgtoparent, strlen(msgtoparent) + 1);

        close(pipe1[0]);
        close(pipe2[1]);
    }
    else if (pid > 0)
    {
        // parent process
        close(pipe1[0]);
        close(pipe2[1]);

        char msgtochild[100];
        cout << "PARENT : Enter messager to enter to child : " << endl;
        cin.getline(msgtochild, sizeof(msgtochild));

        write(pipe1[1], msgtochild, strlen(msgtochild) + 1);

        // reading message from child
        char msgfromchild[100];
        read(pipe2[0], msgfromchild, sizeof(msgfromchild));

        if (strlen(msgfromchild) == 0)
        {
            cout << "No Message Received from Child !" << endl;
            exit(1);
        }

        cout << "PARENT : Message Recived From Child : " << msgfromchild << endl;

        close(pipe1[1]);
        close(pipe2[0]);
    }

    else
    {
        cout << "Error while executing fork() system call" << endl;
        exit(1);
    }

    return 0;
}