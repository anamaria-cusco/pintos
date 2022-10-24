#include <stdio.h>
#include "threads/thread.h"

void create_threads(void);
void th_func_to_exec(void *aux UNUSED);
void print_all_threads_info();

#define NUM_THREADS 5

int total_thread_no;

void th_func_to_exec(void *aux UNUSED)
{
    struct thread *current_th = thread_current();
    print_thread_info(current_th);
}

/* Prints info about all threads in the system */
void print_all_threads_info()
{
    intr_disable();
    thread_foreach(print_thread_info, NULL);
    intr_enable();
}

/* Prints info about ready threads in the system */
void print_ready_threads_info()
{
    intr_disable();
    thread_foreach_ready(print_thread_info, NULL);
    intr_enable();
}

void my_test_create_threads()
{
    char name[16];
    for (int i = 0; i < NUM_THREADS; i++)
    {
        snprintf(name, sizeof name, "my_thread_%d", i);
        thread_create(name, PRI_DEFAULT, print_ready_threads_info, (void *)NULL);
    }
}
