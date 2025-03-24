#ifndef PUSH_SWAP
# define PUSH_SWAP
    typedef struct s_stack_node {
        int value;
        int Index;
        struct s_stack_node *next;
    }               t_stack_node;

    typedef struct s_stack {
        t_stack_node *top;
        int size;
    }               t_stack;

    t_stack *stack_init(void);
    void stack_push(t_stack *stack, int value);
    int stack_pop(t_stack *stack);
    void stack_free(t_stack *stack);
    int is_stack_sorted(t_stack *stack);
#endif