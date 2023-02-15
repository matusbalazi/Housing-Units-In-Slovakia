#pragma once

#include "structures/array/array.h"
#include "matrix.h"
#include <iostream>
#include "../heap_monitor.h"

namespace structures
{
	template <typename T>
	class MatrixDiscontinuous : public Matrix<T>
	{

	private:
		Array<Array<T>*>* aArray;
		unsigned int aRows;
		unsigned int aCols;

	public:
		MatrixDiscontinuous(const int pRows, const int pCols, const T pData);
		MatrixDiscontinuous(const MatrixDiscontinuous<T>& other);

		MatrixDiscontinuous<T>& operator=(const MatrixDiscontinuous<T>& other);

		Matrix<T>& operator=(const Matrix<T>& other) override;

		Matrix<T>* addition(const Matrix<T>& other) override;
		Matrix<T>* multiplication(const Matrix<T>& other) override;

		Structure* clone() const override;
		void setElement(unsigned int pRow, unsigned int pCol, T pValue) override;
		T getElement(unsigned int pRow, unsigned int pCol) const override;
		unsigned int getRows() override;
		unsigned int getColumns() override;
		void print() override;

		~MatrixDiscontinuous();
	};

	// Konstruktor vytvori maticu o velkosti pocet riadkov * pocet stlpcov.
	// Vytvorenu maticu naplni inicializacnymi hodnotami.
	template<typename T>
	inline MatrixDiscontinuous<T>::MatrixDiscontinuous(const int pRows, const int pCols, const T pData) :
		aRows(pRows), aCols(pCols), aArray(new Array<Array<T>*>(pRows))
	{
		for (int i = 0; i < pRows; i++) {
			aArray->operator[](i) = new Array<T>(pCols);
		}
		for (int j = 0; j < pRows; j++) {
			for (int k = 0; k < pCols; k++) {
				setElement(j, k, pData);
			}
		}
	}

	// Kopirovaci konstruktor. 
	template<typename T>
	inline MatrixDiscontinuous<T>::MatrixDiscontinuous(const MatrixDiscontinuous<T>& other) :
		aRows(other.aRows), aCols(other.aCols), aArray(new Array<Array<T>*>(other.aRows))
	{
		for (int i = 0; i < other.aRows; i++) {
			aArray->operator[](i) = new Array<T>(other.aCols);
			for (int j = 0; j < other.aCols; j++) {
				setElement(i, j, other.getElement(i, j));
			}
		}
	}

	// Operator priradenia.
	// Vrati adresu, na ktorej sa tato matica nachadza po priradeni.
	template<typename T>
	inline MatrixDiscontinuous<T>& MatrixDiscontinuous<T>::operator=(const MatrixDiscontinuous<T>& other)
	{
		if (this != &other) {
			if (aRows == other.aRows && aCols == other.aCols) {
				for (int i = 0; i < aRows; i++) {
					delete aArray[i];
					aArray[i] = nullptr;
				}
				delete aArray;
				aArray = nullptr;
				aRows = 0;
				aCols = 0;

				aRows = other.aRows;
				aCols = other.aCols;

				aArray = new Array<Array<T>*>(*other.aRows);
				for (int i = 0; i < other.aRows; i++) {
					aArray->operator[](i) = new Array<T>(other.aCols);
					for (int j = 0; j < other.aCols; j++) {
						setElement(i, j, *other.getElement(i, j));
					}
				}
			}
		}
		return *this;
	}

	// Operator priradenia (zdedeny). 
	// Vrati adresu, na ktorej sa tato matica nachadza po priradeni.
	template<typename T>
	inline Matrix<T>& MatrixDiscontinuous<T>::operator=(const Matrix<T>& other)
	{
		if (this != &other) {
			*this = dynamic_cast<const Matrix<T>&>(other);
		}
		return *this;
	}

	// Scitavanie dvoch obdlznikovych matic rovnakych rozmerov m*n.
	// Vysledkom je vypocitana tretia matica rozmerov m*n, ktora je ich suctom.
	template<typename T>
	inline Matrix<T>* MatrixDiscontinuous<T>::addition(const Matrix<T>& other)
	{

		MatrixDiscontinuous<T> matrix2 = dynamic_cast<const MatrixDiscontinuous<T>&>(other);

		if (aRows != matrix2.aRows || aCols != matrix2.aCols) {
			return this;
		}

		MatrixDiscontinuous<T>* result = new MatrixDiscontinuous<T>(aRows, aCols, 0);

		for (int i = 0; i < result->aRows; i++) {
			for (int j = 0; j < result->aCols; j++) {
				result->setElement(i, j, getElement(i, j) + matrix2.getElement(i, j));
			}
		}

		return result;
	}

	// Nasobenie dvoch obdlznikovych matic rozmerov m*n a n*m.
	// Vysledkom je vypocitana tretia matica rozmerov m*m, ktora je ich sucinom.
	template<typename T>
	inline Matrix<T>* MatrixDiscontinuous<T>::multiplication(const Matrix<T>& other)
	{
		MatrixDiscontinuous<T> matrix2 = dynamic_cast<const MatrixDiscontinuous<T>&>(other);

		if (aRows != matrix2.aCols || aCols != matrix2.aRows) {
			return this;
		}

		MatrixDiscontinuous<T>* result = new MatrixDiscontinuous<T>(aRows, matrix2.aCols, 0);

		for (int i = 0; i < result->aRows; i++) {
			for (int j = 0; j < result->aCols; j++) {
				for (int k = 0; k < aCols; k++) {
					result->setElement(i, j, result->getElement(i, j) + (getElement(i, k) * matrix2.getElement(k, j)));
				}
			}
		}
		return result;
	}

	// Operacia klonovania. Vytvori a vrati duplikat matice.
	// Vrati ukazovatel na vytvoreny klon matice.
	template<typename T>
	inline Structure* MatrixDiscontinuous<T>::clone() const
	{
		return new MatrixDiscontinuous<T>(*this);
	}

	// Nastavi hodnotu prvku na danych indexoch
	template<typename T>
	inline void MatrixDiscontinuous<T>::setElement(unsigned int pRow, unsigned int pCol, T pValue)
	{
		aArray->operator[](pRow)->operator[](pCol) = pValue;
	}

	// Vrati prvok na danych indexoch.
	template<typename T>
	inline T MatrixDiscontinuous<T>::getElement(unsigned int pRow, unsigned int pCol) const
	{
		return aArray->operator[](pRow)->operator[](pCol);
	}

	// Vrati pocet riadkov matice.
	template<typename T>
	inline unsigned int MatrixDiscontinuous<T>::getRows()
	{
		return aRows;
	}

	// Vrati pocet stlpcov matice.
	template<typename T>
	inline unsigned int MatrixDiscontinuous<T>::getColumns()
	{
		return aCols;
	}

	// Vypis matice na konzolu.
	template<typename T>
	inline void MatrixDiscontinuous<T>::print()
	{
		for (int i = 0; i < aRows; i++) {
			for (int j = 0; j < aCols; j++) {
				std::cout << getElement(i, j) << " ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}

	// Destruktor.
	template<typename T>
	inline MatrixDiscontinuous<T>::~MatrixDiscontinuous()
	{
		for (int i = 0; i < aRows; i++) {
			delete aArray->operator[](i);
			aArray->operator[](i) = nullptr;
		}
		delete aArray;
		aArray = nullptr;
		aRows = 0;
		aCols = 0;
	}

}

