#ifndef QSTRINGSTREAM_H
#define QSTRINGSTREAM_H

#include <QString>
#include <QTextStream>

/*! \class QStringStream
 * \brief The class is a handle for a textstream against a QString
 *
 * Incudes: QString & QTextStream
 *
 * \author Created by: Sailordi
 * \author Last to touch it: Sailordi
 *
 * \date Created: 2021-04-20
 * \date Last update: 2021-04-20
*/
class QStringStream
{
public:
    /*! Constructor */
    QStringStream();
    /*! Destructor */
    ~QStringStream();

    /*! Checks if the stream is empty
     * \returns bool
    */
    bool isEmpty();

private:
    QString v_str;
    QTextStream* v_steam = nullptr;

};
#endif // QSTRINGSTREAM_H
