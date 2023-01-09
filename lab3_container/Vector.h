#pragma once
#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iterator>
#include <iomanip>
#include<conio.h>

template <class T>
class Set {
private:
	std::vector<T> arr;
	int size;
	bool check_num(T num) {
		for (auto i : arr) {
			if (i == num)
				return true;
		}
		return false;
	}
public:
	Set() = default;
	Set(const Set& second) = default;
	~Set() = default;
	Set& operator=(const Set& value) = default;

	T operator[](const int index) { //значение по индексу
		return arr.at(index);
	}
	Set& operator += (T num) { //добавление числа
		if (check_num(num) == false) {
			this->arr.push_back(num);
		}
		return *this;
	}
	Set operator+(T num) { // добавление числа
		Set res = *this;
		if (check_num(num) == false) {
			res.arr.push_back(num);
		}
		return res;
	}
	Set operator + (const Set& second) { //объединение множеств
		Set res = *this;
		for (auto i : second.arr) {
			if (check_num(i) == false) {
				res.arr.push_back(i);
			}
		}
		return res;
	}
	Set intersection(const Set& second) { //пересечение
		Set res;
		for (auto i : arr) {
			for (auto j : second.arr) {
				if (j == i) {
					res.arr.push_back(j);
				}
			}
		}
		return res;
	}
	bool check_count(const Set& second) { //все элементы 1 множества хотя бы раз встречаются во 2 множестве
		bool flag = false;
		for (auto i : arr) {
			flag = false;
			for (auto j : second.arr) {
				if (i == j) {
					flag = true;
					break;
				}
			}
			if (flag == false)
				return false;
		}
		return true;
	}
	bool operator==(const Set& second) { //равенство
		if (second.size != size)
			return false;
		else
		{
			bool flag = false;
			for (auto i: arr)
			{
				flag = false;
				for (auto j: second.arr) {
					if (i == j) {
						flag = true;
						break;
					}
				}
				if (flag == false)
					return false;
			}
			return true;
		}
	}
	bool operator!=(const Set& second) { //неравенство
		if (second.size != size)
			return true;
		else
		{
			bool flag = true;
			for (auto i : arr)
			{
				flag = true;
				for (auto j : second.arr) {
					if (i == j) {
						flag = false;
						break;
					}
				}
				if (flag == true)
					return true;
			}
			return false;
		}
	}
	Set& operator -=(T num) { //удаление числа
		for (typename std::vector<T>::iterator it = arr.begin(); it != arr.end();)
		{
			if (*it == num)
				it = arr.erase(it);
			else
				++it;
		}
		return *this;
	}
	Set operator -(T num) { //удаление числа
		Set res = *this;
		for (typename std::vector<T>::iterator it = res.arr.begin(); it != res.arr.end();)
		{
			if (*it == num)
				it = res.arr.erase(it);
			else
				++it;
		}
		return res;
	}
	Set operator -(const Set& second) { //разность множеств
		Set res = *this;
		for (auto i : second.arr) {
			for (typename std::vector<T>::iterator it = res.arr.begin(); it != res.arr.end();)
			{
				if (*it == i)
					it = res.arr.erase(it);
				else
					++it;
			}
		}
		return res;
	}
	


	friend std::ostream& operator << (std::ostream& os, const Set& set)
	{
		for (auto i : set.arr)
		{
			os << i << " ";
		}
		return os;
	}
	auto begin()
	{
		return arr.begin();
	}
	auto end()
	{
		return arr.end();
	}
};