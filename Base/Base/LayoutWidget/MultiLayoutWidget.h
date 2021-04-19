#ifndef MULTILAYOUTWIDGET_H
#define MULTILAYOUTWIDGET_H

#include <QWidget>
#include <QList>

class QHBoxLayout;
class QGridLayout;
class QVBoxLayout;

/*! \class MultiLayoutWidget
 * \brief The class represents a widget with multiple layouts of the same type
 *
 * Incudes: QWidget & QList
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
class MultiLayoutWidget : public QWidget
{
    Q_OBJECT
public:
    /*! Constructor
     * \param parent - The parent [Default: nullptr]
    */
    explicit MultiLayoutWidget(QWidget *parent = nullptr);
    /*! Deconstructor */
   ~MultiLayoutWidget();

protected:
    QWidget* v_p = nullptr;

    QList<QHBoxLayout*> v_hLayouts;
    QList<QGridLayout*> v_gLayouts;
    QList<QVBoxLayout*> v_vLayouts;

    /*! Returns a specific grid layout
    * \param pos- The position
    * \return QGridLayout*
   */
    QGridLayout* gLayout(int pos);

};
#endif // MULTILAYOUTWIDGET_H
