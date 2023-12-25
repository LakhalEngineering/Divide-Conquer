#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int main(){
    // Define array of 6 int [p:r] where p =1 and r=6
    // Define array that has 1/2 sorted items
    int p=0;
    int r=8;
    int array[8] = {5,6,7,8,0,2,3,4};
    // Cal len of array
    int len_array = sizeof(array)/(sizeof(int));
    // We have array[1:6] == [p:r]
    // Cal q 
    int q;
    int res;
    res = len_array%2;
    printf("rest e : %d\n",res);
    if(res == 0){
        q=len_array/2;
    }else{
        q=(len_array/2)+1;
    }
    // Define subarray 1 
    // Cal nL and nR
    int nL = q;//q - 1 + 1;// q-p+1
    int nR = 8-q;//r - q;
    int arrayL[4];
    int arrayR[4];
    for(int i=0;i<nL;i++){
        arrayL[i]=array[i];
    }
    for(int j=0;j<nR;j++){
        arrayR[j]=array[q+j];
    }
    
    // Display arrays
    for(int x=0;x<nL;x++){
        printf("ArrayL index : %d, TL[%d]=%d\n",x,x,arrayL[x]);
    }
    printf("********************************\n");
    for(int z=0;z<nR;z++){
        printf("ArrayR index : %d, TR[%d]=%d\n",z,z,arrayR[z]);
    }
    printf("q e : %d\n",q);
    printf("Length of array is : %d\n",len_array);

    int i = 0;
    int j = 0;
    int k = 0;

    while(i<nL && j<nR){
        if (arrayL[i]<=arrayR[j]){
            array[k] = arrayL[i];
            i = i + 1;
        }else{
            array[k]=arrayR[j];
            j = j + 1;
        }
        k = k +1;
    }

    while(i<nL){
        array[k]=arrayL[i];
        i = i +1;
        k = k + 1;
    }
    while(j<nR){
        array[k]=arrayR[j];
        j = j +1;
        k = k + 1;
    }

    //Display array
    printf("********************************\n");
    for(int i=0;i<8;i++){
        printf("index e : %d, array[%d] = %d\n",i,i,array[i]);
    }
    return 0;
}