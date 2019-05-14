#include <iostream>
using namespace std;
namespace itertools {

	template <typename T>
	class powerset {
	private:
		T start;

	public:
		powerset(T s) : start(s){}
		iterator begin() {
			return iterator(start.begin(), start.end());
		}
		iterator end() {
			return iterator(start.end(), start.end());
		}
		
		class iterator {
		private:
			typename T::iterator itr;
			

		public:
			iterator(typename T::iterator itrA) : itr(itrA){}

			auto operator*() {
				string s = "{}";
				return s;
			}

			powerset::iterator& operator++() {
				itr++;
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
		
	};


	}