#pragma once
class BadTypeException
{
private:
	const char* message;

public:
	BadTypeException(const char* m) : message(m) {
	}
	const char* getMessage() {
		return message;
	}
};
