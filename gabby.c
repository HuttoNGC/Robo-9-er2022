#include <kipr/wombat.h>
#include <stdio.h>
int main()
{
	int x = 1;
	int sleep = 0;
	char ch1;
	enable_servos();
	while (x == 1){
    	printf("what would you like me to do f:forward,b:backward,t:turn  : ");
    	scanf("%c", &ch1);
    	if (ch1 == 'b'){
			printf("for how long would you like to drive forward in ms: ");
			scanf("%d", &sleep);  
			bk(1);
			fd(0);
			msleep(sleep);
    	} 
		if (ch1 == 'f'){
			printf("for how long would you like to drive backward in ms: ");
			scanf("%d", &sleep);  
			fd(1);
			bk(0);
			msleep(sleep);
    	} 
		if (ch1 == 't'){
			printf("for how long would you like to turn right if a negative will turn left, in ms: ");
			scanf("%d", &sleep);  
			if (sleep > 0){
				fd(1);
				fd(0);
				msleep(sleep);
			}
			if (sleep < 0){
				sleep *= -1;
				bk(1);
				bk(0);
				msleep(sleep);
			}
    	} 
    	ao();
	}
	disable_servos();
	ao();
	return 0;