#include "SudalException.h"
#include <sstream>

SudalException::SudalException(int line, const char* file) noexcept
	:
	line(line),
	file(file)
{}

const char* SudalException::what() const noexcept
{
	std::ostringstream oss;
	oss << GetType() << std::endl << GetOriginString();
	whatBuffer = oss.str();
	return whatBuffer.c_str();
}

const char* SudalException::GetType() const noexcept
{
	return "Sudal Exception";
}

int SudalException::GetLine() const noexcept
{
	return line;
}

const std::string& SudalException::GetFile() const noexcept
{
	return file;
}

std::string SudalException::GetOriginString() const noexcept
{
	std::ostringstream oss;
	oss << "[File] " << file << std::endl
		<< "[Line] " << line;
	return oss.str();
}