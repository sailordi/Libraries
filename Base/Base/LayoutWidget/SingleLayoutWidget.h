#ifndef SINGLELAYOUTWIDGET_H
#define SINGLELAYOUTWIDGET_H

#include "Base/LayoutWidget/BaseLayoutWidget.h"

/*! \class SingleLayoutWidget
 * \brief The class represents a widget with one layout of the same type
 *
 * Incudes: BaseLayoutWidget
 *
 * Inherits: BaseLayoutWidget
 *
 * \author Created by: Sailordi
 * \author Last to touch it: Sailordi
 *
 * \date Created: 2021-04-20
 * \date Last update: 2021-04-28
*/
class SingleLayoutWidget : public BaseLayoutWidget
{
    Q_OBJECT
public:
    /*! Constructor
     * \param parent - The parent [Default: nullptr]
    */
    explicit SingleLayoutWidget(QWidget *parent = nullptr);

protected:
    QHBoxLayout* v_hLayout = nullptr;
    QGridLayout* v_gLayout = nullptr;
    QVBoxLayout* v_vLayout = nullptr;

};
#endif // SINGLELAYOUTWIDGET_H
