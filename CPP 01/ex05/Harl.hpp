#ifndef HARL.HPP
# define HARL.HPP

# include <iostream>

class Harl
{
	public:
		Harl();
		Harl(const Harl& other);
		~Harl();
		Harl& operator=(const Harl& other);

		void complain(std::string level);

	private:
	
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
}

#endif
