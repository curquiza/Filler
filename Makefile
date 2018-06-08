NAME = curquiza.filler

CC = gcc -Wall -Wextra -Werror
#CC = gcc -Wall -Wextra -Werror -g -fsanitize=address

C_DIR = srcs
ifeq ($(DEBUG), 1)
  C_DEBUG_FILE = $(C_DIR)/debug_files_others_on.c $(C_DIR)/debug_files_stratmap_on.c
else
  C_DEBUG_FILE = $(C_DIR)/debug_files_off.c
endif
C_OTHER_FILES = $(addprefix $(C_DIR)/, \
				tools_basics.c \
				tools_player.c \
				tools_strat.c \
				tools_read.c \
				first_init.c \
				get_data.c \
				put_piece.c \
				border_check.c \
				border_calc.c \
				border_clear.c \
				heat_calc_main.c \
				heat_calc_sub_fct.c \
				strat_calc.c \
				strat_adjustment.c \
				delete_and_clear.c \
				main.c)
C_FILES = $(C_DEBUG_FILE) $(C_OTHER_FILES)


O_DIR = objs
O_FILES = $(C_FILES:$(C_DIR)/%.c=$(O_DIR)/%.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
H_DIR = includes

LIB = -L$(LIBFT_DIR) -lft
INCL = -I$(H_DIR) -I$(LIBFT_DIR)/includes

################################################################################
#################################### RULES #####################################
################################################################################

all : debug $(NAME)

$(LIBFT) :
	@echo "\033[1;31m-- LIBFT ----------------------\033[0m"
	@make -C $(LIBFT_DIR)
	@printf  "%-45s\033[1;32m%s\033[0m\n" "Make $@" "OK"
	@echo "\033[1;31m-- OBJECTS ---------------------\033[0m"

$(NAME) : $(LIBFT) $(O_FILES)
	@$(CC) $(O_FILES) -o $@ $(LIB)
	@echo "\033[1;31m-- EXEC ------------------------\033[0m"
	@printf  "%-45s\033[1;32m%s\033[0m\n" "Make $@" "OK"

$(O_DIR)/%.o : $(C_DIR)/%.c $(H_DIR)
	@mkdir -p $(O_DIR)
	@$(CC) -o $@ -c $< $(INCL)
	@printf  "%-45s\033[1;32m%s\033[0m\n" "Make $@" "OK"

clean :
	@make clean -C $(LIBFT_DIR)
	@rm -rf $(O_DIR)

fclean : clean
	@make fclean -C $(LIBFT_DIR)
	@rm -rf $(NAME)

re : fclean all

debug:
ifeq ($(DEBUG), 1)
	@rm -rf $(O_DIR)/debug_files_off.o
else
	@rm -rf $(O_DIR)/debug_files_on.o
endif

.PHONY : clean all fclean re
