#ifndef ILIST_H_
#define ILIST_H_

template<typename ItemType>
class IList
{
    public:
        virtual bool isEmpty() const = 0;

        virtual int getLength() const = 0;

        virtual bool insert(int position, const ItemType& item) = 0;

        virtual bool removeAt(int position) = 0;

        virtual void clear() = 0;

        virtual ItemType getItem(int position) const = 0;
};

#endif
