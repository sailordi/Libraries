#ifndef SETTINGSFILE_H
#define SETTINGSFILE_H

#include <QString>
#include <QRegularExpression>

class QFile;
class QTextStream;
class QVariant;

class SettingsGroup;

/*! \class SettingsFile
 * \brief The class handles writing/reading settings to/from a file
 *
 * Incudes: QString
 *
 * Forward declarations: QFile, QTextStream, QVariant & SettingsGroup
 *
 * \author Created by: Sailordi
 * \author Last to touch it: Sailordi
 *
 * \date Created: 2021-04-22
 * \date Last update: 2022-10-18
*/
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

    /*! Writes a settings group to file
     * \param groupName - The group's name
     * \param gD - The settings group data
     * \throws QString
    */
    void write(QString groupName,SettingsGroup* gD);
    /*! Reads a settings group from the file
     * \param groupName - The group's name
     * \param gD - The settings group data
     * \throws QString
    */
    void read(QString& groupName,SettingsGroup* gD);

    /*! Check´s if the file is at end
     * \returns bool
    */
    bool atEnd();

    /*! Check`s if the file is open
     * \returns bool
    */
    bool open();

private:
    QFile* v_f = nullptr;
    QTextStream* v_s = nullptr;
    bool v_read;
   QRegularExpression v_reg;

    /*! Checks if a string is a group name
     *  \param s - The string to check
     *  \returns bool
    */
    bool isGoup(QString s);
    /*! Checks if a string is an array
     *  \param s - The string to check
     *  \returns bool
    */
    bool isArray(QString s);
    /*! Checks if a string is a block
     *  \param s - The string to check
     *  \returns bool
    */
    bool isBlock(QString s);

    /*! Separates a string into the variables in it
     *  \param type - Type string that encapsulates the variables
     *  \param str - String with variables
     *  \returns QStringList
    */
    QStringList separate(QString type,QString str);

    /*! Converts QVariant to QString
     *  \param v - Variant to convert to QString
     *  \returns QString
    */
    QString variantToString(QVariant v);
    /*! Converts QVariant to QString
     *  \param s - String to convert to QVariant
     *  \returns QVariant
    */
    QVariant stringToVariant(QString s);

    /*! Writes a key and a value to a file
     *  \param s - Textstream
     *  \param key - The key to be written
     *  \param val - The value
    */
    void writeKeyValue(QTextStream* s,QString key,QVariant val);

    /*! Parses a group name from a string
     *  \param str - The string to parse group name from
     *  \returns QString
    */
    QString parseGroupName(QString str);
    /*! Parses settings block from a string
     *  \param str - String to parse block from
     *  \param gD - Group to add block to
    */
    void parseBlock(QString str,SettingsGroup* gD);
    /*! Parses settings array from a string
     *  \param s - Textstream to parse array from
     *  \param gD - Group to add array to
    */
    void parseArray(QTextStream* s,SettingsGroup* gD);

};
#endif // SETTINGSFILE_H
