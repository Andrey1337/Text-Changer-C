#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

int main(int argc, char *argv[])
{
	if (argc == 3)
	{
		char const* const writingFile = argv[1];
		char const* const readingFile = argv[2];

		FILE* startFile = fopen(writingFile, "r");
		FILE* readFile = fopen(readingFile, "r");
		FILE* newFile = fopen("new.txt", "w");

		char* fiendWord[100];
		memset(fiendWord, '\0', sizeof(fiendWord));
		fgets(fiendWord, sizeof(fiendWord), readFile);

		

		char buffer[250];
		memset(buffer, '\0', sizeof(buffer));

		int c;
		while (EOF != (c = getc(startFile)))
		{
			while (EOF != c && c != ' ' && c != '\0')
			{
				strcat(buffer, &c);
				c = fgetc(startFile);
			}

			char *ptr = strstr(fiendWord, buffer);
			if (ptr != NULL)
			{
				int flag = FALSE;
				char temp[50];
				while (!(*ptr >= 'a' && *ptr <= 'z') || flag != TRUE) // ÄÎØ¨Ë ÄÎ ÑÈÍÎÍÈÌÀ
				{
					if (*ptr == '-')
					{
						flag = TRUE;
					}
					++ptr;
				}

				memset(temp, '\0', sizeof(temp));
				while (*ptr >= 'a' && *ptr <= 'z') // ÂÛÁÐÀË ÑÈÍÎÍÈÌ
				{
					char c = *ptr;
					strncat(temp, &c, 1);
					++ptr;
				}
				strcat(temp, " ");
				fputs(temp, newFile);
			}

			else
			{
				strcat(buffer, " ");
				fputs(buffer, newFile);
			}
			printf("%s\n", buffer);
			memset(buffer, '\0', sizeof(buffer));
		}

		fputs(buffer, newFile);

		fcloseall();
	}
	else
	{
		fprintf(stderr, "Usage: copy file1 file2\n");
		return -1;
	}

	return 0;
}

