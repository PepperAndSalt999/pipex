CC = gcc

CFLAGS = -Wall -Wextra -Werror

HEADER = ./includes/pipex.h

NAME = pipex

OBJECTS =	./main/pipex.o \
			./parsing/parsing_utils/ft_split.o \
			./parsing/parsing_utils/ft_strjoin.o \
			./parsing/parsing_utils/ft_strncmp.o \
			./parsing/parsing_utils/ft_strlcpy.o \
			./parsing/parsing_utils/ft_strlen.o \
			./parsing/parsing_utils/ft_strlcpy.o \
			./parsing/parsing_utils/ft_memcpy.o \
			./parsing/parsing_utils/ft_strtrim.o \
			./parsing/parsing_utils/ft_strdup.o \
			./parsing/parsing_utils/ft_strchr.o \
			./parsing/parse_input/init_object/init_paths.o \
			./parsing/parse_input/init_object/init_object.o \
			./parsing/parse_input/init_object/init_pipeline.o \
			./parsing/parse_input/fill_object.o \
			./parsing/parse_input/fill_object/fill_fd.o \
			./parsing/parse_input/fill_object/fill_path.o \
			./parsing/parse_input/fill_object/format_arguments.o \
			./interpreting/close_pipeline.o \
			./interpreting/use_pipeline.o \
			./error_handling/error_display.o \
			./error_handling/ft_putstr.o

.PHONY: all fclean clean re

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ 

$(OBJECTS): $(HEADER)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re:	fclean all