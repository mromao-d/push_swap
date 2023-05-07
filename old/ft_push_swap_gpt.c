#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 1000

typedef struct {
	int top;
	int items[STACK_SIZE];
} stack;

int optimal_sort(stack *stack_a, stack *stack_b, int *unsorted, int n, int *moves);
void generate_moves(stack *stack_a, stack *stack_b, int *unsorted, int n, int **moves, int *num_moves);
void apply_move(stack *stack_a, stack *stack_b, int *unsorted, int n, int move_type, int move_arg);

int main() {
	stack stack_a = {0, {0}};
	stack stack_b = {0, {0}};
	int unsorted[] = {4, 121212, 2, 1, 3, 5, 1212};
	int n = sizeof(unsorted) / sizeof(int);
	int moves[2 * n];
	int i;
	int num_moves = optimal_sort(&stack_a, &stack_b, unsorted, n, moves);

	printf("Minimum number of moves: %d\n", num_moves);
	i = -1;
	while (++i < num_moves)
	/* for (int i = 0; i < num_moves; i += 2) */ {
		switch (moves[i]) {
			case 0:
				printf("push a %d\n", moves[i + 1]);
				break;
			case 1:
				printf("push b %d\n", moves[i + 1]);
				break;
			case 2:
				printf("pop a\n");
				break;
			case 3:
				printf("pop b\n");
				break;
			case 4:
				printf("swap\n");
				break;
		}
		i++;
	}
	i = -1;
	while (unsorted[++i])
		printf("\n\n%i", unsorted[i]);

	return 0;
}

int optimal_sort(stack *stack_a, stack *stack_b, int *unsorted, int n, int *moves) {
	if (n == 0) {
		return 0;
	}

	int *all_moves = NULL;
	int num_all_moves = 0;
	generate_moves(stack_a, stack_b, unsorted, n, &all_moves, &num_all_moves);

	int best_moves[2 * n];
	int best_num_moves = 2 * n;

	for (int i = 0; i < num_all_moves; i += 2) {
		int move_type = all_moves[i];
		int move_arg = all_moves[i + 1];

		stack new_stack_a = *stack_a;
		stack new_stack_b = *stack_b;
		int new_unsorted[n - 1];

		if (move_type == 0) {
			new_stack_a.items[new_stack_a.top++] = move_arg;
			for (int j = 1; j < n; j++) {
				new_unsorted[j - 1] = unsorted[j];
			}
		} else if (move_type == 1) {
			new_stack_b.items[new_stack_b.top++] = move_arg;
			for (int j = 1; j < n; j++) {
				new_unsorted[j - 1] = unsorted[j];
			}
		} else if (move_type == 2) {
			new_stack_a.top--;
			for (int j = 0; j < n - 1; j++) {
				new_unsorted[j] = unsorted[j];
			}
		} else if (move_type == 3) {
			new_stack_b.top--;
			for (int j = 0; j < n - 1; j++) {
				new_unsorted[j] = unsorted[j];
			}
		} else if (move_type == 4) {
			int top_a = new_stack_a.items[new_stack_a.top - 1];
			new_stack_a.items[new_stack_a.top - 1] = new_stack_a.items[new_stack_a.top - 2];
			new_stack_a.items[new_stack_a.top - 2] = top_a;
			for (int j = 0; j < n - 1; j++) {
				new_unsorted[j] = unsorted[j];
			}
		}

		int new_moves[2 * n];
		int new_num_moves = optimal_sort(&new_stack_a, &new_stack_b, new_unsorted, n - 1, new_moves);

		if (new_num_moves + 2 < best_num_moves) {
			best_num_moves = new_num_moves + 2;
			best_moves[0] = move_type;
			best_moves[1] = move_arg;
			for (int j = 0; j < new_num_moves; j++) {
				best_moves[j + 2] = new_moves[j];
			}
		}
	}

	for (int i = 0; i < best_num_moves; i++) {
		moves[i] = best_moves[i];
	}

	return best_num_moves;
}

void generate_moves(stack *stack_a, stack *stack_b, int *unsorted, int n, int **moves, int *num_moves) {
    *num_moves = 0;
    *moves = (int*) malloc(10 * n * sizeof(int));

    for (int i = 0; i < n; i++) {
        if (stack_a->top == 0 || unsorted[i] < stack_a->items[stack_a->top - 1]) {
            (*moves)[(*num_moves)++] = 0; // push onto stack A
            (*moves)[(*num_moves)++] = unsorted[i];
        } else if (stack_b->top == 0 || unsorted[i] < stack_b->items[stack_b->top - 1]) {
            (*moves)[(*num_moves)++] = 1; // push onto stack B
            (*moves)[(*num_moves)++] = unsorted[i];
        } else {
            for (int j = stack_b->top - 1; j >= 0; j--) {
                if (unsorted[i] > stack_b->items[j]) {
                    (*moves)[(*num_moves)++] = 3; // rotate stack B up
                    (*moves)[(*num_moves)++] = 0;
                } else {
                    (*moves)[(*num_moves)++] = 2; // rotate stack A up
                    (*moves)[(*num_moves)++] = 0;
                }
            }
            (*moves)[(*num_moves)++] = 0; // push onto stack A
            (*moves)[(*num_moves)++] = unsorted[i];
        }
    }
}
