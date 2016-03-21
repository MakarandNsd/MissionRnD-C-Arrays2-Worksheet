/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include<stdio.h>
struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int compare(char *, char *);
int isvalid(char *);
void convert(char *, int*, int*, int*);
int countGreaterNumbers(struct transaction *Arr, int len, char *date)
{
	if (Arr == NULL || len <= 0 || date == 0)
		return -1;
	int i;
	for (i = 0; i < len; i++)
		if (isvalid(Arr[i].date) == 0)
			return -1;
	int set = 0;
	for (i = 0; i < len; i++)
	{
		if (compare(date, Arr[i].date) == 1)
		{
			set = 1;
			break;
		}

	}
	if (set == 1)
		return (len - i);
	else
		return 0;

}

int isvalid(char * date)
{
	int day, mnth, year;
	convert(date, &day, &mnth, &year);

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
int compare(char *date1, char *date2)
{
	int day1, mnth1, year1;
	convert(date1, &day1, &mnth1, &year1);

	int day2, mnth2, year2;
	convert(date2, &day2, &mnth2, &year2);

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
void convert(char *date, int*day, int*mnth, int*year)
{
	*day = ((date[0] - '0') * 10) + (date[1] - '0');
	*mnth = ((date[3] - '0') * 10) + (date[4] - '0');
	*year = ((date[6] - '0') * 1000) + ((date[7] - '0') * 100) + ((date[8] - '0') * 10) + (date[9] - '0');
	return;
}

