#include <iostream>
#include "Header.h"
#include <algorithm>

using namespace std;

const double pi=3.14;

class comp_{
public:
    bool operator()(figure* first,figure* second){
        return *first<*second;
    }
};

double Rectangle::perimeter() {
    return side_y*2+side_x*2;
}

double Rectangle::square() {
    return side_x*side_y;
}

bool Rectangle::operator<( IPhysObject &ob)  {
    return (this->mass()<ob.mass());
}

bool Rectangle::operator==(IPhysObject &ob) {
    return (this->mass()==ob.mass());
}

CVector2D Rectangle::position() {
    CVector2D tmp;
    tmp.x=side_x/2+x;
    tmp.y=side_y/2+y;
    return tmp;
}

double Rectangle::mass() {
    return square()*density;
}

void Rectangle::draw() {
    cout<<endl;
    cout<<"Rectangle name : "<<this->classname()<<endl;
    cout<<"Start ( "<<x<<","<<y<<") "<<endl;
    cout<<"Side x= "<<side_x<<"     Side y= "<<side_y<<endl;
    cout<<"Square = "<<this->square()<<"    Perimeter= "<<this->perimeter()<<endl;
    cout<<"Mass = "<<this->mass()<<" ";
    CVector2D tmp=this->position();
    cout<<"Center mass ( "<<tmp.x<<","<<tmp.y<<" )"<<endl;
}

void Rectangle::initFromDialog() {
    cout<<"Enter name "<<endl;
    cin>>name;
    cout<<"Enter start  "<<endl;
    cin>>x>>y;
    side_x=0;
    cout<<"Enter side x "<<endl;
    while(side_x<=0){
        cin>>side_x;
        if(side_x<=0){
            cout<<"Incorrect side. Please try again"<<endl;
        }
    }
    side_y=0;
    cout<<"Enter side y"<<endl;
    while(side_y<=0){
        cin>>side_y;
        if(side_y<=0){
            cout<<"Incorrect side. Please try again"<<endl;
        }
    }
    density=0;
    cout<<"Enter density"<<endl;
    while(density<=0){
        cin>>density;
        if(density<=0){
            cout<<"Incorrect density. Please try again"<<endl;
        }
    }
}

unsigned int Rectangle::size() {
    return name.size()+ sizeof(side_y)+ sizeof(side_x)+ sizeof(density)+sizeof(x)+sizeof(y);
}

string Rectangle::classname() {
    return name;
}

double Ellipse::square() {
    return pi*a*b;
}

double Ellipse::perimeter() {
    return (4*((pi*a*b+(a-b))/(a+b)));
}

string Ellipse::classname() {
    return name;
}

unsigned int Ellipse::size() {
    return name.size()+ sizeof(a)+ sizeof(b)+ sizeof(density)+sizeof(x)+sizeof(y);
}

void Ellipse::initFromDialog() {
    cout<<"Enter name "<<endl;
    cin>>name;
    cout<<"Enter start  "<<endl;
    cin>>x>>y;
    a=0;
    cout<<"Enter a "<<endl;
    while(a==0){
        cin>>a;
        if(a==0){
            cout<<"Incorrect a. Please try again"<<endl;
        }
    }
    b=0;
    cout<<"Enter b"<<endl;
    while(b==0){
        cin>>b;
        if(b==0){
            cout<<"Incorrect b. Please try again"<<endl;
        }
    }
    density=0;
    cout<<"Enter density"<<endl;
    while(density<=0){
        cin>>density;
        if(density<=0){
            cout<<"Incorrect density. Please try again"<<endl;
        }
    }
}

void Ellipse::draw() {
    cout<<endl;
    cout<<"Ellipse name : "<<this->classname()<<endl;
    cout<<"Start ( "<<x<<","<<y<<" ) "<<endl;
    cout<<"a= "<<a<<"     b= "<<b<<endl;
    cout<<"Square = "<<this->square()<<"    Perimeter= "<<this->perimeter()<<endl;
    cout<<"Mass = "<<this->mass()<<" ";
    CVector2D tmp=this->position();
    cout<<"Center mass ( "<<tmp.x<<","<<tmp.y<<" )"<<endl;
}

double Ellipse::mass() {
    return this->square()*density;
}

CVector2D Ellipse::position() {
    CVector2D tmp;
    tmp.x=x;
    tmp.y=y;
    return tmp;
}

bool Ellipse::operator==(IPhysObject &ob) {
    return (this->mass()==ob.mass());
}

bool Ellipse::operator<( IPhysObject &ob)  {
    return (this->mass()<ob.mass());
}


void Menu::Start() {
    this->Info();
    string tmp;
    cin>>tmp;
    while(tmp!="exit"){
        bool flag=false;
        if(tmp=="rec"){
            cout<<endl;
            this->SetNewRectangle();
            flag=true;
        }
        if(tmp=="ell"){
            this->SetNewEllipse();
            flag=true;
        }
        if(tmp=="dr"){
            cout<<endl;
            this->DrawAll();
            flag=true;
        }
        if(tmp=="sq"){
            cout<<endl;
            this->SquareAll();
            flag=true;
        }
        if(tmp=="per"){
            cout<<endl;
            this->PerimeterAll();
            flag=true;
        }
        if(tmp=="center"){
            cout<<endl;
            this->CenterAll();
            flag=true;
        }
        if(tmp=="mem"){
            cout<<endl;
            this->SizeAll();
            flag=true;
        }
        if(tmp=="sort"){
            cout<<endl;
            this->SortAll();
            flag=true;
        }
        if(tmp=="info"){
            cout<<endl;
            this->Info();
            flag=true;
        }
        if(flag) {
            cout << "All correct. Wait a command" << endl;
        }else{
            cout<<" I don't know this command "<<endl;
        }
        cin>>tmp;
    }
}

void Menu::SetNewRectangle() {
    Rectangle *tmp = new Rectangle;
    tmp->initFromDialog();
    object.push_back(tmp);
}

void Menu::SetNewEllipse() {
    Ellipse *tmp = new Ellipse;
    tmp->initFromDialog();
    object.push_back(tmp);
}

void Menu::DrawAll() {
    for(int i=0;i<object.size();i++){
        cout<<i+1<<" Object"<<endl;
        object[i]->draw();
    }
}

void Menu::SizeAll() {
    unsigned int tmp=0;
    for(int i=0;i<object.size();i++){
        tmp+=object[i]->size();
    }
    cout<<"Memory all system = "<<tmp<<endl;
}

void Menu::PerimeterAll() {
    double tmp=0;
    for(int i=0;i<object.size();i++){
        tmp+=object[i]->perimeter();
    }
    cout<<"Sum all perimeter = "<<tmp<<endl;
}

void Menu::CenterAll() {
    CVector2D tmp_r;
    tmp_r.x=0;
    tmp_r.y=0;
    double tmp_m=0;
    for(int i=0;i<object.size();i++){
        double m=object[i]->mass();
        CVector2D r=object[i]->position();
        r.x*=m;
        r.y*=m;
        tmp_r.x+=r.x;
        tmp_r.y+=r.y;
        tmp_m+=m;
    }
    cout<<"Center all system ( "<<tmp_r.x/tmp_m<<","<<tmp_r.y/tmp_m<<" )"<<endl;
}

void Menu::SortAll() {
    sort(object.begin(),object.end(),comp_());
}

void Menu::Info() {
    cout<<"Function :"<<endl<<"--Create new rectangle: rec"<<endl;
    cout<<"--Create new ellipse: ell"<<endl<<"--Draw all: dr"<<endl<<"--Sum all square: sq"<<endl;
    cout<<"--Sum all perimeter: per"<<endl<<"--Center all system: center"<<endl;
    cout<<"--Memory all system: mem"<<endl<<"--Sort to mass: sort"<<endl;
    cout<<"--Repeat info about system: info"<<endl;
    cout<<"--Exit: exit"<<endl;
}

void Menu::SquareAll() {
    double tmp=0;
    for(int i=0;i<object.size();i++){
        tmp+=object[i]->square();
    }
    cout<<"Sum all square = "<<tmp<<endl;
}
