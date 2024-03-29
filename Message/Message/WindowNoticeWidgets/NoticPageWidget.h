#ifndef NOTICPAGEWIDGET_H
#define NOTICPAGEWIDGET_H


#include <QList>
#include <QSharedPointer>
#include <QString>
#include <QStringList>

#include "Base/LayoutWidget/SingleLayoutWidget.h"
#include "Message_global.h"
#include "Message/Notice/NoticePage.h"

class QPushButton;
class QLabel;

/*! Index reset flag */
enum class ResetFlag{
    PAGE,/*!< Reset page index flag */
    LIST,/*!< Reset list index flag */
    BOTH /*!< Reset page & list index flag */
};

typedef QSharedPointer<NoticePage> NoticePageP;

/*! \class NoticPageWidget
 * \brief The class handles page widget logic
 *
 * Incudes: QList, QSharedPointer, QString, QStringList, SingleLayoutWidget, Message_global.h & NoticePage
 *
 * Forward declarations: QPushButton & Label
 *
 * Inherits: SingleLayoutWidget
 *
 * \author Created by: Sailordi
 * \author Last to touch it: Sailordi
 *
 * \date Created: 2021-05-04
 * \date Last update: 2021-05-10
*/
class MESSAGE_EXPORT NoticPageWidget : public SingleLayoutWidget
{
    Q_OBJECT
public:
    /*! Constructor
    * \param btnText - Button text
    * \param gL - Gridlayout
    * \param hL - Hboxlayout
    * \param tr - If the text has translation text
    * \param parent - The parent [Default: nullptr]
    */
    NoticPageWidget(QStringList btnText,QGridLayout* gL,QHBoxLayout* hL,bool tr,QWidget* parent = nullptr);
    /*! Deconstructor */
    virtual ~NoticPageWidget();

    /*! Sets the font for the NoticPageWidget
     * \param f - The font
    */
    void setFont(QFont f);
    /*! Sets the fonts for the NoticPageWidget
     * \param f - The fonts
    */
    void setFont(QList<QFont> f);

    /*! Adds a NoticePage to list
     * \param p - The page to add
    */
    void add(NoticePage* p);
    /*! Adds a NoticePage to list
     * \param p - The page to add
    */
    void add(NoticePageP p);

    /*! Retuns the current page
     * \returns NoticePageP
    */
    NoticePageP currentPage();
    /*! Retuns the current list
     * \returns NoticeListP
    */
    NoticeListP curretList();

    /*! Reset index
     * \param f - Reset type [PAGE, LIST, BOTH]
    */
    void resetIndex(ResetFlag f);

    /*! Clears the list of pages */
    void clear();

    /*! Retranslates all NoticePages and buttons & NoticePage label */
    void reTranslate();

signals:
    /*! Signal for list changed */
    void listChanged();

protected slots:
    /*! Goes to the next page */
    void nextPagePressed();
    /*! Goes to the previous page */
    void prevPagePressed();

    /*! Goes to the next list */
    void nextListPressed();
    /*! Goes to the previous list */
    void prevListPressed();

protected:
    int v_pageIndex = 0,v_listIndex = 0;
    bool v_pageH = false,v_labelH = false;

    QLabel* v_pageLabel = nullptr;
    QPushButton* v_prevPageB = nullptr,*v_nextPageB = nullptr;
    QPushButton* v_prevListB = nullptr,*v_nextListB = nullptr;

    QString v_nextPageText = "",v_nextListText = "",v_prevPageText = "",v_prevListText = "";
    QString v_nextPageTr = "",v_nextListTr = "",v_prevPageTr = "",v_prevListTr = "";

    QList<NoticePageP> v_pages;

    /*! Function for initializing variables that are needed in NoticPageWidget */
    void init();

    /*! Checks if page can be updated
     * \param num - The number to check if can be updated
     * \returns bool
    */
    bool canUpdatePage(int num);
    /*! Checks if list can be updated
     * \param num - The number to check if can be updated
     * \returns bool
    */
    bool canUpdateList(int num);

    /*! Hides / shows page widgets */
    void hidePageWidgets();
    /*! Hides / shows list widgets */
    void hideListWidgets();

    /*! Sets the page label */
    void setPageLabel();

};
#endif // NOTICPAGEWIDGET_H
