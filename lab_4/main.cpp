#include <iostream>
#include "header.h"
#include <string>
#include <cstring>
#include <cstdio>


using namespace std;

int main() {
    int n,i;
    string s;
    EditableText a("I'm waking up to ash and dust\n"
                   "I wipe my brow and I sweat my rust\n"
                   "I'm breathing in the chemicals\n"
                   "I'm breaking in, shaping up,\n"
                   "Then checking out on the prison bus\n"
                   "This is it, the apocalypse\n"
                   "Whoa\n"
                   "I'm waking up, I feel it in my bones\n"
                   "Enough to make my systems blow\n"
                   "Welcome to the new age, to the new age\n"
                   "Welcome to the new age, to the new age\n"
                   "Whoa, whoa, I'm radioactive, radioactive\n"
                   "Whoa, whoa, I'm radioactive, radioactive\n"
                   "I raise my flags, don my clothes\n"
                   "It's a revolution, I suppose\n"
                   "We'll paint it red to fit right in\n"
                   "Whoa\n"
                   "I'm breaking in, shaping up,\n"
                   "Then checking out on the prison bus\n"
                   "This is it, the apocalypse\n"
                   "Whoa\n"
                   "I'm waking up, I feel it in my bones\n"
                   "Enough to make my systems blow\n"
                   "Welcome to the new age, to the new age\n"
                   "Welcome to the new age, to the new age\n"
                   "Whoa, whoa, I'm radioactive, radioactive\n"
                   "Whoa, whoa, I'm radioactive, radioactive\n"
                   "All systems go, sun hasn't died\n"
                   "Deep in my bones, straight from inside\n"
                   "I'm waking up, I feel it in my bones\n"
                   "Enough to make my systems blow\n"
                   "Welcome to the new age, to the new age\n"
                   "Welcome to the new age, to the new age\n"
                   "Whoa, whoa, I'm radioactive, radioactive\n"
                   "Whoa, whoa, I'm radioactive, radioactive");
    Text b("Will you hold the line\n"
           "When every one of them has given up and given in? Tell me\n"
           "In this house of mine\n"
           "Nothing ever comes without a consequence or cost, tell me\n"
           "Will the stars align?\n"
           "Will heaven step in? Will it save us from our sin? Will it?\n"
           "Cause this house of mine stands strong\n"
           "[Pre-Chorus]\n"
           "That's the price you pay\n"
           "Leave behind your heart and cast away\n"
           "Just another product of today\n"
           "Rather be the hunter than the prey\n"
           "And you're standing on the edge, face up 'cause you're a...\n"
           "[Chorus]\n"
           "Natural\n"
           "A beating heart of stone\n"
           "You gotta be so cold\n"
           "To make it in this world\n"
           "Yeah, you're a natural\n"
           "Living your life cutthroat\n"
           "You gotta be so cold\n"
           "Yeah, you're a natural\n"
           "[Verse 2]\n"
           "Will somebody\n"
           "Let me see the light within the dark trees shadowing?\n"
           "What's happenin'?\n"
           "Lookin' through the glass find the wrong within the past knowin'\n"
           "Oh, we are the youth\n"
           "Cut until it bleeds inside a world without the peace, face it\n"
           "A bit of the truth, the truth\n"
           "[Pre-Chorus]\n"
           "That's the price you pay\n"
           "Leave behind your heart and cast away\n"
           "Just another product of today\n"
           "Rather be the hunter than the prey\n"
           "And you're standing on the edge, face up 'cause you're a...\n"
           "[Chorus]\n"
           "Natural\n"
           "A beating heart of stone\n"
           "You gotta be so cold\n"
           "To make it in this world\n"
           "Yeah, you're a natural\n"
           "Living your life cutthroat\n"
           "You gotta be so cold\n"
           "Yeah, you're a natural\n"
           "[Outro]\n"
           "Deep inside me, I'm fading to black, I'm fading\n"
           "Took an oath by the blood of my hand, won't break it\n"
           "I can taste it, the end is upon us, I swear\n"
           "Gonna make it\n"
           "I'm gonna make it");
    b.show();
    cout<<"In text b "<<b.how_much_line()<<" line"<<endl;
    cout<<"Which line do you want to get? "<<endl;
    cin>>n;
    cout<<b.which_line(n)<<endl;
    cout<<"Which line do you want to know the lexem? "<<endl;
    cin>>n;
    cout<<"Which lexem do you want to know? "<<endl;
    cin>>i;
    cout<<"In line "<<n<<" "<<i<<"th lexem is "<<b.what_is_lexem(n,i)<<endl;
    cout<<"Which line do you want to know how many lexem? "<<endl;
    cin>>n;
    cout<<"In line "<<n<<" "<<b.how_much_lexems(n)<<" lexem"<<endl<<endl;

    a.show();
    cout<<"In text a "<<a.how_much_line()<<" line"<<endl;
    cout<<"Which line do you want to replace? "<<endl;
    cin>>n;
    cout<<"What to replace ? "<<endl;
    getline(cin,s);
    getline(cin,s);
    cout<<s<<endl;
    a.replace_line(n,s);
    a.show();
    cout<<"Which line do you want to replace the lexem? "<<endl;
    cin>>n;
    cout<<"Which lexem do you want to replace? "<<endl;
    cin>>i;
    cout<<"What to replace? "<<endl;
    getline(cin,s);
    getline(cin,s);
    a.replace_lexem(n,i,s);
    a.show();
    cout<<"What lexem do you want to find? "<<endl;
    getline(cin,s);
    a.where_is_lexem(s);
    cout<<"The end"<<endl;
    return 0;
}