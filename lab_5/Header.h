#pragma once

#include <vector>
#include <string>

using  namespace std;

class IGeoFig{
public:
    virtual double square()=0;
    virtual double perimeter()=0;
};

class CVector2D{
public:
    double x,y;
};

class IPhysObject{
public:
    virtual double mass()=0;
    virtual  CVector2D position()=0;
    virtual bool operator==( IPhysObject& ob) =0;
    virtual bool operator<(IPhysObject& ob) =0;
};

class IPrintable{
public:
    virtual void draw()=0;
};

class IDialogInitiable{
public:
    virtual void initFromDialog()=0;
};

class BasecObject{
public:
    virtual string classname()=0;
    virtual unsigned int size()=0;
};

class figure : public IGeoFig,public IPhysObject,public IPrintable,public IDialogInitiable,public BasecObject {
public:
};


class Rectangle: public figure{
public:
     double square() ;
     double perimeter();
     string classname();
     unsigned int size();
     void initFromDialog();
     void draw();
     double mass();
     CVector2D position();
     bool operator==( IPhysObject& ob);
     bool operator<( IPhysObject& ob) ;

    double side_x,side_y,density,x,y;
    string name;
};

class Ellipse: public figure{
public:
    double square();
    double perimeter();
    string classname();
    unsigned int size();
    void initFromDialog();
    void draw();
    double mass();
    CVector2D position();
    bool operator==( IPhysObject& ob) ;
    bool operator<(IPhysObject& ob) ;

    double a,b,density,x,y;
    string name;
};



class Menu{
public:
    vector<figure*> object;
private:
    void Info();
    void SetNewRectangle();
    void SetNewEllipse();
    void DrawAll();
    void SquareAll();
    void SizeAll();
    void PerimeterAll();
    void CenterAll();
    void SortAll();
public:
    void Start();
};
