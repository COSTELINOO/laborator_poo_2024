#pragma once
class students
{
private:
	char student_name[100];
	 int mate, eng, ist;
public:
	void set_name(char* c);
	void set_mate( int x);
	void set_eng( int x);
	void set_ist( int x);
	char* get_name();
	int get_mate();
	int get_eng();
	int get_ist();
	double media();
};