#include "polygon.h"

/* This function should read the number of vertices record from the file with the supplied file_name,
     allocate memory for the vertex array, and populate the array with data read from the file.
   Note that only x and y fields need to be populated by this function.
   The function should return a pointer to the populated array of vertex records and the number of read records in count.
   If the function fails to read data from the file, it should return NULL and count should be set to 0.
   INPUT:
        file_name: name of the input file located in the local directory
        count: pointer to an int for holding the number of vertices
   OUTPUTS:
        count: holds the number of vertices
   RETURN:        
        pointer to allocated and populated vertex array
        (NULL if read failure)
*/
vertex* read_polygon(char *file_name, int *count)
{
     FILE *file = fopen(file_name, "r");
     if (file == NULL){
          *count = 0;
          return NULL;
     }else{
          fscanf(file, "%d", count);
          vertex *vrtx = malloc((*count) * sizeof(vertex));
          int x, y;
          for (int i = 0; i < *count; i++){
               fscanf(file, "%d %d", &x, &y);
               vrtx[i].x = x;
               vrtx[i].y = y;
               vrtx[i].length = 0.0f; // Initialize length to 0
          }
          fclose(file);
          return vrtx;
     }
     return NULL;
}

/* This function should calculate length of each side of the polygon as well as the polygon’s perimeter.
   The length of polygon’s side is computed as sqrt((x2-x1)^2 + (y2-y1)^2),
   This value should be stored in the length field for polygon with coordinates (x1, y1).
   Perimeter is computed by finding the sum of all side lengths of the polygon.
   This value should be computed and returned by the function.
   INPUT:
        vrtx: pointer to an array of vertices
        count: the length of the vertex array
   OUTPUTS:
        length field of each vertex calculated
   RETURN:        
        calculated perimeter
*/
float calc_perimeter(vertex* vrtx, int count)
{
     if (vrtx == NULL || count <= 0) {
          return 0.0f;
     }
     float perimeter = 0.0f;
     for (int i = 0; i < count; i++) {
          int next_index = (i + 1) % count; // Wrap around to the first vertex
          int dx = vrtx[next_index].x - vrtx[i].x;
          int dy = vrtx[next_index].y - vrtx[i].y;
          float length = sqrt(dx * dx + dy * dy);
          vrtx[i].length = length; // Store the length in the vertex
          perimeter += length; // Add to the perimeter
     }
     return perimeter;
}

/* This function should write to file file_name the number of vertices record followed by records
     for each vertex consisting of the space-separated x, y, and length fields, followed by the perimeter.
   The function should also free memory allocated for vertex array.
   It should return 1 if the data is successfully stored in the output file, or 0 otherwise.
   INPUT:
        file_name: name of the output file
        vrtx: pointer to an array of vertices
        count: the length of the vertex array
        perimeter: the perimeter of the polygon
   OUTPUTS:
        data is written to file_name
   RETURN:        
        1 if file successfully written and vertix freed
        0 otherwise
*/
int record_polygon(char *file_name, vertex *vrtx, int count, float perimeter)
{
     FILE *file = fopen(file_name, "w");
     if (file == NULL) {
          return 0; // Failed to open file
     }
     fprintf(file, "%d\n", count);
     for (int i = 0; i < count; i++){
          fprintf(file, "%d %d %.2f\n", vrtx[i].x, vrtx[i].y, vrtx[i].length);
     }
     fprintf(file, "%.2f\n", perimeter);
     return 0;
}
