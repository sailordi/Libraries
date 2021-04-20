#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include <QObject>
#include <QTranslator>
#include <QString>

class QAction;
class QActionGroup;
class QMenu;
class QLocale;

/*! \class Translator
 * \brief The class handles translation logic
 *
 * Incudes: QObject, QTranslator & QString
 *
 * Forward declarations: QAction, QActionGroup, QMenu & QLocale
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

    /*! Set's the language file's folder path & the locale to use
     * \param path - The language file's folder path
     * \param lang - The locale to use
     * \param fileFilter - The file filter to be used
    */
    void setData(QString path,QLocale lang,QString fileFilter);

    /*! Populates the language menu
     * \param m - The menu item to be language menu
     * \param title - The menu title
    */
    void populateLanguageMenu(QMenu* m,QString title);

signals:
    /*! Signal that tells the objects that a retranslation is Needed */
    void reTranslate();

private slots:
    /*! Slot that is called when the language is changed
    * \param a - The action that vas triggered
    */
    void languageChanged(QAction* a);

protected:
    QString v_langPath,v_currentLang,v_fileFilter;
    QTranslator v_trans;
    bool v_found = true;

    /*! Strips a string down to get a locale letters
     *  \param str - String to strip
     *  \returns QString
    */
    virtual QString getLocaleLetters(const QString str);
    /*! Strips a file name down to get the locale letters
     *  \param str - The file name
     *  \returns QString
    */
    virtual QString getLocaleLettersFromFileName(const QString str);

    /*! Adds a language action to a menu
     *  \param lang - The language
     *  \param m - The menu
     *  \param g - The action group
     *  \param currentLang - The current language
    */
    void addActionToLangMenu(QString lang,QMenu* m,QActionGroup* g,QString currentLang);

    /*! Switches the current language to a new one and loads it to the translator
     * \param newLanguage - Language to be switched to
    */
    void switchLanguage(const QString& newLanguage);

};
#endif // TRANSLATOR_H
