#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *create_node(int x);
void push(struct node **top, int x);
void pop(struct node **top);
void delete_stack(struct node **top);
void print_stack(struct node *top);

int main()
{
    struct node *my_stack = NULL;

    int i = 1;
    for (i = 1; i <= 10; i++)
    {
        push(&my_stack, i);
        print_stack(my_stack);
    }

    pop(&my_stack);
    print_stack(my_stack);

    delete_stack(&my_stack);
    print_stack(my_stack);

    return 0;
}

struct node *create_node(int x)
{
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = x;
    new_node->next = NULL;
    return new_node;
}

void push(struct node **top, int x)
{
    struct node *new_node = create_node(x);
    new_node->next = *top;
    *top = new_node;
    return;
}

void pop(struct node **top)
{
    struct node *tmp = *top;
    *top = (*top)->next;
    free(tmp);
    return;
}

void delete_stack(struct node **top)
{
    while (*top != NULL)
        pop(top);
    return;
}

void print_stack(struct node *top)
{
    struct node *r = top;
    while (r != NULL)
    {
        printf("%d -> ", r->data);
        r = r->next;
    }
    printf("NULL\n");
    return;
}
