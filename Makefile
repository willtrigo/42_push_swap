# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/25 02:06:14 by dande-je          #+#    #+#              #
#    Updated: 2024/08/07 06:03:06 by dande-je         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#******************************************************************************#
#                                REQUIREMENTS                                  #
#******************************************************************************#

LIBFT_VERSION                   := 3.2.1

#******************************************************************************#
#                                   COLOR                                      #
#******************************************************************************#

RED                             := \033[0;31m
GREEN                           := \033[0;32m
YELLOW                          := \033[0;33m
PURPLE                          := \033[0;35m
CYAN                            := \033[0;36m
RESET                           := \033[0m

#******************************************************************************#
#                                   PATH                                       #
#******************************************************************************#

SRCS_DIR                        := src/
SRCS_INTERNAL_DIR               := src/internal/
SRCS_PARSE_DIR                  := $(SRCS_INTERNAL_DIR)parse/
SRCS_HANDLE_DIR                 := $(SRCS_INTERNAL_DIR)handle/
SRCS_SORT_DIR                   := $(SRCS_INTERNAL_DIR)sort/
SRCS_FOUR_DIR                   := $(SRCS_SORT_DIR)four/
SRCS_ALL_DIR                    := $(SRCS_SORT_DIR)all/
SRCS_STACK_DIR                  := $(SRCS_HANDLE_DIR)stack/
SRCS_OPERATION_DIR              := $(SRCS_STACK_DIR)operation/
SRCS_STATE_DIR                  := $(SRCS_STACK_DIR)state/
SRCS_BONUS_DIR                  := bonus/
SRCS_INTERNAL_BONUS_DIR         := bonus/internal/
SRCS_PARSE_BONUS_DIR            := $(SRCS_INTERNAL_BONUS_DIR)parse/
SRCS_HANDLE_BONUS_DIR           := $(SRCS_INTERNAL_BONUS_DIR)handle/
SRCS_CHECKER_BONUS_DIR          := $(SRCS_INTERNAL_BONUS_DIR)check/
SRCS_STACK_BONUS_DIR            := $(SRCS_HANDLE_BONUS_DIR)stack/
SRCS_OPERATION_BONUS_DIR        := $(SRCS_STACK_BONUS_DIR)operation/
SRCS_STATE_BONUS_DIR            := $(SRCS_STACK_BONUS_DIR)state/
INCS                            := src/ bonus/ lib/42_libft/include/
BUILD_DIR                       := build/
LIBFT_DIR                       := lib/42_libft/

#******************************************************************************#
#                                  COMMANDS                                    #
#******************************************************************************#

RM                              := rm -rf
MKDIR                           := mkdir -p
MAKEFLAGS                       += --no-print-directory
SLEEP                           := sleep 0.01

#******************************************************************************#
#                                   FILES                                      #
#******************************************************************************#

LIBFT                           = $(addprefix $(LIBFT_DIR), libft.a)
LIBS                            := ./lib/42_libft/libft.a

NAME                            = push_swap
NAME_BONUS                      = checker

SRCS_FILES                      += $(addprefix $(SRCS_DIR), main.c)
SRCS_FILES                      += $(addprefix $(SRCS_STACK_DIR), ft_build.c \
								   ft_destroy.c \
								   ft_normalize.c \
								   ft_stack.c)
SRCS_FILES                      += $(addprefix $(SRCS_STATE_DIR), ft_peek.c \
								   ft_state.c)
SRCS_FILES                      += $(addprefix $(SRCS_OPERATION_DIR), ft_pop.c \
								   ft_push.c \
								   ft_rotate.c \
								   ft_swap.c)
SRCS_FILES                      += $(addprefix $(SRCS_PARSE_DIR), ft_parse_arguments.c)
SRCS_FILES                      += $(addprefix $(SRCS_SORT_DIR), ft_sort.c \
								   ft_three.c)
SRCS_FILES                      += $(addprefix $(SRCS_ALL_DIR), ft_all.c \
								   ft_cost.c \
								   ft_return_nbrs.c)
SRCS_FILES                      += $(addprefix $(SRCS_FOUR_DIR), ft_four.c \
								   ft_targets.c)
SRCS_FILES                      += $(addprefix $(SRCS_HANDLE_DIR), ft_output.c)

SRCS_BONUS_FILES                += $(addprefix $(SRCS_BONUS_DIR), main.c)
SRCS_BONUS_FILES                += $(addprefix $(SRCS_STACK_BONUS_DIR), ft_build_bonus.c \
								   ft_destroy_bonus.c \
								   ft_normalize_bonus.c \
								   ft_stack_bonus.c)
SRCS_BONUS_FILES                += $(addprefix $(SRCS_STATE_BONUS_DIR), ft_peek_bonus.c \
								   ft_state_bonus.c)
SRCS_BONUS_FILES                += $(addprefix $(SRCS_OPERATION_BONUS_DIR), ft_pop_bonus.c \
								   ft_push_bonus.c \
								   ft_rotate_bonus.c \
								   ft_swap_bonus.c)
SRCS_BONUS_FILES                += $(addprefix $(SRCS_PARSE_BONUS_DIR), ft_parse_arguments_bonus.c)
SRCS_BONUS_FILES                += $(addprefix $(SRCS_CHECKER_BONUS_DIR), ft_checker_bonus.c)
SRCS_BONUS_FILES                += $(addprefix $(SRCS_HANDLE_BONUS_DIR), ft_output_bonus.c)

OBJS                            += $(SRCS_FILES:%.c=$(BUILD_DIR)%.o)
OBJS_BONUS                      += $(SRCS_BONUS_FILES:%.c=$(BUILD_DIR)%.o)

DEPS                            += $(OBJS:.o=.d)

NAME_TEST                       := run_test.sh

#******************************************************************************#
#                               OUTPUTS MESSAGES                               #
#******************************************************************************#

COUNT                           = 0
OBJS_COUNT                      = 0
MATH                            = 0
CLEAN_MESSAGE                   := Push swap objects deleted
FCLEAN_MESSAGE                  := Push swap deleted
EXE_MESSAGE                     = $(RESET)[100%%] $(GREEN)Built target push_swap
EXE_BONUS_MESSAGE               = [100%%] $(GREEN)Built target checker
COMP_MESSAGE                    = Building C object
COMP_BONUS_MESSAGE              = $(CYAN)[BONUS]$(RESET) $(YELLOW)Building C object
TEST_INIT_MESSAGE               = Running tests
TEST_FINISHED_MESSAGE           = Completed tests
SUCESS_MESSAGE                  = $(GREEN)Success: $(RESET)
FAIL_MESSAGE                    = $(RED)Fail: $(RESET)

#******************************************************************************#
#                               COMPILATION                                    #
#******************************************************************************#

CC                             := cc
CFLAGS                         = -Wall -Wextra -Werror -Ofast
CPPFLAGS                       := $(addprefix -I,$(INCS)) -MMD -MP
DFLAGS                         := -Wall -Wextra -Werror -g3
LFLAGS                         := -march=native
LDFLAGS                        := $(addprefix -L,$(dir $(LIBS)))
LDLIBS                         := -lft -ldl
COMPILE_OBJS                   = $(CC) $(CFLAGS) $(LFLAGS) $(CPPFLAGS) -c $< -o $@
COMPILE_EXE                    = $(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) $(LDLIBS) -o $(NAME)

#******************************************************************************#
#                                   DEFINE                                     #
#******************************************************************************#

ifdef WITH_DEBUG
	CFLAGS                     = $(DFLAGS)
endif

ifdef WITH_BONUS
	NAME                       = $(NAME_BONUS)
	OBJS                       = $(OBJS_BONUS)
	COMP_MESSAGE               = $(COMP_BONUS_MESSAGE)
	EXE_MESSAGE                = $(EXE_BONUS_MESSAGE)
endif

#******************************************************************************#
#                                  FUNCTION                                    #
#******************************************************************************#

define create_dir
	$(MKDIR) $(dir $@)
endef

define submodule_update_libft
	printf "$(PURPLE)Building library Libft\n$(RESET)"
	git submodule update --init --remote >/dev/null 2>&1 || true
	git submodule foreach -q \
		'branch="$(git config -f $toplevel/.gitmodules submodule.42_libft)"; \
		git pull origin main; \
		git fetch; \
		git checkout v$(LIBFT_VERSION)' \
		>/dev/null 2>&1 || true
	$(SLEEP)
	$(MAKE) -C $(LIBFT_DIR)
endef

define comp_objs
	$(eval COUNT=$(shell expr $(COUNT) + 1))
	$(COMPILE_OBJS)
	$(eval MATH=$(shell expr "$(COUNT)" \* 100 \/ "$(OBJS_COUNT)"))
	$(eval MATH=$(shell if [ $(COUNT) -lt 1 ]; then echo $(shell expr "$(MATH)" + 100) ; else echo $(MATH) ; fi))
	printf "[%3d%%] $(YELLOW)$(COMP_MESSAGE) $@ \r$(RESET)\n" $$(echo $(MATH))
endef

define bonus
	$(MAKE) WITH_BONUS=TRUE
endef

define comp_exe
	$(COMPILE_EXE)
	$(SLEEP)
	printf "$(EXE_MESSAGE)\n$(RESET)"
endef

define clean
	$(RM) $(BUILD_DIR)
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(SLEEP)
	printf "$(RED)$(CLEAN_MESSAGE)$(RESET)\n"
endef

define fclean
	$(RM) $(NAME) $(NAME_BONUS)
	$(SLEEP)
	printf "$(RED)$(FCLEAN_MESSAGE)$(RESET)\n"
endef

define debug
	$(call clean)
	$(call fclean)
	$(MAKE) WITH_DEBUG=TRUE
endef

define reset_count
	$(eval COUNT=$(1))
	$(eval OBJS_COUNT=$(words $(SRCS_FILES)))
endef

define test
	printf "$(YELLOW)$(TEST_INIT_MESSAGE)$(RESET)\n"
	./$(NAME_TEST) >/dev/null 2>&1 || true 
	printf "$(CYAN)$(TEST_FINISHED_MESSAGE)$(RESET)\n"
endef

define test_output
	printf "$(SUCESS_MESSAGE)"
	$(eval FAIL=$(shell cat test-out.txt| grep "KO" | wc -l))
	$(eval TOTAL_TEST=$(shell cat test-out.txt | grep "command" | wc -l))
	$(eval MATH=$(shell expr "$(TOTAL_TEST)" \- "$(FAIL)"))
	printf "$(MATH) / $(shell cat test-out.txt | grep "command" | wc -l)\n"
	printf "$(GREEN)$(shell cat test-out.txt | grep -E 'OK|er:  /')"
	if [ "$(FAIL)" -gt 0 ]; then \
		printf "$(FAIL_MESSAGE)"; \
		printf "$(FAIL) / $(TOTAL_TEST)\n"; \
		printf "$(RED)$(shell cat test-out.txt | grep "KO")"; \
	else \
		printf "All tests passed!\n"; \
	fi
endef

#******************************************************************************#
#                                   TARGETS                                    #
#******************************************************************************#

all: $(NAME)

$(BUILD_DIR)%.o: %.c
	$(call create_dir)
	$(call comp_objs)

$(NAME): $(LIBFT) $(call reset_count, -$(words $(OBJS))) $(OBJS)
	$(call comp_exe)

$(LIBFT):
	$(call submodule_update_libft)

bonus:
	$(call bonus)

clean:
	$(call clean)

fclean: clean
	$(call fclean)

re: fclean all

debug:
	$(call debug)

test: debug test_run | test_output

test_run:
	$(call test)

test_output:
	$(call test_output)

.PHONY: all clean fclean re debug test test_run test_output bonus
.DEFAULT_GOAL := all
.SILENT:

-include $(DEPS)
