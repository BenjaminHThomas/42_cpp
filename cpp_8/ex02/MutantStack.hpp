/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 18:07:06 by bthomas           #+#    #+#             */
/*   Updated: 2024/10/10 11:14:39 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <class T>
class MutantStack : public std::stack<T>
{
	private:
		std::deque<T> _container;

	public:
		MutantStack (void);
		MutantStack (const MutantStack &other);
		~MutantStack (void);
		MutantStack & operator=(const MutantStack &other);

	public:
		typedef typename std::deque<T>::iterator iterator;
		typedef typename std::deque<T>::const_iterator const_iterator;

	public:
		void push(T);
		void pop(void);
		T& top(void);
		bool empty();
		size_t size();
		iterator begin();
		iterator end();
		const_iterator begin() const;
		const_iterator end() const;
};

#include "MutantStack.tpp"

#endif /* MUTANTSTACK_HPP */
