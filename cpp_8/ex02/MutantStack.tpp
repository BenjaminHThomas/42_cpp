/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:20:03 by bthomas           #+#    #+#             */
/*   Updated: 2024/10/10 11:12:20 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack(void)
{
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &other)
{
	_container = other._container;
}

template <typename T>
MutantStack<T>::~MutantStack()
{
	
}

template <typename T>
MutantStack<T> & MutantStack<T>::operator=(const MutantStack &other)
{
	if (this != &other)
	{
		_container = other._container;
	}
	return *this;
}

template <typename T>
void MutantStack<T>::push(T in) {
	_container.push_back(in);
}

template <typename T>
void MutantStack<T>::pop(void) {
	_container.pop_back();
}

template <typename T>
T& MutantStack<T>::top(void) {
	return _container.back();
}

template <typename T>
bool MutantStack<T>::empty(void) {
	return _container.empty();
}

template <typename T>
size_t MutantStack<T>::size(void) {
	return _container.size();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
	return _container.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
	return _container.end();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const {
	return _container.begin();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const {
	return _container.end();
}