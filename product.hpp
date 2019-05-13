#include <iostream>
namespace itertools {
	template <typename T1, typename T2>

	class product {
	private:
		T1 frist;
		T2 second;

	public:
		product(T1 start, T2 end) : frist(start), second(end) {
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
			I2 itr2Begin;
			int equal;

		public:
			iterator(I1 itA, I2 itB) : itr1(itA), itr2(itB), equal(1), itr2Begin(itr2){
			}
			iterator<I1, I2>& operator++() {
				if (equal == 1) {
					++itr2;
				}
				else
					++itr1;
				return *this;
			}
			bool operator!=(iterator<I1, I2>  it) {
				if (equal == 1 && !(itr2 != it.itr2)) {
					equal = 2;
					itr2 = itr2Begin;
				}
				else
					equal = 1;
				if (equal == 1) {
					return itr1 != it.itr1;
				}
				else {
					return itr2 != it.itr2;
				}
				

			}
			pair<decltype(*itr1), decltype(*itr2)> operator*() const {
				return pair<decltype(*itr1), decltype(*itr2)>(*itr1, *itr2);
			}
			
		};
	};

}