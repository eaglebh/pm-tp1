#include <cstring>
#include <sstream>
#include "pagesreader.h"
#include "util.h"

Pages* PagesReader::parsePages(const string text)
{
    string values = Util::parseField("pages",text);
    return parsePagesFromValue(values);
}

Pages *PagesReader::parsePagesFromValue(const string values)
{
    Pages *pages = new Pages();
    char str[1024];
    strcpy(str, values.c_str());
    char * pch;
    pch = strtok (str,",-");
    int lastNumber = 0;
    bool actualIsASequence = false;
    while (pch != NULL)
    {
        int pageNumber = 0;
        istringstream(pch) >> pageNumber;

        if(actualIsASequence) {
            actualIsASequence = false;
            for(int i = lastNumber+1; i <=pageNumber; i++){
                pages->addPage( i);
                lastNumber = i;
            }
        } else {
            pages->addPage( pageNumber);
            lastNumber = pageNumber;
        }
        if(values[pch-str+strlen(pch)] == '-') {
            actualIsASequence = true;
        }
        pch = strtok (NULL, ",-");
    }

    return pages;
}


