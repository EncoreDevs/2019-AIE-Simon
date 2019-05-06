#pragma once
template <typename T>
class dynamicarray
{
public:
	//Add and Remove Data
	//Ask Element Count
	//Ask Capacity
	dynamicarray<T>()
	{
		m_data = new T[m_default_capacity];
		m_capacity = m_default_capacity;
		m_count = 0;
	}

	~dynamicarray()
	{
		delete[] m_data;
		m_data = nullptr;

		m_capacity = 0;
		m_count = 0;

	}

	//Copy Constructor
	dynamicarray(const dynamicarray& a_other)
	{
		m_count = a_other.count;
		m_capacity = a_other.capacity;
		m_data = new T[m_capacity];
		//Need to Deep copy the array data
		for (size_t i = 0; i < m_capacity; i++)
		{
			m_data[i] = a_other.m_data[i];
		}
	}
	// Assignment Operator is the same as copy constructor
	// Except we have to check if cop destination is already in use
	dynamicarray& operator=(const dynamicarray& a_other)
	{
		// Prevent Copying over self
		if (&a_other == this) return *this;

		// clean up any existing data
		if (m_data)
		{
			delete[] m_data;
			m_data = nullptr;
		}

		//member wise copy
		m_count = a_other.m_count;
		m_capacity = a_other.m_capacity;

		//Need to deep copy the array data 
		m_data = new T[m_capacity];
		for (size_t i = 0; i < m_capacity; i++)
		{
			this->m_data[i] = a_other.m_data[i];
		}
		return *this;
	}

	T& operator[] (const int index)
	{
		return m_data[index];
	}

	//Add Data()

	void push(const T& a_data, const T& index)
	{
		//check capacity
		if (m_count == m_capacity)
		{
			std::cout << "Capacity increased" << std::endl;
			//Increase size of the array
			m_capacity *= 2;
			T* new_location = new T[m_capacity];
			for (size_t i = 0; i < m_count; i++)
			{
				new_location[i] = m_data[i];
			}
			delete[] m_data;
			m_data = new_location;
		}
		m_data[m_count] = a_data;
		++m_count;
	}
	void pop()
	{
		--m_count;
	}
	size_t count() const
	{
		return m_count;
	}
	size_t capacity() const
	{
		return m_capacity;
	}
	void bubbleSort()
	{
		bool swapped = true;
		for (size_t i = 0; i < m_count; ++i)
		{
			std::cout << "Loop: " << i << std::endl;
			swapped = false;
			for (size_t j = 1; j < m_count; ++j)
			{
				if (m_data[j - 1] > m_data[j])
				{
					T temp = m_data[j];
					m_data[j] = m_data[j - 1];
					m_data[j - 1] = temp;
					swapped = true;
				}

				if (swapped == false) break;
			}
		}
	}
	void cocktailShaker()
	{
		bool swapped = true;
		size_t start = 0;
		size_t end = m_count - 1;
		while (swapped)
		{
			swapped = false;
			//First Inner Loop Going UP
			for (size_t i = start; i < end; ++i)
			{
				T temp = m_data[i];
				m_data[i] = m_data[i + 1];
				m_data[i + 1] = temp;
				swapped = true;
			}

			if (swapped == false) break;
			end--;
			//Second Inner Loop Going DOWN
			swapped = false;

			for (size_t i = end; i >= start; --i)
			{
				T temp = m_data[i];
				m_data[i] = m_data[i + 1];
				m_data[i + 1] = temp;
				swapped = true;
			}

			if (swapped == false) break;
			start++;
		}
	}
	void insertSort()
	{
		T key = 0;

		for (size_t i = 1; i < m_count; ++i) //loops through each element 
		{
			key = m_data[i]; // setting the key (data value for comparing)

			size_t j = i - 1; // Element before i

			while ((j <= 0) && (m_data[j] > key))
			{
				m_data[j + 1] = m_data[j];
				m_data[j] = key;
				j--;
			}
			//m_data[j + 1] = key;

			//printArray()
			std::cout << "\Moved\: " << key << std::endl;
		}

	}



private:
	//Pointer To Storage
	T* m_data = nullptr;
	//Data Type?

	//Store Current Length
	size_t m_size = 0; //Size Count Length 

	//Store Current Capacity
	size_t m_capacity = 0;

	const size_t m_default_capacity = 8;

};
