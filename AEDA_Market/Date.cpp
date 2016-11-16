#include "Date.h"

Date::Date(string date) {
	stringstream ss(date);
	char delimiter;
	uni d, m, y;
	if (ss << d << delimiter << m << delimiter << y && count_digits(y) == 4) {
		struct tm t = { 0 };
		t.tm_mday = d;
		t.tm_mon = m - 1;
		t.tm_year = y - 1900;
		t.tm_isdst = -1;

		time_t when = mktime(&t);
		const struct tm *norm = localtime(&when);
		if (norm->tm_mday == d && norm->tm_mon == m - 1 && norm->tm_year == y - 1900) {
			this->day = d;
			this->month = m;
			this->year = y;
		}

		else if (norm->tm_mday != d) throw InvalidDate(1);
		else if (norm->tm_mon != m) throw InvalidDate(2);
		else if (norm->tm_year != y) throw InvalidDate(3);
	}
	else throw InvalidDate(4);
}

Date::Date(uni day, uni month, uni year) {
	struct tm t = { 0 };
	t.tm_mday = day;
	t.tm_mon = month - 1;
	t.tm_year = year - 1900;
	t.tm_isdst = -1;

	time_t when = mktime(&t);
	const struct tm *norm = localtime(&when);
	if (norm->tm_mday == day && norm->tm_mon == month - 1 && norm->tm_year == year - 1900) {
		this->day = day;
		this->month = month;
		this->year = year;
	}

	else if (norm->tm_mday != day) throw InvalidDate(1);
	else if (norm->tm_mon != month) throw InvalidDate(2);
	else if (norm->tm_year != year) throw InvalidDate(3);
	
}

uni Date::getDay() {
	return this->day;
}

uni Date::getMonth() {
	return this->month;
}

uni Date::getYear() {
	return this->year;
}

bool Date::setDay(uni day) {
	struct tm t = { 0 };
	t.tm_mday = day;
	t.tm_isdst = -1;

	time_t when = mktime(&t);
	const struct tm *norm = localtime(&when);
	if (norm->tm_mday == day) {
		this->day = day;
		return true;
	}
	else throw InvalidDate(1);

	return false;
}

bool Date::setMonth(uni month) {
	struct tm t = { 0 };
	t.tm_mon = month;
	t.tm_isdst = -1;

	time_t when = mktime(&t);
	const struct tm *norm = localtime(&when);
	if (norm->tm_mon== month) {
		this->month = month;
		return true;
	}
	else throw InvalidDate(2);

	return false;
}

bool Date::setYear(uni year) {
	if (count_digits(year) == 4) {
		struct tm t = { 0 };
		t.tm_year = year;
		t.tm_isdst = -1;

		time_t when = mktime(&t);
		const struct tm *norm = localtime(&when);
		if (norm->tm_year == year) {
			this->year = year;
			return true;
		}
		else throw InvalidDate(3);
		return false;
	}
	
	else throw InvalidDate(4);

	return false;
}

InvalidDate::InvalidDate(uni t) {
	this->type = t;
}

uni InvalidDate::getType() {
	return this->type;
}

string InvalidDate::what() {
	string what;
	switch (type) {
	case 1: what = "Invalid Day.\n";
	case 2: what = "Invalid Month.\n";
	case 3: what = "Invalid Year.\n";
	case 4: what = "Invalid Input of Date.\n";
		
	}
	return what;
}

bool Date::operator < (Date* rhs) {

	if (this->year > rhs->getYear()) return true;
	else if (this->year == rhs->getYear() && this->month > rhs->getMonth()) return true;
	else if (this->year == rhs->getYear() && this->month == rhs->getMonth() && this->day > rhs->getDay()) return true;
	else return false;
}

bool Date::operator == (Date* rhs) {
	if (year == rhs->getYear() && month == rhs->getMonth() && day == rhs->getDay()) return true;
	else return false;
}

