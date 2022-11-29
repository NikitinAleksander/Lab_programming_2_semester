
#ifndef LAB_4_HEADER_H
#define LAB_4_HEADER_H

#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class Text {
public:
    Text();

    Text(string tex);

    virtual void show();

    virtual int how_much_lexems(int n);

    virtual string what_is_lexem(int n,int i);

    virtual int how_much_line();

    virtual string which_line(int n);

protected:
    vector<string> blok;
};

class EditableText: public Text{
public:
    EditableText();

    EditableText(string tex);

    void show();

    int how_much_lexems(int n);

    string what_is_lexem(int n,int i);

    void replace_line(int n,string tex);

    void replace_lexem(int n,int i,string tex);

    void where_is_lexem(string tex);
};

#endif //LAB_4_HEADER_H
