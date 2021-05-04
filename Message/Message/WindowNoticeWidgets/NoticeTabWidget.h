#ifndef NOTICETABWIDGET_H
#define NOTICETABWIDGET_H

#include <QString>
#include <QStringList>

#include "Base/LayoutWidget/SingleLayoutWidget.h"

#include "Message_global.h"

class QLabel;
class QSpinBox;
class QTextEdit;
class QTabWidget;

enum class NoticeFlag;

/*! \class NoticeTabWidget
 * \brief The class handels error/ warning/ message tab widget logic
 *
 * Incudes: QString, QStringList, SingleLayoutWidget & Message_global.h
 *
 * Forward declarations: QLabel, QSpinBox, QTextEdit,QTabWidget & NoticeFlag
 *
 * Inherits: SingleLayoutWidget
 *
 * \author Created by: Sailordi
 * \author Last to touch it: Sailordi
 *
 * \date Created: 2021-05-04
 * \date Last update: 2021-05-04
*/
class MESSAGE_EXPORT NoticeTabWidget : public SingleLayoutWidget
{
    Q_OBJECT
public:
    /*! Constructor
     * \param in - Tab index
     * \param gL - Gridlayout
     * \param tab - The tab
     * \param tabW - The tab widget
     * \param text - The tab text
     * \param tr - If the text has translation text
     * \param f - The notice type [ERROR,WARNING,MESSAGE]
     * \param parent - The parent [Default: nullptr]
    */
    NoticeTabWidget(int in,QGridLayout* gL,QWidget* tab,QTabWidget* tabW,QStringList& text,bool tr,NoticeFlag f,QWidget* parent = nullptr);

    /*! Sets the font for the NoticeTabWidget */
    void setFont(QFont f);

    /*! Sets the child tab widget
     * \param ch - Child tab widget
    */
    void setChild(NoticeTabWidget* ch);

    /*! Sets textedit text
     * \param t - The text
     * \param a - The aligment to be used
    */
    void setText(QString t,QFlags<Qt::AlignmentFlag> f);

    /*! Sets label text
     * \param pos - The text position
     * \param size - Amount of messages
    */
    void setLabel(int pos,int size);

protected:
    int v_originalIndex = 0,v_index = 0;
    NoticeFlag v_flag;

    NoticeTabWidget* v_child = nullptr;

    QSpinBox* v_spin = nullptr;
    QTextEdit* v_edit = nullptr;
    QLabel* v_label = nullptr;

    QWidget* v_tab = nullptr;
    QTabWidget* v_tabW = nullptr;

    QString v_tabText = "",v_trTab = "",v_labelText = "",v_trLabel = "";

    /*! Returns the palette for the TextEdit depending on the NoticeFlag
     * \returns QPalette
    */
    QPalette textEditPalette();

    /*! Function for initializing variables that are needed in NoticeTabWidget */
    void init();

    /*! Aligns the text in the TextEdit
     *  \param f - The alignmemnt
    */
    void alignTextEdit(QFlags<Qt::AlignmentFlag> f);

    /*! Checks if tab should be used
     * \param size - The amount of messages
     * \returns bool
    */
    bool tabUsed(int size);

    /*! Change the child index */
    void childIndexChange();
};
#endif // NOTICETABWIDGET_H
