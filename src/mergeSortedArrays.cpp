/*
OVERVIEW: You are given 2 bank statements that are ordered by date - 
Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include<malloc.h>

int compare2(char *, char *);
int isvalid2(char *);
void convert2(char *, int*, int*, int*);

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen)
{
	if (A == NULL || B == NULL || ALen <= 0 || BLen <= 0)
		return NULL;
	struct transaction *merge = (struct transaction*)calloc(ALen + BLen, sizeof(struct transaction));
	int i, j;
	for (j = 0; j < BLen; j++)
	{
		if (isvalid2(B[j].date) == 0)
			return NULL;
	}
	for (i = 0; i < ALen; i++)
	{
		if (isvalid2(A[i].date) == 0)
			return NULL;
	}
	int k = 0;
	for (i = 0, j = 0; ((k < BLen + ALen) && (i<ALen) && (j<BLen));)
	{
		int c = compare2((A[i].date), (B[j].date));
		if (c == 1)
		{
			merge[k] = A[i];
			k++;
			i++;
		}
		else if (c == -1)
		{
			merge[k] = B[j];
			k++;
			j++;
		}
		else
		{
			merge[k] = A[i];
			k++;
			i++;
			merge[k] = B[j];
			k++;
			j++;
		}

	}
	for (; i <ALen; i++, k++)
		merge[k] = A[i];
	for (; j <BLen; j++, k++)
		merge[k] = B[j];
	return merge;
}
int isvalid2(char * date)
{
	int day, mnth, year;
	convert2(date, &day, &mnth, &year);

	if ((mnth == 1 || mnth == 3 || mnth == 5 || mnth == 7 || mnth == 8 || mnth == 10 || mnth == 12) && day <= 31)
		return 1;
	if ((mnth == 4 || mnth == 6 || mnth == 9 || mnth == 11) && day <= 30)
		return 1;
	if ((year % 4 == 0) && (mnth == 2) && day <= 29)
		return 1;
	if ((year % 4 != 0) && (mnth == 2) && day <= 28)
		return 1;
	return 0;

}
int compare2(char *date1, char *date2)
{
	int day1, mnth1, year1;
	convert2(date1, &day1, &mnth1, &year1);

	int day2, mnth2, year2;
	convert2(date2, &day2, &mnth2, &year2);

	if (year2 > year1)
		return 1;
	else if (year2 < year1)
		return -1;
	else
	{
		if (mnth2>mnth1)
			return 1;
		else if (mnth1 > mnth2)
			return -1;
		else
		{
			if (day2 > day1)
				return 1;
			else if (day1 > day2)
				return -1;
			else
				return 0;
		}
	}
}
void convert2(char *date, int*day, int*mnth, int*year)
{
	*day = ((date[0] - '0') * 10) + (date[1] - '0');
	*mnth = ((date[3] - '0') * 10) + (date[4] - '0');
	*year = ((date[6] - '0') * 1000) + ((date[7] - '0') * 100) + ((date[8] - '0') * 10) + (date[9] - '0');
	return;
}
