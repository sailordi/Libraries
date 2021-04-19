#ifndef SINGLELAYOUTWIDGET_H
#define SINGLELAYOUTWIDGET_H

#include <QWidget>

class QHBoxLayout;
class QGridLayout;
class QVBoxLayout;

/*! \class SingleLayoutWidget
 * \brief The class represents a widget with one layout of the same type
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
 * \date Created: 2021-04-20
 * \date Last update: 2021-04-20
*/
class SingleLayoutWidget : public QWidget
{
    Q_OBJECT
public:
    /*! Constructor
     * \param parent - The parent [Default: nullptr]
    */
    explicit SingleLayoutWidget(QWidget *parent = nullptr);
    /*! Deconstructor */
    ~SingleLayoutWidget();

protected:
    QWidget* v_p = nullptr;

    QHBoxLayout* v_hLayout = nullptr;
    QGridLayout* v_gLayout = nullptr;
    QVBoxLayout* v_vLayout = nullptr;

};
#endif // SINGLELAYOUTWIDGET_H
