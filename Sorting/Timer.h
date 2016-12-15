#pragma once
#include <chrono>
#include <iostream>
#include <string>
#include <ctime>

using namespace std::chrono;

/*This class creates an object that starts a count.  When the object goes out of scope, 
it prints the time to console.*/
class Timer
{
private:
	steady_clock::time_point m_start;
	steady_clock::time_point m_end;
	std::string m_name;

public:

	Timer(std::string name)
	{
		m_name = name;
		m_start = steady_clock::now();
	}

	~Timer()
	{
		m_end = steady_clock::now();

		duration<double> time_span = duration_cast<duration<double>>(m_end - m_start);

		std::cout << m_name << " timer elapsed after " << time_span.count() << " seconds" << std::endl;
	}
};