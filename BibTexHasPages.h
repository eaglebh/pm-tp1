#ifndef HASPAGES_H
#define HASPAGES_H

#include "BibtexFormat.h"
#include "pages.h"

class BibtexHasPages : public BibtexFormat
{
private:
    Pages pages;
public:
    BibtexHasPages();
    virtual string getRequiredFieldsText() const;
    Pages getPages() const;
    void setPages(const Pages &value);
};

#endif // HASPAGES_H
