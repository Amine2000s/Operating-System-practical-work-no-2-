#include <stdio.h>
#include <stdlib.h>
#include "amin1.h"

int main()
{



    int user_choise,memory_paritionss;
    prgm *head , *tail ;

    printf("\t==========================================================\n");
    printf("\t\t   welcome to the Memory management \n\t\t(Dynamic partitioning : bit map simulation program ss");
    printf("\n\t==========================================================\n");


    do{
        printf("\nCHOOSE AN OPERATION (-1 FOR EXIT )\n");

        printf("\n 1: DEFINE MEMORY SIZE AND ALLOCATION UNIT  \n ");

        printf("\n 2: ADD PROGRAMS TO MEMORY \n ");

        printf("\n 3: SHOW THE MEMORY IN LINKED LIST FORMAT    \n ");

        printf("\n 4: SHOW THE MEMORY IN BITMAP(MATRIX) FORMAT  \n ");

        printf("\n 5: FREE AN ALLOCATED MEMORY PARTION \n");

        printf("\n 6: CALCULATE THE FRAGEMNTATION RATE  \n ");

        scanf("%d",&user_choise);

        switch(user_choise){
            case (1) :

                    allocation_unit_and_size();

                    break;
            case (2):

                   add_program_to_queue();//show queue program

                    break;

            case (3):

                    show_memory_linked_list_form();

                    break;

            case (4) :
                    matrix_display();
                    break;

            case (5):

                    free_a_memoory_parition();
                    break;
            case (6):
                    fragmentation_rate();
                    break;
            //case (7):
                   // () ;

        }

    }while(user_choise!=-1);

    return 0;
}
