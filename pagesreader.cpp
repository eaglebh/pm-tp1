#include <cstring>
#include <sstream>
#include "pagesreader.h"
#include "util.h"

PagesReader::PagesReader()
{
}

Pages* PagesReader::parsePages(const string text)
{
    Pages *pages = new Pages();

    string values = Util::parseField("pages",text);
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
