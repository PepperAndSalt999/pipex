/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpicot <rpicot@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/13 06:22:14 by rpicot        #+#    #+#                 */
/*   Updated: 2022/03/24 02:03:04 by rpicot        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stddef.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/syscall.h>
# include <sys/wait.h>
# include <errno.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

struct	s_cmd
{
	char	**arguments;
	char	*path;
};

struct	s_pipe_config
{
	int	read_from;
	int	write_to;
	int	to_close[2];
};

struct	s_fd_data
{
	struct s_pipe_config	pipeline;
	int						fd;
	int						open_code;
	char					*file;
};

struct	s_input
{
	struct s_fd_data	fd_data[2];
	struct s_cmd		cmd[2];
	mode_t				mode;
};

//Parsing Utilities
size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*ft_strtrim(char const *s1, char const *set);

//Initiate data structure and meta-data
char	**init_paths(char **envp);
void	init_object(struct s_input *input, char **argv);
void	init_pipeline(struct s_fd_data *infile, struct s_fd_data *outfile);

//Fill data structures
void	fill_object(struct s_input *input, char **argv, char **paths);
void	fill_fd(struct s_fd_data *fd_data, mode_t mode);
void	fill_path(struct s_cmd *cmd, char **paths);
int		fill_arguments(struct s_cmd *parsed, char *arg);

//Reformating
void	format_arguments(struct s_cmd *cmd, char *texte);

//Pipeline utilities
void	use_pipeline(struct s_input *input);
void	piping_details(struct s_pipe_config *pipeline, struct s_cmd *cmd);

//closing fd
void	closing_loop(int *to_close);

//Error handling
void	error_display(int code, char *string);
void	process_error(int code, char *string);
void	ft_putstr(char	*string);

#endif