#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    short r = 0;
    short c = 0;

    scanf("%hd %hd", &r, &c);

    char *map = malloc(r * c);

    short bX = -1;
    short bY = -1;
    short dirX = 0;

    char *subStr = malloc(c + 1);

    for (short i = 0; i < r; i++)
    {
        scanf("%s", subStr);

        // Find the boulder
        if (bX == -1)
        {
            for (short j = 0; j < c; j++)
            {
                if (subStr[j] == 'B')
                {
                    bX = j;
                    bY = i;
                    subStr[j] = '.';
                }
            }
        }

        // Don't copy EOL c + 1
        memcpy(map + i * c, subStr, c);
    }

    free(subStr);

    short dead = 0;
    short descending = 0;
    while (1)
    {
        char currB = map[bY * c + bX];

        if (currB == 'S' || currB == '#')
        {
            if (currB == 'S')
                dead = 1;

            break;
        }
        else if (currB == '.')
        {
            if (map[(bY + 1) * c + bX] != '#')
            {
                bY++;
                descending = 1;
            }
            else
            {
                if (!dirX || map[bY * c + bX + dirX] == '#')
                    break;

                bX += dirX;
            }
        }
        else if (currB == '\\')
        {
            if (descending)
                dirX = 1;
            else
                break;

            descending = 0;
            char nxt = map[bY * c + bX + dirX];
            if (nxt != '\\' && nxt != '#')
                bX += dirX;
        }
        else
        {
            if (descending)
                dirX = -1;
            else
                break;

            descending = 0;
            char nxt = map[bY * c + bX + dirX];
            if (nxt != '/' && nxt != '#')
                bX += dirX;
        }
    }

    free(map);

    if (dead)
    {
        printf("Ponnukaka\n");
    }
    else
    {
        printf("Heill a hufi\n");
    }

    return 0;
}
