#ifndef BIBFILEIO_H
#define BIBFILEIO_H

#include "bibfile.h"

class BibfileIO
{
private:
    const string fileName;
    BibFile* bibFile;
    BibtexFormat* readBibtex(stringstream &bibStr);
    static BibtexFormat *parseTypeAndReference(const string bibStr);
public:
    BibfileIO(const string fileName);
    BibFile* getBibFile();
    void persist();
};

#endif // BIBFILEIO_H
