/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 18:07:06 by bthomas           #+#    #+#             */
/*   Updated: 2024/10/09 19:37:12 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <class T>
class MutantStack
{
	private:
		std::deque<T> _container;

	public:
		MutantStack (void);
		MutantStack (const MutantStack &other);
		~MutantStack (void);
		MutantStack & operator=(const MutantStack &other);

	public:
		void push(T);
		void pop(void);
		T& top(void);
		bool empty();
		size_t size();
		typename std::deque<T>::iterator begin();
		typename std::deque<T>::iterator end();
};

#endif /* MUTANTSTACK_HPP */
