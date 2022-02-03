#include "sortic_check.h"

int stringToInt(string s) {
    int num = 0;
    for (int i = 0; i < itc_len(s); i++) {
        num += (int(s[i]) - 48) * itc_pow(10, itc_len(s) - i - 1);
    }
    return num;
}

void print(vector <int> a, vector <int> b, string funcs) {
    int v_size;
    if (a.size() > b.size()) v_size = a.size();
    else v_size = b.size();

    for (int i = 0; i < 80; i++) cout << "-";
    cout << endl << "Exec " << funcs << ":" << endl;
    for (int i = 0; i < v_size; i++){
        if (i < a.size()) cout << a[i];
        else cout << " ";
        if (i < b.size()) cout << " " << b[i];
        cout << endl;
    }
    cout << "- -" << endl << "a b" << endl;
}

void input(vector <int> &a, vector <int> &b, vector <string> &commands) {
    ifstream in;
    string line;
    in.open("input.txt");
    string num;
    bool nums = true;
    while(in.good()){
        getline(in, line);
        cout << line << endl;
        if (nums) {
            if (line == "!") nums = false;
            else a.push_back(stringToInt(line));
        }else {
            if (line == "*") cout << "";
            else commands.push_back(line);
        }
    }
    in.close();

}

int main()
{
    vector <int> a;
    vector <int> b;
    vector <string> commands;
    string num;
    cin >> num;
    if (num == "file") input(a, b, commands);
    else {
    while (num != "!") {
        a.push_back(stringToInt(num));
        cin >> num;
    }
    string command;
    cin >> command;
    while (command != "*") {
        commands.push_back(command);
        cin >> command;
    }
    }
    for (int i = 0; i < commands.size(); i++) {
        if (commands[i] == "pb") pb(a, b);
        if (commands[i] == "pa") pa(a, b);
        if (commands[i] == "ra") ra(a);
        if (commands[i] == "rb") rb(b);
        if (commands[i] == "sa") sa(a);
        if (commands[i] == "sb") sb(b);
        if (commands[i] == "ss") ss(a, b);
        if (commands[i] == "rr") rr(a, b);
        if (commands[i] == "rra") rra(a);
        if (commands[i] == "rrb") rrb(b);
        if (commands[i] == "rrr") rrr(a, b);
    }
    print(a, b, "your commands (");
    bool right = true;
    for (int i = 0; i < a.size() - 1; i++) {
        if (a[i] > a[i + 1]) right = false;
    }
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 13);
    if (right && b.size() == 0) cout << "Ok";
    else cout << "Neok";
    SetConsoleTextAttribute(hConsole, 15);

    return 0;
}
