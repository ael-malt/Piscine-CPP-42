#ifndef COLORS_HPP
# define COLORS_HPP


# define COLOR(id)		"\033[38;5;"#id"m"
# define COLOR_BOLD(id)	"\033[38;5;"#id";01m"

# define BLACK			"\033[30m"
# define RED			"\033[31m"
# define GREEN			"\033[32m"
# define BLUE			"\033[34m"
# define MAGENTA		"\033[35m"
# define CYAN			"\033[36m"
# define WHITE			"\033[37m"
# define LIGHT_BLUE		COLOR(12)
# define LIGHT_CYAN		COLOR(45)
# define ORANGE			COLOR(130)
# define YELLOW			COLOR(142)


# define DEFAULT		"\033[0m"
# define BOLD			"\033[1m"
# define UNDERLINE		"\033[4m"
# define INVERSE		"\033[7m"
# define BOLD_OFF		"\033[21m"
# define UNDERLINE_OFF	"\033[24m"
# define INVERSE_OFF	"\033[27m"

#endif
