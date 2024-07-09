/*
Non-traversal related functions go here
*/

#include "main.h"

int getInput() {
    String filename;
    String startVertex;
    
    printf("Input filename: ");
    scanf("%99s", filename);
    
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("%s not found.", filename);
        exit(1);
    }

    Graph *graph = initGraph(fp);
    fclose(fp);

    printGraph(*graph);

    printf("Input start vertex for the traversal: ");
    scanf("%s", startVertex);

    return 0;
}