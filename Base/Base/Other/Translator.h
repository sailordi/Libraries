#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include <QObject>
#include <QTranslator>
#include <QString>

/*! \class Translator
 * \brief The class handles translation logic
 *
 * Incudes: QObject, QTranslator & QString
 *
 * Inherits: QObject
 *
 * \author Created by: Sailordi
 * \author Last to touch it: Sailordi
 *
 * \date Created: 2021-04-20
 * \date Last update: 2021-04-20
*/
class Translator : public QObject
{
    Q_OBJECT
public:
    /*! Constructor
     * \param parent - The parent [Default: nullptr]
    */
    explicit Translator(QObject *parent = nullptr);
    /*! Constructor
     * \param path - The language file's folder path
     * \param lang - The locale to use
     * \param fileFilter - The file filter to be used
     * \param parent - The parent [Default: nullptr]
    */
    explicit Translator(QString path,QLocale lang,QString fileFilter,QObject *parent = nullptr);
    /*! Destructor */
    virtual ~Translator();

signals:

private slots:

protected:
    QString v_langPath,v_currentLang,v_fileFilter;
    QTranslator v_trans;
    bool v_found = true;

};
#endif // TRANSLATOR_H
