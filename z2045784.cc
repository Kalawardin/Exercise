#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define INIT_CAP 1024
#define MAX_WORDLEN 4096

static void *xrealloc(void *p, size_t n) {
    void *q = realloc(p, n);
    if (!q) { perror("realloc"); exit(1); }
    return q;
}

static char *xstrdup_lower(const char *s) {
    size_t n = strlen(s);
    char *t = (char *)malloc(n + 1);
    if (!t) { perror("malloc"); exit(1); }
    for (size_t i = 0; i < n; i++) t[i] = (char)tolower((unsigned char)s[i]);
    t[n] = '\0';
    return t;
}

static int strptr_cmp(const void *a, const void *b) {
    const char * const *sa = (const char * const *)a;
    const char * const *sb = (const char * const *)b;
    return strcmp(*sa, *sb);
}

int main(int argc, char **argv) {
    FILE *fp = NULL;
    if (argc == 1) {
        // No filename provided: read from standard input
        fp = stdin;
    } else if (argc == 2) {
        // Read from the provided file
        fp = fopen(argv[1], "r");
        if (!fp) { perror("fopen"); return 1; }
    } else {
        fprintf(stderr, "usage: %s [input-file]\n", argv[0]);
        return 1;
    }

    // counts by word length
    size_t cap = INIT_CAP;
    size_t *len_counts = (size_t *)calloc(cap, sizeof(size_t));
    if (!len_counts) { perror("calloc"); return 1; }

    
    size_t max_len = 0, longest_cap = 128, longest_n = 0;
    char **longest = (char **)malloc(longest_cap * sizeof(char*));
    if (!longest) { perror("malloc"); return 1; }

    // read lines
    char *line = NULL;
    size_t linecap = 0;
    ssize_t linelen;
    size_t total_words = 0;

    while ((linelen = getline(&line, &linecap, fp)) != -1) {
        if (linelen > 0 && line[0] == '#') continue;  // ignore commented line

        // make a mutable copy and "ignore" punctuation . , ; ( )
        for (ssize_t i = 0; i < linelen; i++) {
            char c = line[i];
            if (c == '.' || c == ',' || c == ';' || c == '(' || c == ')')
                line[i] = ' ';
        }
        char *saveptr = NULL;
        for (char *tok = strtok_r(line, " \t\r\n", &saveptr);
             tok != NULL;
             tok = strtok_r(NULL, " \t\r\n", &saveptr)) {

            size_t L = strlen(tok);
            if (L == 0) continue;

            if (L >= cap) {
                size_t newcap = cap;
                while (L >= newcap) newcap *= 2;
                len_counts = (size_t *)xrealloc(len_counts, newcap * sizeof(size_t));
                memset(len_counts + cap, 0, (newcap - cap) * sizeof(size_t));
                cap = newcap;
            }

            len_counts[L] += 1;
            total_words += 1;

            if (L > max_len) {

                for (size_t i = 0; i < longest_n; i++) free(longest[i]);
                longest_n = 0;
                max_len = L;
            }
            if (L == max_len) {
                if (longest_n == longest_cap) {
                    longest_cap *= 2;
                    longest = (char **)xrealloc(longest, longest_cap * sizeof(char*));
                }
                longest[longest_n++] = xstrdup_lower(tok); // store lowercase for de-dup
            }
        }
    }
    free(line);
    if (fp != stdin) fclose(fp);

  
    size_t best_size = 0, best_count = 0;
    for (size_t L = 1; L < cap; L++) {
        if (len_counts[L] > best_count || (len_counts[L] == best_count && L < best_size)) {
            best_count = len_counts[L];
            best_size  = L;
        }
    }

    qsort(longest, longest_n, sizeof(char*), strptr_cmp);
    size_t unique_n = 0;
    for (size_t i = 0; i < longest_n; i++) {
        if (i == 0 || strcmp(longest[i], longest[i-1]) != 0) {
            longest[unique_n++] = longest[i];
        } else {
            free(longest[i]);
        }
    }

    // report
    printf("Total words: %zu\n", total_words);
    printf("Most frequent word size: %zu (%zu times)\n", best_size, best_count);
    printf("Longest word length: %zu (%zu words)\n", max_len, (max_len < cap ? len_counts[max_len] : 0));
    printf("Longest words (unique):\n");
    for (size_t i = 0; i < unique_n; i++) {
        printf("%s\n", longest[i]);
        free(longest[i]);
    }

    free(longest);
    free(len_counts);
    return 0;
}