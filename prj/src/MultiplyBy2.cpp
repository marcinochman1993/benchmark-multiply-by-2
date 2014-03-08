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
	for( unsigned int i =0; i != m_inputData.size(); i++)
		m_outputData.push_back(2*m_inputData[i]);
}
