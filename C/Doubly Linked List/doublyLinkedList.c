#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct node{
	int num;
	struct node *previous_node;
	struct node *next_node;
} node;

node* reverse_list(node *dll)
{
	node *current_node = dll;
	node *aux_node = NULL;
    node *start = NULL;
	
	while(current_node->next_node != NULL)
	{
		current_node = current_node->next_node;
	}
	
	start = current_node;
	
	do
	{
		aux_node = current_node->next_node;
		current_node->next_node = current_node->previous_node;
		current_node->previous_node = aux_node;
		current_node = current_node->next_node;
	}
	while(current_node != NULL);
	
	return start;
}

node* get_node_by_index(node *dll, int index)
{
    if(index < 0)
    {
        return NULL;
    }
    
    for(int i = 0; i != index; i++)
    {
        if(dll->next_node != NULL)
        {
            dll = dll->next_node;
        }
        else
        {
            return NULL;
        }
    }
    
    return dll;
}

node* swap_nodes(node *dll, int first_element, int second_element)
{
    node *first_node = NULL;
    node *second_node = NULL;
    
	if(first_element < 0 || second_element < 0)
	{
		return NULL;
	}
	
	first_node = get_node_by_index(dll, first_element);
    second_node = get_node_by_index(dll, second_element);
    
    first_node->previous_node->num = first_node->previous_node->num + second_node->previous_node->num;
    second_node->previous_node->num = first_node->previous_node->num - second_node->previous_node->num;
    first_node->previous_node->num = first_node->previous_node->num - second_node->previous_node->num;
    
    return dll;
}

node* sort_list(node *dll)
{
    bool swapped;
    
    while(dll->previous_node != NULL)
    {
        dll = dll->previous_node;
    }
    
    do
    {
        swapped = false;
        for(int i = 1; dll->next_node != NULL; i++)
        {
            if(dll->num > dll->next_node->num)
            {
                dll->num = dll->num + dll->next_node->num;
                dll->next_node->num = dll->num - dll->next_node->num;
                dll->num = dll->num - dll->next_node->num;
                swapped = true;
            }
            dll = dll->next_node;
        }
        
        while(dll->previous_node != NULL)
        {
            dll = dll->previous_node;
        }
    }
    while(swapped == true);
    
    return dll;
}

node* add_node(node *dll, int num)
{
    node* start = NULL;
    
    if(dll == NULL)
    {
        start = malloc(sizeof(node));
    }
    else
    {
        while(dll->next_node != NULL)
        {
            dll = dll->next_node;
        }
        dll->next_node = malloc(sizeof(node));
        start = dll->next_node;
    }
    
    start->previous_node = dll;
    start->num = num;
    
    return start;
}

node* slice_list(node *dll, int first_element, int last_element)
{
    node *slice = NULL;
    node *start = NULL;
    
    while(dll->previous_node != NULL)
    {
        dll = dll->previous_node;
    }
    
    if(first_element < 0 || last_element < 0)
    {
        return NULL;
    }
    
    for(int i = 0; i <= last_element; i++)
    {
        if(i >= first_element)
        {
            slice = add_node(slice, dll->num);
        }
        dll = dll->next_node;
    }
    
    start = slice;
    while(start->previous_node != NULL)
    {
        start = start->previous_node;
    }
    
    return start;
}

void print_list(node *dll)
{
    for(int i = 0; dll != NULL; i++)
    {
        printf("Node: %d Num: %d\n", i, dll->num);
        dll = dll->next_node;
    }
    
    return;
}
