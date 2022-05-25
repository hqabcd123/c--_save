#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <math.h>
#define PATH "p.pla"
using namespace std;
/*
when two var there will have problem*/

int find_index_of_root(int binary_tree[][3], int target, int lenght)
{
    for (int i = 1; i < lenght - 1; i++)
    {
        for (int j = 1; j < 3; j++)
        {
            if (binary_tree[i][j] == target)
            {
                cout << binary_tree[i][0] << " is target" << endl;
                return i;
            }
        }
    }
}

void dot_output(int binary_tree[][3], int lenght)
{
    string str = "digraph ROBDD";
    char label = 'a';
    ofstream file;
    file.open("robdd.dot");
    if (file.is_open())
    {
        cout << "work" << endl;
        file << str << "{\n\t";
        file << "{rank=same 1}\n\t{rank=same 2}\n\t";
        // for (int i = 1; i < lenght - 1; i++)
        // {
        //     if (binary_tree[i][0] != -1)
        //     {
        //         file << "{rank=same " << 
        //              << "}";
        //     }
        // }
        file << "0 [label=0, shape=box]\n\t";
        for (int i = 1; i < lenght; i++)
        {
            if (binary_tree[i][0] != -1)
            {
                if (i == lenght-1)
                {
                    file << lenght-1 << " [label=1, shape=box]\n\t";
                }
                else
                {
                    file << binary_tree[i][0] << " "
                        << "[label = " << label << "]\n\t";
                    label += 1;
                }
            }
        }
        for (int i = 1; i < lenght - 1; i++)
        {
            if (binary_tree[i][0] != -1)
            {
                
                if (binary_tree[i][1] == 1)
                    file << binary_tree[i][0] << " -> " << lenght - 1 << "[label=\"1\", style=dotted]\n\t";
                else
                    file << binary_tree[i][0] << " -> " << binary_tree[i][1] << "[label=\"1\", style=dotted]\n\t";
                if (binary_tree[i][2] == 1)
                    file << binary_tree[i][0] << " -> " << lenght - 1 << "[label=\"1\", style=dotted]\n\t";
                else
                    file << binary_tree[i][0] << " -> " << binary_tree[i][2] << "[label=\"0\", style=solid]\n\t";
            }
        }
        file << "}";
        file.close();
    }
    else
        cout << "don't work" << endl;
}

void reduce(int binary_tree[][3], int lenght)
{
    int count = 0;
    for (int i = 1; i < lenght - 1; i++)
    {
        if (binary_tree[i][1] == binary_tree[i][2])
        {
            cout << binary_tree[i][0] << " is same element" << endl;
            int index = find_index_of_root(binary_tree, binary_tree[i][0], lenght);
            for (int j = 1; j < 3; j++)
            {
                if (binary_tree[index][j] == binary_tree[i][0])
                {
                    binary_tree[index][j] = binary_tree[i][1];
                    binary_tree[i][0] = -1;
                    binary_tree[i][1] = -1;
                    binary_tree[i][2] = -1;
                }
            }
        }
    }
    cout << "reduced bineary tree: " << endl;
    for (int i = 1; i < lenght; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << binary_tree[i][j];
        }
        cout << endl;
    }
    for (int i = 1; i < lenght - 1; i++)
    {
        for (int j = i + 1; j < lenght - 1; j++)
        {
            if (binary_tree[i][1] == binary_tree[j][1] && binary_tree[i][2] == binary_tree[j][2])
            {
                count++;
                if (binary_tree[j][0] % 2 == 0)
                {
                    binary_tree[(binary_tree[j][0]/2)][1] = binary_tree[i][0];
                }
                else
                    binary_tree[(binary_tree[j][0]/2)][2] = binary_tree[i][0];
                for (int k = 0; k < 3; k++)
                {
                    binary_tree[j][k] = -1;
                }
            }
        }
    }
    if (count > 3)
    {
        for (int i = 1; i < lenght - 1; i++)
    {
        for (int j = i + 1; j < lenght - 1; j++)
        {
            if (binary_tree[i][1] == binary_tree[j][1] && binary_tree[i][2] == binary_tree[j][2])
            {
                count++;
                if (binary_tree[j][0] % 2 == 0)
                {
                    binary_tree[(binary_tree[j][0]/2)][1] = binary_tree[i][0];
                }
                else
                    binary_tree[(binary_tree[j][0]/2)][2] = binary_tree[i][0];
                for (int k = 0; k < 3; k++)
                {
                    binary_tree[j][k] = -1;
                }
            }
        }
    }
    }
    cout << "reduced bineary tree: " << endl;
    for (int i = 1; i < lenght; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << binary_tree[i][j];
        }
        cout << endl;
    }
    dot_output(binary_tree, lenght);
}

int find_input_number(string buffer, char target, bool statement)
{
    int number = 0, count = 0;
    for(int i = 0; i < buffer.length(); i++)
    {
        if(buffer[i] == target)
        {
            count = i+2;
            number = buffer[i+2]-48;
            break;
        }
    }
    if(!statement)
    {
        cout << "count is " << count << endl;
        return count;
    }
    else
    {
        cout << "number is " << number << endl;
        return number;
    }
}

string find_procedure(string buffer, int count, int input_number)
{
    string temp, temp2;
    int index[2] = {0};
    bool statement[2] = {0};
    for (int i = count+2, j = 0; i < buffer.length(); i++, j++)
    {
        if (j == input_number + 3)
        {
            //cout << "inside if j is " << j << endl;
            j = 0;
        }
        if (buffer[i] == '.')
            break;
        else if (buffer[i] == '-')
        {
            temp += '1';
            statement[0] = 1;
            index[0] = j;
            //cout << "inside j is " << j << endl;
            if (buffer[i+1] == '-')
            {
                buffer[i + 1] = '1';
                statement[1] = 1;
                index[1] = j + 1;
            }
        }
        else
            temp += buffer[i];
        if (statement[0] && buffer[i] == '\n')
        {
            //cout << "j is " << j << endl;
            temp2 += temp;
            temp[index[0]] = '0';
            if (statement[1])
            {
                temp[index[1]] = '0';
            }
            //cout << "temp2 is " << temp2 << "temp is " << temp << endl;
            temp2.append(temp);
            if (statement[1])
            {
                //cout << "**********************************************" << endl;
                temp[index[1]] = '1';
                //cout << "temp2 is " << temp2 << "temp is " << temp << endl;
                temp2.append(temp);
                temp[index[0]] = '1';
                temp[index[1]] = '0';
                //cout << "temp2 is " << temp2 << "temp is " << temp << endl;
                temp2.append(temp);
                statement[1] = 0;
            }
            temp.clear();
            //cout << "temp2 is " << temp2 << "temp is " << temp << endl;
            statement[0] = 0;
        }
    }
    return temp2;
}

void point_out(int binary_tree[][3], string procedure, int number)
{
    int index = 1, level = (int)pow(2, number-1), lenght = (int)pow(2, number)+1;
    bool state = 0;
    cout << procedure << endl;
    for (int i = 1; i < lenght; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << binary_tree[i][j];
        }
        cout << endl;
    }
    cout << "***********************************" << endl;
    for (int i = 0; i < procedure.length(); i++)
    {
        if (procedure[i] != '\n' && procedure[i] != ' ' && !state)
        {
            //cout << "i = " << i << endl;
            if (procedure[i] == '1')
            {
                if (index < level)
                {
                    index = index * 2;
                    //cout << "index = " << index << endl;
                }
                else
                {
                    binary_tree[index][1] = procedure[i+2]-'0';
                }
            }
            else if (procedure[i] == '0')
            {
                if (index < level)
                {
                    index = (index * 2) + 1;
                }
                else
                {
                    binary_tree[index][2] = procedure[i+2]-'0';
                }
            }
        }
        else if (procedure[i] == ' ')
        {
            state = 1;
        }
        else if (procedure[i] == '\n')
        {
            index = 1;
            state = 0;
        }

    }
    //****************************************
    for (int i = level; i < lenght; i++)
    {
        for (int j = 1; j < 3; j++)
        {
            if (binary_tree[i][j] > 1)
                binary_tree[i][j] = 0;
        }
    }
    //****************************************
    for (int i = 1; i < lenght; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << binary_tree[i][j];
        }
        cout << endl;
    }
    reduce(binary_tree, lenght);
}

int main(int argc, char *argv[])
{
    int input_number = 0, level_number, procedure = 0;
    // char *arg = argv[1];
    // if (arg == NULL)
    // {
    //     cout << "no assigned file\ninsert command like g++ Digital_home_work1 example.pla" << endl;
    //     return 1;
    // }
    FILE *file = fopen(PATH, "r");
    char buffer[1024];
    fread(&buffer, 1024, 1, file);
    cout << buffer << endl;
    //*********************************************************
    input_number = find_input_number(buffer, 'i', 1);
    //cout << "level is " << input_number << endl;
    level_number = (int)pow(2, input_number)+1;
    //cout << "now level is " << level_number << endl;
    //*********************************************************
    int binary_tree[level_number][3];
    binary_tree[0][0] = 0;
    binary_tree[0][1] = -1;
    binary_tree[0][2] = -1;
    binary_tree[level_number-1][0] = 1;
    binary_tree[level_number-1][1] = -1;
    binary_tree[level_number-1][2] = -1;
    for (int i = 1; i < level_number-1; i++)
    {
        binary_tree[i][0] = i;
        binary_tree[i][1] = i*2;
        binary_tree[i][2] = (i*2)+1;
    }
    cout << "Binary tree: " << endl;
    // for (int i = 0; i < level_number; i++)
    // {
    //     cout << "binary tree: " << i << " " << binary_tree[i][0] << '\n'
    //          << "binary tree: " << i << " " << binary_tree[i][1] << '\n' 
    //          << "binary tree: " << i << " " << binary_tree[i][2] << endl;
    // }
    procedure = find_input_number(buffer, 'p', 0);
    point_out(binary_tree, find_procedure(buffer, procedure, input_number), input_number);
    return 1;
}