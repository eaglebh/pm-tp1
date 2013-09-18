#ifndef UTIL_H
#define UTIL_H

#include <string>

using namespace std;

class Util
{
public:
    Util();
    static unsigned int parseInt(const string text);
    static void stripBrackets(string &searchString);
    static string parseString(const string text);
    static string parseField(const string fieldName, const string text);
    static void test();
    static int parseIntField(const string fieldName, const string text);
};

#endif // UTIL_H
