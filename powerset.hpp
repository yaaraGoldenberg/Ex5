#include <iostream>
using namespace std;
namespace itertools {

	template <typename T>
	class powerset {
	private:
		T start;

	public:
		powerset(T s) : start(s){}

		auto begin() {
			return iterator<decltype(start.begin())>(start.begin());
		}
		auto end() {
			return iterator<decltype(start.end())>(start.end());
		}

		template <typename I>
		class iterator {
		private:
			I itr;

		public:
			iterator(I it) : itr(it){}

			auto operator*() {
				string s = "{}";
				return s;
			}

			iterator<I>& operator++() {
				itr++;
				return *this;
			}
			const iterator operator++(int) {
				iterator tempIt(*this);
				operator++();
				return tempIt;
			}
			bool operator==(const iterator<I>& it) const {
				return itr == it.itr;
			}
			bool operator!=(const iterator<I>& it) const {
				return itr != it.itr;
			}
		};
		

	};


	}