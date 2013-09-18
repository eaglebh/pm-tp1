#ifndef BIBFILEIO_H
#define BIBFILEIO_H

#include "bibfile.h"

class BibfileIO
{
private:
    BibFile* bibFile;
    BibtexFormat* readBibtex(stringstream &bibStr);
public:
    BibfileIO(const string fileName);
    BibFile* getBibFile();
    void persist();
};

#endif // BIBFILEIO_H
