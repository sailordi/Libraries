#ifndef WINDOWNOTICE_H
#define WINDOWNOTICE_H

#include <QMainWindow>
#include <QString>
#include <QStringList>

#include "Message_global.h"

namespace Ui { class WindowNotice; }

class QMenu;

class NoticePage;
class NoticeTabWidget;
class NoticPageWidget;
class Settings;
class Translator;

/*! \class WindowNotice
 * \brief The class is the defult ui for notices
 *
 * Incudes: QMainWindow, QSharedPointer, QString, QStringList & Message_global.h
 *
 * Forward declarations: QMen, NoticePage, NoticeTabWidget, NoticPageWidget, Settings & Translator
 *
 * Inherits: QMainWindow
 *
 * \author Created by: Sailordi
 * \author Last to touch it: Sailordi
 *
 * \date Created: 2021-05-06
 * \date Last update: 2021-05-06
*/
class MESSAGE_EXPORT WindowNotice : public QMainWindow
{
    Q_OBJECT
public:
    /*! Constructor
     * \param parent - The parent [Default: nullptr]
    */
    explicit WindowNotice(QWidget *parent = nullptr);
    /*! Constructor
     * \param tr - Translation handle
     * \param languageTitle - The language menu title
     * \param tabText - The text for all TabWidgets
     * \param pageText - The text for the NoticePageWidget buttons
     * \param parent - The parent [Default: nullptr]
    */
    explicit WindowNotice(Translator* tr,QStringList languageTitle,QStringList tabText,QStringList pageText,QWidget *parent = nullptr);
    /*! Deconstructor */
    ~WindowNotice();

    /*! Loads settings
     * \param s - Settings handle
    */
    void loadSettings(Settings* s);
    /*! Saves settings
     * \param s - Settings handle
    */
    void saveSettings(Settings* s);

    /*! Adds a NoticePage to be shown
     * \param p - NoticePage to add
    */
    void add(NoticePage* p);
    /*! Adds a NoticePage to be shown
     * \param p - NoticePage to add
    */
    void add(QSharedPointer<NoticePage> p);

    /*! Clears all NoticePages */
    void clear();

    /*! Prepere window for being shown */
    void prepare();

private slots:
    /*! Slot for NoticeList changed */
    void listChange();

private:
    Ui::WindowNotice* v_ui = nullptr;
    QMenu* v_languageM = nullptr;

    NoticeTabWidget* v_errorW = nullptr,*v_warningW = nullptr,*v_messageW = nullptr;
    NoticPageWidget* v_pageW = nullptr;
    QString v_languageTitle = "",v_languageTitleTr = "";
    Translator* v_translator = nullptr;

    /*! Function for initializing variables that need to be initialized
     * \param tabText - The text for all TabWidgets
     * \param pageText - The text for the NoticePageWidget buttons
     * \param tr - If the text is translation text
    */
    void init(QStringList tabText,QStringList pageText,bool tr);

    /*! Sets the tabs that should be shown */
    void setTabsShown();

};
#endif // WINDOWNOTICE_H
