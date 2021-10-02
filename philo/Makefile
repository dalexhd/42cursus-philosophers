#-fsanitize=address
NAME				=	philo.a
OUTPUT				=	philo

CC					=	@gcc
SH					=	@bash
RM					=	@/bin/rm -rf
FLAGS				=	-Wextra -Wall -Werror -pthread -g3 -fsanitize=address

HEADER_DIR			=	includes/
OBJ_DIR				=	obj/
OBJ_LIB_DIR			=	obj/lib/
SRC_DIR				=	srcs/
LIB_DIR				=	lib/
ifeq ($(shell whoami), runner)
	COVID_NORM		=	ruby ~/.norminette/norminette.rb
else
	COVID_NORM		=	ruby -e STDOUT.sync=true -e 'load($$0=ARGV.shift)' ~/.norminette/norminette.rb
endif
RESULT				=	$(shell cat output.txt)
AUTHOR				=	$(shell cat author)
LAST_COMMIT_DATE	=	$(shell git log -1 --date=format:"%m/%d/%Y" --format="%ad   [%cr]")
LAST_COMMIT_HASH	=	$(shell git log -1 --date=format:"%m/%d/%y %T" --format="%H")
LAST_COMMIT_MESSAGE	=	$(shell git log -1 --date=format:"%m/%d/%y %T" --format=\'%s\')
OS					=	$(shell uname)
USER				=	$(shell whoami)
ARCH				=	$(shell uname -m | sed 's/x86_//;s/i[3-6]86/32/')
VER					=	$(shell lsb_release -sr)
COUNTER				= 	0
COLUMNS				=	$(shell stty size | cut -d" " -f2)

# Mandatory part

SRCS				=	validation.c			initialization.c		memory.c				logging.c	\
						runtime.c				utils.c

LIB					= 	ft_atoll.c				ft_isdigit.c			ft_isspace.c			ft_strlen.c	\
						ft_strevery.c			ft_bzero.c				ft_atoi.c				ft_error.c	\
						ft_strcmp.c				ft_putchar_fd.c			ft_putstr_fd.c			ft_calloc.c	\
						ft_usleep.c

SOURCES				=	$(SRCS) $(addprefix $(LIB_DIR),$(LIB))

# Bonus part

LEAKS_FLAGS			=	--tool=memcheck --leak-check=full --leak-resolution=high --show-leak-kinds=all --track-origins=yes


LEAKS_EXE			=	./tools/memory_leak.sh ${OUTPUT} ${LEAKS_FLAGS}
NORME				=	$(addsuffix *.h,$(HEADER_DIR)) \
						$(addprefix $(SRC_DIR),$(SOURCES)) \
						$(addsuffix **/*.h,$(LIBFT_DIR)) \
						$(addsuffix **/*.c,$(LIBFT_DIR)) \
						$(addsuffix **/**/*.c,$(LIBFT_DIR))


# Mandatory Objects
OFILE				=	$(SOURCES:%.c=%.o)
OBJS				=	$(addprefix $(OBJ_DIR), $(OFILE))

# Functions
disp_indent			=	for I in `seq 1 $(MAKELEVEL)`; do \
						test "$(MAKELEVEL)" '!=' '0' && printf "\t"; \
						done

exec_color			=	$(call disp_indent); \
						echo $(1)$(2) $(3) $(4) $(5) $(6) $(7) $(8) $(9) $(10)"\033[31m"; \
						$(2) $(3) $(4) $(5) $(6) $(7) $(8) $(9) $(10)

disp_title			=	$(call disp_indent); \
						echo "$(2)[  $(1) \#$(MAKELEVEL)  ]\033[0m"


################
##   COLORS   ##
################

Y					=	$(shell printf "\033[33m")
R					=	$(shell printf "\033[31m")
G					=	$(shell printf "\033[32m")
CYAN				=	$(shell printf "\033[36m")
B					=	$(shell printf "\033[34m")
X					=	$(shell printf "\033[0m")
UP					=	$(shell printf "\033[A")
CUT					=	$(shell printf "\033[K")
W					=	$(shell printf "\033[37m")
UND					=	$(shell printf "\033[4m")
BLINK				=	$(shell printf "\033[5m")
BOLD				=	$(shell printf "\033[1m")
UP					=	$(shell printf "\033[5A")
NORM_COLOR_T		=	$(shell printf "\033[0;1;141m")
NORM_COLOR			=	$(shell printf "\033[0;38;5;153m")
NORM_COLOR_WAR		=	$(shell printf "\033[38;5;214m")
NORM_COLOR_ERR		=	$(shell printf "\033[0;41m")
BG_X				=	$(shell printf "\033[0;39m")
TAB					=	$(shell printf "\t")

# Make all files.
all:	$(NAME)

# Objects directory
$(OBJ_DIR):
			@echo ${CUT}[${Y}$(OUTPUT)]${X} ${B}Creating: ${R}$(OBJ_DIR)${X}
			@mkdir -p $(OBJ_DIR)

$(OBJ_LIB_DIR):
			@echo ${CUT}[${Y}$(OUTPUT)]${X} ${B}Creating: ${R}$(OBJ_LIB_DIR)${X}
			@mkdir -p $(OBJ_DIR)/lib

# Normal objects
$(NAME): $(OBJ_LIB_DIR) $(OBJ_DIR) $(OBJS)
			@echo
			$(CC) main.c $(OBJS) -I $(HEADER_DIR) $(FLAGS) -o $(OUTPUT)
			@echo ${B}[-------------------------------------]${X}
			@echo ${B}[------------ ${BOLD}OK${X}${B} - ${BOLD}$(NAME)${X}${B} -----------]${X}
			@echo ${B}[--- 🍴 Let\'s feed philosophers 🍴 ---]${X}
			@echo ${B}[-------------------------------------]${X}

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
			$(eval COUNTER=$(shell echo $$(($(COUNTER)+1))))
			$(eval SIZE=$(shell wc -c < $<))
			$(eval STR=$(shell echo ${CUT}[${Y}$(OUTPUT)]${X} ${B}Compiling: ${X}$(SIZE) Bytes${R} $<${X}))
			$(eval COMPILED=$(shell echo '$(COUNTER) files compiled'))
			$(eval LEN=$(shell echo $$(($(COLUMNS)-$(shell echo \'$(STR)$(COMPILED)\' | wc -m)))))
			@$(SH) -c "printf '\r$(STR)%$(LEN)s $(COMPILED) $(shell seq -s. $(COUNTER)|tr -d '[:digit:]')\0'"
			$(CC) -c $(FLAGS) -I$(HEADER_DIR) $< -o $@

##@ Cleaning
clean:		## Clean all objects.
			$(RM) $(OBJ_DIR)


fclean:		## Remove all objects and executables.
			$(RM) $(OUTPUT)
			$(RM) $(OBJ_DIR)
			$(RM) $(NAME)
			@echo ${CUT}[${Y}$(OUTPUT)]${X} [Garbage collector:${Y} ${OUTPUT} $(NAME) *.o${X}][${G}OK!${X}]

##@ Checks
normi:		## Check norminette.
			@$(call disp_title,Checking norminette,$(NORM_COLOR_T))
			@if [ ${uname} = "Linux" ]; then\
				norminette $(NORME) | sed "s/Norme/$(NORM_COLOR_T)➤  $(NORM_COLOR)Norme/g;s/Warning/\t $(NORM_COLOR_WAR)Warning/g;s/Error/\t🚨 $(NORM_COLOR_ERR)Error/gm;s/$$/$(X)/g"; \
			else\
				norminette $(NORME) | sed "s/Norme/$(NORM_COLOR_T)➤  $(NORM_COLOR)Norme/g;s/Warning/\t $(NORM_COLOR_WAR)Warning/g;s/Error:/$(TAB)🚨 $(NORM_COLOR_ERR)Error:/g;s/$$/$(X)/g"; \
			fi

##@ Compilation

re:			## Call fclean => all
			@make clean
			@make all

##@ Testing

test:		## Make test
			cd .. && ./philosophers_test/run -p 1

##@ Help
help:		## View all available commands.
			$(shell $(TARGETS_EXE))
			@echo ${CYAN} Proyecto: ${UND}${BOLD}$(OUTPUT)${CYAN}${X}${CYAN}${UND}\\t\\t\\t\\t\\tAuthor: $(AUTHOR)${X}
			@echo ${CYAN} Last commit:${X}
			@echo ${CYAN} \\tDate: $(LAST_COMMIT_DATE)
			@echo ${CYAN} \\tHash: $(LAST_COMMIT_HASH)${X}
			@echo ${CYAN} \\tMessage: $(LAST_COMMIT_MESSAGE)${X}
			@echo ${CYAN}--------------------------------------------------------------------------
			@echo ${CYAN}Available commands: "\\t\\t\\t\\t(${G}Usage:${X} make ${CYAN}<target>${X})"
			@awk 'BEGIN {FS = ":.*##"; printf ""} /^[a-zA-Z_-]+:.*?##/ { printf "  ${CYAN}%-25s${X} %s\n", $$1, $$2 } /^##@/ { printf "\n${UND}${BOLD}%s${X}\n", substr($$0, 5) } ' $(MAKEFILE_LIST)
			@echo ${CYAN}--------------------------------------------------------------------------

.PHONY:		all clean flclean re test
