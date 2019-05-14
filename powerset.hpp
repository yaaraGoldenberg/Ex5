#include <iostream>
using namespace std;
namespace itertools {

	template <typename T>
	class powerset {
	private:
		T start;

	public:
		powerset(T s) : start(s){}
		
		class iterator {
		private:
			typename T::iterator itr1;
			typename T::iterator itr2;

		public:
			iterator(typename T::iterator itrA, typename T::iterator itrB) : itr1(itrA), itr2(itrB){}

			auto operator*() {
				string s = "{}";
				return s;
			}

			powerset::iterator& operator++() {
				itr1++;
				itr2++;
				return *this;
			}
			const iterator operator++(int) {
				/*iterator tempIt(*this);
				operator++();
				return tempIt;*/
			}
			bool operator==(const iterator& it) const {
				return true;
			}
			bool operator!=(const iterator& it) const {
				return true;
			}
		};
		iterator begin() {
			return iterator(start.begin(), start.end());
		}
		iterator end() {
			return iterator(start.end(), start.end());
		}
	};


	}