#pragma once

#include "structures/array/array.h"
#include "matrix.h"
#include <iostream>
#include "../heap_monitor.h"

namespace structures 
{
	template <typename T>
	class MatrixContinuous : public Matrix<T>
	{

	private:
		Array<T>* aArray;
		unsigned int aRows;
		unsigned int aCols;
		int mapFunction(const int pRow, const int pCol) const;

	public:
		MatrixContinuous(const int pRows, const int pCols, const T pData);
		MatrixContinuous(const MatrixContinuous<T>& other);

		MatrixContinuous<T>& operator=(const MatrixContinuous<T>& other);

		Matrix<T>& operator=(const Matrix<T>& other) override;

		Matrix<T>* addition(const Matrix<T>& other) override;
		Matrix<T>* multiplication(const Matrix<T>& other) override;

		Structure* clone() const override;
		void setElement(unsigned int pRow, unsigned int pCol, T pValue) override;
		T getElement(unsigned int pRow, unsigned int pCol) const override;
		unsigned int getRows() override;
		unsigned int getColumns() override;
		void print() override;

		~MatrixContinuous();
	};

	// Konstruktor vytvori maticu o velkosti pocet riadkov * pocet stlpcov.
	// Vytvorenu maticu naplni inicializacnymi hodnotami.
	template<typename T>
	inline MatrixContinuous<T>::MatrixContinuous(const int pRows, const int pCols, T pData) :
		aRows(pRows), aCols(pCols), aArray(new Array<T>(pRows * pCols))
	{
		for (int i = 0; i < aArray->size(); i++) {
			aArray->operator[](i) = pData;
		}
	}

	// Kopirovaci konstruktor. 
	template<typename T>
	inline MatrixContinuous<T>::MatrixContinuous(const MatrixContinuous<T>& other) :
		aRows(other.aRows), aCols(other.aCols), aArray(new Array<T>(*other.aArray))
	{
	}

	// Operator priradenia.
	// Vrati adresu, na ktorej sa tato matica nachadza po priradeni.
	template<typename T>
	inline MatrixContinuous<T>& MatrixContinuous<T>::operator=(const MatrixContinuous<T>& other)
	{
		if (this != &other) {
			if (aArray->size() == other.aArray->size()) {
				*aArray = *other.aArray;
			}
			else {
				delete aArray;
				aRows = other.aRows;
				aCols = other.aCols;
				aArray = new Array<T>(*other.aArray);
			}
		}
		return *this;
	}

	// Operator priradenia (zdedeny). 
	// Vrati adresu, na ktorej sa tato matica nachadza po priradeni.
	template<typename T>
	inline Matrix<T>& MatrixContinuous<T>::operator=(const Matrix<T>& other)
	{
		if (this != &other) {
			*this = dynamic_cast<const Matrix<T>&>(other);
		}
		return *this;
	}

	// Scitavanie dvoch obdlznikovych matic rovnakych rozmerov m*n.
	// Vysledkom je vypocitana tretia matica rozmerov m*n, ktora je ich suctom.
	template<typename T>
	inline Matrix<T>* MatrixContinuous<T>::addition(const Matrix<T>& other)
	{
		MatrixContinuous<T> matrix2 = dynamic_cast<const MatrixContinuous<T>&>(other);

		if (aRows != matrix2.aRows || aCols != matrix2.aCols) {
			return this;
		}

		MatrixContinuous<T>* result = new MatrixContinuous<T>(aRows, aCols, 0);
		
		/*for (int i = 0; i < result->aRows; i++) {
			for (int j = 0; j < result->aCols; j++) {
				(*result)[i][j] = ((getElement(i, j)) + second.getElement(i, j));
			}
		}*/

		for (int i = 0; i < aArray->size(); i++) {
			(*result->aArray)[i] = (*aArray)[i] + (*matrix2.aArray)[i];
		}

		return result;
	}

	// Nasobenie dvoch obdlznikovych matic rozmerov m*n a n*m.
	// Vysledkom je vypocitana tretia matica rozmerov m*m, ktora je ich sucinom.
	template<typename T>
	inline Matrix<T>* MatrixContinuous<T>::multiplication(const Matrix<T>& other)
	{
		MatrixContinuous<T> matrix2 = dynamic_cast<const MatrixContinuous<T>&>(other);

		if (aRows != matrix2.aCols || aCols != matrix2.aRows) {
			return this;
		}

		MatrixContinuous<T>* result = new MatrixContinuous<T>(aRows, matrix2.aCols, 0);

		for (int i = 0; i < result->aRows; i++) {
			for (int j = 0; j < result->aCols; j++) {
				for (int k = 0; k < aCols; k++) {
					(*result->aArray)[result->mapFunction(i, j)] += (*aArray)[mapFunction(i, k)] * (*matrix2.aArray)[matrix2.mapFunction(k, j)];
				}
			}
		}

		return result;
	}

	// Operacia klonovania. Vytvori a vrati duplikat matice.
	// Vrati ukazovatel na vytvoreny klon matice.
	template<typename T>
	inline Structure* MatrixContinuous<T>::clone() const
	{
		return new MatrixContinuous<T>(*this);
	}

	// Nastavi hodnotu prvku na danych indexoch
	template<typename T>
	inline void MatrixContinuous<T>::setElement(unsigned int pRow, unsigned int pCol, T pData)
	{
		aArray->operator[](mapFunction(pRow, pCol)) = pData;
	}

	// Vrati prvok na danych indexoch.
	template<typename T>
	inline T MatrixContinuous<T>::getElement(unsigned int pRow, unsigned int pCol) const
	{
		return aArray->operator[](mapFunction(pRow, pCol));
	}

	// Vrati pocet riadkov matice.
	template<typename T>
	inline unsigned int MatrixContinuous<T>::getRows()
	{
		return aRows;
	}

	// Vrati pocet stlpcov matice.
	template<typename T>
	inline unsigned int MatrixContinuous<T>::getColumns()
	{
		return aCols;
	}

	// Vypis matice na konzolu.
	template<typename T>
	inline void MatrixContinuous<T>::print()
	{
		for (int i = 0; i < aArray->size(); i++) {
			if (i % aCols == 0) {
				std::cout << std::endl;
			}
			std::cout << aArray->operator[](i) << " ";
		}
		std::cout << std::endl;
	}

	// Destruktor.
	template<typename T>
	inline MatrixContinuous<T>::~MatrixContinuous()
	{
		delete aArray;
		aArray = nullptr;
		aRows = 0;
		aCols = 0;
	}

	// Mapovacia funckia, ktora prevedie indexy v matici na index v poli.
	template<typename T>
	inline int MatrixContinuous<T>::mapFunction(const int pRow, const int pCol) const
	{
		return ((pRow * aCols) + pCol);
	}
}
