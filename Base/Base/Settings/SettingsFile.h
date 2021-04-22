#ifndef SETTINGSFILE_H
#define SETTINGSFILE_H

#include <QString>

class QFile;
class QTextStream;

class SettingsFile
{
public:
    /*! Constructor
     * \param file - The file name
     * \param read- If file should be in read mode
    */
    SettingsFile(QString file,bool read);
    /*! Deconstructor */
    ~SettingsFile();

private:
    QFile* v_f = nullptr;
    QTextStream* v_s = nullptr;
    bool v_read;

};
#endif // SETTINGSFILE_H
