#ifndef HELPER_H
#define HELPER_H

#include <QString>

/*!
 * \brief The namespace contains help functions
 *
 * Incudes: QString
 *
 * \author Created by: Sailordi
 * \author Last to touch it: Sailordi
 *
 * \date Created: 2021-04-20
 * \date Last update: 2021-04-20
*/
namespace Helper {
    /*! Exits the program from the current place
     * \param msg - Message to be shown
     * \param code - The exit code
    */
    void quitProgram [[noreturn]](QString msg,int code);

    /*!  Generates new rows for qt
     * \param num - Number of new rows [Default: 1]
     * \returns QString
    */
    QString newRow(int num = 1);

};
#endif // HELPER_H
