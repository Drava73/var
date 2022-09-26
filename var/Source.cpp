#include <iostream>
#include "Header.h"
 using namespace std;
  var::var(const int& number)
{
    type = 0;
    intvar = new int(number);
}

var::var(const double& number)
{
    type = 1;
    pDe = new double(number);
}

var::var(const string& str)
{
    type = 2;
    mystring = new string(str);
}

void var::Show()
{
    switch (type)
    {
    case 0: cout << *intvar; return;
    case 1: cout << *pDe; return;
    case 2: cout << *mystring; return;
    }
    cout << "NULL";

}

int var::toInt() const
{
    switch (type)
    {
    case 0: return *intvar;
    case 1: return (int)*pDe;
    case 2: return atoi((*mystring).c_str());
    }
    return 0;
}

double var::toDouble() const
{
    switch (type)
    {
    case 0: return (double)*intvar;
    case 1: return *pDe;
    case 2: return (double)atof((*mystring).c_str());
    }
    return 0;
}

char* var::toCharPtr() const
{
    char* tmpStr = new char[80];
    switch (type)
    {
    case 0:
        return itoa(*intvar, tmpStr, 10);
    case 1:
        sprintf(tmpStr, "%lf", *pDe);
        return tmpStr;
    case 2:
        strcpy(tmpStr, (*mystring).c_str());
        return tmpStr;
    }
    return NULL;
}

const string var::toString() const
{
    if (type == 2)
    {
        return string(*mystring);

    }
    return string(toCharPtr());


}

const var var::operator + (const var& rVar)
{
    switch (type)
    {
    case 0:
        return var(*intvar + rVar.toInt());

    case 1:
        return var(*pDe + rVar.toDouble());

    case 2:
        return var(*mystring + rVar.toString());

    }
    return *this;
}

const var var::operator - (const var& rVar)
{
    switch (type)
    {
    case 0:
        return var(*intvar - rVar.toInt());
    case 1:
        return var(*pDe - rVar.toDouble());

    case 2:
        return var(*mystring - rVar.toString());

    }
    return *this;
}

const var var::operator * (const var& rVar)
{
    switch (type)
    {
    case 0:
        return var(*intvar * rVar.toInt());

    case 1:
        return var(*pDe * rVar.toDouble());

    case 2:
        return var(*mystring * rVar.toString());

    }
    return *this;
}

const var var::operator / (const var& rVar)
{
    switch (type)
    {
    case 0:
        return var(*intvar / rVar.toInt());

    case 1:
        return var(*pDe / rVar.toDouble());

    case 2:
        return var(*mystring / rVar.toString());

    }
    return *this;
}

var& var::operator += (const var& rightVar)
{
    switch (type)
    {
    case 0:
        *intvar = *intvar + rightVar.toInt();
        return *this;
    case 1:
        *pDe = *pDe + rightVar.toDouble();
        return *this;
    case 2:
        *mystring = *mystring + rightVar.toString();
        return *this;
    }
    return *this;
}

var& var::operator -= (const var& rightVar)
{
    switch (type)
    {
    case 0:
        *intvar = *intvar - rightVar.toInt();
        return *this;
    case 1:
        *pDe = *pDe - rightVar.toDouble();
        return *this;
    case 2:
        *mystring = *mystring - rightVar.toString();
        return *this;
    }
    return *this;
}

var& var::operator *= (const var& rightVar)
{
    switch (type)
    {
    case 0:
        *intvar = *intvar * rightVar.toInt();
        break;
    case 1:
        *pDe = *pDe * rightVar.toDouble();
        break;
    case 2:
        *mystring = *mystring * rightVar.toString();
        break;
    }
    return *this;
}

var& var::operator /= (const var& rightVar)
{
    switch (type)
    {
    case 0:
        *intvar = *intvar / rightVar.toInt();
        break;
    case 1:
        *pDe = *pDe / rightVar.toDouble();
        break;
    case 2:
        *mystring = *mystring / rightVar.toString();
        break;
    }
    return *this;
}

bool var::operator > (const var& rightVar)
{
    switch (type)
    {
    case 0:
        return *intvar > rightVar.toInt();
    case 1:
        return *pDe > rightVar.toDouble();
    case 2:
        return *mystring > rightVar.toString();
    }
    return false;
}

bool var::operator < (const var& rightVar)
{
    switch (type)
    {
    case 0:
        return *intvar < rightVar.toInt();
    case 1:
        return *pDe < rightVar.toDouble();
    case 2:
        return *mystring < rightVar.toString();
    }
    return false;
}

bool var::operator == (const var& rightVar)
{
    switch (type)
    {
    case 0:
        return *intvar == rightVar.toInt();
    case 1:
        return *pDe == rightVar.toDouble();
    case 2:
        return *mystring == rightVar.toString();
    }
    return false;
}

bool var::operator <= (const var& rightVar)
{
    return(!(*this > rightVar));
}

bool var::operator >= (const var& rightVar)
{
    return(!(*this < rightVar));
}

bool var::operator != (const var& rightVar)
{
    return(!(*this == rightVar));
}
var& var::operator =(const var& rightVar)
{
    if (this == &rightVar)
    {
        return *this;
    }
    switch (type)
    {
    case 0:
        delete intvar;
        break;
    case 1:
        delete pDe;
        break;
    case 2:
        delete mystring;
        break;
    }
    type = -1;
    switch (rightVar.type)
    {
    case 0:
        intvar = new int(*(rightVar.intvar));
        break;
    case 1:
        pDe = new double(*(rightVar.pDe));
        break;
    case 2:
        mystring = new string(*(rightVar.mystring));
        break;
    }
    type = rightVar.type;
    return *this;
}
var& var::operator = (const int& number)
{
    switch (type)
    {
    case 0:
        delete intvar;
        break;
    case 1:
        delete pDe;
        break;
    case 2:
        delete mystring;
        break;
    }
    type = 0;
    intvar = new int(number);
    return *this;


}
var& var::operator = (const double& number)
{
    switch (type)
    {
    case 0:
        delete intvar;
        break;
    case 1:
        delete pDe;
        break;
    case 2:
        delete mystring;
        break;
    }
    type = 1;
    pDe = new double(number);
    return *this;
}
var& var::operator = (const string& str)
{
    switch (type)
    {
    case 0:
        delete intvar;
        break;
    case 1:
        delete pDe;
        break;
    case 2:
        delete mystring;
        break;
    }
    type = 2;
    mystring = new string(str);
    return *this;
}


const string operator * (const string& leftStr, const string& rightStr)
{
    string tmp;
    string::const_iterator i;
    string::const_iterator j;
    for (i = leftStr.cbegin(); i != leftStr.cend(); i++)
        for (j = rightStr.cbegin(); j != rightStr.cend(); j++)
            if (*i == *j)
            {
                tmp.push_back(*i);
                break;
            }

    return tmp;

}
const string operator / (const string& leftStr, const string& rStr)
{
    bool flag = true;
    string tmp;
    string::const_iterator i;
    string::const_iterator j;
    for (i = leftStr.cbegin(); i != leftStr.cend(); i++)
    {
        for (j = rStr.cbegin(); j != rStr.cend(); j++)
        {
            if (*i == *j)
            {
                flag = false;
                break;
            }
        }
        if (!flag)
        {
            flag = true;
            continue;
        }
        tmp.push_back(*i);
    }
    return tmp;

}
const string operator - (const string& lStr, const string& rStr)
{
    return lStr;
}

void test1()
{
    var a = 10, b = "120", c;
    c = a + b;
    c.Show();       
    cout << "  ";
    c = b + a;
    c.Show(); 

}

void test2()
{
    var a = "Microsoft", b = "Windows", c;
    c = a * b;
    c.Show();       
}

void test3()
{
    var a = "Microsoft", b = "Windows", c;
    c = a / b;
    c.Show();       

}

int main()
{
    var a = 15;
    var b = "Hello";
    var c = 7.8;
    var d = "50";
    b = a + d;
    b.Show();       
  
}

