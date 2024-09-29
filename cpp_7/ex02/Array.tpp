/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 14:28:20 by bthomas           #+#    #+#             */
/*   Updated: 2024/09/29 14:41:53 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array() :
	_size(0)
{
	_arr = new T[0];
}

template <typename T>
Array<T>::Array(const Array<T> &other) :
	_size(other._size)
{
	_arr = new T[other.size];
	for (uint32_t i = 0; i < other.size; ++i) {
		_arr[i] = other._arr[i];
	}
}

template <typename T>
Array<T>::~Array()
{
	delete [] _arr;
}

template <typename T>
Array<T> & Array<T>::operator=(const Array<T> &other)
{
	if (this != &other)
	{
		delete [] _arr;
		_arr = new T[other._size];
		for (uint32_t i = 0; i < other._size; ++i) {
			_arr[i] = other._arr[i];
		}
	}
	return *this;
}

template <typename T>
uint32_t Array<T>::size() const {
	return _size;
}

template <typename T>
T& Array<T>::operator[](uint32_t index) {
	if (index > _size) {
		throw std::out_of_range("Error: index out of range\n");
	}
	return _arr[index];
}
