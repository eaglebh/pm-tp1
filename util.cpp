#include <cstring>
#include <sstream>
#include <iostream>
#include "util.h"

using namespace std;

Util::Util()
{
}

void Util::stripBrackets(string &searchString)
{
    size_t pos = searchString.find_first_of('{');
    if(pos != string::npos){
        searchString = searchString.substr(pos+1,searchString.length()-2);
    }
}

unsigned int Util::parseInt(const string text)
{
    unsigned int number = 0;
    istringstream iss(parseString(text));
    iss >> number;
    if(iss.fail()){
        throw "Erro ao ler numero.";
    }

    return number;
}

string Util::parseString(const string text)
{
    string innerText;
    string searchString = text;
    stripBrackets(searchString);
    istringstream iss(searchString);
    iss >> innerText;
    if(iss.fail()){
        throw "Erro ao ler string.";
    }

    return innerText;
}

string Util::parseField(const string fieldName, const string text) {
    string fieldValue;
    stringstream format;
    char array[1024];
    memset(array, '\0', 1024*sizeof(char));
    format << fieldName << " = " << "{%1023[^}]},";
    if(sscanf(text.c_str(), format.str().c_str(), array) <= 0) {
        stringstream format;
        format << fieldName << " = " << "\"%1023[^\"]\",";
        sscanf(text.c_str(), format.str().c_str(), array);
    }
    fieldValue = string(array);
    return fieldValue;
}

void Util::test()
{
    int p1, p2, p3, p4;

    string pages = "12-15,18,20";
    int read = 0;
    sscanf(pages.c_str(), "%d[^-,]%n",&p1, &read);
    sscanf(pages.c_str(), "%d[^-,]%n",&p2, &read);
    sscanf(pages.c_str(), "%d[^-,]%n",&p3, &read);
    sscanf(pages.c_str(), "%d[^-,]%n",&p4, &read);

    cout << "read=" <<read << endl;
    cout << p1 << endl;
    cout << p2 << endl;
    cout << p3 << endl;
    cout << p4 << endl;

    istringstream iss(pages);
    iss >> p1 >> p2 >> p3 >> p4;
    cout << p1 << endl;
    cout << p2 << endl;
    cout << p3 << endl;
    cout << p4 << endl;

}
