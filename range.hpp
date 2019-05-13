
#include "iostream"
namespace itertools {

	template <typename T>
	class range {
	public:
		T from;
		T to;

		range(T f, T t) : from(f), to(t) {}
		range(range const &other) : from(other.from), to(other.to) {}
		

		class iterator {//http://www.cplusplus.com/reference/iterator/iterator/
		private:
			T *ptrIt;

		public:

			iterator(T* itr) :ptrIt(itr) {}
			//iterator(const iterator& itr) : ptrIt(itr.ptrIt) {}

			iterator& operator++() {
				(*ptrIt)++;
				return *this;
			}

			const iterator operator++(int) {
				iterator tempIt(*this);
				operator++();
				return tempIt;
			}

			T& operator*() const{
				return *ptrIt;
			}

			bool operator==(const iterator& itr) const {
				return *ptrIt == *itr.ptrIt;
			}

			bool operator!=(const iterator& itr) const {
				return *ptrIt != *itr.ptrIt;
			}
		};

		iterator begin() {
			return iterator{ &from };
		}

		iterator end() {
			return iterator{ &to };
		}
	};

}
