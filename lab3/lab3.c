#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct team {
char team_name[128];
int games;
int scores;
int prize_fund;
};
typedef struct team teams;

void read_team(teams *t){
	printf("Team name: ");
	scanf("%s", t->team_name);
	printf("Games: ");
	scanf("%d", &t->games);
	printf("Scores: ");
	scanf("%d", &t->scores);
	printf("Prize fund: ");
	scanf("%d", &t->prize_fund);
}

static int cmp(const void *p1, const void *p2){
	teams * t1 = *(teams**)p1;
	teams * t2 = *(teams**)p2;
	return t2->prize_fund - t1->prize_fund;
}

int main(int argc, char **argv){
	int count;
	printf("Enter quantity of teams: ");
	scanf("%d", &count);
	teams** t = (teams**)malloc(sizeof(teams*)*count);
	for (int i=0; i < count; i++){
		t[i] = (teams*) malloc (sizeof(teams));
		printf("#%d\n", i+1);
		read_team(t[i]);
	}
	qsort(t, count, sizeof(teams*), cmp);
	for (int i=0; i < count; i++){
		printf("/nTeam name: %s\n", t[i]->team_name);
		printf("Games: %d\n", t[i]->games);
		printf("Scores: %d\n", t[i]->scores);
		printf("Prize fund: %d\n", t[i]->prize_fund);
	}
	for (int i=0; i < count; i++){
			free(t[i]);
	}
	free(t);
	return 0;
}
