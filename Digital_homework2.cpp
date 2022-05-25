#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <math.h>
#include <vector>
#define PATH "g.pla"
using namespace std;

class Table
{
    public:
        Table(int *binary_function, int input_number, int length);
        Table();
        Table(vector<int> binary);
        Table(const Table &obj);
        vector<int> getVec();
        vector<int> classify(int count, int input_number);
        void set_binary(vector<int> vec);
        void printVec();
        void set_binary_count(int count);
        int get_binary_count();
        int input_number;
        int length;

    private:
        vector<int> vec;
        int binary_count;
        //vector<int>::iterator it;
        //int binary_function[2];
};

Table::Table(int *binary_function, int input_number, int length)
{
    //cout << "Talbe Class's constructor is called" << endl;
    this->input_number = input_number;
    for (int i = 0, j = 0; i < length; i++)
    {
        if (*(binary_function + i) == -1)
            ;
        else
        {
            vec.push_back(binary_function[i]);
            j++;
        }
        this->length = j;
    }
    cout << 
    "input number is: " << this->input_number << 
    " and length is: " << this->length << endl;
    for (int i = 0; i < this->length; i++)
    {
        cout << vec[i];
    }
    cout << endl;
}

Table::Table()
{
   ;
}

Table::Table(vector<int> binary)
{
    vec.assign(binary.begin(), binary.end());
    binary_count = 0;
    //this->input_number = input_number;
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec.at(i) == 1)
            binary_count++;
    }
}

Table::Table(const Table &obj)
{
    input_number = obj.input_number;
    length = obj.length;
    binary_count = obj.binary_count;
    vec.assign(obj.vec.begin(), obj.vec.end());
}
vector<int> Table::getVec()
{
    return vec;
}
/*divide binary by count*/
vector<int> Table::classify(int count, int input_number)
{
    vector<int> return_binary;
    this->input_number = input_number;
    for (int i = count, j = 0; j < input_number; i++)
    {
        return_binary.push_back(vec.at(i));
        j++;
    }
    return return_binary;
}

void Table::set_binary_count(int count)
{
    binary_count = count;
}

void Table::set_binary(vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        this->vec.push_back(vec.at(i));
        if (vec.at(i) == 1)
            binary_count++;
    }
}

void Table::printVec()
{
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec.at(i) == -2)
            cout << "-";
        else
            cout << vec.at(i);
    }
    cout << endl;
}

int Table::get_binary_count()
{
    return binary_count;
}

class Quine_McCluskey
{
    public:
        Quine_McCluskey(vector<Table> tables);
        vector<Table> tables;
    private:
        vector<int> index;
        void filter_same();
        void sorting();
        void reduce();
        void Essential_prime();
        void pack();
};

Quine_McCluskey::Quine_McCluskey(vector<Table> tables)
{
    cout << "Quine McCluskey Method" << endl;
    this->tables.assign(tables.begin(), tables.end());
    sorting();
    for (int i = 0; i < this->tables.size(); i++)
    {
        cout << this->tables.at(i).get_binary_count() << " ";
        this->tables.at(i).printVec();
    }
    cout << "reducing" << endl;
    reduce();
    filter_same();
    cout << "***********************************" << endl;
    for (int i = 0; i < this->tables.size(); i++)
    {
        cout << this->tables.at(i).get_binary_count() << " ";
        this->tables.at(i).printVec();
    }
    Essential_prime();
    cout << "***********************************" << endl;
    for (int i = 0; i < this->tables.size(); i++)
    {
        //cout << this->tables.at(i).get_binary_count() << " ";
        this->tables.at(i).printVec();
    }
    cout << "packing" << endl;
    pack();
    cout << "***********************************" << endl;
    for (int i = 0; i < this->tables.size(); i++)
    {
        //cout << this->tables.at(i).get_binary_count() << " ";
        this->tables.at(i).printVec();
    }
    reduce();
    filter_same();
    cout << "***********************************" << endl;
    for (int i = 0; i < this->tables.size(); i++)
    {
        cout << this->tables.at(i).get_binary_count() << " ";
        this->tables.at(i).printVec();
    }
}

void Quine_McCluskey::sorting()
{
    int length = tables.size();
    for (int i = 0; i < length; i++)
    {
        cout << tables.at(i).get_binary_count() << " ";
    }
    cout << endl;
    for (int i = 0; i < length; i++)
    {
        for (int j = i; j < length; j++)
        {
            // cout << i << " " << tables.at(i).get_binary_count() << " " <<
            //  j << " " << tables.at(j).get_binary_count() << endl;
            if (tables.at(i).get_binary_count() > tables.at(j).get_binary_count())
            {
                Table temp = tables.at(i);
                tables.at(i) = tables.at(j);
                tables.at(j) = temp;
            }
        }
    }
    cout << endl;
    for (int i = 0; i < length; i++)
    {
        cout << tables.at(i).get_binary_count() << " ";
    }
    cout << endl;
}

void Quine_McCluskey::filter_same()
{
    for (int i = 0; i < tables.size(); i++)
    {
        int count = 0;
        for (int j = i; j < tables.size(); j++)
        {
            int len = tables.at(i).getVec().size();
            for (int k = 0; k < len; k++)
            {
                if (tables.at(i).getVec().at(k) == tables.at(j).getVec().at(k))
                    count++;
            }
            if (count == len)
                tables.erase(tables.begin() + j);
            count = 0;
        }
    }
}

void Quine_McCluskey::reduce()
{
    int count = 0;
    vector<Table> temp;
    bool dont_care = 1, have_dont_care = 0;
    //bool second_state = 1;
    bool state = 1;
    while (state)
    {
        cout << "*********************************" << endl;
        int length = tables.size();
        state = 0;
        dont_care = 1;
        have_dont_care = 0;
        for (int i = 0; i < length; i++)
        {
            for (int j = i; j < length; j++)
            {
                if (tables.at(i).get_binary_count() + 1 == tables.at(j).get_binary_count())
                {
                    vector<int> index(0);
                    vector<int> vec1 = tables.at(i).getVec();
                    vector<int> vec2 = tables.at(j).getVec();
                    int len = tables.at(i).getVec().size();
                    for (int k = 0; k < len; k++)
                    {
                        if (vec1.at(k) == -2)
                            have_dont_care = 1;
                        if (vec1.at(k) + 1 == vec2.at(k) || vec1.at(k) - 1 == vec2.at(k))
                        {
                            /*record the index that are same with both vector binary*/
                            index.push_back(k);
                        }
                    }
                    if (index.size() > 1)
                        ;
                    else if (index.size() == 1)
                    {
                        if (have_dont_care)
                        {
                            for (int k = 0; k < len; k++)
                            {
                                if (vec1.at(k) == -2 && vec2.at(k) == -2)
                                    dont_care = 1;
                                else if (vec1.at(k) == -2 || vec2.at(k) == -2)
                                    dont_care = 0;
                            }
                        }
                        if (dont_care)
                        {
                            state = 1;
                            vector<int> buffer;
                            for (int i = 0; i < vec1.size(); i++)
                            {
                                buffer.push_back(vec1.at(i));
                            }
                            buffer.at(index.at(0)) = -2;
                            Table table(buffer);
                            temp.push_back(table);
                        }
                    }
                }
            }
        }
        // for (int i = 0; i < temp.size(); i++)
        // {
        //     cout << temp.at(i).get_binary_count() << " ";
        //     temp.at(i).printVec();
        // }
        count++;
        if (state)
            tables.clear();
        for (int i = 0; i < temp.size(); i++)
        {
            tables.push_back(temp.at(i));
        }
        for (int i = 0; i < temp.size(); i++)
        {
            cout << tables.at(i).get_binary_count() << " ";
            tables.at(i).printVec();
        }
        temp.clear();
    }
}

void Quine_McCluskey::Essential_prime()
{
    vector<Table> temp;
    int len = tables.at(0).getVec().size();
    for (int i = 0; i < tables.size(); i++)
    {
        vector<int> vec = tables.at(i).getVec();
        vector<int> index(0);
        for (int j = 0; j < len; j++)
        {
            if (vec.at(j) == -2)
            {
                vec.at(j) = 0;
                index.push_back(j);
            }
        }
        vector<int> buffer;
        for (int i = 0; i < len; i++)
        {
            buffer.push_back(vec.at(i));
        }
        temp.push_back(Table(buffer));
        buffer.clear();
        if (index.size() > 0)
        {
            for (int i = 0; i < len; i++)
            {
                buffer.push_back(vec.at(i));
            }
            for (int i = 0; i < index.size(); i++)
            {
                buffer.at(index.at(i)) = 1;
                temp.push_back(Table(buffer));
                buffer.at(index.at(i)) = 0;
            }
            buffer.clear();
            for (int i = 0; i < len; i++)
            {
                buffer.push_back(vec.at(i));
            }
            for (int i = 0; i < index.size(); i++)
            {
                buffer.at(index.at(i)) = 1;
            }
            temp.push_back(Table(buffer));
            buffer.clear();
            // for (int i = 0; i < len; i++)
            // {
            //     buffer.push_back(vec.at(i));
            // }
            // for (int i = 0; i < index.size(); i++)
            // {
            //     buffer.at(index.at(i)) = 1;
            // }
            // temp.push_back(Table(buffer));
            // buffer.clear();
        }
    }
    tables.clear();
    for (int i = 0; i < temp.size(); i++)
    {
        tables.push_back(temp.at(i));
    }
}

void Quine_McCluskey::pack()
{
    vector<int> index(0);
    for (int i = 0; i < tables.size(); i++)
    {
        bool state = 0;
        vector<int> vec1 = tables.at(i).getVec();
        for (int j = i + 1; j < tables.size(); j++)
        {
            vector<int> vec2 = tables.at(j).getVec();
            if (vec1 != vec2)
                ;
            else
                state = 1;
        }
        if (!state)
            index.push_back(i);
    }
    for (int i = 0; i < index.size(); i++)
    {
        tables.erase(tables.begin() + index.at(i));
    }
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

string Exhaustive_method(string buffer, int count, int input_number)
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
        else if (buffer[i] == '\n')
        {
            temp2 += temp;
            temp.clear();
        }
    }
    return temp2;
}

int* string_2_int(string buffer, int input_number)
{
    cout << buffer << endl;
    int* ptr = new int[buffer.length()];
    for (int i = 0; i < buffer.length(); i++)
    {
        *(ptr + i) = -1;
    }
    for (int i = 0; i < buffer.length(); i++)
    {
        if (buffer[i] == '\n' || buffer[i] == ' ' || buffer[i - 1] == ' ')
            *(ptr + i) = -1;
        else
        {
            *(ptr + i) = buffer[i] - '0';
            // cout << "The value of "<< i << " is: " <<*(ptr + i) << endl;
            // cout << "The char of "<< i << " is: " <<buffer[i] << endl;
        }
    }
    for (int i = 0; i < buffer.length(); i++)
    {
        if (*(ptr + i) == -1)
            ;
        else
            cout << *(ptr + i);
    }
    return ptr;
}

void output(vector<Table> vec, int input_number)
{
    string str = ".i ";
    str += input_number + '0';
    str += "\n";
    ofstream file;
    file.open("output.pla");
    if (file.is_open())
    {
        cout << "working" << endl;
        file << str << ".o 1\n";
        file << ".ob output\n"
             << ".p " << vec.size() <<"\n";
        for (int i = 0; i < vec.size(); i++)
        {
            vector<int> buffer = vec.at(i).getVec();
            for (int j = 0; j < buffer.size(); j++)
            {
                if (buffer.at(j) == -2)
                    file << "-";
                else
                    file << buffer.at(j);
            }
            file << " 1\n";
        }
        file << ".e";
        file.close();
    }
    else
        cout << "don't work" << endl;
}

int main(int argc, char *argv[])
{
    int input_number = 0, procedure = 0;
    char *arg = argv[1];
    if (arg == NULL)
    {
        cout << "no assigned file\ninsert command like g++ Digital_home_work1 example.pla" << endl;
        return 1;
    }
    FILE *file = fopen(arg, "r");
    //FILE *file = fopen(PATH, "r");
    char buffer[1024];
    fread(&buffer, 1024, 1, file);
    cout << buffer << endl;
    fclose(file);
    //*********************************************************
    input_number = find_input_number(buffer, 'i', 1);
    procedure = find_input_number(buffer, 'p', 0);
    string str = Exhaustive_method(buffer, procedure, input_number);
    Table table(string_2_int(str, input_number), input_number, str.length());
    vector <Table> vectable(table.length / input_number);
    for (int i = 0, j = 0; i < table.length / input_number; i++)
    {
        vectable[i].set_binary(table.classify(j, input_number));
        j += input_number;
    }
    Quine_McCluskey quine(vectable);
    output(quine.tables, input_number);
    return 1;
}