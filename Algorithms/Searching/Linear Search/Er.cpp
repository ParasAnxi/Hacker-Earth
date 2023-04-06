
int solve(int N, vector<int> workload)
{
    int tot = 0;
    int maxTot = 0;
    for (auto i : workload)
    {
        if (i > 6)
            tot++;
        else
            tot = 0;
        if (tot > maxTot)
            maxTot = tot;
    }
    return maxTot;
}