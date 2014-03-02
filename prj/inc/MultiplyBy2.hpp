/*
 * MultiplyBy2.hpp
 *
 *  Created on: 28 Feb 2014
 *      Author: mochman
 */

#ifndef MULTIPLYBY2_HPP_
#define MULTIPLYBY2_HPP_

#include "StandardProblem.hpp"

/*! \brief Klasa reprezentuje algorytm mnożenia tablicy przez 2
 */
class MultiplyBy2: public StandardProblem<>
{
	public:
		/*! \brief Przemnaża tablicę wejściową przez 2
		 *
		 * Metoda wymnaża każdy element przez dwa i zapisuje wynik do tablicy wyjściowej
		 */
		void compute();
		~MultiplyBy2() = default;
};

#endif /* MULTIPLYBY2_HPP_ */
