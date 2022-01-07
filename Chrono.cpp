//C++ supports two types of time manipulatin
//The chrono library, a flexible collection of types that track time with varying degrees of precision
//(e.g. std::chrono::timepoint)
// C style date and time library(e.g. std::time)
//std::chrono library - It defines three main types as well as utility functions and common typesdefs
//1.clocks, 2.time points, 3.durations
// 1. A clock consists of a starting point(or epoch) and a tick rate. For example a clock may have an epoch of 
// 1st January' 2020 and a tick rate of 1 second. C++ defines several clock types
//1. system_clock - wall clock time from the system-wide realtime clock
//2. steady_clock - monotonic clock that will never be adjusted
//3.high_resolution_clock - the clock with shortest tick period available
//Timepoint - It is the duration that passed since the epoch of a specific clock
//clock_cast - converts time point of one clock to another
//Duration - A duration consists a span of time, defined as some number of ticks of some time unit.

#include<iostream>
#include<chrono>
#include<ctime>

long fibonacci(int n)
{
	if (n < 2)
		return n;
	return fibonacci(n - 1) + fibonacci(n - 2);
}
/*
int main()
{
	auto start = std::chrono::system_clock::now();
	std::cout << "f(42) = " << fibonacci(42) << "\n";
	auto end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = end - start;
	std::time_t endtime = std::chrono::system_clock::to_time_t(end);

	std::cout << "finished computation at " << //std::ctime(&endtime) <<
		"elapsed time:" << elapsed_seconds.count() << "s\n";
}
*/