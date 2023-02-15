#pragma once

#include "../structure.h"
#include "../structure_iterator.h"
#include "../ds_structure_types.h"
#include "../heap_monitor.h"

namespace structures 
{
	template <typename T>
	class Matrix : public Structure
	{
	public:
		// ?
		virtual ~Matrix() {};
		
		Structure& operator=(const Structure& other) override;
		size_t size() const override;
		//virtual Structure* clone() const override = 0;
		
		virtual Matrix<T>& operator=(const Matrix<T>& other) = 0;
		/*virtual T& operator[](const unsigned int pRow) = 0;*/
		
		virtual Matrix<T>* operator+(const Matrix<T>& other);
		virtual Matrix<T>* addition(const Matrix<T>& other) = 0;
		
		virtual Matrix<T>* operator*(const Matrix<T>& other);
		virtual Matrix<T>* multiplication(const Matrix<T>& other) = 0;

		virtual void print() = 0;
		virtual void setElement(unsigned int pRow, unsigned int pCol, T pValue) = 0;
		virtual T getElement(unsigned int pRow, unsigned int pCol) const = 0;
		virtual unsigned int getRows() = 0;
		virtual unsigned int getColumns() = 0;

	protected:
		Matrix() {};
		unsigned int aRows;
		unsigned int aCols;
	};

	template<typename T>
	inline Structure& Matrix<T>::operator=(const Structure& other) {
		if (this != &other) {
			*this = dynamic_cast<const Matrix<T>&>(other);
		}
		return *this;
	}

	template<typename T>
	inline size_t Matrix<T>::size() const
	{
		return (aRows * aCols);
	}

	template<typename T>
	inline Matrix<T>* Matrix<T>::operator+(const Matrix<T>& other)
	{
		return addition(other);
	}

	template<typename T>
	inline Matrix<T>* Matrix<T>::operator*(const Matrix<T>& other)
	{
		return multiplication(other);
	}

	template<typename T>
	inline unsigned int Matrix<T>::getRows()
	{
		return aRows;
	}

	template<typename T>
	inline unsigned int Matrix<T>::getColumns()
	{
		return aCols;
	}

}