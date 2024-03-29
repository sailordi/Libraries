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
 * \date Last update: 2021-10-06
*/
class ComboBoxAdapter : public QObject
{
    Q_OBJECT
public:
    /*! Constructor
     * \param box - The combo box
     * \param del - If the combo box should be deleted
     * \param connectBoxToSlot - If the combobox should be connected to the classes slot
     * \param parent - The parent [Default: nullptr]
    */
    ComboBoxAdapter(QComboBox* box,bool del,bool connectBoxToSlot,QObject* parent = nullptr);
    /*! Constructor
     * \param box - The combo box
     * \param del - If the combo box should be deleted
     * \param connectBoxToSlot - If the combobox should be connected to the classes slot
     * \param first - The first item [Default: QString()]
     * \param parent - The parent [Default: nullptr]
    */
    ComboBoxAdapter(QComboBox* box,bool del,bool connectBoxToSlot,QString first = QString(),QObject* parent = nullptr);
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
    /*! Adds data to the end of the combo box
     * \param data - The data
    */
    void addDataEnd(QString data);

    /*! Removes data from the combo box at a certain position
     * \param pos - The position
    */
    void removeData(int pos);

    /*! Sets the combo boxes selected row
     * \param row - Selected row
    */
    void setSelectedRow(int row);
    /*! Sets the first string
     * \param str - The first item
    */
    void setFirstStr(QString str);

    /*! Returns selected row position
     * \returns int
    */
    int selectedRow();
    /*! Returns selected text
     * \returns QString
    */
    QString selectedText();

    /*! Returns amount of rows in combo box
     * \returns int
    */
    int rows();

    /*! Returns a list of all the combo box data
     * \returns QStringList
    */
    QStringList data();

    /*! Clear´s all data from the combo box */
    void clear();

    /*! Returns the combo box
     * \returns QComboBox*
    */
    QComboBox* box();

signals:
    /*! Signal for when the combobox index has changed */
    void indexHasChanged(int index);

protected slots:
    /*! Slot that connects to the combobox signal for when the index has changed */
    void indexChanged(int index);

protected:
    bool v_del = true;
    QStringListModel* v_model = nullptr;
    QComboBox* v_box = nullptr;
    QString v_first;

};
#endif // COMBOBOXADAPTER_H
