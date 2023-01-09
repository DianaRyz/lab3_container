#include "Vector.h"
std::ostream& operator<<(std::ostream& out, const std::pair<int, double>& p)
{
	out << "(" << p.first << ", " << p.second << ")";
	return out;
}
int main() {
	try {
		Set<int> set, s;
		set += 5;
		set += 6;
		set += 7;
		set += 5;
		s += 5;
		s += 8;
		s += 2;
		s += 4;
		std::cout << set << std::endl;
		std::cout << s << std::endl;
		std::cout << set + s << std::endl;
		std::cout << set - s << std::endl;
		std::cout << set.intersection(s) << std::endl;
		std::cout << set.check_count(s) << std::endl;
		std::cout << (set == s) << std::endl;
		std::cout << (set != s) << std::endl;
		std::cout << set[0] << std::endl;
		std::cout << std::endl;

		Set<float> fl, f;
		fl += 6.8;
		fl += 7.9;
		fl += 5.7;
		f += 3.4;
		f += 6.8;
		f += 5.7;
		std::cout << fl << std::endl;
		std::cout << f << std::endl;
		std::cout << fl + f << std::endl;
		std::cout << fl - f << std::endl;
		std::cout << fl.intersection(f) << std::endl;
		std::cout << fl.check_count(f) << std::endl;
		std::cout << fl[1] << std::endl;
		std::cout << std::endl;

		Set<std::string> st, stt;
		st += "mom";
		st += "dad";
		stt += "ree";
		stt += "web";
		stt += "mom";
		std::cout << st << std::endl;
		std::cout << stt << std::endl;
		std::cout << st + stt << std::endl;
		std::cout << st - stt << std::endl;
		std::cout << st[1] << std::endl;
		std::cout << std::endl;

		Set<std::pair<int, double>> p, pp;
		p += {1, 3.4};
		p += {2, 4.6};
		p += {5, 7.8};
		pp += {3, 5.5};
		pp += {1, 3.4};
		pp += {5, 7.8};
		pp += {8, 7.8};
		std::cout << p << std::endl;
		std::cout << pp << std::endl;
		std::cout << p + pp << std::endl;
		std::cout << pp - p << std::endl;
		std::cout << p[0] << std::endl;
		std::cout << std::endl;
		
	}
	catch (std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}

}