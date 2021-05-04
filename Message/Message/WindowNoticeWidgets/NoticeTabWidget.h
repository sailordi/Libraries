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

};
#endif // NOTICETABWIDGET_H
