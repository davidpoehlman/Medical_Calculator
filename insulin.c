#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define CARBOHYDRATE_COVERAGE 15

int main(void)
{
	int glucoseTarget = 0, glucoseCurrent = 0, glucoseFinal = 0;
	float insulinAmt;

	printf("This script will Identify the amount of insulin you should take for your adjusted dose...\n");

	printf("Please start by entering in your current glucose level: ");
	scanf("%d", &glucoseCurrent);

	printf("\nNow enter the level your glucose is suppsed to be at: ");
	scanf("%d", &glucoseTarget);

	glucoseFinal = glucoseCurrent - glucoseTarget;
	insulinAmt = (float)glucoseFinal / (float)CARBOHYDRATE_COVERAGE;

	printf("\nAfter careful consideration... You need to take more insulin.\n");
	printf("Please take %.1f unit(s) of insulin to compensate.\n", insulinAmt);
	
	return 0;
}