#include "SudalTimer.h"

using namespace std::chrono;

SudalTimer::SudalTimer()
{
	last = steady_clock::now();
}

float SudalTimer::Mark()
{
	const auto old = last;
	last = steady_clock::now();
	const duration<float> frameTime = last - old;
	return frameTime.count();
}

float SudalTimer::Peek() const
{
	return duration<float>(steady_clock::now() - last).count();
}