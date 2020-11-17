#pragma once

#include <vector>

class bite
{
	template <class T>
	class stack
	{
	public:
		// 构造
		stack()
		{}
		
		// 方法
		void push(const T& x)
		{
			_con.push_back(x);
		}

		void pop()
		{
			if (!empty())
			{
				_con.pop_back();
			}
		}

		T& top()
		{
			return _con.back();
		}

		const T& top()const
		{
			return _con.back();
		}

		int size()const
		{
			return _con.size();
		}

		bool empty()const
		{
			return _con.empty();
		}
	private:
		std::vector<T> _con;
	};
};