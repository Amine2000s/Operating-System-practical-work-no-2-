#ifndef AMIN1_H_INCLUDED
#define AMIN1_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

///////////////////////////////////////////
///////////////////////////////////////////
   typedef struct program {

        char program_name[20];
        int  program_size ;
        int  estimated_exec_time ;
        int  unit_number;
        struct program *nxt;
    }prgm ;
///////////////////////////////////////////
///////////////////////////////////////////
    typedef struct  memory_list{

        char status;
          //H free P full
        int starting_number;
         //of units
        int number_of_units ;

        struct memory_list* next;

    };
///////////////////////////////////////////
//////////////////////////////////////////

typedef struct index {

    int number_of_units_of_acutal_program ;

    int number_of_units_of_the_upcoming_allocated_memory ;

    struct memory_list *pointer_to_the_spot ;

} index ;
////////////////////////////////////////////
////////////////////////////////////////////



void add_program_to_queue();

void show_program();

void allocation_unit_and_size_of_memory();

void matrix_display();

void show_memory_linked_list_form();

bool bestfit_approach() ;

bool fit_program_to_memory() ;

void free_a_memoory_parition() ;

void fragmentation_rate();


#endif // AMIN1_H_INCLUDED
