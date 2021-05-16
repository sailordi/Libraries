#ifndef CONNECTIONFLAG_H
#define CONNECTIONFLAG_H

/*! Conection names */
enum class ConnectionFlag {
    TEST, /*!< Test connection */
    INSERT, /*!< Insertion flag */
    SELECT, /*!< Selection flag */
    UPDATE, /*!< Update flag */
    CREATE, /*!< Creation flag */
    REMOVE, /*!< Removal flag */
    MODEL, /*!< Model flag */
    OTHER, /*!< Other flag */
    COUNT /*!< The flag count */
};

#endif // CONNECTIONFLAG_H
