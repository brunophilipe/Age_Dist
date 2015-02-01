#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define PEOPLE_COUNT 10000000
#define PEOPLE_COUNT_F (float)(PEOPLE_COUNT/100.f)

/*
 This algorithm generates a set number of people with random ages that fit into a realistic distribution.
 Instead of picking random sets and geretating random ages inside of it, the algorithm tries to stick
 to a more realistic process.
 
 The data was retrieved from this page: http://www.censusscope.org/us/chart_age.html
 
 Created by Bruno Philipe in August 21, 2014.
 */

typedef struct t_person
{
	short age;
	short age_range;
} t_person;

int main(int argc, char const *argv[])
{
	srand(time(0));

	char *_ageRanges[18] = {"0-4", "5-9", "10-14", "15-19", "20-24", "25-29", "30-34", "35-39", "40-44", "45-49", "50-54", "55-59", "60-64", "65-69", "70-74", "75-79", "80-84", "85+"};
	float _ageDistribution[18] = {6.82, 7.3, 7.3, 7.18, 6.74, 6.89, 7.29, 8.07, 7.97, 7.14, 6.25, 4.78, 3.84, 3.38, 3.15, 2.63, 1.76, 1.51};

	t_person *people = malloc(sizeof(t_person) * PEOPLE_COUNT);

	printf("Generating %d People\n", PEOPLE_COUNT);

	// Generating people
	for (long person = 0; person < PEOPLE_COUNT; ++person)
	{
		float accumulator = 0.f;
		int entropy = rand()%10000;

		for (int range = 0; range < 18; ++range)
		{
			//Pick a random value
			accumulator += _ageDistribution[range]*100;

			// Seek the age distribution array for the closest match from the bottom.
			if (accumulator >= entropy)
			{
				// Found a range
				people[person].age_range = range;
				
				if (range != 17)
				{
					//Now use the measurement of how far we are from the next range to calculate the precise age.
					int diff = ((accumulator - entropy)/(accumulator + _ageDistribution[range+1]*100 - entropy)*5);
					people[person].age = (range * 5) + diff;
				}
				else
				{
					//Since we can't go further in ranges, just pick a random age (not optimal).
					int diff = rand()%5;
					people[person].age = (range * 5) + diff;
				}
			
				break;
			}
		}
	}

	// Calculating Statistics
	int actualCount[18];
	float actualDistribution[18];

	memset(&actualCount, '\0', sizeof(actualCount));

	for (long person = 0; person < PEOPLE_COUNT; ++person)
	{
		actualCount[people[person].age / 5]++;
	}

	printf("Range\tCount\t\tCalcul.\tActual\tDeviat.\n");

	float totalDeviation = 0.0f;

	for (int range = 0; range < 18; ++range)
	{
		actualDistribution[range] = actualCount[range]/PEOPLE_COUNT_F;
		float deviation = _ageDistribution[range]-actualDistribution[range];
		totalDeviation += deviation;

		printf("%s\t%d\t\t%.2f\t%.2f\t%+.2f\n", _ageRanges[range], actualCount[range], actualDistribution[range], _ageDistribution[range], deviation);
	}

	printf("Average Deviation: %+.4f\n", totalDeviation/18.f);

	// LOL
	free(people);

	return 0;
}
