#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<string.h>
typedef struct ALP{
	char c;
	int num;
} A;
int isLongPressedName(char * name, char * typed){
	A na[1000], ty[1000];
	for (int i = 0; i < 1000; i++){
		na[i].c = '0'; na[i].num = 0;
		ty[i].c = '0'; ty[i].num = 0;
	}
	char * start1 = name, *end1 = name, *start2 = typed, *end2 = typed;
	int i = 0, j = 0, k = 0, len1 = strlen(name), len2 = strlen(typed);
	for (; i < len1 && i < len2; i++){
		if (*(name + i) != *start1){
			end1 = name + i - 1;
			na[k].c = *start1; na[k].num = end1 - start1 + 1;
			k++;
			start1 = name + i;
		}
		if (*(typed + i) != *start2){
			end2 = typed + i - 1;
			ty[j].c = *start2; ty[j].num = end2 - start2 + 1;
			j++;
			start2 = typed + i;
		}
	}
	int f1 = 0, f2 = 0;
	if (len1 < len2){
		f1 = i;
		int t = i;
		for (; t < len2; t++){
			if (*(typed + t) != *start2){
				end2 = typed + t - 1;
				ty[j].c = *start2; ty[j].num = end2 - start2 + 1;
				j++;
				start2 = typed + t;
			}
		}
		f2 = t;
	}
	else if (len1 > len2){
		f2 = i;
		int t = i;
		for (; t < len1; t++){
			if (*(name + t) != *start1){
				end1 = name + t - 1;
				na[k].c = *start1; na[k].num = end1 - start1 + 1;
				k++;
				start1 = name + t;
			}
		}
		f1 = t;
	}
	end1 = name + f1 - 1;
	na[k].c = *start1; na[k].num = end1 - start1 + 1;
	end2 = typed + f2 - 1;
	ty[j].c = *start2; ty[j].num = end2 - start2 + 1;
	for (int i = 0; i < f1 && i < f2; i++)
		if (na[i].c != ty[i].c || na[i].num > ty[i].num)
			return 0;
	return 1;
}
int main()
{
	char name[] = "yang", typed[] = "yyaaamang";
	printf("%d\n", isLongPressedName(name, typed));

	system("pause");
	return 0;
}






