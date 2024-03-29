NAME = fractol
SRCSFOLDER = ./srcs/
SRCS = keyfunctions.c main.c julia.c mandelbrot.c zoom.c color.c draw.c move.c winresize.c
OBJNAME = $(SRCS:.c=.o)
OBJDIR = ./obj/
OBJ = $(addprefix $(OBJDIR),$(OBJNAME))
INCLUDES = fractol.h
GCCFLAG = -Wall -Wextra -Werror

LIBFTFOLDER = ./libft/
LIBFTINCLUDES = $(LIBFTFOLDER)
LIBFTINK = -I $(LIBFTINCLUDES) -L $(LIBFTFOLDER) -lft

MLXLINTMACOS = -I /usr/local/include -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C $(LIBFTFOLDER)
	gcc -g $(GCCFLAG) $(OBJ) $(MLXLINTMACOS) $(LIBFTINK) -o $(NAME)

clean:
	@$(MAKE) -C $(LIBFTFOLDER) clean
	rm -rf $(OBJDIR)
	rm -rf *.o

fclean: clean
	@$(MAKE) -C $(LIBFTFOLDER) fclean
	rm -rf $(OBJDIR)
	rm -rf $(NAME)

$(OBJDIR)%.o:$(SRCSFOLDER)%.c
	@mkdir -p $(OBJDIR)
	@gcc $(GCCFLAG) -I $(INCLUDES) -o $@ -c $<

re:	fclean $(NAME)

makeft:
	@$(MAKE) -C $(LIBFTFOLDER)