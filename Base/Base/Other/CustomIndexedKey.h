#ifndef CUSTOMINDEXEDKEY_H
#define CUSTOMINDEXEDKEY_H

template <class T>  class CustomIndexedKey
{
public:
    /*! Constructor
     * \param key - The key
    */
    CustomIndexedKey(T key) : v_index(-1),v_key(key) { }
    /*! Constructor
     * \param key - The key
     * \param index - The keys index
    */
    CustomIndexedKey(T key,int index) : v_index(index),v_key(key) { }
    /*! Deconstructor */
    ~CustomIndexedKey() {  }

    /*! Sorts CustomIndexedKey in ascending order (1 -> 10)
     * \param c1 - First key
     * \param c2 - Second key
     * \returns bool
    */
    static bool sortAsc(const CustomIndexedKey<T>& c1,const CustomIndexedKey<T>& c2) { return c1.v_index < c2.v_index; }
    /*! Sorts CustomIndexedKey in descending order (10 -> 1)
     * \param c1 - First key
     * \param c2 - Second key
     * \returns bool
    */
    static bool sortDes(const CustomIndexedKey<T>& c1,const CustomIndexedKey<T>& c2) { return c1.v_index > c2.v_index; }

    /*! Returns the index
     * \returns int
    */
    int index() { return this->v_index; }

    /*! Returns the key
     * \returns const T
    */
    const T keyC() const {  return this->v_key; }
    /*! Returns the key
     * \returns T
    */
    T key() { return this->v_key; }

    /*! Operator to check if keys are the same
    * \param other - The other key to be ckecked against
    * \returns bool
    */
    bool operator==(const CustomIndexedKey<T>& other) const { return this->keyC() == other.keyC(); }

private:
    int v_index;
    T v_key;

};
#endif // CUSTOMINDEXEDKEY_H
