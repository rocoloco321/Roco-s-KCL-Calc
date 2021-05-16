#include <stdio.h>
#include <stdlib.h>

void trickable (int *w)

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

int main() {
	char flag[2] = "00";
	int w = 000;
	char y[3] = "000";
	int z = 0;
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
		
	printf("Your KCL ID is:\na(0x%s,000,0,000,%d)",flag,z);
	return 0;
}
