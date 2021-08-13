#-fsanitize=address
NAME				=	philo.a
OUTPUT				=	philo

CC					=	@gcc
SH					=	@bash
RM					=	@/bin/rm -rf
FLAGS				=	-Wextra -Wall -Werror -g3 -fsanitize=address

HEADER_DIR			=	includes/
OBJ_DIR				=	obj/
SRC_DIR				=	srcs/
LIB_DIR				=	lib/
VALIDATION_DIR		=	validation/
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

# Mandatory part

SRCS				=	validation.c			initialization.c

LIB					= 	ft_atoll.c				ft_isdigit.c			ft_isspace.c			ft_putchar.c	\
						ft_putstr.c				ft_strlen.c				ft_strevery.c			ft_bzero.c		\
						ft_atoi.c				ft_strcat.c				ft_putchar_fd.c			ft_putstr_fd.c	\
						ft_error.c

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
all:
			@make $(NAME)

# Objects directory
$(OBJ_DIR):
			@echo ${CUT}[${Y}$(OUTPUT)]${X} ${B}Creating: ${R}$(OBJ_DIR)${X}
			@mkdir -p $(OBJ_DIR)/lib

# Normal objects
$(NAME): $(OBJ_DIR) $(OBJS)
			@echo ${B}[-------------------------------------]${X}
			@echo ${B}[------------ ${BOLD}OK${X}${B} - ${BOLD}$(NAME)${X}${B} -----------]${X}
			@echo ${B}[--- 🍴 Let\'s feed philosophers 🍴 ---]${X}
			@echo ${B}[-------------------------------------]${X}

$(OBJS):
			@printf '${CUT}[${Y}$(OUTPUT)]${X} ${B}Compiling: ${X}'
			@make $(OFILE)
			@echo ${B}Crafting: ${R}$(OUTPUT)${X}
			$(CC) main.c $(OBJS) -I $(HEADER_DIR) $(FLAGS) -o $(OUTPUT)
			@echo

$(OFILE):
			@printf ${R}'$(@:%.o=%.c) '${X}
			$(CC) -o $(OBJ_DIR)$@ -I$(HEADER_DIR) -c $(SRC_DIR)$(@:%.o=%.c) $(FLAGS)

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

test:		## Make minishell test
			make re && cd 42_minishell_tester && ./grademe.sh -c

leak:		## Run memory leak for valid cub file.
			@if [ $(shell ./tools/memory_leak.sh $(OUTPUT) -c $$FOO $(LEAKS_FLAGS) && cat valgrind_out | grep "definitely lost:" | cut -d : -f 2 | cut -d b  -f 1 | tr -d " " | tr -d ",") ]; then\
				echo ${BOLD}${UND}${R}🚨 Memory leaks detected${X};\
				if [ $(USER) = "runner" ]; then\
					cat valgrind_out;\
				else\
					echo ${G};cat valgrind_out | grep -A2 "HEAP SUMMARY:" | cut -d = -f 5 | cut -c 2-;\
					echo ${CYAN};cat valgrind_out | grep -A5 "LEAK SUMMARY:" | cut -d = -f 5 | cut -c 2-;\
				fi;\
				exit 1;\
			else\
				echo ☕ ${BOLD}${UND}${G}No memory leaks detected${X} ☕;\
				echo ${CYAN};cat valgrind_out | grep -A4 "HEAP SUMMARY:" | cut -d = -f 5 | cut -c 2-;\
			fi

##@ Helpers
kill:		## Kill all minishells
			@pkill -f $(OUTPUT)

escape:		## Kill all minishells
			./tools/escaper.sh
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
