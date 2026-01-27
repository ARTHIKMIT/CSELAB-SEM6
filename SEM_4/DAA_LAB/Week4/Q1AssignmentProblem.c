#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

//Getting all permutations of job assignments and calculating the minimum cost
void generateAssignments(int jobAssignments[], int n, double **efficiencyMat, int l, int r, double *minCost, int optimalAssignment[], int *opCount) {
    if (l == r) {
        double cost = 0;
        for (int i = 0; i < n; i++)
            cost += efficiencyMat[i][jobAssignments[i]];
        (*opCount) += n + 1;

        //Updating the minimum cost and the optimal assignment
        if (*minCost > cost) {
            *minCost = cost;
            for (int i = 0; i < n; i++)
                optimalAssignment[i] = jobAssignments[i];
            (*opCount) += n;
        }
    } else {
        for (int i = l; i <= r; i++) {
            swap(&jobAssignments[l], &jobAssignments[i]);
            generateAssignments(jobAssignments, n, efficiencyMat, l + 1, r, minCost, optimalAssignment, opCount);
            swap(&jobAssignments[l], &jobAssignments[i]);  // Backtrack
        }
    }
}

int main() {
    int n;
    printf("Enter the number of employees and jobs: ");
    scanf("%d", &n);

    double **efficiencyMat = (double **)calloc(n, sizeof(double *));
    int *jobAssignments = (int *)calloc(n, sizeof(int));
    int *optimalAssignment = (int *)calloc(n, sizeof(int));

    //Initializing jobAssignments to represent jobs 0, 1, ..., n-1
    for (int i = 0; i < n; i++) {
        jobAssignments[i] = i;
        efficiencyMat[i] = (double *)calloc(n, sizeof(double));
    }

    //Efficiency matrix (cost for each employee-job pair)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Enter efficiency of employee %d for job %d: ", i + 1, j + 1);
            scanf("%lf", &efficiencyMat[i][j]);
        }
    }

    printf("\nEfficiency matrix is:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%lf ", efficiencyMat[i][j]);
        }
        printf("\n");
    }

    double minCost = 10000.0;
    int opCount = 0;

    generateAssignments(jobAssignments, n, efficiencyMat, 0, n - 1, &minCost, optimalAssignment, &opCount);

    // Output the result
    printf("\nMinimum cost: %lf\n", minCost);
    for (int i = 0; i < n; i++) {
        printf("Employee %d is assigned to job %d\n", i + 1, optimalAssignment[i] + 1);
    }
    printf("It took %d operations.\n", opCount);
    return 0;
}
