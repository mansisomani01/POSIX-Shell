#include "headers.h"
#include <deque>
#include <cstdio>

const int MAX_HISTORY_SIZE = 20;
const int MAX_DISPLAY_SIZE = 10;
string HISTORY_FILE = ""; // Replace with your desired path

vector<string> commandHistory;

void saveHistoryToFile(const string &command)
{
    ofstream historyFile(HISTORY_FILE, ios::app);
    if (historyFile.is_open())
    {
        historyFile << command << endl;
        historyFile.close();
    }
}

void loadCommandHistory()
{
    if (HISTORY_FILE == "")
    {
        HISTORY_FILE = string(SHELL_DIRECTORY_PATH) + "/history.txt";
    }
    ifstream historyFile(HISTORY_FILE);
    if (historyFile.is_open())
    {
        string command;
        while (getline(historyFile, command))
        {
            commandHistory.push_back(command);
        }
        historyFile.close();
    }
}

void addToCommandHistory(const string &command)
{
    commandHistory.push_back(command);

    if (commandHistory.size() > MAX_HISTORY_SIZE)
    {
        commandHistory.erase(commandHistory.begin());
    }

    saveHistoryToFile(command);
}

void displayCommandHistory(int num)
{
    int startIndex = max(0, static_cast<int>(commandHistory.size()) - num);

    for (int i = startIndex; i < commandHistory.size(); ++i)
    {
        cout << commandHistory[i] << endl;
    }
}
