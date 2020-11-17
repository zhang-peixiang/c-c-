#pragma once

#include <list>

class bite
{
	template <class T>
	class queue
	{
	public:
		queue()
		{}

		void push(const T& x)
		{
			q.push_back(x);
		}

		void pop()
		{
			if (!empty())
			{
				q.pop_front();
			}
		}

		size_t size()const
		{
			return q.size();
		}

		T& front()
		{
			return q.front();
		}
		const T& front()const
		{
			return q.front();
		}

		T& back()
		{
			return q.back();
		}
		const T& back()const
		{
			return q.back();
		}

		bool empty()
		{
			return q.empty();
		}


	private:
		std::list<T> q;
	};
};