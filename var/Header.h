#pragma once
class var
{
private:
    int* intvar;
    double* pDe;
    string* mystring;
    int type;  
public:
    var() { type = -1; intvar = NULL; pDe = NULL; mystring = NULL; };
    var(const int& number);
    var(const double& number);
    var(const string& str);
    void Show();
    int toInt()const;
    double toDouble()const;
    char* toCharPtr()const;
    const string toString()const;
    var& operator = (const var& rVar);
    var& operator = (const int& number);
    var& operator = (const double& number);
    var& operator = (const string& str);
    const var operator + (const var& rVar);
    const var operator - (const var& rVar);
    const var operator * (const var& rVar);
    const var operator / (const var& rVar);
    var& operator += (const var& rVar);
    var& operator -= (const var& rVar);
    var& operator *= (const var& rVar);
    var& operator /= (const var& rVar);
    bool operator < (const var& rVar);
    bool operator > (const var& rVar);
    bool operator <= (const var& rVar);
    bool operator >= (const var& rVar);
    bool operator == (const var& rVar);
    bool operator != (const var& rVar);
};

const string operator * (const string& leftStr, const string& rightStr);
const string operator / (const string& leftStr, const string& rightStr);
const string operator - (const string& leftStr, const string& rightStr);