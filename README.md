## Age_Dist

This algorithm generates a set number of people with random ages that fit into a realistic distribution.
Instead of picking random sets and geretating random ages inside of it, the algorithm tries to stick
to a more realistic process.

The data was retrieved from this page: http://www.censusscope.org/us/chart_age.html

## Example of Output

```
Generating 10000000 People
Range	Count		Calcul.	Actual	Deviat.
0-4		683215		6.83	6.82	-0.01
5-9		730651		7.31	7.30	-0.01
10-14	731031		7.31	7.30	-0.01
15-19	716979		7.17	7.18	+0.01
20-24	672489		6.72	6.74	+0.02
25-29	688595		6.89	6.89	+0.00
30-34	729387		7.29	7.29	-0.00
35-39	807742		8.08	8.07	-0.01
40-44	795636		7.96	7.97	+0.01
45-49	714008		7.14	7.14	-0.00
50-54	625394		6.25	6.25	-0.00
55-59	478433		4.78	4.78	-0.00
60-64	383858		3.84	3.84	+0.00
65-69	338074		3.38	3.38	-0.00
70-74	314787		3.15	3.15	+0.00
75-79	263657		2.64	2.63	-0.01
80-84	176031		1.76	1.76	-0.00
85+		150033		1.50	1.51	+0.01
Average Deviation: -0.0000
```