#include <iostream>

namespace itertools {

	template <typename T1, typename T2>
	class chain {

	private:
		T1 itr1;
		T2 itr2;

	public:
		chain(T1 start, T2 end) : itr1(start), itr2(end) {
		}

		auto begin() {
			return iterator<decltype(itr1.begin()), decltype(itr2.begin())>(itr1.begin(), itr2.begin());
		}

		auto end() {
			return iterator<decltype(itr1.end()), decltype(itr2.end())>(itr1.end(), itr2.end());
		}
		template <typename C1, typename C2>
		class iterator {

		private:
			C1 it1;
			C2 it2;
			int equal;
		

		public:
			iterator(C1 itA, C2 itB) : it1(itA), it2(itB), equal(1) {
			}

			iterator<C1, C2>& operator++() {
				if (equal == 1)
					++it1;
				else
					++it2;
				return *this;
			}
			decltype(*it1) operator*() const {

				if (equal == 1)
					return *it1;
				else
					return *it2;
			}
			bool operator!=(iterator<C1, C2>  it) {
				if (equal == 1 && !(it1 != it.it1)) {
					equal = 2;
				}
				if (equal == 1) {
					return it1 != it.it1;
				}
				else {
					return it2 != it.it2;
				}
			}
			const iterator operator++(int) {

			}
			bool operator==(iterator itr) const {

			}
		};

	};
}