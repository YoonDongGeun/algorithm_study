#include <string>
#include <vector>
#include <iostream>
using namespace std;
vector<string> Arr = { "UPDATE 1 1 menu", "UPDATE 1 2 category", "UPDATE 2 1 bibimbap", "UPDATE 2 2 korean", "UPDATE 2 3 rice", "UPDATE 3 1 ramyeon", "UPDATE 3 2 korean", "UPDATE 3 3 noodle", "UPDATE 3 4 instant", "UPDATE 4 1 pasta", "UPDATE 4 2 italian", "UPDATE 4 3 noodle", "MERGE 1 2 1 3", "MERGE 1 4 1 3", "UPDATE korean hansik", "UPDATE 1 3 group", "UNMERGE 1 4", "PRINT 1 3", "PRINT 1 4" };
    struct tree {
        int row;
        int col;
    };
    void update(string& command, vector<vector<string>>& table, vector<vector<tree>>& table2);
    void merge(string& command, vector<vector<string>>& table, vector<vector<tree>>& table2);
    void unmerge(string& command, vector<vector<string>>& table, vector<vector<tree>>& table2);
    string cell_print(string& command, vector<vector<string>>& table, vector<vector<tree>>& table2);
    tree find_root(vector<vector<tree>>& data, tree tree_data) {
        while (data[tree_data.row][tree_data.col].row != tree_data.row || data[tree_data.row][tree_data.col].col != tree_data.col) {
            int temp = tree_data.row; //tree_data.row 바뀌면 tree_datacol도 바뀔가능성 차단.
            tree_data.row = data[tree_data.row][tree_data.col].row;
            tree_data.col = data[temp][tree_data.col].col;
        }
        return tree_data;
    }

    vector<string> solution(vector<string> commands) {
        vector<string> answer;
        vector<vector<string>> table(51, vector<string>(51, "EMPTY"));
        vector<vector<tree>> table2(51, vector<tree>(51, { 0,0 }));
        for (int i = 1; i < 51; i++) {
            for (int j = 1; j < 51; j++) {
                table2[i][j].row = i;
                table2[i][j].col = j;
            }
        }

        for (int i = 0; i < commands.size(); i++) {
            if (commands[i][1] == 'P') {
                update(commands[i], table, table2);
            }
            else if (commands[i][1] == 'E') {
                merge(commands[i], table, table2);
            }
            else if (commands[i][1] == 'N') {
                unmerge(commands[i], table, table2);

            }
            else {
                answer.push_back(cell_print(commands[i], table, table2));
            }
            cout << commands[i] << '\n';
            for (int i = 1; i < 6; i++) {
                for (int j = 1; j < 6; j++) {
                    cout << '[' << table2[i][j].row << ',' << table2[i][j].col << ']' << '(' << table[i][j] << ')' << ' ';
                }
                cout << '\n';
            }
            cout << "-----------------------" << '\n';
        }
        return answer;
    }

    void update(string& command, vector<vector<string>>& table, vector<vector<tree>>& table2) {
        int start = 7, end = 7;
        vector<string> temp;
        string temp_str;
        while (end < command.size())
        {
            while ((command[end] != ' ') && (command[end] != '\0')) {
                end++;
            }
            temp_str = command.substr(start, end - start);
            temp.push_back(temp_str);
            end++;
            start = end;
        }
        if (temp.size() == 3) {
            int row1 = stoi(temp[0]), col1 = stoi(temp[1]);
            tree temp_tree = find_root(table2, { row1, col1 });
            for (int i = 1; i < 51; i++) {
                for (int j = 1; j < 51; j++) {
                    if (table2[i][j].row == temp_tree.row && table2[i][j].col == temp_tree.col) {
                        table[i][j] = temp[2];
                    }
                }
            }
        }
        else
        {
            for (int i = 1; i < 51; i++) {
                for (int j = 1; j < 51; j++) {
                    if (table[i][j] == temp[0]) {
                        table[i][j] = temp[1];
                    }
                }
            }
        }



    }

    void merge(string& command, vector<vector<string>>& table, vector<vector<tree>>& table2) {
        int start = 6, end = 6;
        while (command[end] != ' ') {
            end++;
        }
        string row1_str = command.substr(start, end - start);
        end++;
        start = end;
        while (command[end] != ' ') {
            end++;
        }
        string col1_str = command.substr(start, end - start);
        end++;
        start = end;
        while (command[end] != ' ') {
            end++;
        }
        string row2_str = command.substr(start, end - start);
        end++;
        start = end;
        while (command[end] != '\0') {
            end++;
        }
        string col2_str = command.substr(start, end - start);
        int row1 = stoi(row1_str), row2 = stoi(row2_str), col1 = stoi(col1_str), col2 = stoi(col2_str);
        tree temp_tree = find_root(table2, { row1, col1 });
        tree temp_tree2 = find_root(table2, { row2, col2 });
        if (temp_tree.row == temp_tree2.row && temp_tree.col == temp_tree2.col) {
            return;
        }
        string value = table[temp_tree.row][temp_tree.col];
        if (value == "EMPTY") {
            value = table[temp_tree2.row][temp_tree2.col];
            for (int i = 1; i < 51; i++) {
                for (int j = 1; j < 51; j++) {
                    if (table2[i][j].row == temp_tree.row && table2[i][j].col == temp_tree.col) {
                        table[i][j] = value;
                        table2[i][j] = { temp_tree2.row, temp_tree2.col };
                    }
                }
            }
            return;
        }
        for (int i = 1; i < 51; i++) {
            for (int j = 1; j < 51; j++) {
                if (table2[i][j].row == temp_tree2.row && table2[i][j].col == temp_tree2.col) {
                    table[i][j] = value;
                    table2[i][j] = { temp_tree.row, temp_tree.col };
                }
            }
        }

    }

    void unmerge(string& command, vector<vector<string>>& table, vector<vector<tree>>& table2) {
        int start = 8, end = 8;
        while (command[end] != ' ') {
            end++;
        }
        string row1_str = command.substr(start, end - start);
        end++;
        start = end;
        while (command[end] != '\0') {
            end++;
        }
        string col1_str = command.substr(start, end - start);
        int row1 = stoi(row1_str), col1 = stoi(col1_str);
        tree temp_tree = find_root(table2, { row1, col1 });
        string value = table[temp_tree.row][temp_tree.col];

        for (int i = 1; i < 51; i++) {
            for (int j = 1; j < 51; j++) {
                if (table2[i][j].row == temp_tree.row && table2[i][j].col == temp_tree.col) {
                    table2[i][j] = { i,j };
                    table[i][j] = "EMPTY";
                }
            }
        }
        table[row1][col1] = value;

    }

    string cell_print(string& command, vector<vector<string>>& table, vector<vector<tree>>& table2) {
        int start = 6, end = 6;
        while (command[end] != ' ') {
            end++;
        }
        string row1_str = command.substr(start, end - start);
        end++;
        start = end;
        while (command[end] != '\0') {
            end++;
        }
        string col1_str = command.substr(start, end - start);
        int row1 = stoi(row1_str), col1 = stoi(col1_str);
        tree temp_tree = find_root(table2, { row1, col1 });
        if (table[temp_tree.row][temp_tree.col] == "EMPTY") {
            return "EMPTY";
        }
        return table[temp_tree.row][temp_tree.col];
    }

int main() {
    solution(Arr);
    return 0;
}