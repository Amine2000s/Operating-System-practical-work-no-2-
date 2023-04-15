#include "amin1.h"

    struct  memory_list *main_head;

    int memory_unit ;// for memory

    int memory_total_size;

    int memory_units_number;//total units number

    int free_memory_units ;

    struct program* main_program = NULL ;

    int program_number;

    bool isFree ;

    index the_index1 ;

    int index_to_free ;

    int total_number_of_created_partitions = 0 ;
    ///////////////////////////////////////////////////////////
    void allocation_unit_and_size(){

    printf("\n===============================\n");

    printf("DEFINE THE MEMORY TOTAL SIZE \n");
    scanf("%i",&memory_total_size);

    printf(" DEFINE THE ALLOCATION UNIT :\n");
    scanf("%i",&memory_unit);

    printf("\n===============================\n");

    memory_units_number= memory_total_size / memory_unit ;

    if((memory_total_size % memory_unit) != 0){

        memory_units_number++;
    }

    printf("THE NUMBER UNITS IN THE MEMORY IS :%i \n",memory_units_number);


    main_head = (struct memory_list *)malloc(sizeof(struct memory_list ));

    main_head->number_of_units= memory_units_number ;

    free_memory_units = memory_units_number ;

    main_head->starting_number = 0 ;

    main_head->status = 'H' ;

    main_head->next == NULL ;

    total_number_of_created_partitions++;

 }
//////////////////////////////////////////////////
void in_queue(struct program *temp){
    //good
    if(main_program==NULL){

        main_program=temp;

    }else{

        prgm *temporary;

        temporary=NULL;

        temporary=main_program;

        while(temporary->nxt!=NULL){

            temporary=temporary->nxt;
        }
        temporary->nxt=temp;

    }

   printf("\n SUCCESSFULLY ADDED !\n");


}


/////////////////////////////////////////////////////////////////
////////////////////REMOVING FROM THE QUEUE OF MEMORY ///////////

 void de_queue(){//good

    prgm *temp;
    temp= main_program;


    main_program=main_program->nxt;

    free(temp);

}
/////////////////////////////////////////////////////
bool bestfit_approach() {

        struct memory_list *temporay_pointer_to_new_memory_allocation = (struct memory_list*)malloc(sizeof(struct memory_list));

        prgm *temporary_program_head = main_program ;

        struct memory_list *temp = the_index1.pointer_to_the_spot;

        temporay_pointer_to_new_memory_allocation-> next = temp->next;

        temp->next = temporay_pointer_to_new_memory_allocation ;

        temporay_pointer_to_new_memory_allocation->status ='H' ;

        temporay_pointer_to_new_memory_allocation->number_of_units = temp-> number_of_units - the_index1.number_of_units_of_acutal_program;

        temporay_pointer_to_new_memory_allocation->starting_number = the_index1.number_of_units_of_acutal_program ;

        temp->number_of_units = the_index1.number_of_units_of_acutal_program ;

        temp->status = 'F' ;

        total_number_of_created_partitions++;

        return true ;





    }
////////////////////////////////////////////////////
bool fit_program_to_memory(){

        struct memory_list *temporary_head = main_head ;

        prgm *temporary_program_pointer = main_program ;


        if(temporary_program_pointer == NULL){
            printf("no programs ,add program then try again");
        }
        //index the_index1 ;

        the_index1.number_of_units_of_the_upcoming_allocated_memory = -1 ;

        the_index1.number_of_units_of_acutal_program = temporary_program_pointer->unit_number ;

        //for(temporary_head=main_head ; temporary_head ; temporary_head = temporary_head->next , current_index++ ){
        while(temporary_head != NULL){

            if(temporary_head->status == 'H' && temporary_program_pointer->unit_number <= temporary_head->number_of_units ){

                if(temporary_head->number_of_units == temporary_program_pointer->unit_number){

                    temporary_head->status='F' ;

                    total_number_of_created_partitions++;

                    printf("done in the first time !!! \n");

                    return true ;

                }

                if(the_index1.number_of_units_of_the_upcoming_allocated_memory == -1/*mazal mal9itch node faregh */){

                    //the_index1.number_of_units = current_index ;

                    the_index1.number_of_units_of_the_upcoming_allocated_memory = temporary_head->number_of_units ;

                    the_index1.pointer_to_the_spot = temporary_head ;

                }else{

                    if(temporary_head->number_of_units < the_index1.number_of_units_of_the_upcoming_allocated_memory){

                        the_index1.number_of_units_of_the_upcoming_allocated_memory = temporary_head->number_of_units ;

                        //the_index1.index_to_fit_in = current_index ;

                        the_index1.pointer_to_the_spot = temporary_head ;
                    }

                }
            }

            temporary_head=temporary_head->next ;
        }

            if(the_index1.number_of_units_of_the_upcoming_allocated_memory == -1){

                return false ;

            } else {

                if(bestfit_approach())
                return true ;

            }


    }
//////////////////////////////////////////////////
void add_program_to_queue(){
            int program_numbers;

                prgm *temp;

                temp=NULL;

                temp=malloc(sizeof(struct program));

                printf("Name of program : ");

                scanf("%s",temp->program_name);

                printf("Program size : ");

                scanf("%d",&temp->program_size);

                printf("estimated time of execution :");

                scanf("%d",&temp->estimated_exec_time);


                temp->nxt=NULL;

                temp->unit_number = temp->program_size / memory_unit ;

                if(temp->program_size % memory_unit != 0)
                    temp->unit_number++ ;

                in_queue(temp);

                //}
                if(fit_program_to_memory()){

                    printf("the operation of adding the program to the memory is done with success ");
                    de_queue();

                }else{

                    printf("the operation is failled due to memory is full , try freeing some partions ");

                    }

        }

///////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////


    void show_memory_linked_list_form(){
        struct memory_list *tmp;
        tmp=main_head;
        printf("\n===================================================\n");
        while(tmp!=NULL){
            printf("[ %c | %i | %i ] --> ",tmp->status,tmp->starting_number,tmp->number_of_units);

            if(tmp->next==NULL)
                printf("NULL");

            tmp=tmp->next;

        };
       printf("\n===================================================\n");

    }


///////////////////////////////////////////////////////////////////////////////
////MATRIX DISLAYING /////////////////////
void matrix_display(){

    struct memory_list * temporary;
    int ligne = 0 ;
    temporary=main_head;

    while(temporary!=NULL){

           for(int i=0 ; i < temporary->number_of_units ; i++){
             if(i % 8 == 0){

               printf("\n");

             }
            if(temporary->status=='F'){
                //printf("\t");
                printf("1");
               // ligne++;
                //printf("\t");2829592

            }
            if(temporary->status=='H'){
                //printf("\t");
                printf("0");
                //ligne++;
                //printf("\t");

           }
            }


                       temporary=temporary->next;

           }


        }



    void free_a_memoory_parition() {

            printf(" \n enter the index to delete : \n");
            scanf("%i",&index_to_free);

            if(index_to_free >= total_number_of_created_partitions){
                printf("index out of range , please try again !");
                //return false ;
            }else{

            struct memory_list *temp = main_head ;

            while(index_to_free != 1){

                temp = temp->next ;
                index_to_free--;
            }
                temp->status='H';
                printf("freeing operation done ! ");
                //return true ;

            }
    }

void fragmentation_rate(){

        int fragementation_ammount ;

        struct memory_list *temp = main_head  ;

        while(temp != NULL){

            if(temp->status =='H'){

                fragementation_ammount += temp->number_of_units;

            }

            temp = temp->next ;

        }

        printf(" \n fragemntation amount is : %i \\\ %i \n",fragementation_ammount,memory_units_number);

        float fragemnetation_in_percentage = (fragementation_ammount / memory_units_number) * 100;

        printf(" in percentage %0.2f", fragemnetation_in_percentage);



}

///////////////////////////////////////////////////////////////////



