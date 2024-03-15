#pragma once
#include "Math.h"
#include <cstdarg>
#include <cstring> 

 int Math:: Add(int x, int y)
{
	return  x + y;
}
 int Math::Add(int x, int y, int z)
{
	return  x + y + z;
}
 int Math::Add(double x, double y)
{
	return static_cast<int>(x + y);
}
 int Math::Add(double x, double y, double z)
{
	return static_cast<int>(x + y + z);
}
 int Math::Mul(int x, int y)
{
	return x * y;
}
 int Math::Mul(int x, int y, int z)
{
	return x * y * z;
}
 int Math::Mul(double x, double y)
{
	return static_cast<int>(x * y);
}
 int Math::Mul(double x, double y, double z)
{
	return static_cast<int>(x * y * z);
}
 
 int Math::Add(int count, ...)
 {
	 va_list args;
	 va_start(args, count);
	 int sum = 0;
	 for (int i = 0; i < count; ++i) {
		 sum += va_arg(args, int);
	 }
	 va_end(args);
	 return sum;
 }
 char* Math::Add(const char* s1, const char* s2)
 {
	 if (s1 == nullptr || s2 == nullptr)
		 return nullptr;

	 int n1 = strlen(s1);
	 int n2 = strlen(s2);
	 char * result = new char[n1 + n2 + 1];
	 for (int i = 0; i < n1; i++)
		 result[i] = s1[i];
	 for (int i = 0; i <=n2; i++)
		 result[i+n1] = s2[i];
	 strcpy(result, s1);
	 strcat(result, s2);
	 return result;
 }