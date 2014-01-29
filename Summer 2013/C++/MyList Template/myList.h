/*William Freeman
  CS201L
  7/18/2013
  Lab Assignment 10 - MyList Template
  Description: Create your own list template with functionality and test within
  the main function.*/

template<typename T>
class MyList
{
private:
	//Increases the size of m_list.
	//Returns a dynamic array of new size.
	T* increaseSize();

	int m_size;
	int m_numOfItems;
	T* m_list;
public:
	//Default constructor.
	//Assigns default values for member variables.
	MyList();
	//Constructor.
	//Assigns size to the member variable m_size & initalizes other member
	//variables.
	MyList(int size);
	//Desctructor.
	//Frees up memory space.
	~MyList()
	{
		delete [] m_list;
	}
	//Adds item to m_list if there is room.
	//If not, resizes m_list then adds item.
	void add(const T item);
	//Removes the item from the index position within the m_list array.
	//Shifts all items following that 1 position.
	//Decreases m_numOfItems.
	void remove(int index);
	//Returns the variable stored at index.
	T get(int index);
};

template<typename T>
MyList<T>::MyList()
{
	m_size = 5;
	m_numOfItems = 0;
	m_list = new T[m_size];
}

template<typename T>
MyList<T>::MyList(int size)
{
	m_size = size;
	m_numOfItems = 0;
	m_list = new T[m_size];
}

template<typename T>
void MyList<T>::add(const T item)
{
	if (m_numOfItems == m_size)
	{
		m_list = increaseSize();
	}
	m_list[m_numOfItems] = item;
	m_numOfItems++;
}

template<typename T>
T* MyList<T>::increaseSize()
{
	int oldSize = m_size;
	m_size += 5;
	T* tempList = new T[m_size];
	//Copy from m_list;
	for (int index = 0; index < oldSize; index++)
	{
		tempList[index] = m_list[index];
	}
	return tempList;
}

template<typename T>
void MyList<T>::remove(int index)
{
	m_numOfItems--;
	for (int i = index; i < m_numOfItems; i++)
	{
		m_list[i] = m_list[i + 1];
	}
}

template<typename T>
T MyList<T>::get(int index)
{
	if (index < 0 || index >= m_numOfItems)
	{
		cout << "Attempted to reach out of the index\n";
		return NULL;
	}
	return m_list[index];
}