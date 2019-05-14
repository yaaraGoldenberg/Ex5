#include <iostream>
using namespace std;

#include "badkan.hpp"
#include "range.hpp"
#include "chain.hpp"
#include "zip.hpp"
#include "product.hpp"
#include "powerset.hpp"

#define COMMA ,

using namespace itertools;

int main() {

	badkan::TestCase testcase;
	int grade = 0;
	int signal = setjmp(badkan::longjmp_buffer);
	if (signal == 0) {

	////////range///////////
		testcase.setname("range Test");
		
		string ans = "";
		for (int i : range(2, 7)) {
			ans += to_string(i);
		}
		testcase.CHECK_OUTPUT(ans, "23456");

		ans = "";
		for (int i : range(0, 4)) {
			ans += to_string(i);
		}
		testcase.CHECK_OUTPUT(ans, "0123");

		ans = "";
		for (int i : range(7, 9)) {
			ans += to_string(i);
		}
		testcase.CHECK_OUTPUT(ans, "78");

		ans = "";
		for (double i : range(5.1, 9.1)) {
			ans += to_string(i);
		}
		testcase.CHECK_OUTPUT(ans, "5.1 6.1 7.1 8.1");

		ans = "";
		for (double i : range(4.0, 9.0)) {
			ans += to_string(i);
		}
		testcase.CHECK_OUTPUT(ans, "4.0 5.0 6.0 7.0 8.0");

		ans = "";
		for (char i : range('a', 'k')) {
			ans += i;
		}
		testcase.CHECK_OUTPUT(ans, "abcdefghij");

		ans = "";
		for (char i : range('n', 'q')) {
			ans += i;
		}
		testcase.CHECK_OUTPUT(ans, "nop");

		ans = "";
		for (char i : range('s', 't')) {
			ans += i;
		}
		testcase.CHECK_OUTPUT(ans, "s");

		ans = "";
		for (char i : range('C', 'F')) {
			ans += i;
		}
		testcase.CHECK_OUTPUT(ans, "CDE");

		////////chain///////////
		testcase.setname("chain Test");
		ans = "";
		for (int i : chain(range(3, 5), range(5, 9))) {
			ans += to_string(i);
		}
		testcase.CHECK_OUTPUT(ans, "345678");

		ans = "";
		for (int i : chain(range(1, 4), range(7, 9))) {
			ans += to_string(i);
		}
		testcase.CHECK_OUTPUT(ans, "12378");

		ans = "";
		for (int i : chain(range(3, 5), range(5, 9))) {
			ans += to_string(i);
		}
		testcase.CHECK_OUTPUT(ans, "345678");

		ans = "";
		for (double i : chain(range(1.3, 5.3), range(5.3, 9.3))) {
			ans += to_string(i);
		}
		testcase.CHECK_OUTPUT(ans, "1.32.34.35.36.37.38.3");

		ans = "";
		for (double i : chain(range(2.0, 4.0), range(7.0, 9.0))) {
			ans += to_string(i);
		}
		testcase.CHECK_OUTPUT(ans, "2.03.07.08.0");

		ans = "";
		for (int i : chain(range('a', 'd'), range('A', 'D'))) {
			ans += i;
		}
		testcase.CHECK_OUTPUT(ans, "abcABC");

		ans = "";
		for (int i : chain(range('a', 'd'), string("hello"))) {
			ans += i;
		}
		testcase.CHECK_OUTPUT(ans, "abchello");

		ans = "";
		for (int i : chain(string("yaara"), string(" goldenberg"))) {
			ans += i;
		}
		testcase.CHECK_OUTPUT(ans, "yaara goldenberg");

		////////zip///////////
		testcase.setname("zip Test");
		ans = "";
		ostringstream s;

		for (auto pair : zip(range(1, 4), string("cpp"))) {
			s << pair << " ";
		}
		ans = s.str();
		testcase.CHECK_OUTPUT(ans, "1,c 2,p 3,p ");

		ans = "";
		s.str("");
		for (auto pair : zip(range(9, 13), string("ABCD"))) {
			s << pair << " ";
		}
		ans = s.str();
		testcase.CHECK_OUTPUT(ans, "9,A 10,B 11,C 12,D ");

		ans = "";
		s.str("");
		for (auto pair : zip(range(0, 5), range(5, 10))) {
			s << pair << " ";
		}
		ans = s.str();
		testcase.CHECK_OUTPUT(ans, "0,5 1,6 2,7 3,8 4,9 ");

		ans = "";
		s.str("");
		for (auto pair : zip(zip(range(1, 4), string("xyz")), zip(string("abc"), range(6, 9)))) {
			s << pair << "  ";
		}
		ans = s.str();
		testcase.CHECK_OUTPUT(ans, "1,x,a,6  2,y,b,7  3,z,c,8  ");
		
		////////product///////////
		testcase.setname("product Test");
		ans = "";
		s.str("");
		for (auto pair : product(range(3,6), range('A', 'D'))) {
			s << pair ;
		}
		ans = s.str();
		testcase.CHECK_OUTPUT(ans, "3,A  3,B  3,C  2,A  2,B  2,C  3,A  3,B  3,C  ");

		ans = "";
		s.str("");
		for (auto pair : product(range(3.1, 5.1), string("abc"))) {
			s << pair;
		}
		ans = s.str();
		testcase.CHECK_OUTPUT(ans, "3.1,a 3.1,b 3.1,c 4.1,a 4.1,b 4.1,c");

		ans = "";
		s.str("");
		for (auto pair : product(range(2, 5), range(6, 8))) {
			s << pair;
		}
		ans = s.str();
		testcase.CHECK_OUTPUT(ans, "2,6 2,7 3,6 3,7 4,6 4,7");
		
		////////powerset///////////
		testcase.setname("powerset Test");
		ans = "";
		s.str("");
		for (auto subset : powerset(range(2, 5))) {
			s << subset;
		}
		ans = s.str();
		testcase.CHECK_OUTPUT(ans, "{}{2}{3}{2,3}{4}{2,4}{3,4}{2,3,4}");

		ans = "";
		s.str("");
		for (auto subset : powerset(chain(range('a', 'c'), range('x', 'z') ) )) {
			s << subset;
		}
		ans = s.str();
		testcase.CHECK_OUTPUT(ans, "{}{a}{b}{a,b}{x}{a,x}{b,x}{a,b,x}{y}{a,y}{b,y}{a,b,y}{x,y}{a,x,y}{b,x,y}{a,b,x,y}");

		ans = "";
		s.str("");
		for (auto subset : powerset(chain(range(4,6), range(8,9) ) ) ) {
			s << subset;
		}
		ans = s.str();
		testcase.CHECK_OUTPUT(ans, "{}{4}{5}{4,5}{8}{4,8}{5,8}{4,5,8}");

		ans = "";
		s.str("");
		for (auto subset : powerset(chain(range(1.0, 2.0), range(3.0, 5.0)))) {
			s << subset;
		}
		ans = s.str();
		testcase.CHECK_OUTPUT(ans, "{}{1.0}{3.0}{1.0,3.0}{4.0}{1.0,4.0}{3.0,4.0}{1.0,3.0,4.0}");
		
	grade = testcase.grade();
}
	else {
	testcase.print_signal(signal);
	grade = 0;
	}
	cout << "Your grade is: " << grade << endl;
	return 0;
}//End of main.