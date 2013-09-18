#include <cstring>
#include <fstream>
#include <sstream>
#include <iostream>
#include <regex>
#include "util.h"
#include "bibfileio.h"

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
    int pos = text.find(fieldName);
    string line = text.substr(pos);
    char array[1024];
    memset(array, '\0', 1024*sizeof(char));
    format << fieldName << " = " << "{%1023[^}]},";
    // primeira busca com chaves
    if(sscanf(line.c_str(), format.str().c_str(), array) <= 0) {
        format.str("");
        format << fieldName << " = " << "\"%1023[^\"]\",";
        // segunda busca com aspas
        if(sscanf(line.c_str(), format.str().c_str(), array) <= 0) {
            format.str("");
            format << fieldName << " = " << "%1023[^,],";
            // terceira busca sem separadores
            sscanf(line.c_str(), format.str().c_str(), array);
        }
    }
    fieldValue = string(array);
    return fieldValue;
}

int Util::parseIntField(const string fieldName, const string text) {
    return parseInt(parseField(fieldName, text));
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

    string bibfile = "@INPROCEEDINGS {author:06, "
            "title    = {Some publication title},"
            "author   = {First Author and Second Author},"
            "crossref = {conference:06},"
            "pages    = {330—331},"
            "}"
            "@PROCEEDINGS {conference:06,"
            "editor    = {First Editor and Second Editor},"
            "title     = {Proceedings of the Xth Conference on XYZ},"
            "booktitle = {Proceedings of the Xth Conference on XYZ},"
            "year      = 2006,"
            "month     = oct,"
            "}";

    char str[1024];
    strcpy(str, bibfile.c_str());
    char * pch;
    pch = strtok (str,"@");
    while (pch != NULL)
    {
        cout << "pch=[" << pch << "]" << endl;
        pch = strtok (NULL, "@");
    }


    ifstream ifs("file.bib");
    string bibStr;
    while (getline(ifs, bibStr, '@')) {
        if(bibStr.length() > 0)
            cout << "bibStr=[" << bibStr << "]" <<endl;
    }

    char type[80], ref[80];
    sscanf("Book{Torre2008,", "%[^{]{%[^,],", type, ref);
    cout << "type=" << type << " ref=" << ref << endl;

    std::cmatch m;

    std::regex_match ( bibStr.c_str(), m, std::regex("(author)(.*)") );

    for (unsigned i=0; i<m.size(); ++i) {
        std::cout << "match " << i << ": " << m[i];
        std::cout << " (with a length of " << m[i].length() << ")\n";
    }

    cout << Util::parseField("author",bibStr) << endl;

    BibfileIO fileio("file.bib");
    cout << "fileio=\n" << fileio.getBibFile()->toText() << endl;
}
