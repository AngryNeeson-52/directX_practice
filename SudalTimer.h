#pragma once

#include <chrono>

class SudalTimer
{
public:
	SudalTimer();
	float Mark();
	float Peek() const;

private:
	std::chrono::steady_clock::time_point last;

};