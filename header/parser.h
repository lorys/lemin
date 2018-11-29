#ifndef PARSER_H
# define PARSER_H

# define STATE_ROOMS 1
# define STATE_TUBES 2
# define STATE_START_ROOM 3
# define STATE_END_ROOM 4

void			warn_parsing(char *str, int nline);
void			error_parsing(char *str, int nline);

#endif