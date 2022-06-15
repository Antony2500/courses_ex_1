#ifndef TX_H
#define TX_H

#include<string>

namespace l1 {
	
	class Txt
	{
	private:
		size_t m_arr_size = 0;
		std::string* m_arr = nullptr;

	public:
		Txt();

		Txt(const std::string &path);

		size_t size() const;

		Txt(const Txt& txt);

		Txt& operator=(const Txt &txt);

		Txt(Txt&& txt);

		Txt& operator=(Txt&& txt);

		~Txt();
	};

}




#endif
