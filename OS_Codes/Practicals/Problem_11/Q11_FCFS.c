#include <stdio.h>
#include <math.h>
 
  
void FCFS(int arr[], int head) 
{ 
    int seek_count = 0; 
    int distance, cur_track; 
  
    for (int i = 0; i < 8; i++) { 
        cur_track = arr[i]; 
  
        // calculate absolute distance 
        int r=cur_track - head;
        if(r>=0){
         distance=r;}
        else
        distance = -r;
  
        // increase the total count 
        seek_count += distance; 
  
        // accessed track is now new head 
        head = cur_track; 
    }  

    printf("Total number of seek operations %d\n",seek_count);
  
    // Seek sequence would be the same 
    // as request array sequence 
   
    printf("Seek sequence is\n");
    
  
    for (int i = 0; i < 8; i++) { 
        printf("%d \n",arr[i]); 
    } 
} 
  
// Driver code 
int main() 
{ 
  
    // request array 
    int arr[8] = { 176, 79, 34, 60, 92, 11, 41, 114 }; 
    int head = 50; 
  
    FCFS(arr, head); 
  
    return 0; 
} 
