#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include "../lib/mlx/mlx.h"
# include "../lib/libft/libft.h"

typedef struct s_parse
{
    int		fd;
	char	*file;
    char	**map;
	int		player;
	int		exit;
	int		collect;
	int 	lines;
}	t_parse;

int		check_map(t_parse *parse);
int		parsing(int argc, char **argv, t_parse *parse);
int		check_suffix(char *str);
int		check_exist(char *str, t_parse *parse);
int		check_map_rectangle(t_parse *parse);
int		check_map_edges(t_parse *parse);
int		check_map_content(t_parse *parse);
int		check_map_elements(t_parse *parse);
int		parse_map(t_parse *parse);
int		map_lines(t_parse *parse);

#endif