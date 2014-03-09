#ifndef Vector_HPP_
#define Vector_HPP_

#include <iostream>
#include <algorithm>
namespace MOchman
{
	template<typename Type>
	class Vector
	{
		public:

			/*!
			 * \brief Domyślny konstruktor klasy Vector
			 *
			 * Inicjalizuje odpowiednie pola klasy Vector.
			 */
			Vector()
					: m_data(nullptr), m_size(0), m_allocated(0)
			{
			}
			void swapElements(unsigned int, unsigned int);
			/*!
			 * \brief Odwraca tablicę
			 *
			 * Początek staje sie końcem.
			 */
			void reverse();

			/*!
			 * \brief Pozwala dodać element na koniec tablicy.
			 *
			 * Jeśli jest taka potrzeba, alokuje nową pamięć i kopiuje
			 * wcześniejsze elementy do nowej pamięci.
			 */
			void push_back(Type element);

			/*!
			 * \brief Pozwala dodać elementy z drugiej tablicy na koniec tablicy.
			 *
			 * Jeśli jest taka potrzeba, alokuje nową pamięć i kopiuje
			 * wcześniejsze elementy do nowej pamięci.
			 */
			void push_back(const Vector<Type>& vec);

			/*!
			 * \brief Pozwala pobrać rozmiar tablicy.
			 */
			unsigned int size() const
			{
				return m_size;
			}

			/*!
			 * \brief Pozwala na przypisanie tablicy.
			 *
			 * \param vec - tablica, która ma być skopiowana
			 */
			Vector& operator=(const Vector& vec);

			/*!
			 * \brief Pozwala porównać dwie tablice
			 */
			bool operator==(const Vector& vec);

			/*!
			 * Pozwala stwierdzić czy dwie tablice są różne.
			 */
			bool operator!=(const Vector& vec);

			/*!
			 * \brief Pobiera rozmiar zaalokowanej pamięci.
			 *
			 */
			unsigned int allocatedSize() const
			{
				return m_allocated;
			}

			/*!
			 * \brief Pozwala zaalokować odpowiednią ilość pamięci.
			 *
			 * \param size - ilość pamięci do zaalokowania, musi być większy niż aktualny rozmiar tablicy
			 */
			void reserve(unsigned int size);

			/*!
			 * \brief Usuwa wszystkie przechowywane dane.
			 *
			 * Operacja jest nieodwracalna.
			 */
			void clear();

			/*!
			 * \brief Pozwala pobrać element o określonym indeksie
			 *
			 * Jeśli indeks jest za duży zgłaszany jest wyjątek const char*
			 *
			 * \param index - indeks elementu
			 */
			const Type& operator[](unsigned int index) const;
			/*!
			 * \brief Destruktor zwalniający zasoby listy.
			 */
			~Vector()
			{
				delete m_data;
			}
		private:

			/*!
			 * \brief Przechowuje wskaźnik na dane.
			 */
			Type* m_data;

			/*!
			 * \brief Przechowuje rozmiar tablicy
			 */
			unsigned int m_size;

			/*!
			 * \brief Przechowuje ilość zaalokowanej pamięci
			 */
			unsigned int m_allocated;
	};

}
template<typename Type>
void MOchman::Vector<Type>::swapElements(unsigned int i, unsigned int j)
{
	if(i < size() && j < size())
	{
		Type temp = m_data[i];
		m_data[i] = m_data[j];
		m_data[j] = temp;
	}
	else
		throw "Index too big";
}

template<typename Type>
void MOchman::Vector<Type>::reverse()
{
	if(size() > 0)
	{
		unsigned int i = 0, j = size() - 1;
		while (i < j)
			swapElements(i++, j--);
	}
}

template<typename Type>
void MOchman::Vector<Type>::push_back(Type element)
{
	if(size() == allocatedSize())
	{
		reserve(size() + 1);
		m_data[size()] = element;
		m_size += 1;
		delete[] m_data;
	}
	else
	{
		m_size += 1;
		m_data[size() - 1] = element;
	}
}

template<typename Type>
void MOchman::Vector<Type>::push_back(const Vector<Type>& vec)
{
	if(size() + vec.size() > allocatedSize())
		reserve(size() + vec.size());
	std::copy(vec.m_data, vec.m_data + vec.size(), m_data + size());
	m_size += vec.size();
}

template<typename Type>
MOchman::Vector<Type>& MOchman::Vector<Type>::operator=(
		const Vector<Type>& vec)
{
	if(m_data != nullptr)
		delete[] m_data;
	if(vec.size())
	{
		reserve(vec.m_allocated);
		m_size = vec.m_size;
	}
	else
	{
		m_data = nullptr;
		m_size = 0;
		m_allocated = 0;
	}
}

template<typename Type>
bool MOchman::Vector<Type>::operator==(const Vector& vec)
{
	if(vec.size() != size())
		return false;
	for (unsigned int i = 0; i < size(); i++)
		if(m_data[i] != vec.m_data[i])
			return false;
	return true;
}

template<typename Type>
bool MOchman::Vector<Type>::operator!=(const Vector& vec)
{
	if(vec.size() != size())
		return true;
	for (unsigned int i = 0; i < size(); i++)
		if(m_data[i] != vec.m_data[i])
			return true;
	return false;
}

template<typename Type>
void MOchman::Vector<Type>::reserve(unsigned int size)
{
	if(size < this->size())
		throw "Too many elements to store - not enough size";
	Type* temp = new Type[size];
	std::copy(m_data, m_data + this->size(), temp);
	m_allocated = size;
	if(this->size())
		delete[] m_data;
	m_data = temp;
}

template<typename Type>
void MOchman::Vector<Type>::clear()
{
	if(size())
	{
		delete[] m_data;
		m_size = 0;
		m_allocated = 0;
	}
}

template<typename Type>
const Type& MOchman::Vector<Type>::operator[](unsigned int index) const
{
	if(index < size())
		return m_data[index];
	throw "Index out of range";
}

#endif
