#include "iostream"
namespace itertools {
	template<typename T>
	class range {
	private:
		T from;
		T to;
	public:
		range(T start, T end) : from(start), to(end){}


		class iterator {
		//private:
			

		public:
			T itr;
			iterator(T it) : itr(it){}

			T operator*() const {
				return itr;
			}

			iterator &operator++() {
				itr++;
				return *this;
			}

			const iterator operator++(int) {
				iterator tempIt(*this);
				operator++();
				return tempIt;
			}

			bool operator==(const iterator &it) const {
				return itr == it.itr;
			}

			bool operator!=(const iterator &it) const {
				return itr != it.itr;
			}
		};

		iterator begin() const {
			return iterator(from);
		}

		iterator end() const {
			return iterator(to);
		}
	};
}