#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
//#define PATH "./kiss/case1/case1.kiss"
using namespace std;

class state_class
{
    public:
        state_class(char input_binary, char now_state, char next_state, char output_binary, int count);
        state_class(const state_class &obj);
        state_class();
        void printVec();
        char getNow_state();
        char getNext_state();
        void setNext_state(char Next_state);
        char getInput_binary();
        char getOutput_binary();
        int getCount();
        void setActive(bool isActive);
        bool getActive();

    private:
        char now_state;
        char next_state;
        char input_binary;
        char output_binary;
        int count;
        bool isActive = 1;
};

state_class::state_class(char input_binary, char now_state, char next_state, char output_binary, int count)
{
    this->now_state = now_state;
    this->next_state = next_state;
    this->input_binary = input_binary;
    this->output_binary = output_binary;
    this->count = count;
}

state_class::state_class(const state_class &obj)
{
    now_state = obj.now_state;
    next_state = obj.next_state;
    input_binary = obj.input_binary;
    output_binary = obj.output_binary;
    count = obj.count;
}

state_class::state_class()
{
    ;
}

void state_class::printVec()
{
    cout << input_binary << now_state << next_state << output_binary << " " << count << endl;
}

char state_class::getNow_state()
{
    return now_state;
}

char state_class::getNext_state()
{
    return next_state;
}

void state_class::setNext_state(char Next_state)
{
    this->next_state = Next_state;
}

char state_class::getInput_binary()
{
    return input_binary;
}

char state_class::getOutput_binary()
{
    return output_binary;
}

int state_class::getCount()
{
    return count;
}

void state_class::setActive(bool isActive)
{
    this->isActive = isActive;
}

bool state_class::getActive()
{
    return isActive;
}

class implement_box
{
    public:
        implement_box(char next_state1_for_Row, char next_state2_for_Row, char next_state1_for_Col,
        char next_state2_for_Col, char Row, char Col, int Count_form_state1, int Count_form_state2);
        implement_box();
        void setActive(bool isActive);
        bool getActive();
        void setnext_state1_for_Row(char next_state1_for_Row);
        char getnext_state1_for_Row();
        void setnext_state2_for_Row(char next_state2_for_Row);
        char getnext_state2_for_Row();
        void setnext_state1_for_Col(char next_state1_for_Col);
        char getnext_state1_for_Col();
        void setnext_state2_for_Col(char next_state2_for_Col);
        char getnext_state2_for_Col();
        void setRow(char Row);
        char getRow();
        void setCol(char Col);
        char getCol();
        int getCount_form_state1();
        int getCount_form_state2();
        void print();

    private:
        char next_state1_for_Row;
        char next_state2_for_Row;
        char next_state1_for_Col;
        char next_state2_for_Col;
        char Row;
        char Col;
        bool isActive = 1;
        int Count_form_state1;
        int Count_form_state2;
};

/*Next state1 is input = 0*/
/*Next state2 is input = 1*/
/**
 * Row is A->B->C
 * Col is B->C->D
*/

implement_box::implement_box(
    char next_state1_for_Row, char next_state2_for_Row, char next_state1_for_Col,
    char next_state2_for_Col, char Row, char Col, int Count_form_state1, int Count_form_state2)
{
    this->next_state1_for_Row = next_state1_for_Row;
    this->next_state2_for_Row = next_state2_for_Row;
    this->next_state1_for_Col = next_state1_for_Col;
    this->next_state2_for_Col = next_state2_for_Col;
    this->Row = Row;
    this->Col = Col;
    this->Count_form_state1 = Count_form_state1;
    this->Count_form_state2 = Count_form_state2;
}

implement_box::implement_box()
{
    ;
}

void implement_box::setActive(bool isActive)
{
    this->isActive = isActive;
}

bool implement_box::getActive()
{
    return isActive;
}

void implement_box::setnext_state1_for_Row(char next_state1_for_Row)
{
    this->next_state1_for_Row = next_state1_for_Row;
}

char implement_box::getnext_state1_for_Row()
{
    return next_state1_for_Row;
}

void implement_box::setnext_state2_for_Row(char next_state2_for_Row)
{
    this->next_state2_for_Row = next_state2_for_Row;
}

char implement_box::getnext_state2_for_Row()
{
    return next_state2_for_Row;
}

void implement_box::setnext_state1_for_Col(char next_state1_for_Col)
{
    this->next_state1_for_Col = next_state1_for_Col;
}

char implement_box::getnext_state1_for_Col()
{
    return next_state1_for_Col;
}

void implement_box::setnext_state2_for_Col(char next_state2_for_Col)
{
    this->next_state2_for_Col = next_state2_for_Col;
}

char implement_box::getnext_state2_for_Col()
{
    return next_state2_for_Col;
}

void implement_box::setRow(char Row)
{
    this->Row = Row;
}

char implement_box::getRow()
{
    return Row;
}

void implement_box::setCol(char Col)
{
    this->Col = Col;
}

char implement_box::getCol()
{
    return Col;
}

int implement_box::getCount_form_state1()
{
    return Count_form_state1;
}

int implement_box::getCount_form_state2()
{
    return Count_form_state2;
}

void implement_box::print()
{
    cout << "Row: " << Row << ", Col: " << Col << endl;
    cout << next_state1_for_Col << "-" << next_state1_for_Row << endl;
    cout << next_state2_for_Col << "-" << next_state2_for_Row << endl;
    cout << Count_form_state1 << " " << Count_form_state2 << endl;
}

class implement_table
{
    public:
        implement_table(vector<implement_box> vec_implement_box);
    private:
        vector<state_class> vec_implement_box;
};

implement_table::implement_table(vector<implement_box> vec_implement_box)
{
    //
}

string read_kiss(string path)
{
    ifstream file;
    string str, buffer;
    file.open(path, std::ifstream::in);
    if (!file)
        cout << "can't open file" << endl;
    else
    {
        while(file >> buffer)
        {
            str.append(buffer);
            if (file.peek() == '\n')
                str.append("\n");
            if (file.peek() == ' ')
                str.append(" ");
        }
        file.close();
    }
    str.pop_back();
    cout << str << endl;
    return str;
}

vector<state_class> string_analysis(string str)
{
    int start = str.find(".r a"), length = str.length();
    char input_binary;
    char now_state;
    char next_state;
    char output_binary;
    vector<state_class> vec_state_class;
    for (int i = start + 5, count = 0; i < length; i += 8)
    {
        if (str.find(".end_kiss") == i)
            break;
        else
        {
            input_binary = str.at(i);
            now_state = str.at(i + 2);
            next_state = str.at(i + 4);
            output_binary = str.at(i + 6);
            vec_state_class.push_back(state_class(input_binary, now_state, next_state, output_binary, count));
            count++;
        }
    }
    for (int i = 0; i < vec_state_class.size(); i++)
    {
        vec_state_class.at(i).printVec();
    }
    return vec_state_class;
}

bool isInCompatible(char output1, char output2)
{
    if (output1 != output2)
        return 0;
    else
        return 1;
}

vector<implement_box> state_class_to_implementBox(vector<state_class> vec_state_class)
{
    char Row = 'a', Col = 'b';
    int length = vec_state_class.size(), count = 0;
    vector<implement_box> vec_implement_box;
    for (int i = 0; i < length; i += 2)
    {
        Col = 'b' + count;
        for (int j = i + 2; j < length; j += 2)
        {
            implement_box box(
                vec_state_class.at(i).getNext_state(), vec_state_class.at(i + 1).getNext_state(),
                vec_state_class.at(j).getNext_state(), vec_state_class.at(j + 1).getNext_state(),
                Row, Col, vec_state_class.at(i).getCount(), vec_state_class.at(j).getCount());
            //box.print();
            bool state1 = isInCompatible(
                vec_state_class.at(i).getOutput_binary(), vec_state_class.at(j).getOutput_binary());
            bool state2 = isInCompatible(
                vec_state_class.at(i + 1).getOutput_binary(), vec_state_class.at(j + 1).getOutput_binary());
            if (state1 && state2)
                ;
            else
                box.setActive(0);
            vec_implement_box.push_back(box);
            Col++;
        }
        Row++;
        count++;
    }
    return vec_implement_box;
}

int find_statement(string str)
{
    return str.find(".s", str.find(".s") + 1) + 3;
}

vector<state_class> reduce_implement_box(vector<implement_box> box, vector<state_class> vec_state_class)
{
    int length = box.size();
    bool state = 0;
    vector<state_class> vec;
    do
    {
        state = 0;
        for (int i = 0; i < length; i++)
        {
            for (int j = 0; j < length; j++)
            {
                if (box.at(i).getActive())
                {
                    bool state1 = isInCompatible(box.at(i).getnext_state1_for_Row(), box.at(j).getRow());
                    bool state2 = isInCompatible(box.at(i).getnext_state1_for_Col(), box.at(j).getCol());
                    bool state3 = isInCompatible(box.at(i).getnext_state2_for_Row(), box.at(j).getRow());
                    bool state4 = isInCompatible(box.at(i).getnext_state2_for_Col(), box.at(j).getCol());
                    bool state5 = isInCompatible(box.at(i).getnext_state1_for_Row(), box.at(j).getCol());
                    bool state6 = isInCompatible(box.at(i).getnext_state1_for_Col(), box.at(j).getRow());
                    bool state7 = isInCompatible(box.at(i).getnext_state2_for_Row(), box.at(j).getCol());
                    bool state8 = isInCompatible(box.at(i).getnext_state2_for_Col(), box.at(j).getRow());
                    if ((state1 && state2) || (state3 && state4) || (state5 && state6) || (state7 && state8))
                    {
                        if (!box.at(j).getActive())
                        {
                            box.at(i).setActive(0);
                            state = 1;
                            break;
                        }
                    }
                }
            }
        }
    } while (state);
    for (int i = 0; i < box.size(); i++)
    {
        if (box.at(i).getActive())
        {
            box.at(i).print();
            vec_state_class.at(box.at(i).getCount_form_state1()).printVec();
            vec_state_class.at(box.at(i).getCount_form_state1() + 1).printVec();
            vec_state_class.at(box.at(i).getCount_form_state2()).printVec();
            vec_state_class.at(box.at(i).getCount_form_state2() + 1).printVec();
            bool state1 = isInCompatible(
                vec_state_class.at(box.at(i).getCount_form_state1()).getNext_state(),
                vec_state_class.at(box.at(i).getCount_form_state2()).getNext_state());
            bool state2 = isInCompatible(
                vec_state_class.at(box.at(i).getCount_form_state1() + 1).getNext_state(),
                vec_state_class.at(box.at(i).getCount_form_state2() + 1).getNext_state());
            if (state1 && state2)
            {
                vec_state_class.at(box.at(i).getCount_form_state2()).setActive(0);
                vec_state_class.at(box.at(i).getCount_form_state2() + 1).setActive(0);
            }
            else if(state1 || state2)
            {
                char temp = vec_state_class.at(box.at(i).getCount_form_state1() + 1).getNow_state();
                vec_state_class.at(box.at(i).getCount_form_state1() + 1).setNext_state(temp);
                vec_state_class.at(box.at(i).getCount_form_state2()).setActive(0);
                vec_state_class.at(box.at(i).getCount_form_state2() + 1).setActive(0);
            }
        }
    }
    for (int i = 0; i < vec_state_class.size(); i++)
    {
        if (vec_state_class.at(i).getActive())
        {
            vec.push_back(vec_state_class.at(i));
            vec_state_class.at(i).printVec();
        }
    }
    return vec;
}

void output_kiss(vector<state_class> vec, string out_kiss, string out_dot)
{
    ofstream file;
    string str = ".start_kiss\n.i 1\n.o 1\n";
    int count = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec.at(i).getActive())
            count++;
    }
    file.open(out_kiss);
    if (file.is_open())
    {
        cout << "output start" << endl;
        file << str << ".p " << count << "\n.s " << count / 2<<"\n";
        file << ".r a\n";
        for (int i = 0; i < vec.size(); i++)
        {
            if (vec.at(i).getActive())
            {
                file << vec.at(i).getInput_binary() << " " << vec.at(i).getNow_state() <<
                     " " << vec.at(i).getNext_state() << " " << vec.at(i).getOutput_binary()<<"\n";
            }
        }
        file << ".end_kiss";
        file.close();
    }
    else
        cout << "can't open file" << endl;
    str = "digraph{\n\trankdir = LR\n\tINIT [shape=point]\n\t";
    file.open(out_dot);
    if (file.is_open())
    {
        cout << "output start" << endl;
        file << str;
        for (int i = 0; i < vec.size(); i += 2)
        {
            file << vec.at(i).getNow_state();
            file << " [label=\"" << vec.at(i).getNow_state() << "\"]\n\t";
        }
        file << "INIT -> a\n\t";
        for (int i = 0; i < vec.size(); i++)
        {
            file << vec.at(i).getNow_state() << "->" << vec.at(i).getNext_state() << " [label=\"";
            file << vec.at(i).getInput_binary() << "/" << vec.at(i).getOutput_binary()<<"\"]";
            if (i < vec.size() - 1)
                file << "\n\t";
            else
                file << "\n";
        }
        file << "}";
        file.close();
    }
    else
        cout << "can't open file" << endl;
}

int main(int argc, char *argv[])
{
    string arg = argv[1];
    if (argv == NULL)
    {
        cout << "no assigned file\ninsert command like g++ Digital_home_work1 example.pla" << endl;
        return 1;
    }
    string str = read_kiss(arg);
    vector<state_class> vec_state_class = string_analysis(str);
    vector<implement_box> box = state_class_to_implementBox(vec_state_class);
    for (int i = 0; i < box.size(); i++)
    {
        box.at(i).print();
    }
    cout << "*************************" << endl;
    vector<state_class> temp = reduce_implement_box(box, vec_state_class);
    output_kiss(temp, argv[2], argv[3]);
    return 1;
}