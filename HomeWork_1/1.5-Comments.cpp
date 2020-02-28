#include <iostream>

int main(void)
{
	int k1=0, k2=0, k3=0, k4=0;
	char c;
	enum{S,P1,P2,P3,P4,P5,P6,P7} state = S;
	while((c = getchar()) != EOF)
	{
		if(state==S and c=='(')
		{
			c = getchar();
			if(c=='*')
				state = P2;
			else{
				state = S;
				std::cin.putback(c);
			}
		}
		else if(state==P2 and c=='*')state = P3;
		else if(state==P3 and c==')')
		{
			state = S;
			k1++;
		}
		else if(state==P3) state = P2;

		else if(state==S and c=='{') state = P4;
		else if(state==P4 and c=='}')
		{
			state = S;
			k2++;
		}

		else if(state==S and c=='\'') state = P5;
		else if(state==P5 and c=='\'')
		{
			state = S;
			k4++;
		}

		if(state==S and c=='/')
		{
			c = getchar();
			if(c=='/')
				state = P7;
			else{
				state = S;
				std::cin.putback(c);
			}
		}
		else if(state==P7 and c=='\n')
		{
			state = S;
			k3++;
		}
	}

	std::cout << k1 << ' ' << k2 << ' ' << k3 << ' ' << k4; 

	return 0;
}