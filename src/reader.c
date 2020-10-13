// Authors: Marvin Tan (marvin.tan@wisc.edu), Joseph Martin (jrmartin4@wisc.edu)
#include <pthread.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "util.h"
#include "reader.h"
const int BUFFS = 100;

/*
 * read input line by line from standard input
 * pass the result to the queue
 */
void startRead(Queue *queue){
    char buff[BUFFS];   
    //keep reading until the end of the line 
    while(fgets(buff, BUFFS , stdin)!=NULL){
        int inputLength = strlen(buff);
        //check if the last character is the new line symbol
        if(buff[inputLength - 1] == '\n'){
            //replace the new line with null symbol
            buff[inputLength - 1] = '\0';
            //allocate mem for the string(reserve space for \0)
            char *currS = calloc_w(1,inputLength);
            strncpy(currS,buff,inputLength);
            //pass the string to the queue
            EnqueueString(queue,currS);
        }//if there are multiple null char in the same line
        else if(inputLength<(BUFFS - 1)){
            //allocate mem for the string(reserve space for \0)
            //ignore all the char after the first null
            char *currS = calloc_w(1,inputLength);
            strncpy(currS,buff,inputLength);
            //pass the string to the queue
            EnqueueString(queue,currS);
            
        }
        //if the input line does exceeds the buffer size,or something else
        else
        {
            //print out a warning for the overflown line
            fprintf(stderr,"Line is truncated for the buffer size\n");
            //allocate mem for the string(reserve space for \0)
            char *currS = calloc_w(1,inputLength+1);
            strncpy(currS,buff,inputLength+1);
            //pass the string to the queue
            EnqueueString(queue,currS);
            //flush the rest of the line
            char c = getchar();
            while ('\n' != c && EOF !=c){
                c =getchar();
            }                        
        }
    }
    //queue a NULL string as the last input to indicate completion
    EnqueueString(queue,NULL);
}
/*
 * Function wrapper for startRead
 */
void *startReadWrapper(void *data){
    Queue *queue = (Queue *)data;
    startRead(queue);
    pthread_exit(NULL);
}
