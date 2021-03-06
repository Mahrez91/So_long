/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 18:17:19 by idhiba            #+#    #+#             */
/*   Updated: 2019/11/17 18:17:21 by idhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <fcntl.h>
# include <sys/uio.h>

typedef struct s_vars{
	int		nb_move;
	char	**map;
	void	*img_map;
	void	*img_perso;
	void	*img_collect;
	void	*img_exit;
	void	*img_floor;
	void	*img_ennemy;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*mlx;
	void	*win;
	int		collectible;
	int		appears;
	int		exit;
}				t_vars;

int			get_next_line(int fd, char **line);
char		*ft_strjoin_free(char *s1, char *s2, int f);
char		*ft_strchr(char *s, int c);
void		*ft_calloc(int count, int size);
char		*ft_substr(char *s, int start, int len);
char		*ft_strdup(char *s);
int			ft_strlen(char *s);
int			ft_count(char *s1, char *s2);
int			read_line(int fd, char **dest);
char		*ft_no_leaks(char *dest, int i);
char		*ft_strcat(char *dest, char *src);
char		**ft_split(char *s, char c);
int			key_hook(int keycode, t_vars *vars);
int			mouse_hook(t_vars *vars);
void		error_close_map_exit(char **str);
void		error_close_map_collectible(char **str);
void		error_close_map_appear(char **str);
void		error_close_map(char **str);
void		aff_map( t_vars vars, int side);
void		aff_perso( t_vars vars, int side);
void		aff_collect( t_vars vars, int side);
void		aff_exit(t_vars vars, int side);
void		*mlx_init(void);
t_vars		open_window(t_vars vars, int side);
t_vars		load_image(int s, t_vars vars);
void		aff_game(t_vars vars, int side);
void		verif_first_end_wall(char **str, int last_line, int lengh);
void		check_lengh_line(char **str, int count_line);
t_vars		wall_map(t_vars vars, int count_ligne);
t_vars		inside_map(t_vars vars, int count_line);
t_vars		ft_map_condition(t_vars vars);
t_vars		parcing(int fd);
t_vars		open_game(t_vars vars);
void		aff_floor(t_vars vars, int side);
void		ft_check_access(t_vars vars);
t_vars		check_character_inside(t_vars vars, int count, int i);
t_vars		new_map_up(t_vars vars, int count_line, int count_charac);
t_vars		new_map_right(t_vars vars, int count_line, int count_charac);
t_vars		new_map_left(t_vars vars, int count_line, int count_charac);
t_vars		new_map_down(t_vars vars, int count_line, int count_charac);
void		free_str(char **str);
void		free_map(t_vars vars);
void		*mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title);
int			mlx_clear_window(void *mlx_ptr, void *win_ptr);
int			mlx_pixel_put(void *mlx_ptr, void *win_ptr,
				int x, int y, int color);
void		*mlx_new_image(void *mlx_ptr, int width, int height);
char		*mlx_get_vars_addr(void *img_ptr, int *bits_per_pixel,
				int *size_line, int *endian);
int			mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr,
				int x, int y);
int			mlx_get_color_value(void *mlx_ptr, int color);
int			mlx_key_hook(void *win_ptr, int (*funct_ptr)(), void *param);
int			mlx_loop(void *mlx_ptr);
void		mlx_set_font(void *mlx_ptr, void *win_ptr, char *name);
void		*mlx_xpm_to_image(void *mlx_ptr, char **xpm_data,
				int *width, int *height);
void		*mlx_xpm_file_to_image(void *mlx_ptr, char *filename,
				   int *width, int *height);
int			mlx_destroy_window(void *mlx_ptr, void *win_ptr);
int			mlx_destroy_image(void *mlx_ptr, void *img_ptr);
int			mlx_destroy_display(void *mlx_ptr);
int			mlx_hook(void *win_ptr, int x_event, int x_mask,
				 int (*funct)(), void *param);
int			mlx_do_key_autorepeatoff(void *mlx_ptr);
int			mlx_do_key_autorepeaton(void *mlx_ptr);
int			mlx_do_sync(void *mlx_ptr);
int			mlx_mouse_get_pos(void *mlx_ptr, void *win_ptr, int *x, int *y);
int			mlx_mouse_move(void *mlx_ptr, void *win_ptr, int x, int y);
int			mlx_mouse_hide(void *mlx_ptr, void *win_ptr);
int			mlx_mouse_show(void *mlx_ptr, void *win_ptr);
int			mlx_get_screen_size(void *mlx_ptr, int *sizex, int *sizey);

#endif
