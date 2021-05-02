#ifndef NOTICEFLAG_H
#define NOTICEFLAG_H

#include "Message_global.h"

/*! \class NoticeFlag
 * \brief Enumeration for the message type
 *
 * \author Created by: Sailordi
 * \author Last to touch it: Sailordi
 *
 * \date Created: 2021-05-02
 * \date Last update: 2021-05-02
*/
enum class NoticeFlag {
    ERROR, /*!< A error message */
    WARNING, /*!< A warning message */
    MESSAGE /*!< A normal message */
};

#endif // NOTICEFLAG_H
