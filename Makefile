NAME = ft_ls

CPP = clang

CFLAGS = -g3 -fsanitize=address

DIR_LIB = srcs/libft/

HEADER = includes -I $(DIR_LIB)/includes/

SOURCES = main.c \
			parsing.c \
			misc.c \
			sort.c \
			read.c \
			print.c

DIR_O = objs

DIR_S = srcs

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))
OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: $(NAME)

${NAME}: $(DIR_O) $(OBJS)
	make -C $(DIR_LIB)
	${CPP} $(CFLAGS) -o $@ $(OBJS) $(DIR_LIB)/libft.a

$(DIR_O)/%.o: $(DIR_S)/%.c
	$(CPP) $(CFLAGS) -I $(HEADER) -c -o $@ $<

$(DIR_O):
	mkdir -p $(DIR_O)

clean:
	make clean -C $(DIR_LIB)
	rm -rf $(OBJS)

fclean: clean
	make fclean -C $(DIR_LIB)
	rm -rf $(NAME)

re: fclean all

.PHONY : fclean clean
