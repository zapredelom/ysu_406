#pragma once
#include <cstring>
#include <iostream>
class Employee {
private:
	char * m_name;
	char m_position[80];
	int  m_sallary;
	int  m_day;
	int  m_month;
	int  m_year;
public:
	Employee()
		:m_sallary(-1) {
	}
	Employee(const char* name, const char* position,
		int sallay = 0, int day = 0, int month = 0, int year = 0)
		:m_day(day), m_month(month), m_year(year) {
		int name_len = strlen(name);
		m_name = new char[name_len];
		strcpy(m_name, name);
		strcpy(m_position, position);


	}
	void print_employee() {

	}
	void set_name(char* name) {
		strcpy(m_name, name);
	}
	const char* get_name() {
		return m_name;
	}
	
	void set_position(char* position) {
		int i = 0;
		while (position[i] != '\0')
		{
			m_position[i] = position[i];
			i++;
		}
	}
	const char* get_position()
	{
		return m_position;
	}
	void set_day(int d) {
		if (d < 1 || d>31) {
			std::cout << "not a valid day";
			exit(1);
		}
	}
	~Employee() {
		delete[] m_name;
	}
};
