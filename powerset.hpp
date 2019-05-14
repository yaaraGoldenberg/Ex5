#include <iostream>
using namespace std;
namespace itertools {

	template <typename T>
	class powerset {
	private:
		T start;

	public:
		powerset(T s) : start(s){}

		/*auto begin() {
			return iterator<decltype(start.begin())>(start.begin(), start.end());
		}
		auto end() {
			return iterator<decltype(start.end())>(start.end(), start.end());
		}
		iterator begin() const {
			return iterator(start.begin(), start.end());
		}

		iterator end() const {
			return iterator(start.begin(), start.end());
		}*/
		int* begin() const { return nullptr; }
		int* end() const { return nullptr; }

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
			bool operator==( iterator& it)  {
				return true;
			}
			bool operator!=( iterator& it)  {
				return true;
			}
		};
		
	};


	}