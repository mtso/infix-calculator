// Collection.h Interface
// Lab 2: Stack ADT
// CIS 22C F2016: Adrian Marroquin, Matthew Tso

#ifndef STACKADT_COLLECTION_H
#define STACKADT_COLLECTION_H

/**
 * Collection Interface
 * An interface for collections of like data objects.
 */
template<typename T>
class Collection
{
public:
	/**
	 * Gets the number of items in the collection.
	 * @returns The integer number of items.
	 */
	virtual int getCount() const = 0;
	
	/**
	 * Checks if the collection contains objects.
	 * @returns True if no items exists and false if items exist.
	 */
	virtual bool isEmpty() const = 0;

	/**
	 * Adds an element into the collection.
	 */
	virtual bool add(const T& newElement) = 0;

	/**
	 * Removes an element from the collection.
	 */
	virtual bool remove(const T& element) = 0;

	/**
	 * Removes all elements from the collection.
	 */
	virtual void clear() = 0;
};

#endif