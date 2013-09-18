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
    while (pch != NULL)
    {
        int pageNumber = 0;
        istringstream(pch) >> pageNumber;
        if(values[pch-str+strlen(pch)] == '-') {
            for(int i = lastNumber+1; i <=pageNumber; i++){
                pages->addPage( pageNumber);
                lastNumber = pageNumber;
            }
        } else {
            pages->addPage( pageNumber);
            lastNumber = pageNumber;
        }
        pch = strtok (NULL, ",-");
    }

    return pages;
}
