#include <stdio.h>
#include <stdlib.h>
#include <GLUT/glut.h>

typedef struct {
  float normal[3];
  float point[3][3];
} Triangle;

unsigned int parse(char *filename, Triangle **tris_p) {
  static int INIT_SIZE = 9000, REALLOC_SIZE = 100, BUFFER_SIZE=100;
  FILE *fp = fopen(filename, "r");
  char buf[100];
  float buffer[BUFFER_SIZE];
  int i, j;
  unsigned int cnt, tris_len;
  
  fread(buf, sizeof(char), 80, fp);
  fread(&tris_len, sizeof(int), 1, fp);

  *tris_p = (Triangle*)malloc(tris_len * sizeof(Triangle));

  printf("tris_len: %d\n", tris_len);
  
  cnt = 0;
  for(cnt=0; cnt<tris_len; cnt++) {
    fread(buffer, sizeof(float), 12, fp);
    for(i=0; i<3; i++) {
      (*tris_p)[cnt].normal[i] = buffer[i];
    }
    for(i=0; i<3; i++) {
      for(j=0; j<3; j++) {
        (*tris_p)[cnt].point[i][j] = buffer[3+i*3+j];
      }
    }
  }
  fclose(fp);
  return tris_len;
}

int main(void) {
  Triangle *tris;
  unsigned int tris_len;
  int i, j, k;
  
  tris_len = parse("./Pieza1a.STL", &tris);
  for(i=0; i<tris_len; i++) {
    printf("Normal: (%f, %f, %f) | ", tris[i].normal[0], tris[i].normal[1], tris[i].normal[2]);
    for(j=0; j<3; j++) {
      printf("(%f, %f, %f) ", tris[i].point[j][0], tris[i].point[j][1], tris[i].point[j][2]);
    }
    printf("\n");
  }

  free(tris);
  return 0;
}
