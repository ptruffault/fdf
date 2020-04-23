# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ptruffau <ptruffau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/16 11:16:13 by ptruffau          #+#    #+#              #
#    Updated: 2019/04/27 12:00:31 by fstadelw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fdf

SRC		:=	\
	main.c	\
	setup.c \
	parseur.c \
	helpers.c \
	free_struct.c  \
	draw.c \
	brensenham.c \
	event.c
	

SRCDIR	:=	srcs
INCDIR	:=	includes
LIBDIR	:=	lib

BUILDDIR	:=	bin
OBJDIR		:=	$(BUILDDIR)/obj
DBGDIR		:=	$(BUILDDIR)/debug
DEPDIR		:=	$(BUILDDIR)/dep

#### LIBRARY ####
# MinilibX


ifeq ($(UNAME), Darwin)
	MINILIBX		:=	libmlx.a
	MINILIBX_PATH :=  $(LIBDIR)/minilibx-macos
	MINILIBX_LINK :=  -L/usr/local/lib/  -lmlx -framework OpenGL -framework AppKit
	MINILIBX_INC  := -I $(MINILIBX_PATH)-I/usr/local/include
else
	MINILIBX		:=	libmlx_Linux.a
	MINILIBX_PATH :=  $(LIBDIR)/minilibx-linux
	MINILIBX_LINK := -L $(MINILIBX_PATH) -lmlx  -L/usr/include/../lib -lXext -lX11 -lm -lbsd
	MINILIBX_INC  := -I $(MINILIBX_PATH) -I/usr/local/include
endif


# Libft
LIBFT		:=	libft.a
LIBFT_PATH	:= $(LIBDIR)/libft
LIB_LINK	+= -L $(LIBFT_PATH) -lft
LIB_INC		+= -I $(LIBFT_PATH)/includes

#### COMPILER ####
CC			?=	cc

INCFLAG		:=	-I $(INCDIR) $(LIB_INC)

WFLAGS		?=	-Wall -Wextra -Werror -pedantic
CFLAGS		=	$(WFLAGS) $(INCFLAG) $(STDFLAG)

DEPGEN		:=	$(CC)
DEPFLAG		:=	-MM $(INCFLAG)

LD			:=	$(CC)
LDFLAG		=	$(LIB_LINK) -ltermcap
LDFLAG		+=	-Wno-unused-command-line-argument $(WFLAGS)

#############################
#    MAKEFILE VARIABLES     #
#############################
#### FILE STRUCTURE ####
# *LOCA is the list of all subdirectory in a directory
SRCLOCA	:=	$(shell find $(SRCDIR) -type d)
OBJLOCA	:=	$(subst $(SRCDIR), $(OBJDIR), $(SRCLOCA))
DBGLOCA	:=	$(subst $(SRCDIR), $(DBGDIR), $(SRCLOCA))
DEPLOCA	:=	$(subst $(SRCDIR), $(DEPDIR), $(SRCLOCA))

OBJ		:=	$(addprefix $(OBJDIR)/, $(SRC:.c=.o))
DBG		:=	$(addprefix $(DBGDIR)/, $(SRC:.c=.o))
DEP		:=	$(addprefix $(DEPDIR)/, $(SRC:.c=.d))
SRC		:=	$(addprefix $(SRCDIR)/, $(SRC))

COLOR		= 		\033[01;34m
NO_COLOR	= 		\033[00m
OP_COLOR	= 		\033[1;31m
DONE 		= 		$(NO_COLOR)[\033[1;32mOK$(NO_COLOR)]
KO			= 		$(NO_COLOR)[\033[00;31mKO$(NO_COLOR)]


#############################
#           RULES           #
#############################
#### COMPILE ####
all: $(NAME)

$(NAME):	$(OBJ) $(LIBFT_PATH)/$(LIBFT) $(MINILIBX_PATH)/$(MINILIBX)
	@ echo "$(OP_COLOR) building $(NAME)$(NO_COLOR)"
	@ $(LD) -o $(NAME) $(OBJ) $(LDFLAG)
	@ printf "$(DONE)$(OP_COLOR)$(NAME)$(NO_COLOR)\n"


$(OBJDIR)/%.o:	$(SRCDIR)/%.c | $(OBJDIR) $(DEPDIR)
	@ $(CC) -c $< $(CFLAGS) -o $@ \
		&& printf "$(DONE)	: $(COLOR)$<$(NO_COLOR)\n" \
		|| (printf "$(KO)	<-  $(COLOR)$<$(NO_COLOR)\n" ; false)
	@ $(DEPGEN) -c $< $(DEPFLAG) -MQ $@ \
			> $(subst $(SRCDIR), $(DEPDIR), $(<:.c=.d))

$(LIBFT_PATH)/$(LIBFT):
	@ $(MAKE) -C $(LIBFT_PATH) 

$(MINILIBX_PATH)/$(MINILIBX):
	@ $(MAKE) -C $(MINILIBX_PATH) 

# Dir created to store build cache
$(OBJDIR):
	@ mkdir -p $(OBJLOCA)
$(DBGDIR):
	@ mkdir -p $(DBGLOCA)
$(DEPDIR):
	@ mkdir -p $(DEPLOCA)
$(BUILDDIR):
	@ mkdir -p $(BUILDDIR)


sclean:
	@rm -rf $(OBJ) $(NAME)

#### LOCAL (Don't recompile lib) ####
lclean:
	@ rm -r $(BUILDDIR) 1> /dev/null 2> /dev/null \
		&& printf "$(OP_COLOR)[CLR]$(NO_COLOR)	: obj\n" \
		; (exit 0)

lfclean: lclean
	@ rm -Rf *.dSYM 1> /dev/null 2> /dev/null
	@ rm $(NAME) 1> /dev/null 2> /dev/null \
		&& printf "$(OP_COLOR)[CLR]$(NO_COLOR)	: $(NAME)\n" \
		; (exit 0)

#### MANDATORY ####
clean: lclean
	@ $(MAKE) -C $(LIBFT_PATH)  clean
	@ $(MAKE) -C $(MINILIBX_PATH)  clean

fclean:	lfclean
	@ $(MAKE) -C $(LIBFT_PATH)  fclean
	@ $(MAKE) -C $(MINILIBX_PATH)  clean

re:	fclean all

exe: all
	./$(NAME)


save: fclean
	@ git add --all && git commit -m "make save" && git pull
	@ git push


#############################
#          SETTING          #
#############################
# Add rule to phony if they are not based on actual files.
.PHONY: all re
.PHONY: debug rdebug debugclean
.PHONY: warn
.PHONY: lclean lfclean lre val exe fre
.PHONY: sclean clean fclean save
.PHONY: full-test test save val exe fre

#############################
#         DEPENDENCY        #
#############################
# Include all custom dependency rules created in .d's
# the '-' prevent error in case of non existing files
-include $(DEP)
