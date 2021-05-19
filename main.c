#include <stdio.h>
#include <stdlib.h>

void trickable (int *w){ //W type
	char combine[3];
	int next = 0;
	int temp;
	int a;
	int b;
	int c;
	while (next == 0){
		printf("Is your surface trickable?\n0 = No\n1 = Yes\n"); //Trickable
		scanf("%d", &temp);
		switch (temp)
		{
			case 0: //No
			a = 0;
			next = 1;
			break;
			case 1: //yes
			a = 1;
			next = 1;
			break;
			default:
				printf("Invalid option. Please try again\n");
		}
	}
	next = 0;
	while (next == 0){  // Driveable
		printf("Is your surface driveable?\n0 = Yes\n1 = Not drivable. Forces a player to change direction which makes the player unable to drive on that surface.\n");
		scanf("%d", &temp);
		switch (temp)
		{
			case 0: //Yes
			b = 0;
			next = 1;
			break;
			case 1: //No
			b = 1;
			next = 1;
			break;
			default:
				printf("Invalid option. Please try again\n");
		}
	}
		next = 0;
		while (next == 0){  // Bounce on Collision
		printf("(Walls only. Input 0 if your surface is not a wall) Will your surface make you bounce when colliding with them?\n0 = Yes\n1 = No\n");
		scanf("%d", &temp);
		switch (temp)
		{
			case 0: //Yes
			c = 0;
			next = 1;
			break;
			case 1: //No
			c = 1;
			next = 1;
			break;
			default:
				printf("Invalid option. Please try again\n");
		}
	}
	sprintf(combine, "%d%d%d", c, b, a);
	sscanf(combine, "%d", &*w);
}

void roadtype (int *z){
	int temp;
		int roadnext = 0;
	while (roadnext == 0){
		printf("Select your road type:\n0 = Normal\n1 = Dirt, GFX on slots 7.3 and 8.3\n2 = Dirt, no GFX\n3 = Smooth\n4 = Wood\n5 = Snow with GFX\n6 = Metal grate\n7 = Normal, but the sound cuts off and returns immediately when triggered.\n" );
		scanf("%d", &temp);
		switch (temp)
		{
			case 0: //Normal
			*z = 0;
			roadnext = 1;
			break;
			case 1: //Dirt GFX
			*z = 1;
			roadnext = 1;
			break;
			case 2: //DIrt no GFX
			*z = 2;
			roadnext = 1;
			break;
			case 3: //Smooth
			*z = 3;
			roadnext = 1;
			break;
			case 4: //Wood
			*z = 4;
			roadnext = 1;
			break;
			case 5: //Snow GFX
			*z = 5;
			roadnext = 1;
			break;
			case 6: //Metal Grate
			*z = 6;
			roadnext = 1;
			break;
			case 7: //Normal Sound cuts
			*z = 7;
			roadnext = 1;
			break;
			default:
				printf("Invalid option. Please try again\n");
		}
	}

}

void shadoweff (int *y){ //Shadow Effect
	int temp;
	int next = 0;
	while (next == 0){
		printf("Pick your Shadow Effect ID (Must be a value between 0 and 999)\n");
		scanf("%d", &temp);
		if (temp <= 999){
			*y = temp;
			next = 1;
		}else printf("Invalid value. Please try again.\n");
	}
}

int main() {
	char flag[2] = "00";
	int w;
	int y;
	int z;
	int temp;
	int next = 0;

	
	while (next == 0)
	{
		printf("Please select your kcl flag:\n0 = road\n1 = off-road\n2 = Boost Panel\n3 = Wall\n");
		scanf("%d", &temp);
		switch (temp)
		{
			case 0: //Road kcl was picked
				strcpy(flag, "00");
				roadtype(&z);
				trickable(&w);
				shadoweff(&y);
				next = 1;
				break;
			case 1: //Off-Rad KCL was picked
				strcpy(flag, "03");
				next = 1;
				break;
			case 2: //BoostPanel KCL was picked
				strcpy(flag, "06");
				next = 1;
				break;
			case 3: //Wall kcl was picked
				strcpy(flag, "0C");
				next = 1;
				break;
			default:
				printf("Invalid option. Please try again\n");
		}
	}	
		
	printf("Your KCL ID is:\na(0x%s,%d,0,%d,%d)",flag,w,y,z);
	return 0;
}
