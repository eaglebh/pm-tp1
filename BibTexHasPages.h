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
    Pages getPages() const;
    void setPages(const Pages &value);
    virtual string getRequiredFieldsText() const;
};

#endif // HASPAGES_H
