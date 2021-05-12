#ifndef UPDATEINFO_H
#define UPDATEINFO_H

#include "SQL_global.h"

/*! \class UpdateInfo
 * \brief The class contains SQL update info
 *
 * Incudes: SQL_global
 *
 * \tparam T - The class to be used as a for updating info
 *
 * \author Created by: Sailordi
 * \author Last to touch it: Sailordi
 *
 * \date Created: 2021-05-12
 * \date Last update: 2021-05-12
*/
template <class T> class SQL_EXPORT UpdateInfo
{
public:
    /*! Constructor */
    UpdateInfo() {  }
    /*! Constructor
     * \param oldD - The old data
     * \param newD - The new data [Default: nullptr]
    */
    UpdateInfo(T* oldD,T* newD = nullptr) { this->setData(oldD,newD); }
    /*! Deconstructor */
    ~UpdateInfo() {  }

    /*! Set´s the old data
     * \param oldD - The old data
    */
    void setOldData(T* oldD) { this->v_oldD = oldD; }
    /*! Set´s the new data
     * \param newD - The new data
    */
    void setNewData(T* newD) { this->v_newD = newD; }
    /*! Set´s the old & new data
     * \param oldD - The old data
     * \param newD - The new data
    */
    void setData(T* oldD,T* newD) { this->setOldData(oldD); this->setNewData(newD); }

private:
    T* v_oldD = nullptr,*v_newD = nullptr;

};
#endif // UPDATEINFO_H
