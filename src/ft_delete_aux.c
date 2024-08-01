
#include "ft_non_standard/ft_non_standard.h"
#include <unistd.h>
#include "ft_non_standard/ft_non_standard.h"
#include "internal/handle/stack/ft_stack.h"
#include "internal/handle/stack/state/ft_state.h"

void	ft_print_stack(int target_stack)
{
	t_stack	*temp_stack;

	if (target_stack == STACK_A)
		temp_stack = ft_stack()->a;
	else
		temp_stack = ft_stack()->b;
	while (temp_stack)
	{
		ft_putnbr_fd(temp_stack->nbr, STDERR_FILENO);
		ft_putstr_fd(" | ", STDERR_FILENO);
		ft_putnbr_fd(temp_stack->index, STDERR_FILENO);
		if (target_stack == STACK_A)
			ft_putendl_fd(" -> stack a", STDERR_FILENO);
		else
			ft_putendl_fd(" -> stack b", STDERR_FILENO);
		temp_stack = temp_stack->next;
	}
}

void	ft_pt1(void)
{
	ft_putendl_fd("Init stack A\n", STDERR_FILENO);
	ft_print_stack(STACK_A);
	ft_print_stack(STACK_B);
	ft_putendl_fd("\nOperations:", STDERR_FILENO);
}

void	ft_pt2(void)
{
	ft_putendl_fd("\nEnd stack A", STDERR_FILENO);
	ft_print_stack(STACK_A);
	ft_print_stack(STACK_B);
	ft_stack_normalize(STACK_DEFAULT);
	if (ft_is_sorted(ft_stack()->a, STACK_INDEX, ft_stack()->info.a_size))
		ft_putendl_fd("\nsorted.", STDERR_FILENO);
	else
		ft_putendl_fd("\nnot sorted.", STDERR_FILENO);
}
