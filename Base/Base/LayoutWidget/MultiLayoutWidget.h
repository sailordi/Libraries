#ifndef MULTILAYOUTWIDGET_H
#define MULTILAYOUTWIDGET_H

#include <QList>

#include "Base/LayoutWidget/BaseLayoutWidget.h"

/*! \class MultiLayoutWidget
 * \brief The class represents a widget with multiple layouts of the same type
 *
 * Incudes: BaseLayoutWidget & QList
 *
 * Inherits: BaseLayoutWidget
 *
 * \author Created by: Sailordi
 * \author Last to touch it: Sailordi
 *
 * \date Created: 2021-04-20
 * \date Last update: 2021-04-28
*/
class MultiLayoutWidget : public BaseLayoutWidget
{
    Q_OBJECT
public:
    /*! Constructor
     * \param parent - The parent [Default: nullptr]
    */
    explicit MultiLayoutWidget(QWidget *parent = nullptr);
    /*! Deconstructor */
   virtual ~MultiLayoutWidget();

protected:
    QList<QHBoxLayout*> v_hLayouts;
    QList<QGridLayout*> v_gLayouts;
    QList<QVBoxLayout*> v_vLayouts;

    /*! Returns a specific grid layout
    * \param pos - The position
    * \return QGridLayout*
   */
    QGridLayout* gLayout(int pos);
    /*! Returns a specific hBox layout
     * \param pos - The position
     * \return QHBoxLayout*
    */
    QHBoxLayout* hLayout(int pos);
    /*! Returns a specific vBox layout
     * \param pos - The position
     * \return QVBoxLayout*
    */
    QVBoxLayout* vLayout(int pos);

};
#endif // MULTILAYOUTWIDGET_H
