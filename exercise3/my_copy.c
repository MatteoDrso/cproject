#include <stdio.h>
#include <stdlib.h>

// source: fread man page
// #define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

enum {
  ARRAY_SIZE = 32
};

int main(int argc, char *argv[])
{
  if (argc != 3) {
    printf("Usage: %s <path_to_file> <target_of_file>", argv[0]);
    return 1;
  }


  FILE *fp1 = fopen(argv[1], "r");
  if (!fp1) {
    perror("fopen first file");
    return EXIT_FAILURE;
  }

  FILE *fp2 = fopen(argv[2], "w");
  if (!fp2) {
    perror("fopen second file");
    return EXIT_FAILURE;
  }

  unsigned char buf[ARRAY_SIZE];

  while (!feof(fp1)) {

    size_t read_ret = fread(buf, sizeof(*buf), ARRAY_SIZE, fp1);

    if (ferror(fp1)) {
      fprintf(stderr, "fread failed: %zu\n", read_ret);
      printf("buf: %s", buf);
      exit(EXIT_FAILURE);
    }

    size_t items_written = 0;

    while (items_written != read_ret) {

      size_t write_ret = fwrite(buf, sizeof(*buf), read_ret, fp2);
        if (ferror(fp2)) {
        fprintf(stderr, "fwrite failed: %zu\n", write_ret);
        exit(EXIT_FAILURE);
      }

      items_written += write_ret;
    }

  
  }

  printf("Success.\n");
  return 0;
}