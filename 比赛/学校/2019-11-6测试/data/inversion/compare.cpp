#include <cstdio>

FILE *fin, *fans, *fout, *score, *Log;
double player, answer;
const double eps = 1e-6;

bool compare (double x, double y) {
	if (x < y) {double t = x; x = y, y = t;}
	return x - y <= eps;
}

int main (int argv, char **argc)
{
	fin = fopen (argc[1], "r");
	fout = fopen (argc[2], "r");
	fans = fopen (argc[3], "r");
	//argc[4] -> The Fullgrade
	score = fopen (argc[5], "w");
	Log = fopen (argc[6], "w");

	fscanf (fout, "%lf", &player);
	fscanf (fans, "%lf", &answer);
	if (player != player || compare (player, answer) == 0)
		fprintf (score, "0");
	else
		fprintf (score, argc[4]);
	return 0;
}
