/*
 * MultiplyBy2.cpp
 *
 *  Created on: 28 Feb 2014
 *      Author: mochman
 */

#include "MultiplyBy2.hpp"

void MultiplyBy2::compute()
{
	m_outputData.clear();
	for( auto it = m_inputData.begin(); it != m_inputData.end(); it++)
		m_outputData.push_back(*it*2);
}
