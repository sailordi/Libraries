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
 * \date Last update: 2021-05-04
*/
class NoticPageWidget : public SingleLayoutWidget
{
    Q_OBJECT
public:
    /*! Constructor
    * \param btnText - Button text
    * \param gL - Gridlayout
    * \param hL - Hboxlayout
    * \param parent - The parent [Default: nullptr]
    */
    NoticPageWidget(QStringList btnText,QGridLayout* gL,QHBoxLayout* hL,QWidget* parent = nullptr);
    /*! Deconstructor */
    virtual ~NoticPageWidget();

    /*! Sets the font for the NoticPageWidget */
    void setFont(QFont f);

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
    virtual void init();

};
#endif // NOTICPAGEWIDGET_H
