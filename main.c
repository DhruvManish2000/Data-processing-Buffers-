#include <stdio.h>
#include "io.h"

//#define _CRT_SECURE_NO_WARNINGS

#define BUFFER_SIZE 64

#define MIN     0
#define MAX     1
#define ODD     2
#define EVEN    3
#define MINMAX  4
#define ODDEVEN 5

// prototypes of your functions you need to write

// this function fills input buffer using values
// obtained with the function get_value()
void reading(int[]);

// this function performs processing of data in local buffer
// and put results back into local buffer
void processing(int[]);

// this function transfers data between two buffers
// it is used to transfer data from input buffer to local buffer
// and to transfer data from local buffer to output buffer
void transferring(int[], int[]);

// this function submit the results stored
// in output buffer for validation
void submitting(int[]);


// two functions provided to you (defined in io.h and io.c) are:
// int get_value(void);
//       this function generates a single value
//       you use it to obtain this value and put it into an input buffer
// int submit_result(int[]);
//       you use this function to submit the data processing results
//       for validation (your results are checked inside this function)


int main(void) {

    int inputBuffer[BUFFER_SIZE] = {0};
    int localBuffer[BUFFER_SIZE] = {0};
    int outputBuffer[BUFFER_SIZE]= {4};
    reading(inputBuffer);

    while (inputBuffer[0]!=-1) {

        transferring(inputBuffer,localBuffer);
        processing(localBuffer);
        transferring(localBuffer,outputBuffer);
        submitting(outputBuffer);
        // set all buffers to 0
        for (int j = 0; j < 64; j++) {
            inputBuffer[j] = 0;  // put your value here.
            outputBuffer[j] = 0;
            localBuffer[j] = 0;
        }
        reading(inputBuffer);
    }
    return 0;
}

void reading(int inputBuffer[]) {

    // inputting the getvalue() integers into input buffer
    inputBuffer[0] = get_value();
    inputBuffer[1] = get_value();
    for(int i = 0; i < inputBuffer[1];i++) {
        inputBuffer[i+2] = get_value();
    }

    // printing the input buffer contents
    printf("inputBuffer elements \n");
    for(int j = 0; j<13;j++){

        printf("%d ", inputBuffer[j]);
    }
    printf("\n");
}

void processing(int localBuffer[]) {
    // printing local buffer prior the operations performed
    printf("local buffer elements \n");
    for (int j = 0; j < 13; j++) {

        printf("%d ", localBuffer[j]);
    }
    printf("\n");

    // Declaration of local variables
    int Max = localBuffer[2];
    int Min = localBuffer[2];
    int odd = 0;
    int even = 0;

    // Operation ID
    int x = localBuffer[0];

    switch (x) {
        // Minimum value
        case 0:
            for (int r = 0; r < localBuffer[1]; r++) {
                if (Min > localBuffer[r+2]) {

                    Min = localBuffer[r+2];
                }
                localBuffer[2] = Min;
            }
            break;

            // Max value
        case 1:
            for (int e = 0; e < localBuffer[1]; e++) {
                if (Max < localBuffer[e+2]) {

                    Max = localBuffer[e+2];
                }
                localBuffer[2] = Max;
            }
            break;

            // odd determinant
        case 2:
            for(int t = 0; t<localBuffer[1];t++){
                if ((localBuffer[t+2] % 2)== 1){
                    odd++;
                }
            }
            localBuffer[2] = odd;
            break;

            // even determinant
        case 3:
            for(int y = 0; y<localBuffer[1];y++){
                if ((localBuffer[y+2] % 2) == 0){
                    even++;
                }
                localBuffer[2] = even;
            }
            break;

            // min and max determinant
        case 4:
            for (int r = 0; r < localBuffer[1]; r++) {
                if (Min > localBuffer[r+2]) {

                    Min = localBuffer[r+2];
                }
            }
            for (int e = 0; e < localBuffer[1]; e++) {
                if (Max < localBuffer[e+2]) {

                    Max = localBuffer[e+2];
                }
            }
            localBuffer[2] = Min;
            localBuffer[3] = Max;
            break;

            // Odd and even determination
        case 5:
            for(int t = 0; t<localBuffer[1];t++){
                if ((localBuffer[t+2] % 2) == 1){
                    odd = odd + 1;
                }
            }

            for(int y = 0; y<localBuffer[1];y++){
                if ((localBuffer[y+2] % 2) == 0){
                    even = even + 1;
                }
            }

            localBuffer[2] = odd;
            localBuffer[3] = even;
            break;

        default:
            printf("the operation ID is not in the range of 0-5");
            break;
    }

    // printing local buffer values once either of the process above was done:
    printf("updated local buffer elements \n");
    for (int t = 0; t < 13; t++) {

        printf("%d ", localBuffer[t]);
    }
    printf("\n");

}

// over here its the switch function job

void transferring(int sourceBuffer[], int destinationBuffer[]) {

    // transferring to local buffer
    for (int z = 0; z < 13; z++) {
        destinationBuffer[z] = sourceBuffer[z];
    }


}
void submitting(int outputBuffer[]) {
// ensuring the correct format for the output buffer
    int x = outputBuffer[0];

    switch (x) {
        case 0:
            outputBuffer[1] = 1;
            break;
        case 1:
            outputBuffer[1] = 1;
            break;
        case 2:
            outputBuffer[1] = 1;
            break;
        case 3:
            outputBuffer[1] = 1;
            break;
        case 4:
            outputBuffer[1] = 2;
            break;
        case 5:
            outputBuffer[1] = 2;
            break;
        default:
            printf("No ID matched");
            break;
    }

    // printing output buffer
    printf("Output buffer elements \n");
    if(outputBuffer[0] == 1 || outputBuffer[0] == 0 || outputBuffer [0] == 2 || outputBuffer[0] == 3)
        for (int j = 0; j < 3; j++) {

            printf("%d ", outputBuffer[j]);
        }
    else {
        for (int j = 0; j < 4; j++) {

            printf("%d ", outputBuffer[j]);
        }
    }
    printf("\n");

    // Confirming the results
    printf("%d \n", submit_results(outputBuffer));
    printf("\n");



}
