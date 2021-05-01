#ifndef MESSAGE_GLOBAL_H
#define MESSAGE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(MESSAGE_LIBRARY)
#  define MESSAGE_EXPORT Q_DECL_EXPORT
#else
#  define MESSAGE_EXPORT Q_DECL_IMPORT
#endif

#endif // MESSAGE_GLOBAL_H
