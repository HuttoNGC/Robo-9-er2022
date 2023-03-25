#include <kipr/wombat.h>

int main()
{
    //wait_for_light(0);
    printf("Hello World\n");
    create_connect();
    create_drive_direct(500,500);
    msleep(1500);
    create_drive_direct(-500,500);
    msleep(500);
    int go = 0; 
    while (go==0){
        go = 1;
        while (get_create_lfcliff_amt() > 2000 || get_create_rfcliff_amt() > 2000){
        	if ( get_create_rfcliff_amt() < 2000 && get_create_lfcliff_amt() > 2000){
            	create_drive_direct(50,-70);
        	}
        	else if ( get_create_lfcliff_amt() < 2000 && get_create_rfcliff_amt() > 2000){
            	create_drive_direct(-70,50);
                printf("no");
        	}
        	else {
        		create_drive_direct(100,100);
        	}
        }
    }
    create_drive_direct(200,200);
    msleep(1000);
    create_drive_direct(200,-200);
    msleep(885);
    while (get_create_rbump()==0){
        if (get_create_rfcliff_amt() > 2000){
            create_drive_direct(480,500);
        } 
        else{
            create_drive_direct(500,480);
        }
    }
    create_disconnect();
    return 0;
}
