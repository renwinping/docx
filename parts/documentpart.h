#ifndef DOCUMENTPART_H
#define DOCUMENTPART_H

#include "../docx_global.h"
#include "../opc/part.h"

#include <QPair>
#include <QDomDocument>
#include <QByteArray>

namespace Docx {
//class Body;
class CT_Default;
class Paragraph;
class Table;
class DocumentPart : public Part
{
public:
    DocumentPart(const QString &partName, const QString &contentType, const QByteArray &blob = QByteArray(), Package *package = nullptr);
    Paragraph* addParagraph(const QString &text, const QString &style = QStringLiteral(""));
    static DocumentPart *load(const PackURI &partName, const QString &contentType, const QByteArray &blob = QByteArray(), Package *package = nullptr);
    Table * addTable(int rows, int cols);
    void afterUnmarshal();
    QDomDocument * element() const;
    QByteArray blob() const;
    virtual ~DocumentPart();

private:
    //Body *m_body;
    QDomDocument *m_dom;

};


//class Body
//{
//public:
//    Body(DocumentPart *docPart);
//    Paragraph* addParagraph(const QString &text, const QString &style);
//    Table * addTable(int rows, int cols);

//private:
//    DocumentPart *m_parent;
//};

}

#endif // DOCUMENTPART_H
