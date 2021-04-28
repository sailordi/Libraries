#ifndef BASELAYOUTWIDGET_H
#define BASELAYOUTWIDGET_H

#include <QWidget>

class QGridLayout;
class QHBoxLayout;
class QVBoxLayout;

/*! \class BaseLayoutWidget
 * \brief The class contains common functionality shared by the layout widgets
 *
 * Incudes: QWidget
 *
 * Forward declarations: QGridLayout, QHBoxLayout & QVBoxLayout
 *
 * Inherits: QWidget
 *
 * \author Created by: Sailordi
 * \author Last to touch it: Sailordi
 *
 * \date Created: 2021-04-28
 * \date Last update: 2021-04-28
*/
class BaseLayoutWidget : public QWidget
{
    Q_OBJECT
public:
    /*! Constructor
     * \param parent - The parent [Default: nullptr]
    */
    explicit BaseLayoutWidget(QWidget *parent = nullptr);
    /*! Deconstructor */
    virtual ~BaseLayoutWidget();

protected:
    QWidget* v_p = nullptr;

    /*! Clears a grid layout of all items
     * \param l - Layout to be cleared
    */
    virtual void clearLayout(QGridLayout* l);
    /*! Clears a hbox layout of all items
     * \param l - Layout to be cleared
    */
    virtual void clearLayout(QHBoxLayout* l);
    /*! Clears a vbox layout of all items
     * \param l - Layout to be cleared
    */
    virtual void clearLayout(QVBoxLayout* l);

};
#endif // BASELAYOUTWIDGET_H
