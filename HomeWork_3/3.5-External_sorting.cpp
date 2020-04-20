#include <stdio.h>
#include <string.h>
#include <unistd.h>

using namespace std; 
const int LEN = 10002;


int main()
{
	FILE *src = fopen("input.txt", "r");
	FILE *dst = fopen("output.txt", "w");
	FILE *f_merge = fopen("temp_3.txt", "w+");
	FILE *f_1 = fopen("temp_1.txt", "w+");
	FILE *f_2 = fopen("temp_2.txt", "w+");

	char s[LEN];
	char s1[LEN];
	char s2[LEN];

	unsigned int count = 0, n = 0;
	while(fgets(s, LEN, src))
	{
		++n;
		fputs(s,f_merge);
	}
	fputc('\n',f_merge);
	

	unsigned int series_size = 1, merge_size = 2;

	while(merge_size < 2*n)
	{
		truncate("temp_3.txt", ftell(f_merge));
		rewind(f_merge);
		rewind(f_1);
		rewind(f_2);

		bool file1 = true;
		count = 0;
		while(fgets(s, LEN, f_merge))
		{
			++count;
			fputs(s, file1 ? f_1 : f_2);
			if(count == series_size)
			{
				count = 0;
				file1 = !file1;
			}
		}

		truncate("temp_1.txt", ftell(f_1));
		truncate("temp_2.txt", ftell(f_2));
		rewind(f_1);
		rewind(f_2);
		rewind(f_merge);
		unsigned int i = 0, j = 0;

		auto k1 = fgets(s1, LEN, f_1);
		auto k2 = fgets(s2, LEN, f_2);
		while(k1 && k2)
		{ 
			while(k1 && k2)
			{
				if(strcmp(s1,s2)<0)
				{
					fputs(s1, f_merge);
					k1 = fgets(s1, LEN, f_1);
					if(++i == series_size)
						break;
				}
				else
				{
					fputs(s2, f_merge);
					k2 = fgets(s2, LEN, f_2);
					if(++j == series_size)
						break;
				}
			}

			while(k1)
			{
				if(i == series_size)
					break;
				fputs(s1, f_merge);
				k1 = fgets(s1, LEN, f_1);
				++i;
			}
			while(k2)
			{
				if(j == series_size)
					break;
				fputs(s2, f_merge);
				k2 = fgets(s2, LEN, f_2);
				++j;
			}
			i = 0;
			j = 0;
		}

		while(k1)
		{
			fputs(s1, f_merge);
			k1 = fgets(s1, LEN, f_1);
		}
		while(k2)
		{
			fputs(s2, f_merge);
			k2 = fgets(s2, LEN, f_2);
		}

		series_size = merge_size;
		merge_size = merge_size * 2;

	}
	rewind(f_merge);
	count = 0;
	while(fgets(s, LEN, f_merge))
		fputs(s, dst);


	return 0;
}