#include <iostream>
using namespace std;

namespace itertools {
	template <typename T1, typename T2>

	class zip {
	private:
		T1 frist;
		T2 second;

	public:
		zip(T1 start, T2 end) : frist(start), second(end) {
		}
		auto begin() {
			return iterator<decltype(frist.begin()), decltype(second.begin())>(frist.begin(), second.begin());
		}
		auto end() {
			return iterator<decltype(frist.end()), decltype(second.end())>(frist.end(), second.end());
		}

		template <typename I1, typename I2>
		class iterator {
		private:
			I1 itr1;
			I2 itr2;

		public:
			iterator(I1 itA, I2 itB) : itr1(itA), itr2(itB) {}

			iterator<I1, I2>& operator++() {
				++itr1;
				++itr2;
				return *this;
			}

			bool operator!=(iterator<I1, I2>  it) {
				return (itr1 != it.itr1 && itr2 != it.itr2);
				
			}

			pair<decltype(*itr1), decltype(*itr2)> operator*() const {
				return pair<decltype(*itr1), decltype(*itr2)>(*itr1, *itr2);
			}
		

		};

	};

	template <typename X1, typename X2>
	ostream &operator<<(ostream &os, const pair<X1, X2> &x) {
		os << x.first << ',' << x.second;
		return os;
	}
}
