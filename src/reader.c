#include "reader.h"
const int BUFFS = 100;

/*
 * read input line by line from standard input
 * pass the result to the queue
 */
void startRead(Queue *queue){
    char buff[BUFFS];   
    printf("startRead called\n");//DELETE
    //keep reading until the end of the line 
    while(fgets(buff, BUFFS , stdin)!=NULL){
        printf("start reading\n");//DELETE
        int inputLength = strlen(buff);
        //check if the last character is the new line symbol
        if(buff[inputLength - 1] == '\n'){
            //replace the new line with null symbol
            buff[inputLength - 1] = '\0';
            //allocate mem for the string(reserve space for \0)
            char *currS = calloc(1,inputLength);
            strncpy(currS,buff,inputLength);
            printf("Line: %s\n",currS);//DELETE
            //pass the string to the queue
            EnqueueString(queue,currS);
        }
        //if the input line exceeds the buffer size
        else{
            //print out a warning for the overflown line
            fprintf(stderr,"Line is truncated for the buffer size");
            //allocate mem for the string(reserve space for \0)
            char *currS = calloc(1,inputLength+1);
            strncpy(currS,buff,inputLength+1);
            printf("Line: %s\n",currS);//DELETE
            //pass the string to the queue
            EnqueueString(queue,currS);
                        
        }
    }
    //queue a NULL string as the last input to indicate completion
    EnqueueString(queue,NULL);
    printf("end of the read\n");
}

void *startReadWrapper(void *data){
    Queue *queue = (Queue *)data;
    startRead(queue);
    pthread_exit(NULL);
}
