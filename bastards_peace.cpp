#include <stdlib.h>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef struct
{
    long long *opps;
    long long *strengths;
    int cnt;
    int loc;
} floor_t;

typedef pair<long long, int> plli_t;

int main()
{
    int n, opps;
    unsigned long long s;

    cin >> n >> s;

    priority_queue<plli_t, vector<plli_t>, greater<plli_t>> prio;
    floor_t *floors = (floor_t *)malloc(sizeof(floor_t) * n);

    for (int i = 0; i < n; i++)
    {
        cin >> opps;

        floors[i].opps = (long long *)malloc(sizeof(long long) * opps);
        floors[i].strengths = (long long *)malloc(sizeof(long long) * opps);
        floors[i].cnt = opps;
        floors[i].loc = 0;

        for (int j = 0; j < opps; j++)
        {
            cin >> floors[i].opps[j];

            if (!j)
            {
                prio.push(make_pair(floors[i].opps[j], i));
            }
        }

        for (int j = 0; j < opps; j++)
        {
            cin >> floors[i].strengths[j];
        }
    }

    bool victory = true;

    while (!prio.empty())
    {
        pair<long long, int> curr = prio.top();
        prio.pop();

        if (curr.first >= s)
        {
            victory = false;
            break;
        }

        int f = curr.second;

        s += floors[f].strengths[floors[f].loc++];

        if (floors[f].loc < floors[f].cnt)
        {
            prio.push(make_pair(floors[f].opps[floors[f].loc], f));
        }
    }

    for (int i = 0; i < n; i++)
    {
        free(floors[i].opps);
        free(floors[i].strengths);
    }

    free(floors);

    if (victory)
        cout << "Sigur!" << endl;
    else
        cout << s << endl;

    return 0;
}