#ifndef COMBOBOXADAPTER_H
#define COMBOBOXADAPTER_H

#include <QObject>
#include <QString>
#include <QStringList>
#include <QComboBox>

class QStringListModel;

/*! \class ComboBoxAdapter
 * \brief The class is an adapter against QComboBox
 *
 * Incudes: QObject, QString, QStringList & QCombobox
 *
 * Forward declarations: QStringListModel
 *
 * Inherits: QObject
 *
 * \author Created by: Sailordi
 * \author Last to touch it: Sailordi
 *
 * \date Created: 2021-04-24
 * \date Last update: 2021-04-24
*/
class ComboBoxAdapter
{
public:
    /*! Constructor
     * \param box - The combo box
     * \param del - If the combo box should be deleted
     * \param first - The first item [Default: QString()]
    */
    ComboBoxAdapter(QComboBox* box,bool del,QString first = QString() );
    /*! Deconstructor */
    ~ComboBoxAdapter();

    /*! Adds data to the combo box at a certain position
     * \param pos - The position
     * \param data - The data
    */
    void addData(int pos,QString data);
    /*! Adds data to the beginning of the combo box
     * \param data - The data
    */
    void addDataBeginning(QString data);

protected:
    bool v_del = true;
    QStringListModel* v_model = nullptr;
    QComboBox* v_box = nullptr;
    QString v_first;

};
#endif // COMBOBOXADAPTER_H
