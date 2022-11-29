#include <iostream>
#include "header.h"
#include<vector>
#include <string>
#include <cstring>

using  namespace std;

Text::Text(){

}

Text::Text(string tex) {
    string tmp;
    int start, end, j;
    j = 0;
    start = 0;
    end = 0;
    while (end < tex.length()) {
        end = 0;
        while (end == 0) {
            j++;
            if (j == tex.length()) {
                end = j;
            } else {
                if (tex[j] == '\n') {
                    end = j - 1;
                }
            }
        }

        tmp.resize(end - start + 1);
        for (int k = start; k <= end; k++) {
            tmp[k - start] = tex[k];
        }
        blok.push_back(tmp);
        start = end + 2;
    }
}

void Text::show() {
    for(int i=0;i<blok.size();i++){
        if(blok[i].size()>0) {
            cout << "| " << blok[i] << " |" << endl;
        }
    }
    cout<<endl;
}

int Text::how_much_lexems(int n) {
    if(n>blok.size()||n<1){
        cout<<"I don't know this line :( "<<endl;
        return 0;
    }else{
        n--;
        int count=0;
        for(int i=0;i<blok[n].size()-1;i++){
            if((isalnum(blok[n][i]))&&((i+1==blok[n].size()-1)||(!isalnum(blok[n][i+1]))||(blok[n][i+1]=='\n'))){
                count++;
            }
        }
        return count;
    }
}

string Text::what_is_lexem(int n, int i) {
    if(n>blok.size()||n<1){
        cout<<"I don't know this line :( "<<endl;
        return "";
    }else{
        n--;
        if(i<1){
            cout<<"I don't know this lexem "<<endl;
            return "";
        }
        i--;
        int count=0;
        int start=0;
        int end=0;
        for(int j=0;j<blok[n].size();j++){
            if(j>0){
                if(isalnum(blok[n][j])&&(!isalnum(blok[n][j-1]))){
                    start=j;
                }
            }
            if((isalnum(blok[n][j]))&&((j==blok[n].size()-1)||(!isalnum(blok[n][j+1]))||(blok[n][j+1]=='\n'))){
                count++;
                end=j;
            }
            if(count==i+1){

                string tmp;
                tmp.resize(end-start +1);
                for(int k=start;k<=end;k++){
                    tmp[k-start]=blok[n][k];
                }
                return tmp;
            }
        }
        return "NULL";
    }
}

int Text::how_much_line() {
    return blok.size();
}

string Text::which_line(int n) {
    if(n>blok.size()||n<1){
        cout<<" I don't know this line ";
        return "";
    }else{
        n--;
        return blok[n];
    }
}

EditableText::EditableText():Text(){

}

EditableText::EditableText(string tex) : Text(tex) {

}

void EditableText::show() {
    Text::show();
}

int EditableText::how_much_lexems(int n) {
    return Text::how_much_lexems(n);
}

string EditableText::what_is_lexem(int n, int i) {
    return Text::what_is_lexem(n, i);
}

void EditableText::replace_line(int n, string tex) {
    if((n>blok.size())||(n<1)){
        cout<<"I don't know this line "<<endl;
    }else{
        n--;
        blok[n].resize(tex.size());
        blok[n]=tex;
    }
}

void EditableText::replace_lexem(int n, int i, string tex) {
    if(n>blok.size()||n<1){
        cout<<"I don't know this line :( "<<endl;

    }else{
        n--;
        if(i<1){
            cout<<"I don't know this lexem "<<endl;

        }

        int count=0;
        int start=0;
        int end=0;
        for(int j=0;j<blok[n].size();j++){
            if(j>0){
                if(isalnum(blok[n][j])&&(!isalnum(blok[n][j-1]))){
                    start=j;
                }
            }
            if((isalnum(blok[n][j]))&&((j+1==blok[n].size())||(!isalnum(blok[n][j+1]))||(blok[n][j+1]=='\n'))){
                count++;
                end=j;
            }
            if(count==i){
                string tmp;
                tmp.resize(blok[n].size()+tex.size()-(end-start+1));
                int j=0;
                int k=0;
                while(j<tmp.size()){
                    if(j<start){
                        tmp[j]=blok[n][j];
                    }
                    if(k==tex.size()&&end<blok[n].size()){
                        end++;
                        tmp[j]=blok[n][end];
                    }
                    if(j>=start&&k<tex.size()){
                        tmp[j]=tex[k];
                        k++;
                    }

                    j++;
                }
                blok[n].resize(tmp.size());
                blok[n]=tmp;
                break;
            }
        }
        if(count<i) {
            cout << "I don't know this lexem " << endl;
        }
    }
}

void EditableText::where_is_lexem(string tex) {
    bool is_lexem=true;
    bool find_lexem=0;
    for(int k=0;k<tex.size();k++){
        if(!isalnum(tex[k])){
            is_lexem= false;
        }
    }
    if(is_lexem){
        for(int n=0;n<blok.size();n++){
            for(int i=0;i<blok[n].size();i++){
                if(Text::what_is_lexem(n+1, i+1)==tex){
                    find_lexem=true;
                    cout<<"Lexem ("<<tex<<") on line "<<n+1<<" on the "<<i+1<<"th place"<<endl;
                    break;
                }

            }
            if(find_lexem){
                break;
            }
        }
        if(!find_lexem){
            cout<<"I don't know this lexem "<<endl;
        }
    }else{
        cout<<"It is not lexem "<<endl;
    }
}


