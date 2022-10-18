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
 * \date Last update: 2022-10-18
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

    /*! Sets the font for the NoticeTabWidget
     *  \param f - The font
    */
    void setFont(QFont f);
    /*! Sets the fonts for the NoticeTabWidget
     *  \param f - The fonts
    */
    void setFont(QList<QFont> f);

    /*! Sets the child tab widget
     * \param ch - Child tab widget
    */
    void setChild(NoticeTabWidget* ch);

    /*! Sets textedit text
     * \param t - The text
     * \param f - The aligment to be used
    */
    void setText(QString t,QFlags<Qt::AlignmentFlag> f);

    /*! Sets label text
     * \param pos - The text position
    */
    void setLabel(int pos);

    /*! Sets data for the tab if it is in use
     * \param pos - The text position
    */
    virtual void setData(int size,int pos);

    /*! Resets the tab
     * \param resetChild - If child chould be reset [Default: true]
    */
    virtual void resetTab(bool resetChild = true);

    /*! Checks if tab is in used
     * \returns bool
    */
    bool inUse();

    /*! Retranslates the tab & label text */
    void reTranslate();

signals:
    /*! Signal for message changed
     * \param pos - The message position
     * \param flag - The notice type [ERROR,WARNING,MESSAGE]
    */
    void messageChanged(int pos,NoticeFlag flag);

protected slots:
    /*! Slot for the spinbox number changed */
    void numberChanged();

protected:
    int v_originalIndex = 0,v_index = 0,v_size = 0;
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
     * \returns bool
    */
    bool tabUsed();

    /*! Change the child index */
    void childIndexChange();
};
#endif // NOTICETABWIDGET_H
